#ifndef KINETICSSOLVER_H
#define KINETICSSOLVER_H

#include "AbstractSolver.h"

class KineticsSolver : public AbstractSolver
{
public:
    KineticsSolver(Mesh &mesh, Library &library) : 
	AbstractSolver(mesh, library), 
	m_library(library), m_mesh(mesh){}
	
	void solve();
	
private:
    Library &m_library;
	Mesh &m_mesh;
		
};

#endif