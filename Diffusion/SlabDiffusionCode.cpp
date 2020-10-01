#include "BaseDiffusionCode.h"
#include "SlabDiffusionCode.h"
#include "numeric_tools.h"

using namespace Eigen;
using namespace PrintFuncs;

MatrixXd SlabDiffusionCode::createMMatrix()
{
    MatrixXd M = MatrixXd::Zero(m_cells, m_cells);

    VectorXd D         = getInterfaceDiffusionConstants();
    VectorXd cellSizes = m_mesh.getCellSizes("m");

    for(int i = 0; i < m_cells; i++)
    {
        if (i == 0)
        {
            M(i, i)     = + D[i + 1] / cellSizes(i + 1);
            M(i, i + 1) = - D[i + 1] / cellSizes(i + 1);
        }
        else if (i == m_cells - 1)
        {
            M(i, i)     = + D[i] / cellSizes(i - 1);
            M(i, i - 1) = - D[i] / cellSizes(i - 1);
        }
        else
        {
            M(i, i)     = + D[i] / cellSizes(i - 1) 
                          + D[i + 1] / cellSizes(i + 1);
                          
            M(i, i - 1) = - D[i] / cellSizes(i - 1);
            M(i, i + 1) = - D[i + 1] / cellSizes(i + 1);
        }
    }

    return M;
}

MatrixXd SlabDiffusionCode::applyBoundaryConditions(MatrixXd &M)
{
    VectorXd boundaries = m_mesh.getHeatBoundaryConditions();
    VectorXd lambda     = getInterfaceDiffusionConstants();

    // Left boundary condition

    double deltaXL = m_radii(1) - m_radii(0);

    double AL = boundaries(0);
    double BL = boundaries(1);
    //double CL = boundaries(2);

    double denominatorL = (deltaXL / (2.0 * lambda(0))) * AL + BL;
    double alphaL =  AL / denominatorL;
    //double betaL  = -CL / denominatorL;

    M(0, 0) = M(0, 0) + alphaL;

    // Right boundary condition

    double deltaXR = m_radii(m_cells) - m_radii(m_cells - 1);

    double AR = boundaries(3);
    double BR = boundaries(4);
    //double CR = boundaries(5);

    double denominatorR = (deltaXR / (2.0 * lambda(m_cells - 1))) * AR + BR;
    double alphaR =  AR / denominatorR;
    //double betaR  = -CR / denominatorR;

    M(m_cells - 1, m_cells - 1) = M(m_cells - 1, m_cells - 1) + alphaR;

    out.print(TraceLevel::DEBUG, "Thermal conductivities [W/(m*K)]:");
    printVector(lambda, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "M matrix [W/(m2*K)]:");
    printMatrix(M, out, TraceLevel::DEBUG);

    return M;
}
