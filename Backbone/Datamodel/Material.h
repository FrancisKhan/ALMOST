#ifndef MATERIAL_H
#define MATERIAL_H

#include "PolynomialFunction.h"
#include "numeric_tools.h"

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

	// Neutron cross section
	void setNi(const Eigen::VectorXd &ni) {m_ni = ni;}
	void setChi(const Eigen::VectorXd &chi) {m_chi = chi;}
	void setFissionXS(const Eigen::VectorXd &fission) {m_fission = fission;}
	void setTotalXS(const Eigen::VectorXd &total) {m_total = total;}
	void setScattMatrix(const Eigen::MatrixXd &scattMatrix) {m_scattMatrix = scattMatrix;}
	void setScattMatrix(const Numerics::Tensor2d &scattMatrix);

	Eigen::VectorXd getNi() {return m_ni;}
	Eigen::VectorXd getChi() {return m_chi;}
	Eigen::VectorXd getFissionXS() {return m_fission;}
	Eigen::VectorXd getTotalXS() {return m_total;}
	Eigen::MatrixXd getScattMatrix() {return m_scattMatrix;}

private:
	const std::string m_name;
	double m_temperature; // Celsius
	double m_heatSource; // Watt/m3

	// Neutron cross section
	Eigen::VectorXd m_ni;
	Eigen::VectorXd m_chi;
	Eigen::VectorXd m_fission; 
	Eigen::VectorXd m_total; 
	Eigen::MatrixXd m_scattMatrix; 

	std::shared_ptr<PolynomialFunction> m_thermalConductivityLaw;

};

#endif