#ifndef CROSSSECTIONSET_H
#define CROSSSECTIONSET_H

#include "numeric_tools.h"

#include <unsupported/Eigen/CXX11/Tensor>
#include <Eigen/Dense>
#include <vector>

//using namespace Eigen;

class CrossSectionSet
{
public:
	CrossSectionSet(){}
	
	void setNi(Eigen::MatrixXd &ni) {m_ni = ni;}
	void setChi(Eigen::MatrixXd &chi) {m_chi = chi;}
	void setFission(Eigen::MatrixXd &fission) {m_fission = fission;}
	void setTotal(Eigen::MatrixXd &total) {m_total = total;}
	void setScattMatrix(Numerics::Tensor3d &scattMatrix) {m_scattMatrix = scattMatrix;}
	
	Eigen::MatrixXd getNi() {return m_ni;}
	Eigen::MatrixXd getChi() {return m_chi;}
	Eigen::MatrixXd getFission() {return m_fission;}
	Eigen::MatrixXd getTotal() {return m_total;}
	Numerics::Tensor3d getScattMatrix() {return m_scattMatrix;}
	
private:
	Eigen::MatrixXd m_ni;
	Eigen::MatrixXd m_chi;
	Eigen::MatrixXd m_fission;
	Eigen::MatrixXd m_total;
	Numerics::Tensor3d m_scattMatrix;
	
};

#endif