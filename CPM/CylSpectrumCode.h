#ifndef CYLSPECTRUMCODE_H
#define CYLSPECTRUMCODE_H

#include "BaseSpectrumCode.h"
#include <unsupported/Eigen/CXX11/Tensor>

class CylSpectrumCode : public BaseSpectrumCode
{
public:
    CylSpectrumCode(Reactor &reactor, Library &library) : 
	BaseSpectrumCode(reactor, library), 
	m_reactor(reactor),
	m_library(library), m_mesh(reactor.getMesh()), 
	m_radii(m_mesh.getBoundaries("cm")),
	m_volumes(m_mesh.getVolumes("cm")),
	m_totalXS(m_mesh.getTotalXSs()),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_mesh.getEnergyGroupsNumber()),
	m_rays(sizeof(abscissa) / sizeof(abscissa[0])),
	m_surface(m_mesh.getSurface("cm")) {}
	
	std::pair<Numerics::Tensor3d, Numerics::Tensor4d> calcTracks() override;
	Numerics::Tensor3d calcCPs(std::pair<Numerics::Tensor3d, Numerics::Tensor4d> &trackData) override;
	void applyBoundaryConditions(Numerics::Tensor3d &gcpm) override; 

private:
	Eigen::VectorXd calcFissionPowerDistribution();
	
	Reactor &m_reactor;
	Library &m_library;
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