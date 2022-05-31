#ifndef FORWARDSPECTRUMCODE_H
#define FORWARDSPECTRUMCODE_H

#include "BaseDiffusionCode.h"

class ForwardDiffusionCode : public BaseDiffusionCode
{
public:
    ForwardDiffusionCode(Reactor &reactor, Library &library, SolverData &solverData) : 
    BaseDiffusionCode(reactor, library, solverData),
	m_reactor(reactor), m_library(library), m_solverData(solverData),
	m_mesh(reactor.getMesh()), m_radii(m_mesh.getBoundaries("cm")),
	m_volumes(m_mesh.getVolumes("cm")),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_solverData.getEnergies()) {}

	~ForwardDiffusionCode(){}
	
	Eigen::MatrixXd calcMMatrix(Eigen::MatrixXd &diffMatrix) override;
	Eigen::MatrixXd calcFMatrix() override;
	
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