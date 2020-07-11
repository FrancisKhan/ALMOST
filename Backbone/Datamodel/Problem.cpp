#include "KineticsSolver.h"
#include "HeatSolver.h"
#include "Problem.h"
#include "Output.h"

void Problem::calculate()
{
    if(m_calculations.size() == 1)
	{
		if(m_calculations[0] == CalculationKind::NEUTRONICS)
		{
			SpectrumSolver spectrum(m_reactor, m_library);
	    	spectrum.solve();
		}
		else if(m_calculations[0] == CalculationKind::KINETICS)
		{
			KineticsSolver kinetics(m_reactor, m_library);
	    	kinetics.solve();
		}
		else if(m_calculations[0] == CalculationKind::HEAT)
		{
			HeatSolver heat(m_reactor, m_library);
	    	heat.solve();
		}
	}
	else if(m_calculations.size() == 2)
	{
		
	}
	else
	{
		out.getLogger()->critical("More than two coupled solvers are not possible at the moment");
	    exit(-1);
	}

}