#ifndef BASESPECTRUMCODE_H
#define BASESPECTRUMCODE_H

#include "Reactor.h"
#include "Library.h"
#include "additionalPrintFuncs.h"
#include "Output.h"

#include <unsupported/Eigen/CXX11/Tensor>

class BaseSpectrumCode
{
public:
    BaseSpectrumCode(Reactor &reactor, Library &library, SolverData &solverData) :
	m_reactor(reactor), m_library(library), m_solverData(solverData),
	m_mesh(reactor.getMesh()), 
	m_radii(m_mesh.getBoundaries("cm")),
	m_volumes(m_mesh.getVolumes("cm")),
	m_totalXS(m_mesh.getTotalXSs()),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_solverData.getEnergies()),
	m_rays(sizeof(abscissa) / sizeof(abscissa[0])) {}
	
	~BaseSpectrumCode(){}
	
	virtual std::pair<Numerics::Tensor3d, Numerics::Tensor4d> calcTracks() = 0;
	virtual Numerics::Tensor3d calcCPs(std::pair<Numerics::Tensor3d, Numerics::Tensor4d> &trackData) = 0;
	void particleBalanceCheck(Numerics::Tensor3d &gcpm);
	Eigen::MatrixXd calcCPMMatrix(Numerics::Tensor3d &gcpm);
	Eigen::MatrixXd calcMMatrix(Eigen::MatrixXd &cpm);
	Eigen::MatrixXd calcFMatrix(Eigen::MatrixXd &cpm);
	virtual void applyBoundaryConditions(Numerics::Tensor3d &gcpm) = 0; 
	void setNewHeatSource(Numerics::SourceIterResults result);
	
protected:
	virtual Eigen::VectorXd calcFissionPowerDistribution() = 0;
	const static double abscissa[8];
	const static double weights[8];

private:
	Reactor &m_reactor;
	Library &m_library;
	SolverData &m_solverData;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	Eigen::MatrixXd m_totalXS;
	int m_cells;
	int m_energies;
	int m_rays;
};

#endif