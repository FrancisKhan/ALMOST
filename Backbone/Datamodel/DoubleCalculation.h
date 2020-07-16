#ifndef DOUBLECALCULATION_H
#define DOUBLECALCULATION_H

#include "BaseCalculation.h"

class DoubleCalculation : public BaseCalculation
{
public:
    DoubleCalculation(Reactor &reactor, 
    Library &library, std::vector<SolverKind> &solvers):
    m_reactor(reactor), m_library(library), 
    m_solvers(solvers) {}

	void solve(int max_iter_number, double accuracy) override;

private:
    Reactor m_reactor;
	Library m_library;
    std::vector<SolverKind> m_solvers;
};

#endif