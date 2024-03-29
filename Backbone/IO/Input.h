#ifndef INPUT_H
#define INPUT_H

#include "Reactor.h"
#include "Library.h"
#include "SolverKind.h"
#include "SolverData.h"
#include "helper_tools.h"
#include "numeric_tools.h"
#include "PlotKind.h"


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
	std::vector<SolverData> getSolvers() {return m_solvers;};

	static std::vector<PlotKind> getPlots() {return m_plots;}
	
private:									  
    void removeExtraSpaces(const std::string &input, std::string &output);
    std::vector<std::string> splitLine(std::string line);

    std::string findKeyword(std::string toSearch, unsigned lowLimit = 0, 
	unsigned topLimit = std::numeric_limits<unsigned>::max(), bool optional = false);
	
	std::pair<unsigned, unsigned> findBlock(std::string keyOne, std::string keyTwo);
	void setGeometryKind();
	void setMesh();
	void setMaterials(SolverKind calc);
	void setKineticsParameters();
	void setsetKineticsParameters();
	void setReactivity();
   	void setSolvers();
	void setMaterialProperties(std::string name);
	void setThermalConductivity(std::vector<std::string> &values, unsigned index);
	void setPlots();

    std::string readOneParameter(std::string name);
	std::vector<std::string> readManyParameters(std::string name, bool optional = false);
	
	std::vector<double> setManyParameters(std::string name, 
										  std::string prefix = "");

	void setXS(std::string name, std::string outputName);
	void setMatrixXS(std::string name, std::string outputName);

	void setTemperatures();
	void setHeatSources();
	void setThermalPower();

	void setSolverProperties(std::string name, 
		 SolverKind inputSolver = SolverKind::UNDEFINED);

    Reactor &m_reactor;
 	Mesh &m_mesh;
	Library &m_library;
	unsigned m_energies;
	unsigned m_cells;
	std::string m_inputPath;
	std::vector<SolverData> m_solvers;
	std::vector<std::string> m_inputLines;
	std::vector<std::string> m_materialMap;
	std::vector<std::string> m_materialList;
	static std::vector<PlotKind> m_plots;
};

#endif