#include "KineticsSolver.h"
#include "SpectrumSolver.h"
#include "HeatSolver.h"
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

	std::string calculation = input.readData();

	if(calculation == "neutronics")
	{
		SpectrumSolver spectrum(reactor, library);
	    spectrum.solve();
	}
	else if(calculation == "kinetics")
	{
		KineticsSolver kinetics(reactor, library);
	    kinetics.solve();
	}
	else if(calculation == "heat")
	{
		HeatSolver heat(reactor, library);
	    heat.solve();
	}

	out.printEnd();
}
