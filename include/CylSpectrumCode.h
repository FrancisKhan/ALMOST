#ifndef CYLSPECTRUMCODE_H
#define CYLSPECTRUMCODE_H

#include "AbstractSpectrumCode.h"
#include <unsupported/Eigen/CXX11/Tensor>

typedef Eigen::Tensor<double, 3> Tensor3d;
typedef Eigen::Tensor<double, 4> Tensor4d;

class CylSpectrumCode : public AbstractSpectrumCode
{
public:
    CylSpectrumCode(Mesh &mesh, Library &library) : 
	AbstractSpectrumCode(mesh, library), m_library(library), m_mesh(mesh)
	{
		m_cellsNumber    = m_mesh.getCellsNumber();
		m_energiesNumber = m_mesh.getEnergyGroupsNumber();
		m_raysNumber     = sizeof(abscissa) / sizeof(abscissa[0]);
		
		m_tau = Tensor4d(m_cellsNumber, m_cellsNumber, m_raysNumber, m_energiesNumber);
	    m_tau.setZero();
	}
	
	void calcTracks();
	void calcCPs();
	
private:
	const static double abscissa[8];
	const static double weights[8];
	Library &m_library;
	Mesh &m_mesh;
	int m_cellsNumber;
	int m_energiesNumber;
	int m_raysNumber;
	Tensor4d m_tau;
};

#endif