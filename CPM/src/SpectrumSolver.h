#ifndef SPECTRUMSOLVER_H
#define SPECTRUMSOLVER_H

#include "AbstractSolver.h"

class SpectrumSolver : public AbstractSolver
{
public:
    SpectrumSolver(Mesh &mesh, Library &library) : 
	AbstractSolver(mesh, library), 
	m_library(library), m_mesh(mesh){}
	
	void solve(int max_iter_number = 20, double accuracy = 0.00000001);
	
private:
    Library &m_library;
	Mesh &m_mesh;
		
};

#endif