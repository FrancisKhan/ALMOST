#ifndef ADSCALCULATION_H
#define ADSCALCULATION_H

#include "BaseCalculation.h"

class ADSCalculation : public BaseCalculation
{
public:
    ADSCalculation(Reactor &reactor, 
    Library &library, std::vector<SolverData> &solvers):
    m_reactor(reactor), m_library(library), 
    m_solvers(solvers) {}

	void solve() override;

private:
    SolverData getCoupledSolver();

    Reactor m_reactor;
	Library m_library;
    std::vector<SolverData> m_solvers;
};

#endif