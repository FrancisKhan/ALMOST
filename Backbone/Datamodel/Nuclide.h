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
    void setTotalXS(XSType &xs) {m_totXS = xs;}
    XSType getTotalXS() {return m_totXS;}

    void printDebugData();

private:
    std::string m_name;
    double m_awr;
    std::vector<double> m_temperatures;

    XSType m_totXS;
};

#endif