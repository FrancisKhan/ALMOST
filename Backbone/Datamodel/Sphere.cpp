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

VectorXd Sphere::surfaces(VectorXd &boundaries, std::string dim)
{
	VectorXd surfaces = VectorXd::Zero(boundaries.size());
	
	for(unsigned i = 0; i < boundaries.size(); i++)
		surfaces(i) = 4.0 * M_PI * pow(boundaries(i), 2);
	
	if(dim == "m")  
		return surfaces;
	else if(dim == "cm") 
		return surfaces * 10000.0;
	else
		return surfaces * -1.0;
}

double Sphere::externalSurface(VectorXd &boundaries, std::string dim)
{
	VectorXd s = surfaces(boundaries, dim);

	if(dim == "m")  
		return s(Eigen::last);
	else if(dim == "cm") 
		return s(Eigen::last) * 10000.0;
	else
		return s(Eigen::last) * -1.0;	
}