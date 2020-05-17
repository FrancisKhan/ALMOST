#include "Slab.h"
#include <math.h>
#include <iostream>

using namespace Eigen;

VectorXd Slab::volumes(VectorXd &boundaries, std::string dim)
{
	VectorXd volumes = VectorXd::Zero(boundaries.size() - 1);
	
	for(unsigned i = 1; i < boundaries.size(); i++)
		volumes(i - 1) = boundaries(i) - boundaries(i - 1);
	
	if(dim == "m")  
		return volumes;
	else if(dim == "cm") 
		return volumes * 100.0;
	else
		return volumes * -1.0;
}

double Slab::surface(VectorXd &boundaries, std::string dim)
{
    double surface = 1.0;

	if(dim == "m")  
		return surface;
	else if(dim == "cm") 
		return surface;
	else
		return -1.0;	
}