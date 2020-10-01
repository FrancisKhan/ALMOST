#include "BaseDiffusionCode.h"
#include "CylDiffusionCode.h"
#include "numeric_tools.h"

using namespace Eigen;
using namespace PrintFuncs;

MatrixXd CylDiffusionCode::createMMatrix()
{
    MatrixXd T = MatrixXd::Zero(m_cells, m_cells);

    m_temperatures     = m_mesh.getTemperatures("C");
    m_heatSources      = m_mesh.getHeatSources();
    VectorXd lambda    = getInterfaceDiffusionConstants();
    VectorXd cellSizes = m_mesh.getCellSizes("m");

    for(int i = 0; i < m_cells; i++)
    {
        if(i == 0)
        {
            T(i, i)     = + lambda[i + 1] * m_radii(i + 1) / cellSizes(i + 1);
            T(i, i + 1) = - lambda[i + 1] * m_radii(i + 1) / cellSizes(i + 1);
        }
        else if(i == m_cells - 1)
        {
            T(i, i)     = + lambda[i] * m_radii(i) / cellSizes(i - 1);
            T(i, i - 1) = - lambda[i] * m_radii(i) / cellSizes(i - 1);
        }
        else
        {
            T(i, i)     = + lambda[i] * m_radii(i) / cellSizes(i - 1) + 
                            lambda[i + 1] * m_radii(i + 1) / cellSizes(i + 1);

            T(i, i - 1) = - lambda[i] * m_radii(i) / cellSizes(i - 1);
            T(i, i + 1) = - lambda[i + 1] * m_radii(i + 1) / cellSizes(i + 1);
        }
    }

    return T;
}

MatrixXd CylDiffusionCode::applyBoundaryConditions(MatrixXd &T)
{
    VectorXd boundaries = m_mesh.getHeatBoundaryConditions();
    VectorXd lambda     = getInterfaceDiffusionConstants();

    // Right boundary condition

    double deltaXR = m_radii(m_cells) - m_radii(m_cells - 1);

    double AR = boundaries(3);
    double BR = boundaries(4);
    //double CR = boundaries(5);

    double denominatorR = (deltaXR / (2.0 * m_radii(m_cells) * lambda(m_cells - 1))) * AR + BR;
    double alphaR =  AR / denominatorR;
    //double betaR  = -CR / denominatorR;

    T(m_cells - 1, m_cells - 1) = T(m_cells - 1, m_cells - 1) + alphaR;

    out.print(TraceLevel::DEBUG, "Thermal conductivities [W/(m*K)]:");
    printVector(lambda, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "T matrix [W/(m*K)]:");
    printMatrix(T, out, TraceLevel::DEBUG);

    return T;
}
