#include "DiffusionCodeFactory.h"
#include "ForwardDiffusionCode.h"

std::shared_ptr<BaseDiffusionCode> DiffusionCodeFactory::setDiffusionCode(Reactor &reactor, Library &library, SolverData &solverData)
{
  if (solverData.getDirection() == DirectionKind::FORWARD)
  {
    return std::make_shared<ForwardDiffusionCode>(reactor, library, solverData);
  }
  else if (solverData.getDirection() == DirectionKind::ADJOINT)
  {
    out.print(TraceLevel::CRITICAL, "Not ready for adjoint diffusion calculations!");
	  exit(-1);
    return std::shared_ptr<BaseDiffusionCode>(nullptr);
  }
  else
  {
	return std::shared_ptr<BaseDiffusionCode>(nullptr);
  }
}