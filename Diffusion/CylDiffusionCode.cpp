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

    double albedoL = 1.0; // Fixed to reflective
    double albedoR = m_solverData.getAlbedo()[0];

    double A, B;

    for(int e = 0; e < m_energies; e++)
    {
        for(int m = 0; m < m_cells; m++)
        {
            double volume  = M_PI * (pow(m_radii(m + 1), 2) - pow(m_radii(m), 2));
            double SOverVp = (2.0 * M_PI * m_radii(m + 1));
            double SOverVm = (2.0 * M_PI * m_radii(m));

            if(m == 0)
            {
                A = (D(e, m) * D(e, m + 1)) * SOverVp / ((cellSizes(m + 1) * D(e, m) + cellSizes(m) * D(e, m + 1)));
                B = D(e, m) * (1.0 - albedoL) * SOverVm  / ((4.0 * D(e, m) * (1.0 + albedoL) + cellSizes(m) * (1.0 - albedoL)));
                //B = D(e, m) * SOverVm / cellSizes(m);      
                M(m + e * m_cells, m + 1 + e * m_cells) = - 2.0 * A;
            }
            else if (m == m_cells - 1)
            {
                A = D(e, m) * (1.0 - albedoR) * SOverVp / ((4.0 * D(e, m) * (1.0 + albedoR) + cellSizes(m) * (1.0 - albedoR)));
                //A = D(e, m) * SOverVp / cellSizes(m);
                B = (D(e, m) * D(e, m - 1) * SOverVm) / ((cellSizes(m) * D(e, m - 1) + cellSizes(m - 1) * D(e, m)));             
                M(m + e * m_cells, m - 1 + e * m_cells) = - 2.0 * B;
            }
            else
            {      
                A = (D(e, m) * D(e, m + 1)) * SOverVp / ((cellSizes(m + 1) * D(e, m) + cellSizes(m) * D(e, m + 1)));
                B = (D(e, m) * D(e, m - 1)) * SOverVm / ((cellSizes(m) * D(e, m - 1) + cellSizes(m - 1) * D(e, m)));         
                M(m + e * m_cells, m - 1 + e * m_cells) = - 2.0 * B;
                M(m + e * m_cells, m + 1 + e * m_cells) = - 2.0 * A;
            }

            M(m + e * m_cells, m + e * m_cells) = 2.0 * (A + B + 0.5 * totXS(e, m) * volume); 
        }
    }
        
    out.print(TraceLevel::DEBUG, "Diffusion operator matrix []:");
    printMatrix(M, out, TraceLevel::DEBUG);

    return M;
}