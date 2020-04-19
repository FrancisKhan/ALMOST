#ifndef BASEHEATCODE_H
#define BASEHEATCODE_H

#include "Mesh.h"
#include "Library.h"

class BaseHeatCode
{
public:
    BaseHeatCode(Mesh &mesh, Library &library) : 
	m_library(library), m_mesh(mesh), m_radii(m_mesh.getBoundaries()),
	m_volumes(m_mesh.getVolumes()),
	m_cells(m_mesh.getCellsNumber()) {}
	
	~BaseHeatCode(){}

	std::vector<double> exactSolution();
	void setupMatrix();
	
private:
	Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
	Eigen::MatrixXd m_matrix;
};

#endif