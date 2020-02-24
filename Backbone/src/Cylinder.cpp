#include "Cylinder.h"
#include <math.h>
#include <iostream>

using namespace Eigen;

VectorXd Cylinder::volumes(VectorXd &boundaries)
{
	VectorXd volumes = VectorXd::Zero(boundaries.size() - 1);
	
	for(unsigned i = 1; i < boundaries.size(); i++)
	{
		volumes(i - 1) = M_PI * (pow(boundaries(i), 2) - pow(boundaries(i - 1), 2));
	}
	
	return volumes;
}

double Cylinder::surface(VectorXd &boundaries)
{
	return 2.0 * M_PI * boundaries(boundaries.size() - 1);
}