#include "Library.h"

#include <iostream>

void Library::setMatProperties(std::vector<MaterialKind> &matProperties) 
{
    for(const auto & mat : matProperties)
    {
        std::shared_ptr<AbstractMaterial> pMat = AbstractMaterial::setMaterial(mat);
        m_matProperties.push_back(pMat);
    }
}
