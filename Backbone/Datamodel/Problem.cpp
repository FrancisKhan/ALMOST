#include "Problem.h"
#include "BaseCalculation.h"

using namespace Eigen;

void Problem::solve(int max_iter_number, double accuracy)
{
    std::shared_ptr<BaseCalculation> pm_calc = BaseCalculation::setCalculation(m_reactor, m_library, m_solvers);
    pm_calc->solve();
}