#include "SpectrumSolver.h"
#include "KineticsSolver.h"
#include "HeatSolver.h"
#include "Output.h"
#include "Input.h"

#include <iostream>

int main(int argc, char** argv)
{
	Mesh mesh;
	Library library;

	Input input(mesh, library);
	input.getArguments(argc, argv);
	out.printStart();
	input.printData();

	std::string calculation = input.readData();

	if(calculation == "neutronics")
	{
		SpectrumSolver spectrum(mesh, library);
	    spectrum.solve();
	}
	else if(calculation == "kinetics")
	{
		KineticsSolver kinetics(mesh, library);
	    kinetics.solve();
	}
	else if(calculation == "heat")
	{
		HeatSolver heat(mesh, library);
	    heat.solve();
	}

	out.printEnd();
}
