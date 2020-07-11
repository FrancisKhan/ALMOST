#ifndef PROBLEM_H
#define PROBLEM_H

#include "Reactor.h"
#include "Library.h"
#include "SpectrumSolver.h"
#include "CalculationKind.h"

#include <vector>
#include <string>

class Problem
{
public:
	Problem(Reactor &reactor, Library &library, 
    std::vector<CalculationKind> &calculations) :
    m_reactor(reactor), m_library(library), 
    m_calculations(calculations) {}

    void calculate();

private:
	Reactor m_reactor;
	Library m_library;
    std::vector<CalculationKind> m_calculations;

};

#endif