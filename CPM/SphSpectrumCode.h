#ifndef SPHSPECTRUMCODE_H
#define SPHSPECTRUMCODE_H

#include "BaseSpectrumCode.h"
#include <unsupported/Eigen/CXX11/Tensor>

class SphSpectrumCode : public BaseSpectrumCode
{
public:
    SphSpectrumCode(Reactor &reactor, Library &library, SolverData &solverData) : 
	BaseSpectrumCode(reactor, library, solverData), 
	m_reactor(reactor), m_library(library), m_solverData(solverData),  
	m_mesh(reactor.getMesh()), 
	m_radii(m_mesh.getBoundaries("cm")),
	m_volumes(m_mesh.getVolumes("cm")),
	m_totalXS(m_mesh.getTotalXSs()),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_solverData.getEnergies()),
	m_rays(sizeof(abscissa) / sizeof(abscissa[0])),
	m_surface(m_mesh.getExternalSurface("cm")) {}
	
	std::pair<Numerics::Tensor3d, Numerics::Tensor4d> calcTracks() override;
	Numerics::Tensor3d calcCPs(std::pair<Numerics::Tensor3d, Numerics::Tensor4d> &pair) override;
	void applyBoundaryConditions(Numerics::Tensor3d &gcpm) override; 
	
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
	double m_surface;
};

#endif