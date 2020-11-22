#ifndef BASEHEATCODE_H
#define BASEHEATCODE_H

#include "Reactor.h"
#include "Library.h"
#include "numeric_tools.h"
#include "additionalPrintFuncs.h"

#include <tuple> 

class BaseHeatCode
{
public:
    BaseHeatCode(Reactor &reactor, Library &library, SolverData &solverData) : 
	m_library(library), m_mesh(reactor.getMesh()), m_solverData(solverData),
	m_radii(m_mesh.getBoundaries("m")),
	m_volumes(m_mesh.getVolumes("m")),
	m_cells(m_mesh.getCellsNumber()),
	m_surfaces(m_mesh.getSurfaces("m")) {}
	~BaseHeatCode(){}
	
	void solveSystem(Eigen::MatrixXd &T, Eigen::VectorXd &source);

	Eigen::MatrixXd setupSystem();
	std::tuple<Eigen::MatrixXd, Eigen::VectorXd> applyBoundaryConditions(Eigen::MatrixXd &T);

protected:
	Eigen::VectorXd getInterfaceThermalConductivities();
	Eigen::VectorXd getInterfaceCellSizes();
	
private:
	Library &m_library;
	Mesh &m_mesh;
	SolverData &m_solverData;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
	Eigen::VectorXd m_surfaces;
	Eigen::VectorXd m_temperatures;
	Eigen::VectorXd m_heatSources;
};

#endif