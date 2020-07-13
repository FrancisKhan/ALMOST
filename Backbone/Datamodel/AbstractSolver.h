#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include "SolverKind.h"
#include "Reactor.h"
#include "Library.h"

class AbstractSolver
{
public:
    AbstractSolver(Reactor &reactor, Library &library) :
	m_reactor(reactor), m_library(library) {}

	virtual ~AbstractSolver() {}
	
	virtual void solve(int max_iter_number = 20, 
	double accuracy = 0.00000001) = 0;

	virtual Eigen::VectorXd getMainParameter() = 0;
	
	static std::shared_ptr<AbstractSolver> getSolver(SolverKind solver, 
	       Reactor &reactor, Library &library);

private:
	Reactor m_reactor;
	Library m_library;
};

#endif