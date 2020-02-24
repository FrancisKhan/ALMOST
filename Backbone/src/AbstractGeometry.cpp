#include "AbstractGeometry.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Slab.h"

AbstractGeometry *AbstractGeometry::setGeometry(GeomKind choice)
{
  if (choice == GeomKind::CYLINDER)
  {
    return new Cylinder;
  }
  else if (choice == GeomKind::SPHERE)
  {
    return new Sphere;
  }
  else if (choice == GeomKind::SLAB)
  {
    return new Slab;
  }
  else
  {
	  return nullptr;
  }
}