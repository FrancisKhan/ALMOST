#include "ADSCalculation.h"
#include "AbstractSolver.h"

using namespace Eigen;

void ADSCalculation::solve()
{

    std::shared_ptr<AbstractSolver> firstSolver;

    if((m_solvers[0].getKind() == SolverKind::DIFFUSION) && 
       (m_solvers[0].getDirection() == DirectionKind::FORWARD) && 
       (m_solvers[0].getEigenmodes() == EigenmodesKind::ALL))
    {
        firstSolver = AbstractSolver::getSolver(m_solvers[0], m_reactor, m_library);
    }
    else
    {
        out.print(TraceLevel::CRITICAL, "\nFor ADS calculations the first solver has to be");
		out.print(TraceLevel::CRITICAL, "a forward all eigenmodes diffusion one");
		exit(-1);
    }

    std::shared_ptr<AbstractSolver> secondSolver;

    if((m_solvers[1].getKind() == SolverKind::DIFFUSION) && 
       (m_solvers[1].getDirection() == DirectionKind::ADJOINT))
    {
        secondSolver = AbstractSolver::getSolver(m_solvers[1], m_reactor, m_library);
    }
    else
    {
        out.print(TraceLevel::CRITICAL, "\nFor ADS calculations the second solver has to be");
		out.print(TraceLevel::CRITICAL, "an adjointdiffusion one");
		exit(-1);
    }

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

SolverData ADSCalculation::getCoupledSolver()
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
