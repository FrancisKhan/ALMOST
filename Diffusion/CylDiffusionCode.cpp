#include "BaseDiffusionCode.h"
#include "CylDiffusionCode.h"
#include "numeric_tools.h"

using namespace Eigen;
using namespace PrintFuncs;

MatrixXd CylDiffusionCode::calcDiffOperatorMatrix()
{
    MatrixXd M = MatrixXd::Zero(m_cells * m_energies, m_cells * m_energies);

    MatrixXd D          = m_mesh.getDiffusionConstants();
    MatrixXd totXS      = m_mesh.getTotalXSs();
    VectorXd cellSizes  = m_mesh.getCellSizes("cm");
    VectorXd surfaces   = m_mesh.getSurfaces("cm");
    VectorXd volumes    = m_mesh.getVolumes("cm");
    MatrixXd DInterface = getInterfaceDiffcoefficients();

    double albedoL = 1.0; // Fixed to reflective
    double albedoR = m_solverData.getAlbedo()[0];

    double B;

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