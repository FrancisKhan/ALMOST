#include "Library.h"

#include <iostream>

void Library::setMatProperties(std::vector<MaterialKind> &matProperties) 
{
    for(const auto & mat : matProperties)
    {
        AbstractMaterial *pMat = AbstractMaterial::setMaterial(mat);
        std::cout << "pMat: " << pMat->whatAmI() << std::endl;
    }
}
