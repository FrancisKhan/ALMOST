#ifndef INPUT_H
#define INPUT_H

#include "Mesh.h"
#include "Library.h"
#include "numeric_tools.h"

class Input
{
    typedef std::pair<unsigned, unsigned> us_pair;

public:
    Input(Mesh &problem, Library &library) : 
	m_problem(problem), m_library(library), m_energies(0),
	m_cells(0), m_inputPath(""){}
	void readData();
	void printData();
	void getArguments(int argc, char** argv);
	
private:									  
    void removeExtraSpaces(const std::string &input, std::string &output);
    std::vector<std::string> splitLine(std::string line);

    std::string findKeyword(std::string toSearch, unsigned lowLimit = 0, 
	unsigned topLimit = std::numeric_limits<unsigned>::max());
	
	std::pair<unsigned, unsigned> findBlock(std::string keyOne, std::string keyTwo);
	void setGeometryKind();
	void setEnergies();
	void setAlbedo();
	void setMesh();
	void setMaterials();
	void getMatProperties(us_pair matBlock, std::vector<MaterialKind> &matProperties);
	void setKineticsParameters();
	void setsetKineticsParameters();
	
    std::string getOneParameter(std::string name);
	std::vector<std::string> getManyParameter(std::string name);

    Eigen::MatrixXd getXS(std::string name);
	Tensor3d getMatrixXS(std::string name);

    bool isFloat(const std::string& s);
    bool isInteger(const std::string& s);
	bool isString(const std::string& s);

 	Mesh &m_problem;
	Library &m_library;
	unsigned m_energies;
	unsigned m_cells;
	std::string m_inputPath;
	std::vector<std::string> m_inputLines;
	std::vector<std::string> m_materialMap;
	std::vector<std::string> m_materialList;
};

#endif