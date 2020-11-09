#include "DiffusionCodeFactory.h"

std::shared_ptr<BaseDiffusionCode> DiffusionCodeFactory::setDiffusionCode(Reactor &reactor, Library &library, SolverData &solverData)
{
  return std::make_shared<BaseDiffusionCode>(reactor, library, solverData);
}