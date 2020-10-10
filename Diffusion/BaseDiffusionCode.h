#ifndef BASEDIFFUSIONCODE_H
#define BASEDIFFUSIONCODE_H

#include "Reactor.h"
#include "Library.h"
#include "numeric_tools.h"
#include "additionalPrintFuncs.h"

#include <tuple> 

class BaseDiffusionCode
{
public:
    BaseDiffusionCode(Reactor &reactor, Library &library) : 
	m_reactor(reactor), m_library(library), 
	m_mesh(reactor.getMesh()), m_radii(m_mesh.getBoundaries("cm")),
	m_volumes(m_mesh.getVolumes("cm")),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_mesh.getEnergyGroupsNumber()) {}

	~BaseDiffusionCode(){}
	
	void solveSystem(Eigen::MatrixXd &T, Eigen::VectorXd &source);
	Eigen::MatrixXd getInterfaceDiffusionConstants();

	virtual Eigen::MatrixXd calcMMatrix() = 0;
	virtual Eigen::MatrixXd calcFMatrix() = 0;
	virtual Eigen::MatrixXd applyBoundaryConditions(Eigen::MatrixXd &T) = 0;
	void setNewHeatSource(Numerics::SourceIterResults result);

	
	
private:
	Reactor &m_reactor;
	Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
	int m_energies;
};

#endif