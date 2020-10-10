#ifndef SLABDIFFUSIONCODE_H
#define SLABDIFFUSIONCODE_H

#include "BaseDiffusionCode.h"

class SlabDiffusionCode : public BaseDiffusionCode
{
public:
    SlabDiffusionCode(Reactor &reactor, Library &library) : 
	BaseDiffusionCode(reactor, library), 
	m_reactor(reactor),
	m_library(library), m_mesh(reactor.getMesh()), 
	m_radii(m_mesh.getBoundaries("cm")),
	m_volumes(m_mesh.getVolumes("cm")),
	m_cells(m_mesh.getCellsNumber()) {}

	Eigen::MatrixXd calcMMatrix() override;
	Eigen::MatrixXd calcFMatrix() override;
	Eigen::MatrixXd applyBoundaryConditions(Eigen::MatrixXd &M) override;
	
private:
	Reactor &m_reactor;
	Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
};

#endif