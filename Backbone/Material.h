#ifndef MATERIAL_H
#define MATERIAL_H

#include "PolynomialFunction.h"

#include <memory>
#include <vector>
#include <string>

class Material
{
public:
	Material(const std::string& name) : 
	m_name(name){}
	std::string getName() {return m_name;}
	void setTemperature(double T) {m_temperature = T;}
	double getTemperature() {return m_temperature;}
	void setThermalConductivityLaw(std::vector<std::string> &vec);
	double getThermalConductivity();
	void setHeatSource(double q) {m_heatSource = q;}
	double getHeatSource() {return m_heatSource;}

private:
	const std::string m_name;
	double m_temperature; // Celsius
	double m_heatSource; // Watt/m3

	std::shared_ptr<PolynomialFunction> m_thermalConductivityLaw;

};

#endif