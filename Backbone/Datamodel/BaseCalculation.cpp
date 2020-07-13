#include "BaseCalculation.h"

std::shared_ptr<SolverKind> BaseCalculation::setGeometry(std::vector<SolverKind> &solvers)
{
  if (choice == GeomKind::CYLINDER)
  {
    return std::make_shared<Cylinder>();
  }
  else if (choice == GeomKind::SPHERE)
  {
    return std::make_shared<Sphere>();
  }
  else if (choice == GeomKind::SLAB)
  {
    return std::make_shared<Slab>();
  }
  else
  {
	  return std::shared_ptr<AbstractGeometry>(nullptr);
  }
}