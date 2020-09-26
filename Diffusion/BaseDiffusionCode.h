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
	m_library(library), m_mesh(reactor.getMesh()), m_radii(m_mesh.getBoundaries("m")),
	m_volumes(m_mesh.getVolumes("m")),
	m_cells(m_mesh.getCellsNumber()) {}
	~BaseDiffusionCode(){}
	
	void solveSystem(Eigen::MatrixXd &T, Eigen::VectorXd &source);
	Eigen::VectorXd getInterfaceThermalConductivities();

	virtual std::tuple<Eigen::MatrixXd, Eigen::VectorXd> setupSystem() = 0;
	virtual std::tuple<Eigen::MatrixXd, Eigen::VectorXd> 
	        applyBoundaryConditions(Eigen::MatrixXd &T, Eigen::VectorXd &source) = 0;
	
private:
	Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
};

#endif