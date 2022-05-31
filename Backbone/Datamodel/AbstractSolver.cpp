#include "AbstractSolver.h"
#include "CoupledSolver.h"
#include "KineticsSolver.h"
#include "SpectrumSolver.h"
#include "HeatSolver.h"
#include "ADSSolver.h"
#include "DiffusionSolver.h"
#include "plot.h"

using namespace PlotFuncs;

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
  else if (solver.getKind() == SolverKind::ADS)
  {
    return std::make_shared<ADSSolver>(reactor, library, solver);
  }
  else
  {
	  return std::shared_ptr<AbstractSolver>(nullptr);
  }
}

void AbstractSolver::plots(const std::vector<PlotKind>& vec)
{
  if(plotsContain(vec, PlotKind::TEMPERATURE))
  {
      plotEigenVectorXd(m_reactor.getMesh().getMeshMiddlePoints(), 
                        m_reactor.getMesh().getTemperatures("C"), 
                        PlotKind::TEMPERATURE);
  }

  if(plotsContain(vec, PlotKind::POWERDENSITY))
  {
      plotEigenVectorXd(m_reactor.getMesh().getMeshMiddlePoints(), 
                        m_reactor.getMesh().getHeatSources(), 
                        PlotKind::POWERDENSITY);
  }

  if(plotsContain(vec, PlotKind::TOTALFLUX))
  {
      plotEigenMatrixXd(m_reactor.getMesh().getMeshMiddlePoints(), 
                        m_reactor.getMesh().getTotalFluxes(), 
                        PlotKind::TOTALFLUX);
  }

  if(plotsContain(vec, PlotKind::NEUTRONFLUX))
  {
      plot3DEigenTensor(m_reactor.getMesh().getMeshMiddlePoints(), 
                        m_reactor.getMesh().getNeutronFluxes(), 
                        PlotKind::NEUTRONFLUX, 5);
  }

  if(plotsContain(vec, PlotKind::ADJOINTFLUX))
  {
      plot3DEigenTensor(m_reactor.getMesh().getMeshMiddlePoints(),
                        m_reactor.getMesh().getAdjointFluxes(), 
                        PlotKind::ADJOINTFLUX, 5);
  }
}