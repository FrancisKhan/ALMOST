#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include "SolverKind.h"
#include "Reactor.h"
#include "Library.h"

#include <variant>

class AbstractSolver
{
public:
    AbstractSolver(Reactor &reactor, Library &library) :
	m_reactor(reactor), m_library(library) {}

	virtual ~AbstractSolver() {}
	
	virtual void solve(int max_iter_number = 20, 
	double accuracy = 0.00000001) = 0; 

	virtual void relaxResults(double param) = 0;

	virtual std::variant<double, Eigen::VectorXd, Eigen::MatrixXd> 
			getMainParameter() = 0;
	
	static std::shared_ptr<AbstractSolver> getSolver(SolverKind solver, 
	       Reactor &reactor, Library &library);
	
	virtual void printResults(TraceLevel level) = 0; 

private:
	Reactor m_reactor;
	Library m_library;
};

#endif