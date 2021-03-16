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
		setTemperatures();

		std::cout << "getTemperatures(): " << std::endl;

		for(auto i : getTemperatures())
		{
			std::cout << stringFormat(i, "%7.6e") << std::endl;
		}
	}
	
private:
	unsigned getNumberOfValuesToRead(unsigned line);
	unsigned getNumberOfLinesToRead(unsigned line);
	std::vector<double> readParameters(const std::string &key);

	void setName();
	std::string getName() {return m_name;}
	void setAWR();
	double getAWR() {return m_awr;}
	void setTemperatures();
	std::vector<double> getTemperatures() {return m_temperatures;}

	std::string m_name;
	double m_awr;
	std::vector<double> m_temperatures;
	std::vector<std::string> m_xsDataLines;
};

#endif