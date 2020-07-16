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

	for (unsigned iter = 0; iter < 1; iter++)
	{
		firstSolver->solve();
		firstParam = firstSolver->getMainParameter();

		secondSolver->solve();
		secondParam = secondSolver->getMainParameter();

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
}
