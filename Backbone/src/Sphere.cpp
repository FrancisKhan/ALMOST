#include "Sphere.h"
#include <math.h>
#include <iostream>

using namespace Eigen;

VectorXd Sphere::volumes(VectorXd &boundaries)
{
	VectorXd volumes = VectorXd::Zero(boundaries.size() - 1);
	
	for(unsigned i = 1; i < boundaries.size(); i++)
	{
		volumes(i - 1) = (4.0 / 3.0) * M_PI * (pow(boundaries(i), 3) - pow(boundaries(i - 1), 3));
	}
	
	return volumes;
}

double Sphere::surface(VectorXd &boundaries)
{
	return 4.0 * M_PI * pow(boundaries(boundaries.size() - 1), 2);
}