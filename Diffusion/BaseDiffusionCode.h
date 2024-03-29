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
    BaseDiffusionCode(Reactor &reactor, Library &library, SolverData &solverData) : 
	m_reactor(reactor), m_library(library), m_solverData(solverData),
	m_mesh(reactor.getMesh()), m_radii(m_mesh.getBoundaries("cm")),
	m_volumes(m_mesh.getVolumes("cm")),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_solverData.getEnergies()) {}

	~BaseDiffusionCode(){}
	
	Eigen::MatrixXd calcDiffOperatorMatrix();
	virtual Eigen::MatrixXd calcMMatrix(Eigen::MatrixXd &diffMatrix) = 0;
	virtual Eigen::MatrixXd calcFMatrix() = 0;
	Eigen::MatrixXd applyBoundaryConditions(Eigen::MatrixXd &M);

	Eigen::VectorXd calcFissionPowerDistribution();
	void setNewHeatSource(const eigenmodesResults& result);
	void setAdjointModes(const eigenmodesResults& result);

protected:
	Eigen::MatrixXd getInterfaceDiffcoefficients();
	
private:
	Reactor &m_reactor;
	Library &m_library;
	SolverData &m_solverData;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	int m_cells;
	int m_energies;
};

#endif