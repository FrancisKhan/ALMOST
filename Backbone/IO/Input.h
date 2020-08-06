#ifndef INPUT_H
#define INPUT_H

#include "Reactor.h"
#include "Library.h"
#include "SolverKind.h"
#include "helper_tools.h"
#include "numeric_tools.h"

class Input
{
    typedef std::pair<unsigned, unsigned> us_pair;

public:
    Input(Reactor &reactor, Library &library) : 
	m_reactor(reactor), m_mesh(reactor.getMesh()), m_library(library), 
	m_energies(0), m_cells(0), m_inputPath("") {}
	void storeInput();
	void readData();
	void printData();
	void getArguments(int argc, char** argv);
	std::vector<SolverKind> getSolvers() {return m_solvers;};
	
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
	void setMaterials(SolverKind calc);
	void setKineticsParameters();
	void setsetKineticsParameters();
	void setReactivity();
   	void setSolvers();
	void setHeatBoundaryConditions();
	void setMaterialProperties(std::string name);
	void setThermalConductivity(std::vector<std::string> &values, unsigned index);
	// void setThermalXSDependence(std::vector<std::string> &values, unsigned index);

    std::string readOneParameter(std::string name);
	std::vector<std::string> readManyParameters(std::string name);
	
	std::vector<double> setManyParameters(std::string name, 
										  std::string prefix = "");

    void setXS(std::string name, std::string outputName);
	Numerics::Tensor3d setMatrixXS(std::string name, std::string outputName);
	void setXSThermalDependence(std::string name, std::string outputName);

	void setTemperatures();
	void setHeatSources();
	void setThermalPower();
	void setRelaxationParameter();

    Reactor &m_reactor;
 	Mesh &m_mesh;
	Library &m_library;
	unsigned m_energies;
	unsigned m_cells;
	std::string m_inputPath;
	std::vector<SolverKind> m_solvers;
	std::vector<std::string> m_inputLines;
	std::vector<std::string> m_materialMap;
	std::vector<std::string> m_materialList;
};

#endif