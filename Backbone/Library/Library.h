#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>

class Library
{
public:
	Library(){}
	void readXSData();
	void getXSNuclides();

	void funcTry();

	//void setMatProperties(std::vector<MaterialKind> &matProperties);
	//std::vector< std::shared_ptr<AbstractMaterial> > getMatProperties() {return m_matProperties;};
	
private:
	//std::vector< std::shared_ptr<AbstractMaterial> > m_matProperties;
	std::vector<std::string> m_xsDataFileLines;
	std::vector<unsigned> findRepetitiveLine(std::string key);
};

#endif