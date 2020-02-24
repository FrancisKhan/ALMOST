#include "SpectrumCodeFactory.h"
#include "CylSpectrumCode.h"
#include "SphSpectrumCode.h"
#include "SlabSpectrumCode.h"

BaseSpectrumCode *SpectrumCodeFactory::setSpectrumCode(Mesh &mesh, Library &library)
{
  if (mesh.getGeometry() == GeomKind::CYLINDER)
  {
    return new CylSpectrumCode(mesh, library);
  }
  else if (mesh.getGeometry() == GeomKind::SPHERE)
  {
    return new SphSpectrumCode(mesh, library);
  }
  else if (mesh.getGeometry() == GeomKind::SLAB)
  {
    return new SlabSpectrumCode(mesh, library);
  }
  else
  {
	return nullptr;
  }
}