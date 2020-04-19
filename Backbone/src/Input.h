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
	std::string readData();
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
	std::vector<MaterialKind> setProperties();
	void setKineticsParameters();
	void setsetKineticsParameters();
	void setReactivity();
    std::string setCalculation();

    std::string readOneParameter(std::string name);
	std::vector<std::string> readManyParameters(std::string name);
	std::vector<double> setManyParameters(std::string name);

    Eigen::MatrixXd setXS(std::string name);
	Tensor3d setMatrixXS(std::string name);

 	Mesh &m_problem;
	Library &m_library;
	unsigned m_energies;
	unsigned m_cells;
	std::string m_inputPath;
	std::string m_calculation;
	std::vector<std::string> m_inputLines;
	std::vector<std::string> m_materialMap;
	std::vector<std::string> m_materialList;
};

#endif