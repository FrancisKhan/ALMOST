#ifndef HEATSOLVER_H
#define HEATSOLVER_H

#include "AbstractSolver.h"

class HeatSolver : public AbstractSolver
{
public:
    HeatSolver(Reactor &reactor, Library &library) : 
	AbstractSolver(reactor, library), 
	m_reactor(reactor), m_library(library), m_mesh(reactor.getMesh()){}
	
	void solve(int max_iter_number, double accuracy);
	Eigen::VectorXd getMainParameter() {return m_mesh.getTemperatures("C");}

private:
	Reactor &m_reactor;
	Library &m_library;
	Mesh &m_mesh;
};

#endif