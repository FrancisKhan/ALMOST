#ifndef NUCLIDE_H
#define NUCLIDE_H

#include "PolynomialFunction.h"
#include "numeric_tools.h"
#include "XSKind.h"

#include <memory>
#include <vector>
#include <string>

typedef std::vector< std::pair<double, std::vector<double> > > XSType;

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

    void setXS(XSKind kind, XSType &xs);
    XSType getXS(XSKind kind);
    std::vector<double> getXS(XSKind kind, unsigned tempIndex);

    void printDebugData();

private:
    void setEnergyGroupsNumber(unsigned n) {m_energyGroupsNumber = n;}
    unsigned getEnergyGroupsNumber() {return m_energyGroupsNumber;}
    XSType populateXS(XSType &xs);

    std::string m_name;
    double m_awr;
    std::vector<double> m_temperatures;
    unsigned m_energyGroupsNumber;

    XSType m_totXS;
    XSType m_elasticXS;
    XSType m_inelasticXS;
    XSType m_n2nXS;
    XSType m_n3nXS;
    XSType m_nnpXS;
    XSType m_ngXS;
    XSType m_npXS;
    XSType m_ndXS;
    XSType m_ntXS;
    XSType m_naXS;
    XSType m_scattXS;
};

#endif