#ifndef SPHSPECTRUMCODE_H
#define SPHSPECTRUMCODE_H

#include "BaseSpectrumCode.h"
#include <unsupported/Eigen/CXX11/Tensor>

class SphSpectrumCode : public BaseSpectrumCode
{
public:
    SphSpectrumCode(Mesh &mesh, Library &library) : 
	BaseSpectrumCode(mesh, library), 
	m_library(library), m_mesh(mesh), m_radii(m_mesh.getBoundaries("cm")),
	m_volumes(m_mesh.getVolumes("cm")),
	m_totalXS(m_library.getCrossSectionSet().getTotal()),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_mesh.getEnergyGroupsNumber()),
	m_rays(sizeof(abscissa) / sizeof(abscissa[0])),
	m_surface(m_mesh.getSurface("cm")) {}
	
	std::pair<Numerics::Tensor3d, Numerics::Tensor4d> calcTracks() override;
	Numerics::Tensor3d calcCPs(std::pair<Numerics::Tensor3d, Numerics::Tensor4d> &pair) override;
	void applyBoundaryConditions(Numerics::Tensor3d &gcpm) override; 
	
private:

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