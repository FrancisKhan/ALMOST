#ifndef REACTOR_H
#define REACTOR_H

#include "numeric_tools.h"
#include "KineticsSet.h"
#include "SolverData.h"
#include "Mesh.h"

#include <vector>
#include <string>

class Reactor
{
public:
	Reactor() : m_thermalPower(-1.0) {}
	
	void setKineticsSet(KineticsSet &kineticsSet) 
	{m_kineticsSet = kineticsSet;}

    KineticsSet getKineticsSet() {return m_kineticsSet;}

    void setForwardEigenValues(const std::vector<double>& v) {m_forwardEigenValues = v;}
	void setAdjointEigenValues(const std::vector<double>& v) {m_adjointEigenValues = v;}
	std::vector<double> getForwardEigenValues() {return m_forwardEigenValues;}
	std::vector<double> getAdjointEigenValues() {return m_adjointEigenValues;}
	double getKFactor() {return m_forwardEigenValues.front();}
	double getAdjointKFactor() {return m_adjointEigenValues.front();}

	void setThermalPower(double thermalPower) {m_thermalPower = thermalPower;}
	double getThermalPower() {return m_thermalPower;}

	Mesh& getMesh() {return m_mesh;}

	// to be placed elsewere
	void setSolvers(std::vector<SolverData> &solvers) {m_solvers = solvers;}
	std::vector<SolverData> getSolvers() {return m_solvers;}
	bool isMultisolvers() {return m_solvers.size() >= 2;}

	void setLogLevel(TraceLevel level) {m_logLevel = level;}
	TraceLevel getLogLevel() {return m_logLevel;}

private:
	KineticsSet m_kineticsSet;
	Mesh m_mesh;
	double m_thermalPower;
	double m_albedo;
	std::vector<double> m_forwardEigenValues;
	std::vector<double> m_adjointEigenValues;

	// to be placed elsewere
	bool m_isMultiSolver;
	std::vector<SolverData> m_solvers;
	TraceLevel m_logLevel;
};

#endif