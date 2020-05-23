#ifndef BASEHEATCODE_H
#define BASEHEATCODE_H

#include "Mesh.h"
#include "Library.h"
#include "numeric_tools.h"

#include <tuple> 

class BaseHeatCode
{
public:
    BaseHeatCode(Mesh &mesh, Library &library) : 
	m_library(library), m_mesh(mesh), m_radii(m_mesh.getBoundaries("m")),
	m_volumes(m_mesh.getVolumes("m")),
	m_cells(m_mesh.getCellsNumber()),
	m_temperatures(m_mesh.getTemperatures()), 
	m_heatSources(m_mesh.getTemperatures()) {}
	
	~BaseHeatCode(){}

	std::tuple<Eigen::VectorXd, Eigen::VectorXd, Eigen::VectorXd> calcInterTemperatures();

    Eigen::VectorXd calcConductivities(Eigen::VectorXd &t);

	std::tuple<Eigen::MatrixXd, Eigen::VectorXd> applyBoundaryConditions(Eigen::MatrixXd &T, 
	Eigen::VectorXd &source);

	void solveSystem(Eigen::MatrixXd &T, Eigen::VectorXd &source);

	std::tuple<Eigen::MatrixXd, Eigen::VectorXd> setupSystem();

    // For testing only
	std::vector<double> exactSolution();
	
private:
	Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
	Eigen::VectorXd m_temperatures;
	Eigen::VectorXd m_heatSources;
	Eigen::MatrixXd m_matrix;
};

#endif