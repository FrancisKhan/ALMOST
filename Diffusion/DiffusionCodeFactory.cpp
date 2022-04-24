#include "DiffusionCodeFactory.h"
#include "ForwardDiffusionCode.h"
#include "AdjointDiffusionCode.h"

std::shared_ptr<BaseDiffusionCode> DiffusionCodeFactory::setDiffusionCode(Reactor &reactor, Library &library, SolverData &solverData)
{
  if (solverData.getDirection() == DirectionKind::FORWARD)
  {
    return std::make_shared<ForwardDiffusionCode>(reactor, library, solverData);
  }
  else if (solverData.getDirection() == DirectionKind::ADJOINT)
  {
    return std::make_shared<AdjointDiffusionCode>(reactor, library, solverData);
  }
  else
  {
	return std::shared_ptr<BaseDiffusionCode>(nullptr);
  }
}