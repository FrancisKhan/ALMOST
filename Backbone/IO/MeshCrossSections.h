#ifndef MESHCROSSSECTIONS_H
#define MESHCROSSSECTIONS_H

struct MeshCrossSections 
{
  	Eigen::MatrixXd m_nis;
	Eigen::MatrixXd m_chis;
	Eigen::MatrixXd m_fissionXSs;
	Eigen::MatrixXd m_totalXSs;
	Numerics::Tensor3d m_scattMatrices;

	MeshCrossSections(const Eigen::MatrixXd &nis, const Eigen::MatrixXd &chis, 
	           		  const Eigen::MatrixXd &fisXSs, const Eigen::MatrixXd &totXSs, 
			   		  const Numerics::Tensor3d &scattMatrices) : m_nis(nis), m_chis(chis), 
			   		  m_fissionXSs(fisXSs), m_totalXSs(totXSs), m_scattMatrices(scattMatrices) {}
};

#endif