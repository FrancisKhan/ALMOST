#include "AbstractSolver.h"
#include "Problem.h"
#include "Output.h"

void Problem::calculate()
{
    if(m_solvers.size() == 1)
	{
		std::shared_ptr<AbstractSolver> solver = 
		AbstractSolver::getSolver(m_solvers[0], m_reactor, m_library);
	    solver->solve(); 
	}
	else if(m_solvers.size() == 2)
	{
		std::shared_ptr<AbstractSolver> firstSolver = 
		AbstractSolver::getSolver(m_solvers[0], m_reactor, m_library);
	    
		std::shared_ptr<AbstractSolver> secondSolver = 
		AbstractSolver::getSolver(m_solvers[1], m_reactor, m_library);

		for (unsigned iter = 0; iter < 1; iter++)
		{
			firstSolver->solve();
			Eigen::VectorXd vec1 = firstSolver->getMainParameter();

			std::cout << "vec1" << std::endl;
			for(auto i : vec1)
			{
				std::cout << i << std::endl;
			}

			//secondSolver->solve();
		}
	}
	else
	{
		out.getLogger()->critical("More than two coupled solvers are not possible at the moment");
	    exit(-1);
	}
}