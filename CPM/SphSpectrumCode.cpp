#include "BaseSpectrumCode.h"
#include "SphSpectrumCode.h"
#include "numeric_tools.h"

#include <iostream>

using namespace Eigen;
using namespace Numerics;
using namespace PrintFuncs;

std::pair<Tensor3d, Tensor4d> SphSpectrumCode::calcTracks()
{
    Tensor4d tau = Tensor4d(m_cells, m_cells, m_rays, m_energies);
	tau.setZero();
	
	Tensor3d zz(m_cells, m_cells, m_rays);
    zz.setZero();
	
	Tensor3d tracks(m_cells, m_cells, m_rays);
    tracks.setZero();
	
	for(int k = 0; k < m_cells; k++)
		for(int j = k; j < m_cells; j++)
          for(int i = 0; i < m_rays; i++)
	      {	
	          zz(k, j, i) = m_radii(k + 1) - (m_radii(k + 1) - m_radii(k)) * pow(abscissa[i], 2); 
			  tracks(k, j, i) = sqrt(pow(m_radii(j + 1), 2) - pow(zz(k, j, i), 2));
			  
			  out.print(TraceLevel::TRACE, "Track: {:3d} {:3d} {:3d} {:5.4f} {:5.4f}", 
			  			k, j, i, zz(k, j, i), tracks(k, j, i));
	
		  }	  
	
	for(int h = 0; h < m_energies; h++)
	{
		for(int k = 0; k < m_cells; k++)
		{
			for(int i = 0; i < m_rays; i++)
			{
				for(int j = k; j < m_cells; j++)
				{
					if(j == k) 
						tau(k, j, i, h) = tracks(k, j, i) * m_totalXS(h, j);
					else
						tau(k, j, i, h) = (tracks(k, j, i) - tracks(k, j - 1, i)) * m_totalXS(h, j) +
					    tau(k, j - 1, i, h);
						
						out.print(TraceLevel::TRACE, "Tau: {:3d} {:3d} {:3d} {:3d} {:5.4f}", 
								  k, j, i, h, tau(k, j, i, h));
				}
					
			}
		}	
	}
  
    std::pair<Tensor3d, Tensor4d> trackData = std::make_pair(zz, tau);
	return trackData;		
}

Tensor3d SphSpectrumCode::calcCPs(std::pair<Tensor3d, Tensor4d> &trackData)
{	
    Tensor3d zz  = trackData.first;
	Tensor4d tau = trackData.second;

	Tensor3d gcpm = Tensor3d(m_cells, m_cells, m_energies);
	gcpm.setZero();

	Tensor3d CSet1(m_cells, m_cells, m_cells);
	Tensor3d CSet2(m_cells, m_cells, m_cells);
	
	MatrixXd C1 = MatrixXd::Zero(m_cells, m_cells);
	MatrixXd C2 = MatrixXd::Zero(m_cells, m_cells);
	
	double taumb;
	double taupb;
	double taupbb;
	double taum;
	double taup;
	
	for(int h = 0; h < m_energies; h++)
	{
		C1.setZero();
		C2.setZero();
		CSet1.setZero();
		CSet2.setZero();
		
		for(int m = 0; m < m_cells; m++)
		{
			for(int i = m; i < m_cells; i++)
			{
				for(int j = i; j < m_cells; j++)
				{
					for(int k = 0; k < m_rays; k++)
				    {
						if(i > m)
						{
							taumb  = tau(m, j, k, h) - tau(m, i - 1, k, h);
							taupb  = taumb + 2.0 * tau(m, i - 1, k, h);
							taupbb = tau(m, j - 1, k, h) - tau(m, i - 1, k, h) + 2.0 * tau(m, i - 1, k, h);
						}
						else
						{
							taumb  = 0.0;
							taupb  = 0.0;
							taupbb = 0.0;
						}
						
						taum = tau(m, j, k, h) - tau(m, i, k, h);
						taup = taum + 2.0 * tau(m, i, k, h);
						
						if (j == i)
						{
							CSet2(m, i, j) = (2.0 * exp(-taupb) + 2.0 * (exp(-taum) - exp(-taumb))
						    - exp(-taup) - exp(-taupbb)) 
							* weights[k] * (m_radii(m + 1) - m_radii(m)) * zz(m, j, k) + CSet2(m, i, j);
						}
						
						CSet1(m, i, j) = (exp(-taupb) - exp(-taup) + exp(-taum) - exp(-taumb))
                        * weights[k] * (m_radii(m + 1) - m_radii(m)) * zz(m, j, k) + CSet1(m, i, j);
					}

					CSet1(m, i, j) *= M_PI * 4.0 / (m_volumes(i) * m_totalXS(h, i));
                    CSet2(m, i, j) *= M_PI * 4.0 / (m_volumes(i) * m_totalXS(h, i));
				}
					
			}
		}	
		
	    for(int i = 0; i < m_cells; i++)
        {
	        for(int m = 0; m <= i; m++)
	        {
		        C2(i, i) += CSet2(m, i, i);
		   
		        for(int j = i; j < m_cells; j++)
	            {
			        C1(i, j) += CSet1(m, i, j);
		        }
	        }
        }

        gcpm(0, 0, h) = C1(0, 0);

        for(int i = 0; i < m_cells; i++)
        {
	        for(int j = i; j < m_cells - 1; j++)
	        {
				gcpm(i, j + 1, h) = C1(i, j) - C1(i, j + 1);
	        }
        } 
   
        for(int i = 0; i < m_cells; i++)
        {
			gcpm(i, i, h) = 1.0 - C2(i, i);
        }

        for(int i = 0; i < m_cells; i++)
        {
	        for(int j = i + 1; j < m_cells; j++)
	        {
		        gcpm(j, i, h) = gcpm(i, j, h) * (m_volumes(i) / m_volumes(j)) 
				* (m_totalXS(h, i) / m_totalXS(h, j));
	        }
        }
	}
	
	out.print(TraceLevel::INFO, "P matrix (vacuum BC)");
    printMatrix(gcpm, out, TraceLevel::INFO, "Group");

	return gcpm;
}

void SphSpectrumCode::applyBoundaryConditions(Tensor3d &gcpm)
{	
	for(int h = 0; h < m_energies; h++)
	{
		out.print(TraceLevel::INFO, "Apply boundary conditions Group {}", h + 1);
		
		double albedo = m_solverData.getAlbedo()[0];
		
		VectorXd Pis = VectorXd::Zero(m_cells);
	    VectorXd psi = VectorXd::Zero(m_cells);
		
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
			
			out.print(TraceLevel::INFO, "Cell n: {} Pis: {:7.6e}  psi [cm]: {:7.6e}", i, Pis(i), psi(i));
		}
		
		double Pss = 0.0;
		
		for(int i = 0; i < m_cells; i++)
        {
			Pss += psi(i) * m_totalXS(h, i);
		}
		
		Pss = 1.0 - Pss;
		
		out.print(TraceLevel::INFO, "Pss [cm2]: {:7.6e} \n", Pss);
		
		for(int i = 0; i < m_cells; i++)
		{
			for(int j = 0; j < m_cells; j++)
			{
				gcpm(i, j, h) += Pis(i) * psi(j) * (albedo / (1.0 - Pss * albedo));
				gcpm(i, j, h) *= m_totalXS(h, j);
			}
		}
				
	}	
	
	out.print(TraceLevel::INFO, "P matrix (white BC)");
    printMatrix(gcpm, out, TraceLevel::INFO, "Group");

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

VectorXd SphSpectrumCode::calcFissionPowerDistribution()
{
	MatrixXd neutronFluxes = m_mesh.getNeutronFluxes();
	MatrixXd fissXSs = m_mesh.getFissionXSs();

	MatrixXd product = neutronFluxes.cwiseProduct(fissXSs);
	VectorXd powerDensities = product.colwise().sum();
	VectorXd powers = powerDensities.cwiseProduct(m_volumes);

	double thermalPower = m_reactor.getThermalPower();

	VectorXd powerDistribution = VectorXd::Zero(m_cells);

	for(int i = 0; i < m_cells; i++)
	{
		powerDistribution(i) = thermalPower * powers(i) / powers.sum();
	}

	return powerDistribution;
}