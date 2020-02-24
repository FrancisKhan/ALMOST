#ifndef INPUT_H
#define INPUT_H

#include "Mesh.h"
#include "Library.h"

class Input
{
public:
    Input(Mesh &problem, Library &library) : 
	m_problem(problem), m_library(library){}
	void readGeometry();
	
private:
 	Mesh &m_problem;
	Library &m_library;
};

#endif