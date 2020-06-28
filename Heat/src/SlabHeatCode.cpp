#include "BaseHeatCode.h"
#include "SlabHeatCode.h"
#include "numeric_tools.h"

using namespace Eigen;

std::tuple<MatrixXd, VectorXd> SlabHeatCode::setupSystem()
{
    MatrixXd T = MatrixXd::Zero(m_cells, m_cells);

    m_temperatures     = m_mesh.getTemperatures("C");
    m_heatSources      = m_mesh.getHeatSources();
    VectorXd lambda    = getInterfaceThermalConductivities();
    VectorXd cellSizes = m_mesh.getCellSizes("m");

    for(int i = 0; i < m_cells; i++)
    {
        if (i == 0)
        {
            T(i, i)     = + lambda[i] / cellSizes(i);
            T(i, i + 1) = - lambda[i] / cellSizes(i + 1);
        }
        else if (i == m_cells - 1)
        {
            T(i, i)     = + lambda[i] / cellSizes(i);
            T(i, i - 1) = - lambda[i] / cellSizes(i - 1);
        }
        else
        {
            T(i, i)     = + lambda[i] / cellSizes(i - 1) + lambda[i] / cellSizes(i + 1);
            T(i, i - 1) = - lambda[i] / cellSizes(i - 1);
            T(i, i + 1) = - lambda[i] / cellSizes(i + 1);
        }

        m_heatSources(i) *= cellSizes(i);
    }
   
    out.getLogger()->debug("T matrix");
    printMatrix(T, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Source");
    printVector(m_heatSources, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Lambda");
    printVector(lambda, out, TraceLevel::DEBUG);

    return std::make_tuple(T, m_heatSources);
}

std::tuple<MatrixXd, VectorXd> SlabHeatCode::applyBoundaryConditions(MatrixXd &T, VectorXd &source)
{
    VectorXd boundaries = m_mesh.getHeatBoundaryConditions();
    VectorXd lambda     = getInterfaceThermalConductivities();

    // Left boundary condition

    double deltaXL = m_radii(1) - m_radii(0);

    double AL = boundaries(0);
    double BL = boundaries(1);
    double CL = boundaries(2);

    double denominatorL = (deltaXL / (2.0 * lambda(0))) * AL + BL;
    double alphaL =  AL / denominatorL;
    double betaL  = -CL / denominatorL;

    T(0, 0) = T(0, 0) + alphaL;
    source(0) = source(0) - betaL;

    // Right boundary condition

    double deltaXR = m_radii(m_cells) - m_radii(m_cells - 1);

    double AR = boundaries(3);
    double BR = boundaries(4);
    double CR = boundaries(5);

    double denominatorR = (deltaXR / (2.0 * lambda(m_cells - 1))) * AR + BR;
    double alphaR =  AR / denominatorR;
    double betaR  = -CR / denominatorR;

    T(m_cells - 1, m_cells - 1) = T(m_cells - 1, m_cells - 1) + alphaR;
    source(m_cells - 1) = source(m_cells - 1) - betaR;

    out.getLogger()->debug("T matrix2");
    printMatrix(T, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Source2");
    printVector(source, out, TraceLevel::DEBUG);

    return std::make_tuple(T, source);
}
