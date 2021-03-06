#include "SingleCalculation.h"

void SingleCalculation::solve()
{
    std::shared_ptr<AbstractSolver> solver = 
	AbstractSolver::getSolver(m_solver, m_reactor, m_library);
	solver->solve(); 
	solver->printResults(TraceLevel::CRITICAL);
}
