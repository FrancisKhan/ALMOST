#include "AdjointDiffusionCode.h"

using namespace Eigen;
using namespace Numerics;
using namespace PrintFuncs;

MatrixXd AdjointDiffusionCode::calcMMatrix(Eigen::MatrixXd &diffMatrix)
{
    MatrixXd MMatrix = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);

	Tensor3d scattMatrix = m_mesh.getScattMatrices();
	
	// scattering matrix generation
	
	for(int i = 0; i < m_energies; i++)
    {
	    for(int j = 0; j < m_energies; j++)
        {
	        for(int k = 0; k < m_cells; k++)
	        {
	      	    MMatrix(k + (i + j) % m_energies * m_cells, k + j * m_cells) = 
				scattMatrix((i + j) % m_energies, j % m_energies, k) * m_volumes(k);
		    }
	    }
	}
	
	MMatrix = diffMatrix - MMatrix;

	out.print(TraceLevel::INFO, "\nMMatrix");
    printMatrix(MMatrix, out, TraceLevel::INFO);

	return MMatrix;
}

MatrixXd AdjointDiffusionCode::calcFMatrix()
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
					FMatrix(i, j) = FMatrix(i, j + (k - n) * m_cells);
				}
			}
		}
	}
   
    for(int i = 0; i < m_cells * m_energies; i++)
    {
	    for(int j = 0; j < m_cells * m_energies; j++)
	    {
			FMatrix(i, j) *= chiMatrix(j);
		}
	}

    out.print(TraceLevel::INFO, "FMatrix");
    printMatrix(FMatrix, out, TraceLevel::INFO);

   return FMatrix;
}