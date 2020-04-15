#ifndef HEATCODE_H
#define HEATCODE_H

#include "Mesh.h"
#include "Library.h"

class HeatCode
{
public:
    HeatCode(Mesh &mesh, Library &library) : 
	m_library(library), m_mesh(mesh), m_radii(m_mesh.getBoundaries()),
	m_volumes(m_mesh.getVolumes()),
	m_cells(m_mesh.getCellsNumber()) {}
	
	~HeatCode(){}

	std::vector<double> exactSolution();
	
private:
	Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
};

#endif