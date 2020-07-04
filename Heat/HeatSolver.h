#ifndef HEATSOLVER_H
#define HEATSOLVER_H

#include "AbstractSolver.h"

class HeatSolver : public AbstractSolver
{
public:
    HeatSolver(Mesh &mesh, Library &library) : 
	AbstractSolver(mesh, library), 
	m_library(library), m_mesh(mesh){}
	
	void solve(int max_iter_number = 20, double accuracy = 0.00000001);

private:
	Library &m_library;
	Mesh &m_mesh;
};

#endif