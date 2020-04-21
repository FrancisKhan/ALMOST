#include "SpectrumCodeFactory.h"
#include "CylSpectrumCode.h"
#include "SphSpectrumCode.h"
#include "SlabSpectrumCode.h"

std::shared_ptr<BaseSpectrumCode> SpectrumCodeFactory::setSpectrumCode(Mesh &mesh, Library &library)
{
  if (mesh.getGeometry() == GeomKind::CYLINDER)
  {
    return std::make_shared<CylSpectrumCode>(mesh, library);
  }
  else if (mesh.getGeometry() == GeomKind::SPHERE)
  {
    return std::make_shared<SphSpectrumCode>(mesh, library);
  }
  else if (mesh.getGeometry() == GeomKind::SLAB)
  {
    return std::make_shared<SlabSpectrumCode>(mesh, library);
  }
  else
  {
	return std::shared_ptr<BaseSpectrumCode>(nullptr);
  }
}