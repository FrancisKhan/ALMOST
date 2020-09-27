#include "AbstractSolver.h"
#include "CoupledSolver.h"
#include "KineticsSolver.h"
#include "SpectrumSolver.h"
#include "HeatSolver.h"
#include "DiffusionSolver.h"

std::shared_ptr<AbstractSolver> AbstractSolver::getSolver(SolverData &solver, 
                 Reactor &reactor, Library &library)
{
  if (solver.getKind() == SolverKind::COUPLED)
  {
    return std::make_shared<CoupledSolver>(reactor, library, solver);
  }
  else if (solver.getKind() == SolverKind::TRANSPORT)
  {
    return std::make_shared<SpectrumSolver>(reactor, library, solver);
  }
  else if (solver.getKind() == SolverKind::KINETICS)
  {
    return std::make_shared<KineticsSolver>(reactor, library, solver);
  }
  else if (solver.getKind() == SolverKind::HEAT)
  {
    return std::make_shared<HeatSolver>(reactor, library, solver);
  }
  else if (solver.getKind() == SolverKind::DIFFUSION)
  {
    return std::make_shared<DiffusionSolver>(reactor, library, solver);
  }
  else
  {
	  return std::shared_ptr<AbstractSolver>(nullptr);
  }
}