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
	m_name(name), m_energies(0), m_temperature(0.0), m_heatSource(0.0) {}
	std::string getName() {return m_name;}
 	void setTemperature(double T) {m_temperature = T;}
	double getTemperature() {return m_temperature;}
	void setThermalConductivityLaw(std::vector<std::string> &vec);
	double getThermalConductivity();
	void setHeatSource(double q) {m_heatSource = q;}
	double getHeatSource() {return m_heatSource;}
	void setEnergies(unsigned n) {m_energies = n;}

    void setNeutronFlux(const Eigen::MatrixXd& neutronFlux) 
	{m_neutronFlux = neutronFlux;}
	Eigen::MatrixXd getNeutronFlux() {return m_neutronFlux;}

	void setAdjointFlux(const Eigen::MatrixXd& adjointFlux) 
	{m_adjointFlux = adjointFlux;}
	Eigen::MatrixXd getAdjointFlux() {return m_adjointFlux;}

	void setTotalFlux(const Eigen::VectorXd& totalFlux) 
	{m_totalFlux = totalFlux;}
	Eigen::MatrixXd getTotalFlux() {return m_totalFlux;}

	// Neutron cross section
	void setTotalXSTempDependenceLaws(std::vector<std::string> &vec);
	void setFissionXSTempDependenceLaws(std::vector<std::string> &vec);
	void setDiffCoeffTempDependenceLaws(std::vector<std::string> &vec);
	void setScattMatrixTempDependenceLaws(std::vector<std::string> &vec);
	void setNiTempDependenceLaws(std::vector<std::string> &vec);
	void setChiTempDependenceLaws(std::vector<std::string> &vec);
	
	Eigen::VectorXd getNi();
	Eigen::VectorXd getChi();
	Eigen::VectorXd getFissionXS();
	Eigen::VectorXd getDiffusionConstants();
	Eigen::VectorXd getTotalXS();
	Eigen::MatrixXd getScattMatrix();

private:
	const std::string m_name;
	unsigned m_energies;
	double m_temperature; // Celsius
	double m_heatSource; // Watt/m3

    Eigen::MatrixXd m_neutronFlux; 
	Eigen::MatrixXd m_adjointFlux;
	Eigen::VectorXd m_totalFlux;

	std::shared_ptr<PolynomialFunction> m_thermalConductivityLaw;
	std::vector< std::shared_ptr<PolynomialFunction> > m_totalXSTempDependenceLaws;
	std::vector< std::shared_ptr<PolynomialFunction> > m_fissionXSTempDependenceLaws;
	std::vector< std::shared_ptr<PolynomialFunction> > m_diffCoeffTempDependenceLaws;
	std::vector< std::shared_ptr<PolynomialFunction> > m_scattMatrixTempDependenceLaws;
	std::vector< std::shared_ptr<PolynomialFunction> > m_niTempDependenceLaws;
	std::vector< std::shared_ptr<PolynomialFunction> > m_chiTempDependenceLaws;
};

#endif