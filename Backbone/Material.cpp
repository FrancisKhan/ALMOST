#include "PolynomialFunction.h"
#include "Material.h"

#include <algorithm>
#include <iostream>


void Material::setThermalConductivityLaw(std::vector<std::string> &strVec)
{
    std::vector<double> dVec(strVec.size(), 0.0);
    std::transform(strVec.begin(), strVec.end(), dVec.begin(), 
    [](std::string &i){return std::stod(i);});

    m_thermalConductivityLaw = std::make_shared<PolynomialFunction>(dVec);
}

double Material::getThermalConductivity()
{
    return m_thermalConductivityLaw->calc(m_temperature);
}