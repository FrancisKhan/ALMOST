#ifndef NUCLIDEBLOCK_H
#define NUCLIDEBLOCK_H

#include <vector>
#include <string>
#include <iostream>

#include "additionalPrintFuncs.h"
#include "Nuclide.h"

using namespace PrintFuncs;

class NuclideBlock
{
public:
	NuclideBlock(std::vector<std::string> &dataVec) : m_xsDataLines(dataVec) {}
	Nuclide* getNuclide();
	
private:
	unsigned getNumberOfValuesToRead(unsigned line);
	unsigned getNumberOfLinesToRead(unsigned line);
	std::vector<double> readParameters(const std::string &key, unsigned lowerBound = 0, 
	unsigned upperBound = std::numeric_limits<unsigned>::max());
	std::vector< std::pair<unsigned, unsigned> > readTemperatureBlocks();
	void readName();
	void readAWR();
	std::vector<double> readTemperatures();
	void readGroupConstants();
	XSSetType readXS(std::string key);

	std::vector<std::string> m_xsDataLines;
	Nuclide m_nuclide;
};

#endif