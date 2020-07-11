#include "KineticsSolver.h"
#include "HeatSolver.h"
#include "Problem.h"
#include "Output.h"

void Problem::calculate()
{
    if(m_solvers.size() == 1)
	{
		if(m_solvers[0] == SolverKind::NEUTRONICS)
		{
			SpectrumSolver spectrum(m_reactor, m_library);
	    	spectrum.solve();
		}
		else if(m_solvers[0] == SolverKind::KINETICS)
		{
			KineticsSolver kinetics(m_reactor, m_library);
	    	kinetics.solve();
		}
		else if(m_solvers[0] == SolverKind::HEAT)
		{
			HeatSolver heat(m_reactor, m_library);
	    	heat.solve();
		}
	}
	else if(m_solvers.size() == 2)
	{
		
	}
	else
	{
		out.getLogger()->critical("More than two coupled solvers are not possible at the moment");
	    exit(-1);
	}

}