#ifndef PROBLEM_H
#define PROBLEM_H

#include "Reactor.h"
#include "Library.h"
#include "SolverData.h"

#include <vector>
#include <string>


class Problem
{
public:
	Problem(Reactor &reactor, Library &library, 
    const std::vector<SolverData> &solvers) :
    m_reactor(reactor), m_library(library), 
    m_solvers(solvers) {}

    void solve();

private:
	Reactor m_reactor;
	Library m_library;
    std::vector<SolverData> m_solvers;

};

#endif