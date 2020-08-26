#ifndef SINGLECALCULATION_H
#define SINGLECALCULATION_H

#include "BaseCalculation.h"

class SingleCalculation : public BaseCalculation
{
public:
    SingleCalculation(Reactor &reactor, 
    Library &library, SolverData &solver):
    m_reactor(reactor), m_library(library), 
    m_solver(solver) {}

	void solve(int max_iter_number, double accuracy) override;

private:
    Reactor m_reactor;
	Library m_library;
    SolverData m_solver;
};

#endif