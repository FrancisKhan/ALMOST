#ifndef PROBLEM_H
#define PROBLEM_H

#include "Reactor.h"
#include "Library.h"
#include "SolverKind.h"

#include <vector>
#include <string>


class Problem
{
public:
	Problem(Reactor &reactor, Library &library, 
    const std::vector<SolverKind> &solvers) :
    m_reactor(reactor), m_library(library), 
    m_solvers(solvers) {}

    void solve(int max_iter_number = 20, double accuracy = 0.00000001);

private:
	Reactor m_reactor;
	Library m_library;
    std::vector<SolverKind> m_solvers;

};

#endif