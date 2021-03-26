#ifndef CROSSSECTION_H
#define CROSSSECTION_H

#include <vector>

typedef std::tuple<double, double, std::vector<double> > XSType;

class CrossSection
{
public:
	CrossSection(double temperature, double backgroundXS, std::vector<double> &values) :
    m_temperature(temperature), m_backgroundXS(backgroundXS), m_values(values) {}

    void setTemperature(double t) {m_temperature = t;}
    double getTemperature() {return m_temperature;}
    void setBackgroundXS(double b) {m_backgroundXS = b;}
    double getBackgroundXS() {return m_backgroundXS;}
    void setValues(std::vector<double> &v) {m_values = v;}
    std::vector<double> getValues() {return m_values;}

private:
    double m_temperature;
    double m_backgroundXS;
    std::vector<double> m_values;

};

#endif