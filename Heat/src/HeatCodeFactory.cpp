#include "HeatCodeFactory.h"
#include "SlabHeatCode.h"

BaseHeatCode *HeatCodeFactory::setHeatCode(Mesh &mesh, Library &library)
{
  if (mesh.getGeometry() == GeomKind::CYLINDER)
  {
    std::cout << "No cylindrical heat transfer solver implemented yet!" << std::endl;
    return new SlabHeatCode(mesh, library);
  }
  else if (mesh.getGeometry() == GeomKind::SPHERE)
  {
    std::cout << "No spherical heat transfer solver implemented yet!" << std::endl;
    return new SlabHeatCode(mesh, library);
  }
  else if (mesh.getGeometry() == GeomKind::SLAB)
  {
    return new SlabHeatCode(mesh, library);
  }
  else
  {
	return nullptr;
  }
}