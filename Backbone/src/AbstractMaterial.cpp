#include "AbstractMaterial.h"
#include "Uranium.h"

#include <iostream>

std::shared_ptr<AbstractMaterial> AbstractMaterial::setMaterial(MaterialKind choice)
{
  if (choice == MaterialKind::U)
  {
      return std::shared_ptr<AbstractMaterial>(Uranium::instance());
  }
  else
  {
	return std::shared_ptr<AbstractMaterial>(nullptr);
  }
}