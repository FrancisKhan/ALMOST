#ifndef NUCLIDE_H
#define NUCLIDE_H

#include "PolynomialFunction.h"
#include "numeric_tools.h"
#include "XSKind.h"

#include <memory>
#include <vector>
#include <string>

typedef std::vector< std::pair<double, std::vector<double> > > XSSetType;

class Nuclide
{
public:
	Nuclide() {}
    Nuclide(std::string name) {m_name = name;}

    void setName(std::string name) {m_name = name;}
    std::string getName() {return m_name;}
    void setAWR(double awr) {m_awr = awr;}
    double getAWR() {return m_awr;}
    void setTemperatures(std::vector<double> &temps) {m_temperatures = temps;}
    std::vector<double> getTemperatures() {return m_temperatures;}
    double getTemperature(unsigned i) {return m_temperatures.at(i);}

    void setXS(XSKind xsKind, XSSetType &xs);
    XSSetType getXS(XSKind xsKind);
    std::vector<double> getXS(XSKind xsKind, unsigned tempIndex);
    double getXSTemp(XSKind xsKind, unsigned tempIndex);

    void printDebugData();
    void printXS(XSKind kind);

private:
    void setEnergyGroupsNumber(unsigned n) {m_energyGroupsNumber = n;}
    unsigned getEnergyGroupsNumber() {return m_energyGroupsNumber;}
    XSSetType populateXS(XSSetType &xs);

    std::string m_name;
    double m_awr;
    std::vector<double> m_temperatures;
    unsigned m_energyGroupsNumber;

    XSSetType m_totXS;
    XSSetType m_elasticXS;
    XSSetType m_inelasticXS;
    XSSetType m_n2nXS;
    XSSetType m_n3nXS;
    XSSetType m_nnpXS;
    XSSetType m_ngXS;
    XSSetType m_npXS;
    XSSetType m_ndXS;
    XSSetType m_ntXS;
    XSSetType m_naXS;
    XSSetType m_scattXS;
};

#endif