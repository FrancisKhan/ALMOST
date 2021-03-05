#include "FuelRod.h"
#include <math.h>
#include <iostream>

using namespace Eigen;

VectorXd FuelRod::volumes(VectorXd &boundaries, std::string dim)
{
	VectorXd volumes = VectorXd::Zero(boundaries.size() - 1);
	
	for(unsigned i = 1; i < boundaries.size(); i++)
		volumes(i - 1) = M_PI * (pow(boundaries(i), 2) - pow(boundaries(i - 1), 2));
	
	if(dim == "m")  
		return volumes;
	else if(dim == "cm") 
		return volumes * 10000.0;
	else
		return volumes * -1.0;
}

VectorXd FuelRod::surfaces(VectorXd &boundaries, std::string dim)
{
	VectorXd surfaces = VectorXd::Zero(boundaries.size());

	surfaces = 2.0 * M_PI * boundaries;
	
	if(dim == "m")  
		return surfaces;
	else if(dim == "cm") 
		return surfaces * 100.0;
	else
		return surfaces * -1.0;
}

double FuelRod::externalSurface(VectorXd &boundaries, std::string dim)
{
	VectorXd s = surfaces(boundaries, dim);
	return s(Eigen::last);
}