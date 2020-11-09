#ifndef DIFFUSIONSOLVER_H
#define DIFFUSIONSOLVER_H

#include "AbstractSolver.h"

class DiffusionSolver : public AbstractSolver
{
public:
    DiffusionSolver(Reactor &reactor, Library &library, SolverData &solverData) : 
	AbstractSolver(reactor, library, solverData), 
	m_reactor(reactor), m_library(library), m_solverData(solverData),
	m_mesh(reactor.getMesh()){}
	
	void solve();

	std::variant<double, Eigen::VectorXd, Eigen::MatrixXd> getMainParameter() 
	{return m_reactor.getKFactor();}

	void relaxResults(double param) override;
	void printResults(TraceLevel level) override;

private:
	Reactor &m_reactor;
	Library &m_library;
	SolverData &m_solverData;
	Mesh &m_mesh;
	Eigen::VectorXd m_oldPowerDensities;
};

#endif