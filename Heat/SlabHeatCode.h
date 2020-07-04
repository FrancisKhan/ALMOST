#ifndef SLABHEATCODE_H
#define SLABHEATCODE_H

#include "BaseHeatCode.h"

class SlabHeatCode : public BaseHeatCode
{
public:
    SlabHeatCode(Mesh &mesh, Library &library) : 
	BaseHeatCode(mesh, library), 
	m_library(library), m_mesh(mesh), m_radii(m_mesh.getBoundaries("m")),
	m_volumes(m_mesh.getVolumes("m")),
	m_cells(m_mesh.getCellsNumber()) {}

	std::tuple<Eigen::MatrixXd, Eigen::VectorXd> setupSystem() override;
	std::tuple<Eigen::MatrixXd, Eigen::VectorXd> 
	        applyBoundaryConditions(Eigen::MatrixXd &T, Eigen::VectorXd &source) override;
	
private:
	Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
	Eigen::VectorXd m_temperatures;
	Eigen::VectorXd m_heatSources;
};

#endif