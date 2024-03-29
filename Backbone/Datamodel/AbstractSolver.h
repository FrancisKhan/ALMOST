#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include "SolverKind.h"
#include "SolverData.h"
#include "Reactor.h"
#include "Library.h"
#include "PlotKind.h"

#include <variant>

class AbstractSolver
{
public:
    AbstractSolver(Reactor &reactor, Library &library, SolverData &solverData) :
	m_reactor(reactor), m_library(library), m_solverData(solverData) {}

	virtual ~AbstractSolver() {}
	
	virtual void solve() = 0; 

	virtual void relaxResults(double param) = 0;

	virtual std::variant<double, Eigen::VectorXd, Eigen::MatrixXd> 
			getMainParameter() = 0;
	
	static std::shared_ptr<AbstractSolver> getSolver(SolverData &solver, 
	       Reactor &reactor, Library &library);

	virtual void printEigenmodesResults(TraceLevel level) {;}
	
	virtual void printResults(TraceLevel level) = 0; 

	void plots(const std::vector<PlotKind>& vec);

private:
	Reactor& m_reactor;
	Library m_library;
	SolverData m_solverData;
};

#endif