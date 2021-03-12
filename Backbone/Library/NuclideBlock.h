#ifndef NUCLIDEBLOCK_H
#define NUCLIDEBLOCK_H

#include <vector>
#include <string>

class NuclideBlock
{
public:
	NuclideBlock(std::vector<std::string> &dataVec) : m_xsDataLines(dataVec) 
	{
		setName();
	}
	
private:
	void setName();
	std::string getName() {return m_name;}

	std::string m_name;
	std::vector<std::string> m_xsDataLines;
};

#endif