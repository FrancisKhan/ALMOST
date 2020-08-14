#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>

#include "Sphere.h"

using namespace Eigen;

VectorXd Sphere::volumes(VectorXd &boundaries, std::string dim)
{
	VectorXd volumes = VectorXd::Zero(boundaries.size() - 1);
	
	for(unsigned i = 1; i < boundaries.size(); i++)
		volumes(i - 1) = (4.0 / 3.0) * M_PI * (pow(boundaries(i), 3) - pow(boundaries(i - 1), 3));
	
	if(dim == "m")  
		return volumes;
	else if(dim == "cm") 
		return volumes * 1000000.0;
	else
		return volumes * -1.0;
}

double Sphere::surface(VectorXd &boundaries, std::string dim)
{
	double surface = 4.0 * M_PI * pow(boundaries(boundaries.size() - 1), 2);

	if(dim == "m")  
		return surface;
	else if(dim == "cm") 
		return surface * 10000.0;
	else
		return surface * -1.0;	
}