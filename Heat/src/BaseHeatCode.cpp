#include "BaseHeatCode.h"

using namespace Eigen;

std::tuple<MatrixXd, VectorXd> BaseHeatCode::setupSystem()
{
    MatrixXd T = MatrixXd::Zero(m_cells, m_cells);

    m_temperatures  = m_mesh.getTemperatures("C");
    m_heatSources   = m_mesh.getHeatSources();
    VectorXd lambda = m_mesh.getThermalConductivities();

    for(int i = 0; i < m_cells; i++)
    {
        double deltaX = m_radii(i + 1) - m_radii(i);

        if ((i == 0) || (i ==  m_cells - 1))
        {
            T(i, i) = lambda[i] / pow(deltaX, 2);
        }
        else
        {
            T(i, i) = 2.0 * lambda[i] / pow(deltaX, 2);
        }

        if (i != 0)
        {
            T(i, i - 1) = -lambda[i] / pow(deltaX, 2);
            T(i - 1, i) = T(i, i - 1);
        }
    }
   
    out.getLogger()->debug("T matrix");
    printMatrix(T, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Source");
    printVector(m_heatSources, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Lambda");
    printVector(lambda, out, TraceLevel::DEBUG);

    return std::make_tuple(T, m_heatSources);
}

std::tuple<MatrixXd, VectorXd> BaseHeatCode::applyBoundaryConditions(MatrixXd &T, VectorXd &source)
{
    VectorXd lambda = m_mesh.getThermalConductivities();

    VectorXd boundaries = m_mesh.getHeatBoundaryConditions();

    // Left boundary condition

    double deltaXL = m_radii(1) - m_radii(0);

    double AL = boundaries(0);
    double BL = boundaries(1);
    double CL = boundaries(2);

    double denominatorL = (deltaXL / (2.0 * lambda(0))) * AL + BL;
    double alphaL =  AL / denominatorL;
    double betaL  = -CL / denominatorL;

    T(0, 0) = T(0, 0) + alphaL / deltaXL;
    source(0) = source(0) - betaL / deltaXL;

    // Right boundary condition

    double deltaXR = m_radii(m_cells) - m_radii(m_cells - 1);

    double AR = boundaries(3);
    double BR = boundaries(4);
    double CR = boundaries(5);

    double denominatorR = (deltaXR / (2.0 * lambda(m_cells - 1))) * AR + BR;
    double alphaR =  AR / denominatorR;
    double betaR  = -CR / denominatorR;

    T(m_cells - 1, m_cells - 1) = T(m_cells - 1, m_cells - 1) + alphaR / deltaXR;
    source(m_cells - 1) = source(m_cells - 1) - betaR / deltaXR;

    out.getLogger()->debug("T matrix2");
    printMatrix(T, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Source2");
    printVector(source, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Lambda2");
    printVector(lambda, out, TraceLevel::DEBUG);

    return std::make_tuple(T, source);
}

void BaseHeatCode::solveSystem(MatrixXd &T, VectorXd &source)
{
    m_temperatures = tridiag_solver(T.diagonal(-1), T.diagonal(), 
                                     T.diagonal(+1), source);

    m_mesh.setTemperatures(m_temperatures);

    out.getLogger()->debug("Mesh middle points:");
    printVector(m_mesh.getMeshMiddlePoints(), out, TraceLevel::DEBUG);

    out.getLogger()->debug("Temperature:");
    printVector(m_temperatures, out, TraceLevel::DEBUG);
}

std::vector<double> BaseHeatCode::exactSolution()
{	
	unsigned Nx = 20;
    std::vector<double> x(Nx, 0.0);
    double L = 1.0;

    std::vector<double> a = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0,  
                             1.0, 1.0, 1.0, 1.0, 1.0, 8.0,
                             8.0, 8.0, 8.0, 8.0, 0.1, 0.1,
                             0.1, 0.1, 0.1};
    
    double u_L = 1.0;
    double u_R = 0.0;

    int count = 0;
    std::generate(x.begin(), x.end(), 
    [&](){return (L / Nx) * count++;});

    std::cout << "x" << std::endl;
    std::for_each(x.begin(), x.end(), [](double i){std::cout << i << std::endl;});
    
    std::vector <double> g(Nx+1, 0.0);
    double dx = x[1] - x[0];
    
    g[0] = 0.5 * dx / a[0];

    for(unsigned i = 1; i < Nx; i++)
        g[i] = g[i-1] + dx/a[i];

    g[Nx] = g[Nx-1] + 0.5*dx/a[Nx];

    count = 0;
    std::vector<double> v(g.size());
    std::generate(v.begin(), v.end(), [&](){return u_L + (u_R - u_L)*g[count++]/g[Nx];});

    std::cout << "v" << std::endl;
    std::for_each(v.begin(), v.end(), [](double i){std::cout << i << std::endl;});

    return v;
}