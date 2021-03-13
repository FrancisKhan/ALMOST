#ifndef NUCLIDEBLOCK_H
#define NUCLIDEBLOCK_H

#include <vector>
#include <string>
#include <iostream>

#include "additionalPrintFuncs.h"

using namespace PrintFuncs;

class NuclideBlock
{
public:
	NuclideBlock(std::vector<std::string> &dataVec) : m_xsDataLines(dataVec) 
	{
		setName();
		setAWR();
		std::cout << "getName(): " << stringFormat(getName(), "%7.6e") << std::endl;
		std::cout << "getAWR(): " << stringFormat(getAWR(), "%7.6e") << std::endl;
	}
	
private:
	void setName();
	std::string getName() {return m_name;}
	void setAWR();
	double getAWR() {return m_awr;}

	std::string m_name;
	double m_awr;
	std::vector<std::string> m_xsDataLines;
};

#endif