#include "HeatCodeFactory.h"

std::shared_ptr<BaseHeatCode> HeatCodeFactory::setHeatCode(Reactor &reactor, Library &library, SolverData &solverData)
{
  return std::make_shared<BaseHeatCode>(reactor, library, solverData);
}