#include "Slab.h"
#include <math.h>
#include <iostream>

using namespace Eigen;

VectorXd Slab::volumes(VectorXd &boundaries)
{
	VectorXd volumes = VectorXd::Zero(boundaries.size() - 1);
	
	for(unsigned i = 1; i < boundaries.size(); i++)
	{
		volumes(i - 1) = boundaries(i) - boundaries(i - 1);
	}
	
	return volumes;
}

double Slab::surface(VectorXd &boundaries)
{
	return -1.0;
}