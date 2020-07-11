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
	std::vector<CalculationKind> calculations = input.readData();
	Problem problem(reactor, library, calculations);
	problem.calculate();
	out.printEnd();
}
