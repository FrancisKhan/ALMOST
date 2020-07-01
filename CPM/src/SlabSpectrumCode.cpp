#include "BaseSpectrumCode.h"
#include "SlabSpectrumCode.h"
#include "numeric_tools.h"

#include <boost/math/special_functions/expint.hpp>
#include <iostream>

using namespace Eigen;
using namespace boost::math;

std::pair<Tensor3d, Tensor4d> SlabSpectrumCode::calcTracks()
{ 
    Tensor4d tau = Tensor4d(m_cells, m_cells, m_rays, m_energies);
	tau.setZero();

    Tensor3d zz(m_cells, m_cells, m_rays);
    zz.setZero();

	std::vector<double> delta(m_radii.size() - 1, 0.0);

	for(size_t i = 0; i < delta.size(); i++)
	{
		delta[i] = m_radii[i + 1] - m_radii[i];
	}
	
	for(int h = 0; h < m_energies; h++)
		for(int i = 0; i < m_cells; i++)
          for(int j = i; j < m_cells; j++)
	      {	
	          if (i == j) 
                  tau(i, j, 0, h) = delta[i] * m_totalXS(h, i);
              else
              {
                  if (i == 0)
					  tau(i, j, 0, h) = delta[j] * m_totalXS(h, j) + tau(0, j - 1, 0, h);
                  else
                      tau(i, j, 0, h) = delta[j] * m_totalXS(h, j) 
                      + tau(0, j - 1, 0, h) - tau(0, i - 1, 0, h);
              }
		  }	  

	for(int h = 0; h < m_energies; h++)
		for(int i = 0; i < m_cells; i++)
          for(int j = i; j < m_cells; j++)
	      {	
	        if (i != j) tau(i, j, 0, h) -= delta[j] * m_totalXS(h, j) +  delta[i] * m_totalXS(h, i);
			if (tau(i, j, 0, h) < 0.0) tau(i, j, 0, h) = 0.0;

			out.getLogger()->trace("Track: {:3d} {:3d} {:3d} {:5.4f}", h, i, j, tau(i, j,  0, h));
	
		  }
  
    std::pair<Tensor3d, Tensor4d> trackData = std::make_pair(zz, tau);
	return trackData;		
}

Tensor3d SlabSpectrumCode::calcCPs(std::pair<Tensor3d, Tensor4d> &trackData)
{	
	Tensor4d tau = trackData.second;

	Tensor3d gcpm = Tensor3d(m_cells, m_cells, m_energies);
	gcpm.setZero();

	Tensor3d CSet1(m_cells, m_cells, m_cells);
	Tensor3d CSet2(m_cells, m_cells, m_cells);
	
	MatrixXd P = MatrixXd::Zero(m_cells, m_cells);
	
    for(int h = 0; h < m_energies; h++)
	{
	  for(int i = 0; i < m_cells; i++)
        for(int j = i; j < m_cells; j++)
		{
          if (j == i) 
            P(i, j) = 1.0 - (1.0 / (2.0 * tau(i, i, 0, h))) * (1.0 - 2.0 * expint(3, tau(i, i, 0, h)));
          else
            P(i, j) = (1.0 / (2.0 * tau(i, i, 0, h))) * (expint(3, tau(i, j, 0, h)) 
			          - expint(3, tau(i, j, 0, h) + tau(i, i, 0, h)) 
					  - expint(3, tau(i, j, 0, h) + tau(j, j, 0, h)) 
					  + expint(3, tau(i, j, 0, h) + tau(j, j, 0, h) + tau(i, i, 0, h)));
		}

	for(int i = 0; i < m_cells; i++)
	  for(int j = i + 1; j < m_cells; j++)
          P(j, i) = P(i, j) * (m_totalXS(h, i) / m_totalXS(h, j)) * (m_volumes(i) / m_volumes(j));

	for(int i = 0; i < m_cells; i++)
	  for(int j = 0; j < m_cells; j++)
		gcpm(i, j, h) = P(i, j);
	}

	out.getLogger()->debug("P matrix (vacuum BC)");
    printMatrix(gcpm, out, TraceLevel::DEBUG, "Group");

	return gcpm;
}

void SlabSpectrumCode::applyBoundaryConditions(Tensor3d &gcpm)
{	
	for(int h = 0; h < m_energies; h++)
	{
		out.getLogger()->debug("Apply boundary conditions Group {}", h + 1);
		
		double albedo = m_mesh.getAlbedo();
		
		VectorXd Pis   = VectorXd::Zero(m_cells);
	    VectorXd psi   = VectorXd::Zero(m_cells);
		
		Pis.setZero();
		psi.setZero();

		for(int i = 0; i < m_cells; i++)
		{
			for(int j = 0; j < m_cells; j++)
			{
				gcpm(i, j, h) /= m_totalXS(h, j);  //reduced
			}
		}
		
		for(int i = 0; i < m_cells; i++)
		{
			for(int j = 0; j < m_cells; j++)
			{
				Pis(i) += gcpm(i, j, h) * m_totalXS(h, j);
			}
			
			Pis(i) = 1.0 - Pis(i);
			psi(i) = (4.0 * m_volumes(i) / m_surface) * Pis(i);
			
			out.getLogger()->debug("Cell n: {} Pis: {:7.6e}  psi [cm]: {:7.6e}", i, Pis(i), psi(i));
		}
		
		double Pss = 0.0;
		
		for(int i = 0; i < m_cells; i++)
        {
			Pss += psi(i) * m_totalXS(h, i);
		}
		
		Pss = 1.0 - Pss;
		
		out.getLogger()->debug("Pss [cm2]: {:7.6e} \n", Pss);
		
		for(int i = 0; i < m_cells; i++)
		{
			for(int j = 0; j < m_cells; j++)
			{
				gcpm(i, j, h) += Pis(i) * psi(j) * (albedo / (1.0 - Pss * albedo));
				gcpm(i, j, h) *= m_totalXS(h, j);
			}
		}
				
	}	
	
	out.getLogger()->debug("P matrix (white BC)");
    printMatrix(gcpm, out, TraceLevel::DEBUG, "Group");

    for(int h = 0; h < m_energies; h++)
	{
	    for(int i = 0; i < m_cells; i++)
		{
			for(int j = 0; j < m_cells; j++)
			{
				gcpm(i, j, h) /= m_totalXS(h, j);
			}
		}
	}	
}