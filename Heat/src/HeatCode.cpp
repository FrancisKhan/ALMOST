#include "HeatCode.h"

std::vector<double> HeatCode::exactSolution()
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