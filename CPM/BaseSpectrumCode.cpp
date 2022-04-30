#include "BaseSpectrumCode.h"
#include "numeric_tools.h"

#include <iostream>
#include <iomanip>

using namespace Eigen;
using namespace Numerics;
using namespace PrintFuncs;

const double BaseSpectrumCode::abscissa[8] = {0.0446339553, 0.1443662570, 0.2868247571,
                                              0.4548133152, 0.6280678354, 0.7856915206,
									   	      0.9086763921, 0.9822200849};
										  
const double BaseSpectrumCode::weights[8] = {0.0032951914, 0.0178429027, 0.0454393195,
                                             0.0791995995, 0.1060473594, 0.1125057995,
										     0.0911190236, 0.0445508044};


void BaseSpectrumCode::particleBalanceCheck(Tensor3d &gcpm)
{
	VectorXd check = VectorXd::Zero(m_cells);
	
	for(int h = 0; h < m_energies; h++)
	{
		out.print(TraceLevel::INFO, "Particles Balance Check for Group: {}", h + 1);

		for(int i = 0; i < m_cells; i++)
        {
			check(i) = 0.0;
	        for(int j = 0; j < m_cells; j++)
	        {
				check(i) += gcpm(i, j, h) * m_totalXS(h, j);
			}
			
			out.print(TraceLevel::INFO, "check: {} {:7.6e}", i + 1, check(i));
		}
	}
}

MatrixXd BaseSpectrumCode::calcCPMMatrix(Tensor3d &gcpm)
{
   // final collision probability matrix calculation (form gcpm to cpm)

   MatrixXd cpm = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);
   
   for(int k = 0; k < m_energies; k++)
    {
	    for(int j = k * m_cells; j < (k + 1) * m_cells; j++)
        {
	        for(int i = k * m_cells; i < (k + 1) * m_cells; i++)
	        {
	      	    cpm(i, j) = gcpm(i - k * m_cells, j - k * m_cells, k);
		    }
	    }
	}
   
   out.print(TraceLevel::DEBUG, "\nCPM matrix");
   printMatrix(cpm, out, TraceLevel::DEBUG);

   return cpm;
}

MatrixXd BaseSpectrumCode::calcMMatrix(MatrixXd &cpm)
{
    MatrixXd MMatrix = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);

	Tensor3d scattMatrix = m_mesh.getScattMatrices();
	
	// scattering matrix generation
	
	for(int k = 0; k < m_energies; k++)
    {
	    for(int j = 0; j < m_energies; j++)
        {
	        for(int i = 0; i < m_cells; i++)
	        {
	      	    MMatrix(i + (k + j) % m_energies * m_cells, i + j * m_cells) = 
				scattMatrix(j % m_energies, (k + j) % m_energies, i);
		    }
	    }
	}
	
    MMatrix = -cpm * MMatrix; // the minus sign!
   
    for(int i = 0; i < m_cells * m_energies; i++)
    {
	   MMatrix(i, i) += 1.0;
    }
   
	out.print(TraceLevel::INFO, "\nMMatrix");
    printMatrix(MMatrix, out, TraceLevel::INFO);

	return MMatrix;
}

MatrixXd BaseSpectrumCode::calcFMatrix(MatrixXd &cpm)
{
    MatrixXd FMatrix = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);

	MatrixXd fissXS = m_mesh.getFissionXSs();
	MatrixXd chiXS  = m_mesh.getChis();
	MatrixXd niXS   = m_mesh.getNis();
	
	VectorXd chiMatrix = VectorXd::Zero(m_cells * m_energies);
	
	// diagonal elements generation
	for(int j = 0; j < m_energies; j++)
    {
	    for(int i = 0; i < m_cells; i++)
	    {
            FMatrix(i + j * m_cells, i + j * m_cells) = fissXS(j, i) * niXS(j, i);
            chiMatrix(i + j * m_cells)                = chiXS(j, i);
		}
	}

    for(int n = 0; n < m_energies; n++)
    {
	    for(int k = 0; k < m_energies; k++)
	    {
			for(int i = k * m_cells; i < (k + 1) * m_cells; i++)
			{
				for(int j = n * m_cells; j < (n + 1) * m_cells; j++)
				{
					FMatrix(i, j) = FMatrix(i + (n - k) * m_cells, j);
				}
			}
		}
	}
   
    for(int i = 0; i < m_cells * m_energies; i++)
    {
	    for(int j = 0; j < m_cells * m_energies; j++)
	    {
			FMatrix(i, j) *= chiMatrix(i);
		}
	}
   
   FMatrix = cpm * FMatrix;
   
   out.print(TraceLevel::INFO, "FMatrix");
   printMatrix(FMatrix, out, TraceLevel::INFO);

   return FMatrix;
}

VectorXd BaseSpectrumCode::calcFissionPowerDistribution()
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


void BaseSpectrumCode::setNewHeatSource(Numerics::eigenmodesResults result)
{
	MatrixXd meshNeutronFluxes = MatrixXd::Zero(m_energies, m_cells);

	for(int i = 0; i < m_cells; i++)
		for(int j = 0; j < m_energies; j++)
				meshNeutronFluxes(j, i) = result.getFundamentalNeutronFLux()(i + j * m_cells);

	m_mesh.setNeutronFluxes(meshNeutronFluxes);
	m_reactor.setKFactor(result.getFundamentalKFactor());

	VectorXd powerDistribution = calcFissionPowerDistribution();

	// The heat diffusion code expects the power density in W/m3

	VectorXd volumes = m_mesh.getVolumes("m");
	m_mesh.setHeatSources(powerDistribution.cwiseQuotient(volumes));
}