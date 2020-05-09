#include "BaseHeatCode.h"

using namespace Eigen;

std::tuple<MatrixXd, VectorXd> BaseHeatCode::setupSystem()
{
    MatrixXd T = MatrixXd::Zero(m_cells, m_cells);

    VectorXd lambda = calcConductivities(m_temperatures);

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

    return std::make_tuple(T, m_heatSources);
}

std::tuple<MatrixXd, VectorXd> BaseHeatCode::applyBoundaryConditions(MatrixXd &T, VectorXd &source)
{
    VectorXd lambda = calcConductivities(m_temperatures);

    VectorXd boundaries = m_mesh.getHeatBoundaries();

    // Left boundary condition

    double deltaXL = m_radii(1) - m_radii(0);

    double AL = boundaries(0);
    double BL = boundaries(1);
    double CL = boundaries(2);

    double alphaL =  AL / ((deltaXL / (2.0 * lambda(0))) * AL - BL);
    double betaL  = -CL / ((deltaXL / (2.0 * lambda(0))) * AL - BL);

    T(0, 0) = T(0, 0) + alphaL / deltaXL;
    source(0) = source(0) - betaL / deltaXL;

    // Right boundary condition

    double deltaXR = m_radii(m_cells) - m_radii(m_cells - 1);

    double AR = boundaries(3);
    double BR = boundaries(4);
    double CR = boundaries(5);

    double alphaR =  AR / ((deltaXR / (2.0 * lambda(m_cells - 1))) * AR - BR);
    double betaR  = -CR / ((deltaXR / (2.0 * lambda(m_cells - 1))) * AR - BR);

    T(m_cells - 1, m_cells - 1) = T(m_cells - 1, m_cells - 1) + alphaR / deltaXR;
    source(m_cells - 1) = source(m_cells - 1) - betaR / deltaXR;

    out.getLogger()->debug("T matrix2");
    printMatrix(T, out, TraceLevel::DEBUG);

    out.getLogger()->debug("Source2");
    printVector(source, out, TraceLevel::DEBUG);

    return std::make_tuple(T, source);
}

void BaseHeatCode::solveSystem(MatrixXd &T, VectorXd &source)
{
    Eigen::ColPivHouseholderQR<Eigen::MatrixXd> CPHQR;
	CPHQR.compute(T);
    VectorXd result = CPHQR.solve(source);

    out.getLogger()->debug("Temperature:");
    printVector(result, out, TraceLevel::DEBUG);
}

VectorXd BaseHeatCode::calcConductivities(VectorXd &t)
{
    std::vector< std::shared_ptr<AbstractMaterial> > matProperties = m_library.getMatProperties();

    VectorXd lambda = VectorXd::Zero(m_cells); // thermal conductivities
    
    for(int i = 0; i < m_cells; i++)
    {
        double t_k = t(i) + 273.15; // from celsius to kelvin
        lambda[i] = matProperties[i]->thermalConductivity(t_k);
    }

    return lambda;
}

std::tuple<VectorXd, VectorXd, VectorXd> BaseHeatCode::calcInterTemperatures()
{
    VectorXd t_i = m_mesh.getTemperatures(); // initial temperatures
    std::vector< std::shared_ptr<AbstractMaterial> > matProperties = m_library.getMatProperties();

    VectorXd lambda = VectorXd::Zero(m_cells); // thermal conductivities
    
    for(int i = 0; i < m_cells; i++)
    {
        double t_k = t_i(i) + 273.15; // from celsius to kelvin
        lambda[i] = matProperties[i]->thermalConductivity(t_k);
    }

    // for(size_t i = 0; i < m_cells; i++)
    // {
    //     std::cout << t_i[i] << " " << lambda[i] << std::endl;
    // }

    VectorXd t_half_plus  = VectorXd::Zero(m_cells - 1);
    VectorXd t_half_minus = VectorXd::Zero(m_cells - 1);

    for(int i = 1; i < m_cells - 2; i++)
    {
        t_half_minus[i] = (t_i[i] * lambda[i] + t_i[i - 1] * lambda[i - 1]) /
        (lambda[i] + lambda[i - 1]);

        t_half_plus[i] = (t_i[i] * lambda[i] + t_i[i + 1] * lambda[i + 1]) /
        (lambda[i] + lambda[i + 1]);
    }

    return std::make_tuple(lambda, t_half_plus, t_half_minus);
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