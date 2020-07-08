#include "SpectrumCodeFactory.h"
#include "CylSpectrumCode.h"
#include "SphSpectrumCode.h"
#include "SlabSpectrumCode.h"

std::shared_ptr<BaseSpectrumCode> SpectrumCodeFactory::setSpectrumCode(Reactor &reactor, Library &library)
{
  if (reactor.getMesh().getGeometry() == GeomKind::CYLINDER)
  {
    return std::make_shared<CylSpectrumCode>(reactor, library);
  }
  else if (reactor.getMesh().getGeometry() == GeomKind::SPHERE)
  {
    return std::make_shared<SphSpectrumCode>(reactor, library);
  }
  else if (reactor.getMesh().getGeometry() == GeomKind::SLAB)
  {
    return std::make_shared<SlabSpectrumCode>(reactor, library);
  }
  else
  {
	return std::shared_ptr<BaseSpectrumCode>(nullptr);
  }
}