#include "SingleCalculation.h"

void SingleCalculation::solve(int max_iter_number, double accuracy)
{
    std::shared_ptr<AbstractSolver> solver = 
	AbstractSolver::getSolver(m_solver, m_reactor, m_library);
	solver->solve(); 
}
