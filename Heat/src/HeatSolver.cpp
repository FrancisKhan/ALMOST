#include "BaseHeatCode.h"
#include "HeatCodeFactory.h"
#include "HeatSolver.h"

#include <iostream>

void HeatSolver::solve(int max_iter_number, double accuracy)
{
   std::shared_ptr<BaseHeatCode> heatCode = HeatCodeFactory::setHeatCode(m_mesh, m_library);
    heatCode->setupMatrix();	
}