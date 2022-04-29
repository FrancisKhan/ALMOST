#include "ADSCodeFactory.h"

std::shared_ptr<BaseADSCode> ADSCodeFactory::setADSCode(Reactor &reactor, Library &library, SolverData &solverData)
{
  return std::make_shared<BaseADSCode>(reactor, library, solverData);
}