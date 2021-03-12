#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>

class Library
{
public:
	Library() {}
	std::vector<std::string> readXSFile(std::string &input);
	void findNuclideBLocks();
	std::pair<unsigned, unsigned> getXSNuclideBLock(const std::string &nuclide);

	void getNuclides();

	//void setMatProperties(std::vector<MaterialKind> &matProperties);
	//std::vector< std::shared_ptr<AbstractMaterial> > getMatProperties() {return m_matProperties;};
	
private:
	//std::vector< std::shared_ptr<AbstractMaterial> > m_matProperties;
	std::vector<std::string> m_xsDataFileLines;
	std::vector<std::string> m_xsNuclides;
	std::vector<unsigned> m_xsNuclideBlocks;
};

#endif