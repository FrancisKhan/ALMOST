#include "Problem.h"
#include "Reactor.h"
#include "Output.h"
#include "Input.h"

#include <iostream>

int main(int argc, char** argv)
{
	Reactor reactor;
	Library library;

	Input input(reactor, library);
	input.getArguments(argc, argv);

	out.printStart();
	input.printData();
	std::vector<SolverKind> solvers = input.readData();
	Problem problem(reactor, library, solvers);
	problem.solve();
	out.printEnd();
}
