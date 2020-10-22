#include "BaseDiffusionCode.h"
#include "CylDiffusionCode.h"
#include "numeric_tools.h"

using namespace Eigen;
using namespace PrintFuncs;

MatrixXd CylDiffusionCode::calcDiffOperatorMatrix()
{
    MatrixXd M = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);

    MatrixXd D         = m_mesh.getDiffusionConstants();
    MatrixXd totXS     = m_mesh.getTotalXSs();
    VectorXd cellSizes = m_mesh.getCellSizes("cm");

    out.print(TraceLevel::DEBUG, "D vector:");
    printMatrix(D, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "totXS vector:");
    printMatrix(totXS, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "cellSizes vector:");
    printVector(cellSizes, out, TraceLevel::DEBUG);

    double albedoL = m_solverData.getAlbedo()[0];
    double albedoR = m_solverData.getAlbedo()[1];

    out.print(TraceLevel::DEBUG, "albedo: {} {}\n", albedoL, albedoR);

    double A, B;

    for(int e = 0; e < m_energies; e++)
    {
        for(int m = 0; m < m_cells; m++)
        {
            if(m == 0)
            {
                A = (D(e, m) * D(e, m + 1)) / (cellSizes(m) * (cellSizes(m + 1) * D(e, m) + cellSizes(m) * D(e, m + 1)));
                B = D(e, m) * (1.0 - albedoL) / (cellSizes(m) * (4.0 * D(e, m) * (1.0 + albedoL) + cellSizes(m) * (1.0 - albedoL)));
                //B = D(e, m) / pow(cellSizes(m), 2);        
                M(m + e * m_cells, m + 1 + e * m_cells) = - 2.0 * A;
            }
            else if (m == m_cells - 1)
            {
                A = D(e, m) * (1.0 - albedoR) / (cellSizes(m) * (4.0 * D(e, m) * (1.0 + albedoR) + cellSizes(m) * (1.0 - albedoR)));
                //A = D(e, m) / pow(cellSizes(m), 2);
                B = (D(e, m) * D(e, m - 1)) / (cellSizes(m) * (cellSizes(m) * D(e, m - 1) + cellSizes(m - 1) * D(e, m)));             
                M(m + e * m_cells, m - 1 + e * m_cells) = - 2.0 * B;
            }
            else
            {      
                A = (D(e, m) * D(e, m + 1)) / (cellSizes(m) * (cellSizes(m + 1) * D(e, m) + cellSizes(m) * D(e, m + 1)));
                B = (D(e, m) * D(e, m - 1)) / (cellSizes(m) * (cellSizes(m) * D(e, m - 1) + cellSizes(m - 1) * D(e, m)));         
                M(m + e * m_cells, m - 1 + e * m_cells) = - 2.0 * B;
                M(m + e * m_cells, m + 1 + e * m_cells) = - 2.0 * A;
            }

            M(m + e * m_cells, m + e * m_cells) = 2.0 * (A + B + 0.5 * totXS(e, m)); 
        }
    }
        
    out.print(TraceLevel::DEBUG, "Diffusion operator matrix []:");
    printMatrix(M, out, TraceLevel::DEBUG);

    return M;
}