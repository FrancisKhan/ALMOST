#ifndef KINETICSSOLVER_H
#define KINETICSSOLVER_H

#include "AbstractSolver.h"

class KineticsSolver : public AbstractSolver
{
public:
    KineticsSolver(Reactor &reactor, Library &library) : 
	AbstractSolver(reactor, library), 
	m_reactor(reactor), m_library(library), m_mesh(reactor.getMesh()){}
	
	void solve(int max_iter_number, double accuracy);
	
	std::variant<double, Eigen::VectorXd, Eigen::MatrixXd> getMainParameter()
		{return -1.0;}

	void relaxResults(double param) override {}
	
private:
	Reactor &m_reactor;
    Library &m_library;
	Mesh &m_mesh;
		
};

#endif