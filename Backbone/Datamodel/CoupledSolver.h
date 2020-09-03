#ifndef COUPLEDSOLVER_H
#define COUPLEDSOLVER_H

#include "AbstractSolver.h"

class CoupledSolver : public AbstractSolver
{
public:
    CoupledSolver(Reactor &reactor, Library &library, SolverData &solverData) : 
	AbstractSolver(reactor, library, solverData), 
	m_reactor(reactor), m_library(library), m_solverData(solverData),
	m_mesh(reactor.getMesh()){}
	
	void solve() {};

	std::variant<double, Eigen::VectorXd, Eigen::MatrixXd> getMainParameter() 
	{return 0.0;}

	void relaxResults(double param) override {};
	void printResults(TraceLevel level) override {}; 
	
private:
	Reactor &m_reactor;
    Library &m_library;
	SolverData &m_solverData;
	Mesh &m_mesh;
};

#endif