#include "BaseHeatCode.h"
#include "HeatCodeFactory.h"
#include "HeatSolver.h"

#include <iostream>

using namespace Eigen;

void HeatSolver::solve(int max_iter_number, double accuracy)
{
    std::shared_ptr<BaseHeatCode> heatCode = HeatCodeFactory::setHeatCode(m_mesh, m_library);

    for(unsigned i = 0; i < 5; i++)
    {
        auto [T, source]   = heatCode->setupSystem();	
        auto [Tb, sourceb] = heatCode->applyBoundaryConditions(T, source);
        heatCode->solveSystem(Tb, sourceb);
    }
}