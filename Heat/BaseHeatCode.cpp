#include "BaseHeatCode.h"
#include "numeric_tools.h"

using namespace Eigen;
using namespace PrintFuncs;

VectorXd BaseHeatCode::getInterfaceCellSizes()
{
    VectorXd interCellSizes  = m_mesh.getCellSizes("m");
    VectorXd cellSizes       = m_mesh.getCellSizes("m");

    for(int i = 1; i < m_cells - 1; i++)
    {
        interCellSizes(i) = 0.5 * (cellSizes(i) + cellSizes(i - 1));  
    }

    return interCellSizes;
}


VectorXd BaseHeatCode::getInterfaceThermalConductivities()
{
    VectorXd materialLambda  = m_mesh.getThermalConductivities();
    VectorXd interfaceLambda = m_mesh.getThermalConductivities();
    VectorXd cellSizes       = m_mesh.getCellSizes("m");

    interfaceLambda(0) *= m_surfaces(0); 

    for(int i = 1; i < m_cells - 1; i++)
    {
        double f = cellSizes(i - 1) / (cellSizes(i) + cellSizes(i - 1));

        interfaceLambda(i) = 1.0 / ((1.0 - f) / materialLambda(i - 1) +
                             f / materialLambda(i));        

        interfaceLambda(i) *= m_surfaces(i);      
    }

    interfaceLambda(m_cells - 1) *= m_surfaces(m_cells - 1); 

    return interfaceLambda;
}

void BaseHeatCode::solveSystem(MatrixXd &T, VectorXd &source)
{
    VectorXd temperatures = VectorXd::Zero(source.size());
    temperatures = T.colPivHouseholderQr().solve(source);
    m_mesh.setTemperatures(temperatures);
}

MatrixXd BaseHeatCode::setupSystem()
{
    MatrixXd T = MatrixXd::Zero(m_cells, m_cells);

    m_temperatures     = m_mesh.getTemperatures("C");
    VectorXd lambda    = getInterfaceThermalConductivities();
    VectorXd cellSizes = getInterfaceCellSizes();

    for(int i = 0; i < m_cells; i++)
    {
        if(i == 0)
        {
            T(i, i)     = + lambda[i + 1] / cellSizes(i + 1);
            T(i, i + 1) = - lambda[i + 1] / cellSizes(i + 1);
        }
        else if(i == m_cells - 1)
        {
            T(i, i)     = + lambda[i] / cellSizes(i - 1);
            T(i, i - 1) = - lambda[i] / cellSizes(i - 1);
        }
        else
        {
            T(i, i)     = + lambda[i] / cellSizes(i) + 
                            lambda[i + 1] / cellSizes(i + 1);

            T(i, i - 1) = - lambda[i] / cellSizes(i);
            T(i, i + 1) = - lambda[i + 1] / cellSizes(i + 1);
        }
    }

    out.print(TraceLevel::DEBUG, "T matrix []:");
    printMatrix(T, out, TraceLevel::DEBUG);

    return T;
}

std::tuple<MatrixXd, VectorXd> BaseHeatCode::applyBoundaryConditions(MatrixXd &T)
{
    std::pair<VectorXd, VectorXd> boundariesPair = m_solverData.getHeatBoundaryConditions();
    VectorXd lambda     = getInterfaceThermalConductivities();
    m_heatSources       = m_mesh.getHeatSources();

    for(int i = 0; i < m_cells; i++)
    {
        m_heatSources(i) *= m_volumes(i);
    }

    VectorXd leftboundary  = boundariesPair.first;
    VectorXd rightboundary = boundariesPair.second;

    // Left boundary condition

    if(m_mesh.getGeometry() == GeomKind::SLAB)
	{
		double deltaXL = m_radii(1) - m_radii(0);

        double AL = leftboundary(0);
        double BL = leftboundary(1);
        double CL = leftboundary(2);

        double denominatorL = (deltaXL / (2.0 * lambda(0))) * AL + BL;
        double alphaL =  AL / denominatorL;
        double betaL  = -CL / denominatorL;

        T(0, 0) = T(0, 0) + alphaL;
        m_heatSources(0) = m_heatSources(0) - betaL;
	}

    // Right boundary condition

    double deltaXR = m_radii(m_cells) - m_radii(m_cells - 1);

    double AR = rightboundary(0);
    double BR = rightboundary(1);
    double CR = rightboundary(2);

    double denominatorR = (deltaXR / (2.0 * m_surfaces(m_cells) * lambda(m_cells - 1) / m_surfaces(m_cells - 1))) * AR + BR / m_surfaces(m_cells);
    double alphaR =  AR / denominatorR;
    double betaR  = -CR / denominatorR;

    T(m_cells - 1, m_cells - 1) = T(m_cells - 1, m_cells - 1) + alphaR;
    m_heatSources(m_cells - 1) = m_heatSources(m_cells - 1) - betaR;

    out.print(TraceLevel::DEBUG, "Thermal conductivities [W/(m*K)]:");
    printVector(lambda, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "T matrix []:");
    printMatrix(T, out, TraceLevel::DEBUG);

    out.print(TraceLevel::DEBUG, "Source [W]:");
    printVector(m_heatSources, out, TraceLevel::DEBUG);

    return std::make_tuple(T, m_heatSources);
}
