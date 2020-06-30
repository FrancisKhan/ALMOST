#include "HeatCodeFactory.h"
#include "SlabHeatCode.h"
#include "CylHeatCode.h"
#include "SphHeatCode.h"

std::shared_ptr<BaseHeatCode> HeatCodeFactory::setHeatCode(Mesh &mesh, Library &library)
{
  if (mesh.getGeometry() == GeomKind::CYLINDER)
  {
    return std::make_shared<CylHeatCode>(mesh, library);
  }
  else if (mesh.getGeometry() == GeomKind::SPHERE)
  {
    return std::make_shared<SphHeatCode>(mesh, library);
  }
  else if (mesh.getGeometry() == GeomKind::SLAB)
  {
    return std::make_shared<SlabHeatCode>(mesh, library);
  }
  else
  {
	return std::shared_ptr<BaseHeatCode>(nullptr);
  }
}