#include "PolynomialFunction.h"
#include "Material.h"

#include <algorithm>
#include <iostream>

using namespace Eigen;

void Material::setXSReferenceTemperature(std::string &str)
{
    m_xs_reference_temperature = std::stod(str);
}

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

void Material::setTotalXSTempDependenceLaws(std::vector<std::string> &strVec)
{
    std::vector<double> dVec(strVec.size(), 0.0);
    std::transform(strVec.begin(), strVec.end(), dVec.begin(), 
    [](std::string &i){return std::stod(i);});

    m_totalXSTempDependenceLaws.push_back(std::make_shared<PolynomialFunction>(dVec));
}

void Material::setFissionXSTempDependenceLaws(std::vector<std::string> &strVec)
{
    std::vector<double> dVec(strVec.size(), 0.0);
    std::transform(strVec.begin(), strVec.end(), dVec.begin(), 
    [](std::string &i){return std::stod(i);});

    m_fissionXSTempDependenceLaws.push_back(std::make_shared<PolynomialFunction>(dVec));
}

void Material::setDiffCoeffTempDependenceLaws(std::vector<std::string> &strVec)
{
    std::vector<double> dVec(strVec.size(), 0.0);
    std::transform(strVec.begin(), strVec.end(), dVec.begin(), 
    [](std::string &i){return std::stod(i);});

    m_diffCoeffTempDependenceLaws.push_back(std::make_shared<PolynomialFunction>(dVec));
}

void Material::setScattMatrixTempDependenceLaws(std::vector<std::string> &strVec)
{
    std::vector<double> dVec(strVec.size(), 0.0);
    std::transform(strVec.begin(), strVec.end(), dVec.begin(), 
    [](std::string &i){return std::stod(i);});

    m_scattMatrixTempDependenceLaws.push_back(std::make_shared<PolynomialFunction>(dVec));
}

void Material::setNiTempDependenceLaws(std::vector<std::string> &strVec)
{
    std::vector<double> dVec(strVec.size(), 0.0);
    std::transform(strVec.begin(), strVec.end(), dVec.begin(), 
    [](std::string &i){return std::stod(i);});

    m_niTempDependenceLaws.push_back(std::make_shared<PolynomialFunction>(dVec));
}

void Material::setChiTempDependenceLaws(std::vector<std::string> &strVec)
{
    std::vector<double> dVec(strVec.size(), 0.0);
    std::transform(strVec.begin(), strVec.end(), dVec.begin(), 
    [](std::string &i){return std::stod(i);});

    m_chiTempDependenceLaws.push_back(std::make_shared<PolynomialFunction>(dVec));
}

VectorXd Material::getNi()
{
    VectorXd results = VectorXd::Zero(m_energies);

    if(m_niTempDependenceLaws.size() > 0)
    {
        for(unsigned i = 0; i < m_energies; i++)
            results(i) = m_niTempDependenceLaws[i]->calc(m_temperature, m_xs_reference_temperature);
    }

    return results;
}

VectorXd Material::getChi()
{
    VectorXd results = VectorXd::Zero(m_energies);

    if(m_chiTempDependenceLaws.size() > 0)
    {
        for(unsigned i = 0; i < m_energies; i++)
            results(i) = m_chiTempDependenceLaws[i]->calc(m_temperature, m_xs_reference_temperature);
    }

    return results;
}

VectorXd Material::getTotalXS()
{
    VectorXd results = VectorXd::Zero(m_energies);

    for(unsigned i = 0; i < m_energies; i++)
        results(i) = m_totalXSTempDependenceLaws[i]->calc(m_temperature, m_xs_reference_temperature);
  
    return results;
}

VectorXd Material::getFissionXS()
{
    VectorXd results = VectorXd::Zero(m_energies);
   
    for(unsigned i = 0; i < m_energies; i++)
        results(i) = m_fissionXSTempDependenceLaws[i]->calc(m_temperature, m_xs_reference_temperature);

    return results;
}

VectorXd Material::getDiffusionConstants()
{
    VectorXd results = VectorXd::Zero(m_energies);;

    for(unsigned i = 0; i < m_energies; i++)
        results(i) = m_diffCoeffTempDependenceLaws[i]->calc(m_temperature, m_xs_reference_temperature);

    return results;
}

MatrixXd Material::getScattMatrix()
{
    MatrixXd results = MatrixXd::Zero(m_energies, m_energies);

    for(size_t i = 0; i < m_energies; i++)
        for(size_t j = 0; j < m_energies; j++)
            results(i, j) = m_scattMatrixTempDependenceLaws[j + i * m_energies]->calc(m_temperature, m_xs_reference_temperature);

    return results;
}
