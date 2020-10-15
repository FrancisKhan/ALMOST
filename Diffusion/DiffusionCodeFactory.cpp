#include "DiffusionCodeFactory.h"
#include "SlabDiffusionCode.h"
#include "CylDiffusionCode.h"
#include "SphDiffusionCode.h"

std::shared_ptr<BaseDiffusionCode> DiffusionCodeFactory::setDiffusionCode(Reactor &reactor, Library &library, SolverData &solverData)
{
  if (reactor.getMesh().getGeometry() == GeomKind::CYLINDER)
  {
    return std::make_shared<CylDiffusionCode>(reactor, library, solverData);
  }
  else if (reactor.getMesh().getGeometry() == GeomKind::SPHERE)
  {
    return std::make_shared<SphDiffusionCode>(reactor, library, solverData);
  }
  else if (reactor.getMesh().getGeometry() == GeomKind::SLAB)
  {
    return std::make_shared<SlabDiffusionCode>(reactor, library, solverData);
  }
  else
  {
	return std::shared_ptr<BaseDiffusionCode>(nullptr);
  }
}