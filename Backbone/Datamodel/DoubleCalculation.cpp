#include "DoubleCalculation.h"
#include "AbstractSolver.h"

using namespace Eigen;

void DoubleCalculation::solve()
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

	int maxIterNumber = getCoupledSolver().getMaxIterNumber();
	double   accuracy = getCoupledSolver().getAccuracy();
    
	int iter;
	for (iter = 0; iter < maxIterNumber; iter++)
	{
		out.print(TraceLevel::INFO, "Coupled iteration: {} \n", iter + 1);

		firstSolver->solve();
		firstSolver->printResults(TraceLevel::INFO);
		firstParam = firstSolver->getMainParameter();
		if (iter != 0) firstSolver->relaxResults(getCoupledSolver().getRelaxationParameter());

		secondSolver->solve();
		secondSolver->printResults(TraceLevel::INFO);
		secondParam = secondSolver->getMainParameter();
		if (iter != 0) secondSolver->relaxResults(getCoupledSolver().getRelaxationParameter());

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
	
	if(iter + 1 > maxIterNumber)
	{
		out.print(TraceLevel::CRITICAL, "\nNumber of coupled iteration: {}", iter + 1);
		out.print(TraceLevel::CRITICAL, "The coupled calculation did not converge!");
		exit(-1);
	}

	if(m_reactor.getLogLevel() == TraceLevel::CRITICAL)
	{
		out.print(TraceLevel::CRITICAL, "\nNumber of coupled iteration: {} \n", iter + 1);
		firstSolver->printResults(TraceLevel::CRITICAL);
		secondSolver->printResults(TraceLevel::CRITICAL);
	}
}

SolverData DoubleCalculation::getCoupledSolver()
{
	std::vector<SolverData>::iterator it = find_if(m_solvers.begin(), m_solvers.end(), 
		[] (SolverData s) { return s.getKind() == SolverKind::COUPLED;});

  	if (it != m_solvers.end())
	  {
		return *it;
	  }
	else
	{
		out.print(TraceLevel::CRITICAL, "coupled solver is empty!");
	    exit(-1);
		SolverData solver(SolverKind::COUPLED);
		return solver;
	}
}
