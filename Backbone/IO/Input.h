#ifndef INPUT_H
#define INPUT_H

#include "Reactor.h"
#include "Library.h"
#include "numeric_tools.h"
#include "CalculationKind.h"
#include "MeshCrossSections.h"

class Input
{
    typedef std::pair<unsigned, unsigned> us_pair;

public:
    Input(Reactor &reactor, Library &library) : 
	m_reactor(reactor), m_mesh(reactor.getMesh()), m_library(library), 
	m_energies(0), m_cells(0), m_inputPath("") {}
	void storeInput();
	std::vector<CalculationKind> readData();
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
	void setMaterials(CalculationKind calc);
	void setKineticsParameters();
	void setsetKineticsParameters();
	void setReactivity();
    std::vector<CalculationKind> setCalculation();
	void setHeatBoundaryConditions();
	void setMaterialProperties(std::string name);
	void setThermalConductivity(std::vector<std::string> &values, unsigned index);

    std::string readOneParameter(std::string name);
	std::vector<std::string> readManyParameters(std::string name);
	
	std::vector<double> setManyParameters(std::string name, 
										  std::string prefix = "");

    Eigen::MatrixXd setXS(std::string name, std::string outputName);
	Numerics::Tensor3d setMatrixXS(std::string name, std::string outputName);

	void setTemperatures();
	void setHeatSources();

    Reactor &m_reactor;
 	Mesh &m_mesh;
	Library &m_library;
	unsigned m_energies;
	unsigned m_cells;
	std::string m_inputPath;
	std::vector<CalculationKind> m_calculations;
	std::vector<std::string> m_inputLines;
	std::vector<std::string> m_materialMap;
	std::vector<std::string> m_materialList;
};

#endif