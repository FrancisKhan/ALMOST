#ifndef NUCLIDE_H
#define NUCLIDE_H

#include "PolynomialFunction.h"
#include "numeric_tools.h"
#include "CrossSectionSet.h"

#include <memory>
#include <vector>
#include <string>

class Nuclide
{
public:
	Nuclide() : m_isResonant(false) {}
    Nuclide(std::string name) : m_isResonant(false) {m_name = name;}

    void setName(std::string name) {m_name = name;}
    std::string getName() {return m_name;}
    void setAWR(double awr) {m_awr = awr;}
    double getAWR() {return m_awr;}
    void setIsResonant(bool value) {m_isResonant = value;}
    bool isResonant() {return m_isResonant;}
    void setTemperatures(std::vector<double> &temps) {m_temperatures = temps;}
    std::vector<double> getTemperatures() {return m_temperatures;}
    double getTemperature(unsigned i) {return m_temperatures.at(i);}

    void setXS(XSKind xsKind, CrossSectionSet &xsSet);
    CrossSectionSet getXSSet(XSKind xsKind);

    void printDebugData();
    void printXSs(XSKind kind);

private:
    void setEnergyGroupsNumber(unsigned n) {m_energyGroupsNumber = n;}
    unsigned getEnergyGroupsNumber() {return m_energyGroupsNumber;}
    CrossSectionSet populateXS(XSKind xsKind, CrossSectionSet &xsSet);

    std::string m_name;
    double m_awr;
    std::vector<double> m_temperatures;
    unsigned m_energyGroupsNumber;
    bool m_isResonant;

    CrossSectionSet m_totXS;
    CrossSectionSet m_elasticXS;
    CrossSectionSet m_inelasticXS;
    CrossSectionSet m_n2nXS;
    CrossSectionSet m_n3nXS;
    CrossSectionSet m_nnpXS;
    CrossSectionSet m_ngXS;
    CrossSectionSet m_npXS;
    CrossSectionSet m_ndXS;
    CrossSectionSet m_ntXS;
    CrossSectionSet m_naXS;
    CrossSectionSet m_scattXS;
};

#endif