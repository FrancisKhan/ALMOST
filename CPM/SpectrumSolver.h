#ifndef SPECTRUMSOLVER_H
#define SPECTRUMSOLVER_H

#include "AbstractSolver.h"

class SpectrumSolver : public AbstractSolver
{
public:
    SpectrumSolver(Reactor &reactor, Library &library) : 
	AbstractSolver(reactor, library), 
	m_reactor(reactor), m_library(library), m_mesh(reactor.getMesh()){}
	
	void solve(int max_iter_number, double accuracy);

	std::variant<double, Eigen::VectorXd, Eigen::MatrixXd> getMainParameter() 
	{return m_reactor.getKFactor();}

	void relaxResults(double param) override;

	void printResults(TraceLevel level) override; 
	
private:
	Reactor &m_reactor;
    Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_oldPowerDensities;
};

#endif