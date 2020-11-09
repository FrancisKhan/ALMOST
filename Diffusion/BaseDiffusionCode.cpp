#include "BaseDiffusionCode.h"

using namespace Eigen;
using namespace Numerics;
using namespace PrintFuncs;

MatrixXd BaseDiffusionCode::calcMMatrix(Eigen::MatrixXd &diffMatrix)
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
				scattMatrix(j % m_energies, (k + j) % m_energies, i) * m_volumes(i);
		    }
	    }
	}
	
	MMatrix = diffMatrix - MMatrix;

	out.print(TraceLevel::INFO, "\nMMatrix");
    printMatrix(MMatrix, out, TraceLevel::INFO);

	return MMatrix;
}

MatrixXd BaseDiffusionCode::calcFMatrix()
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
   
   out.print(TraceLevel::INFO, "FMatrix");
   printMatrix(FMatrix, out, TraceLevel::INFO);

   return FMatrix;
}

VectorXd BaseDiffusionCode::calcFissionPowerDistribution()
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

void BaseDiffusionCode::setNewHeatSource(Numerics::SourceIterResults result)
{
	MatrixXd meshNeutronFluxes = MatrixXd::Zero(m_energies, m_cells);

	for(int i = 0; i < m_cells; i++)
		for(int j = 0; j < m_energies; j++)
				meshNeutronFluxes(j, i) = result.getNeutronFLux()(i + j * m_cells);

	m_mesh.setNeutronFluxes(meshNeutronFluxes);
	m_reactor.setKFactor(result.getKFactor());

	VectorXd powerDistribution = calcFissionPowerDistribution();
	m_mesh.setHeatSources(powerDistribution.cwiseQuotient(m_volumes));
}

Eigen::MatrixXd BaseDiffusionCode::getInterfaceDiffcoefficients()
{
	VectorXd cellSizes = m_mesh.getCellSizes("cm");
	MatrixXd D         = m_mesh.getDiffusionConstants();
	VectorXd surfaces  = m_mesh.getSurfaces("cm");


	MatrixXd DInterface = MatrixXd::Zero(m_energies, m_cells);

    for(int e = 0; e < m_energies; e++)
    {
        for(int m = 0; m < m_cells - 1; m++)
        {
            DInterface(e, m) = (D(e, m) * D(e, m + 1) * surfaces(m + 1)) / 
			(cellSizes(m + 1) * D(e, m) + cellSizes(m) * D(e, m + 1));
        }
    }

	return DInterface;
}

MatrixXd BaseDiffusionCode::calcDiffOperatorMatrix()
{
    MatrixXd M = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);

    MatrixXd totXS      = m_mesh.getTotalXSs();
    VectorXd volumes    = m_mesh.getVolumes("cm");
    MatrixXd DInterface = getInterfaceDiffcoefficients();

    for(int e = 0; e < m_energies; e++)
    {
        for(int m = 0; m < m_cells; m++)
        {
            if((m != 0) && (m != m_cells - 1))
            {             
                M(m + e * m_cells, m - 1 + e * m_cells) = - 2.0 * DInterface(e, m - 1);
                M(m + e * m_cells, m + 1 + e * m_cells) = - 2.0 * DInterface(e, m);
                M(m + e * m_cells, m + e * m_cells) = 2.0 * (DInterface(e, m) + DInterface(e, m - 1) + 0.5 * totXS(e, m) * volumes(m));
            } 
        }
    }
        
    out.print(TraceLevel::DEBUG, "Diffusion operator matrix []:");
    printMatrix(M, out, TraceLevel::DEBUG);

    return M;
}

MatrixXd BaseDiffusionCode::applyBoundaryConditions(MatrixXd &M)
{
    MatrixXd D          = m_mesh.getDiffusionConstants();
    MatrixXd totXS      = m_mesh.getTotalXSs();
    VectorXd cellSizes  = m_mesh.getCellSizes("cm");
    VectorXd surfaces   = m_mesh.getSurfaces("cm");
    VectorXd volumes    = m_mesh.getVolumes("cm");
    MatrixXd DInterface = getInterfaceDiffcoefficients();

	double albedoL, albedoR, B;

	if(m_mesh.getGeometry() == GeomKind::SLAB)
	{
		albedoL = m_solverData.getAlbedo()[0];
    	albedoR = m_solverData.getAlbedo()[1];
	}
	else // CYLINDER and SPHERE
	{
		albedoL = 1.0; // Fixed to reflective
    	albedoR = m_solverData.getAlbedo()[0];
	}

	for(int e = 0; e < m_energies; e++)
    {
		// Left boundary condition

        B = D(e, 0) * (1.0 - albedoL) * surfaces(0) / (4.0 * D(e, 0) * (1.0 + albedoL) + cellSizes(0) * (1.0 - albedoL));     
        M(e * m_cells, 1 + e * m_cells) = - 2.0 * DInterface(e, 0);
        M(e * m_cells, e * m_cells) = 2.0 * (DInterface(e, 0) + B + 0.5 * totXS(e, 0) * volumes(0));

		// Right boundary condition

		int l = m_cells - 1;

		B = D(e, l) * (1.0 - albedoR) * surfaces(l + 1) / (4.0 * D(e, l) * (1.0 + albedoR) + cellSizes(l) * (1.0 - albedoR));          
        M(l + e * m_cells, l - 1 + e * m_cells) = - 2.0 * DInterface(e, l - 1);
        M(l + e * m_cells, l + e * m_cells) = 2.0 * (B + DInterface(e, l - 1) + 0.5 * totXS(e, l) * volumes(l));
    }

    out.print(TraceLevel::DEBUG, "M matrix [] (after boundary conditions):");
    printMatrix(M, out, TraceLevel::DEBUG);

    return M;
}