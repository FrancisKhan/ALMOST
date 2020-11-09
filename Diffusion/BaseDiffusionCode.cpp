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
	
	out.print(TraceLevel::INFO, "\nMMatrix before");
    printMatrix(MMatrix, out, TraceLevel::INFO);

	MMatrix = diffMatrix - MMatrix;

	out.print(TraceLevel::INFO, "\nMMatrix after");
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

void BaseDiffusionCode::solveSystem(MatrixXd &T, VectorXd &source)
{
    VectorXd temperatures = VectorXd::Zero(source.size());
    temperatures = T.colPivHouseholderQr().solve(source);
    m_mesh.setTemperatures(temperatures);
}

void BaseDiffusionCode::setNewHeatSource(Numerics::SourceIterResults result)
{
	MatrixXd meshNeutronFluxes = MatrixXd::Zero(m_energies, m_cells);

	for(int i = 0; i < m_cells; i++)
		for(int j = 0; j < m_energies; j++)
				meshNeutronFluxes(j, i) = result.getNeutronFLux()(i + j * m_cells);

	m_mesh.setNeutronFluxes(meshNeutronFluxes);
	m_reactor.setKFactor(result.getKFactor());

	//VectorXd powerDistribution = calcFissionPowerDistribution();
	//m_mesh.setHeatSources(powerDistribution.cwiseQuotient(m_volumes));
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
	else
	{
		albedoL = 1.0; // Fixed to reflective
    	albedoR = m_solverData.getAlbedo()[0];
	}

    for(int e = 0; e < m_energies; e++)
    {
        for(int m = 0; m < m_cells; m++)
        {
            if(m == 0)
            {
                B = D(e, m) * (1.0 - albedoL) * surfaces(m) / (4.0 * D(e, m) * (1.0 + albedoL) + cellSizes(m) * (1.0 - albedoL));     
                M(m + e * m_cells, m + 1 + e * m_cells) = - 2.0 * DInterface(e, m);
                M(m + e * m_cells, m + e * m_cells) = 2.0 * (DInterface(e, m) + B + 0.5 * totXS(e, m) * volumes(m));
            }
            else if (m == m_cells - 1)
            {
                B = D(e, m) * (1.0 - albedoR) * surfaces(m + 1) / (4.0 * D(e, m) * (1.0 + albedoR) + cellSizes(m) * (1.0 - albedoR));          
                M(m + e * m_cells, m - 1 + e * m_cells) = - 2.0 * DInterface(e, m - 1);
                M(m + e * m_cells, m + e * m_cells) = 2.0 * (B + DInterface(e, m - 1) + 0.5 * totXS(e, m) * volumes(m));
            }
            else
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