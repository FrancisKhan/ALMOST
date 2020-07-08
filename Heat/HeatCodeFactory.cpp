#include "HeatCodeFactory.h"
#include "SlabHeatCode.h"
#include "CylHeatCode.h"
#include "SphHeatCode.h"

std::shared_ptr<BaseHeatCode> HeatCodeFactory::setHeatCode(Reactor &reactor, Library &library)
{
  if (reactor.getMesh().getGeometry() == GeomKind::CYLINDER)
  {
    return std::make_shared<CylHeatCode>(reactor, library);
  }
  else if (reactor.getMesh().getGeometry() == GeomKind::SPHERE)
  {
    return std::make_shared<SphHeatCode>(reactor, library);
  }
  else if (reactor.getMesh().getGeometry() == GeomKind::SLAB)
  {
    return std::make_shared<SlabHeatCode>(reactor, library);
  }
  else
  {
	return std::shared_ptr<BaseHeatCode>(nullptr);
  }
}