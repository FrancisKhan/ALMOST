#ifndef BASESPECTRUMCODE_H
#define BASESPECTRUMCODE_H

#include "Mesh.h"
#include "Library.h"
#include <unsupported/Eigen/CXX11/Tensor>

class BaseSpectrumCode
{
public:
    BaseSpectrumCode(Mesh &mesh, Library &library) : 
	m_library(library), m_mesh(mesh), m_radii(m_mesh.getBoundaries()),
	m_volumes(m_mesh.getVolumes("cm")),
	m_totalXS(m_library.getCrossSectionSet().getTotal()),
	m_cells(m_mesh.getCellsNumber()),
	m_energies(m_mesh.getEnergyGroupsNumber()),
	m_rays(sizeof(abscissa) / sizeof(abscissa[0]))
	{
		// from m to cm
		std::transform(m_radii.begin(), m_radii.end(), m_radii.begin(), 
		[](double j){return j * 100.0;});
	}
	
	~BaseSpectrumCode(){}
	
	virtual std::pair<Tensor3d, Tensor4d> calcTracks() = 0;
	virtual Tensor3d calcCPs(std::pair<Tensor3d, Tensor4d> &trackData) = 0;
	void particleBalanceCheck(Tensor3d &gcpm);
	Eigen::MatrixXd calcCPMMatrix(Tensor3d &gcpm);
	Eigen::MatrixXd calcMMatrix(Eigen::MatrixXd &cpm);
	Eigen::MatrixXd calcFMatrix(Eigen::MatrixXd &cpm);
	virtual void applyBoundaryConditions(Tensor3d &gcpm) = 0; 
	void diagonalDominanceCheck();
	
protected:
	const static double abscissa[8];
	const static double weights[8];

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