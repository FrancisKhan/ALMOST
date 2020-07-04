#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include "Mesh.h"
#include "Library.h"

class AbstractSolver
{
public:
    AbstractSolver(Mesh &mesh, Library &library){};
	virtual ~AbstractSolver(){};
	virtual void solve(int max_iter_number, double accuracy) = 0;
};

#endif