#include "Problem.h"
#include "Reactor.h"
#include "Output.h"
#include "Input.h"

#include <iostream>
#include <chrono>

int main(int argc, char** argv)
{
	Reactor reactor;
	Library library;

	auto start = std::chrono::steady_clock::now();
	library.funcTry();
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	std::cout << "Main, Timing: " 
			  << std::chrono::duration <double, std::milli> (diff).count() / 1000.0 
			  << std::endl;


	// Input input(reactor, library);
	// input.getArguments(argc, argv);

	// out.printStart();
	// input.printData();
	// input.readData();
	// Problem problem(reactor, library, input.getSolvers());
	// problem.solve();
	// out.printEnd();
}
