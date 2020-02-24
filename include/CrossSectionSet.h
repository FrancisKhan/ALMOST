#ifndef CROSSSECTIONSET_H
#define CROSSSECTIONSET_H

#include <Eigen/Dense>
#include <vector>

using namespace Eigen;

class CrossSectionSet
{
public:
	CrossSectionSet(){}
	
	void setNi(MatrixXd &ni) {m_ni = ni;}
	void setChi(MatrixXd &chi) {m_chi = chi;}
	void setFission(MatrixXd &fission) {m_fission = fission;}
	void setScattering(MatrixXd &scattering) {m_scattering = scattering;}
	void setTotal(MatrixXd &total) {m_total = total;}
	
	MatrixXd getNi() {return m_ni;}
	MatrixXd getChi() {return m_chi;}
	MatrixXd getFission() {return m_fission;}
	MatrixXd getScattering() {return m_scattering;}
	MatrixXd getTotal() {return m_total;}
	
private:
	MatrixXd m_ni;
	MatrixXd m_chi;
	MatrixXd m_fission;
	MatrixXd m_scattering;
	MatrixXd m_total;
	
};

#endif