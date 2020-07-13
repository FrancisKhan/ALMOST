#include "AbstractSolver.h"
#include "KineticsSolver.h"
#include "SpectrumSolver.h"
#include "HeatSolver.h"

std::shared_ptr<AbstractSolver> AbstractSolver::getSolver(SolverKind solver, 
                            Reactor &reactor, Library &library)
{
  if (solver == SolverKind::NEUTRONICS)
  {
    return std::make_shared<SpectrumSolver>(reactor, library);
  }
  else if (solver == SolverKind::KINETICS)
  {
    return std::make_shared<KineticsSolver>(reactor, library);
  }
  else if (solver == SolverKind::HEAT)
  {
    return std::make_shared<HeatSolver>(reactor, library);
  }
  else
  {
	  return std::shared_ptr<AbstractSolver>(nullptr);
  }
}