#include "AbstractMaterial.h"
#include "Uranium.h"

#include <iostream>

AbstractMaterial *AbstractMaterial::setMaterial(MaterialKind choice)
{
  if (choice == MaterialKind::U)
  {
      return Uranium::instance();
  }
  else
  {
	return nullptr;
  }
}