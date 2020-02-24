#ifndef SPHSPECTRUMCODE_H
#define SPHSPECTRUMCODE_H

#include "BaseSpectrumCode.h"
#include <unsupported/Eigen/CXX11/Tensor>

class SphSpectrumCode : public BaseSpectrumCode
{
public:
    SphSpectrumCode(Mesh &mesh, Library &library) : 
	BaseSpectrumCode(mesh, library), 
	m_library(library), m_mesh(mesh), m_radii(m_mesh.getBoundaries()),
	m_volumes(m_mesh.getVolumes()),
	m_totalXS(m_library.getCrossSectionSet().getTotal()),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_mesh.getEnergyGroupsNumber()),
	m_rays(sizeof(abscissa) / sizeof(abscissa[0])) {}
	
	std::pair<Tensor3d, Tensor4d> calcTracks() override;
	Tensor3d calcCPs(std::pair<Tensor3d, Tensor4d> &pair) override;
	
private:

	Library &m_library;
	Mesh &m_mesh;
	Eigen::VectorXd m_radii;
	Eigen::VectorXd m_volumes;
	Eigen::MatrixXd m_totalXS;
	int m_cells;
	int m_energies;
	int m_rays;
};

#endif