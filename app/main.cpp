#include "SpectrumSolver.h"
#include "Output.h"
#include "Input.h"
#include "try.h"

#include <iostream>

int main(int argc, char** argv)
{
	Mesh mesh;
	Library library;
	Input input(mesh, library);
	input.getArguments(argc, argv);
	out.printStart();
	input.printData();
	input.readData();
	SpectrumSolver spectrum(mesh, library);
	spectrum.solve();
	out.printEnd();
}
