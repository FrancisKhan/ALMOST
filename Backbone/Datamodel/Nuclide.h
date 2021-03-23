#ifndef NUCLIDE_H
#define NUCLIDE_H

#include "PolynomialFunction.h"
#include "numeric_tools.h"

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

    void setTotalXS(XSType &xs);
    XSType getTotalXS() {return m_totXS;}
    void setElasticXS(XSType &xs) {m_elasticXS = xs;}
    XSType getElasticXS() {return m_elasticXS;}
    void setInelasticXS(XSType &xs);
    XSType getInelasticXS() {return m_inelasticXS;}
    void setN2nXS(XSType &xs);
    XSType getN2nXS() {return m_n2nXS;}
    void setN3nXS(XSType &xs);
    XSType getN3nXS() {return m_n3nXS;}
    void setNnpXS(XSType &xs);
    XSType getNnpXS() {return m_nnpXS;}
    void setNgXS(XSType &xs);
    XSType getNgXS() {return m_ngXS;}
    void setNpXS(XSType &xs);
    XSType getNpXS() {return m_npXS;}
    void setNdXS(XSType &xs);
    XSType getNdXS() {return m_ndXS;}
    void setNtXS(XSType &xs);
    XSType getNtXS() {return m_ntXS;}
    void setNaXS(XSType &xs);
    XSType getNaXS() {return m_naXS;}
    void setScattXS(XSType &xs);
    XSType getScattXS() {return m_scattXS;}

    void printDebugData();

private:
    void setEnergyGroupsNumber(unsigned n) {m_energyGroupsNumber = n;}
    unsigned getEnergyGroupsNumber() {return m_energyGroupsNumber;}
    XSType setXS(XSType &xs);

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