#include "DoubleCalculation.h"
#include "AbstractSolver.h"

using namespace Eigen;

void DoubleCalculation::solve(int max_iter_number, double accuracy)
{
    std::shared_ptr<AbstractSolver> firstSolver = 
	AbstractSolver::getSolver(m_solvers[0], m_reactor, m_library);
	    
	std::shared_ptr<AbstractSolver> secondSolver = 
	AbstractSolver::getSolver(m_solvers[1], m_reactor, m_library);

	std::variant<double, VectorXd, MatrixXd> firstParam;
	std::variant<double, VectorXd, MatrixXd> secondParam;
	std::variant<double, VectorXd, MatrixXd> firstParamOld;
	std::variant<double, VectorXd, MatrixXd> secondParamOld;

	double firstDiff  = 1.0; 
	double secondDiff = 1.0; 
    
	int iter;
	for (iter = 0; iter < max_iter_number; iter++)
	{
		out.print(TraceLevel::INFO, "Iteration: {} \n", iter + 1);

		firstSolver->solve();
		firstSolver->printResults(TraceLevel::INFO);
		firstParam = firstSolver->getMainParameter();
		if (iter != 0) firstSolver->relaxResults(m_reactor.getRelaxationParameter());

		secondSolver->solve();
		secondSolver->printResults(TraceLevel::INFO);
		secondParam = secondSolver->getMainParameter();
		if (iter != 0) secondSolver->relaxResults(m_reactor.getRelaxationParameter());

		if (iter != 0) 
		{
			firstDiff  = getDifference(firstParam, firstParamOld);
			secondDiff = getDifference(secondParam, secondParamOld);
		}

		// exit condition 
		if ((firstDiff <= accuracy) && (secondDiff <= accuracy)) break;

		firstParamOld  = firstParam;
		secondParamOld = secondParam;
	}
 
	if(m_reactor.getLogLevel() == TraceLevel::CRITICAL)
	{
		out.print(TraceLevel::CRITICAL, "Number of iteration: {} \n", iter + 1);
		firstSolver->printResults(TraceLevel::CRITICAL);
		secondSolver->printResults(TraceLevel::CRITICAL);
	}
}
