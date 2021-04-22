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
	std::pair<unsigned, unsigned> getNumberOfValuesToRead(unsigned line);
	unsigned getNumberOfLinesToRead(unsigned line);
	std::vector<double> readParameters(const std::string &key, unsigned lowerBound = 0, 
	unsigned upperBound = std::numeric_limits<unsigned>::max());
	std::vector< std::pair<unsigned, unsigned> > readTemperatureBlocks();
	std::vector< std::pair<unsigned, unsigned> > readDilutionBlocks(std::pair<unsigned, unsigned> &block);
	std::pair<unsigned, unsigned> readInfDilutionBlock(std::pair<unsigned, unsigned> &block);
	void readName();
	void readAWR();
	std::vector<double> readTemperatures();
	std::vector<double> readDilutions(unsigned firstLine, unsigned lastLine);
	void readGroupConstants();
	CrossSectionSet readXS(XSKind xsKind);
	CrossSectionMatrixSet readMatrix(XSMatrixKind xsKind);
	void isNuclideResonant();
	Eigen::MatrixXd assembleMatrixXS(XSMatrixKind xsKind, unsigned lowBound, unsigned upperBound);

	std::vector<std::string> m_xsDataLines;
	Nuclide m_nuclide;
};

#endif