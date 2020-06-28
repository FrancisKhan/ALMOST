#include "BaseHeatCode.h"
#include "CylHeatCode.h"
#include "numeric_tools.h"

using namespace Eigen;

std::tuple<MatrixXd, VectorXd> CylHeatCode::setupSystem()
{
    MatrixXd T = MatrixXd::Zero(m_cells, m_cells);

    m_temperatures  = m_mesh.getTemperatures("C");
    m_heatSources   = m_mesh.getHeatSources();
    VectorXd lambda = m_mesh.getThermalConductivities(); //getInterfaceThermalConductivities();

    for(int i = 0; i < m_cells; i++)
    {
        double deltaX = m_radii(i + 1) - m_radii(i);

        if(i == 0)
        {
            T(i, i)     = + lambda[i] * m_radii(i + 1) / deltaX;
            T(i, i + 1) = - lambda[i] * m_radii(i + 1) / deltaX;
        }
        else if(i == m_cells - 1)
        {
            T(i, i)     = + lambda[i] * m_radii(i) / deltaX;
            T(i, i - 1) = - lambda[i] * m_radii(i) / deltaX;
        }
        else
        {
            T(i, i)     = + lambda[i] * m_radii(i) / deltaX + lambda[i] * m_radii(i + 1) / deltaX;
            T(i, i - 1) = - lambda[i] * m_radii(i) / deltaX;
            T(i, i + 1) = - lambda[i] * m_radii(i + 1) / deltaX;
        }

        m_heatSources(i) *= deltaX * (m_radii(i) + 0.5 * deltaX);
    }
   
    // out.getLogger()->debug("T matrix");
    // printMatrix(T, out, TraceLevel::DEBUG);

    // out.getLogger()->debug("Source");
    // printVector(m_heatSources, out, TraceLevel::DEBUG);

    // out.getLogger()->debug("Lambda");
    // printVector(lambda, out, TraceLevel::DEBUG);

    return std::make_tuple(T, m_heatSources);
}

std::tuple<MatrixXd, VectorXd> CylHeatCode::applyBoundaryConditions(MatrixXd &T, VectorXd &source)
{
    VectorXd boundaries = m_mesh.getHeatBoundaryConditions();
    VectorXd lambda     = m_mesh.getThermalConductivities();

    // Right boundary condition

    double deltaXR = m_radii(m_cells) - m_radii(m_cells - 1);

    double AR = boundaries(3);
    double BR = boundaries(4);
    double CR = boundaries(5);

    double denominatorR = (deltaXR / (2.0 * m_radii(m_cells) * lambda(m_cells - 1))) * AR + BR;
    double alphaR =  AR / denominatorR;
    double betaR  = -CR / denominatorR;

    T(m_cells - 1, m_cells - 1) = T(m_cells - 1, m_cells - 1) + alphaR;
    source(m_cells - 1) = source(m_cells - 1) - betaR;

    // double factor = 2.0 * lambda[m_cells - 1] * m_radii(m_cells) / deltaXR;
    // T(m_cells - 1, m_cells - 1) = T(m_cells - 1, m_cells - 1) + factor;
    // source(m_cells - 1) = source(m_cells - 1) + factor * CR;

    out.getLogger()->debug("T matrix2");
    printMatrix(T, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Source2");
    printVector(source, out, TraceLevel::DEBUG);

    return std::make_tuple(T, source);
}
