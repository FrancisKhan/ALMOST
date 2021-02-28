#include "FuelRod.h"
#include <math.h>
#include <iostream>

using namespace Eigen;

VectorXd FuelRod::volumes(VectorXd &boundaries, std::string dim)
{
	VectorXd volumes = VectorXd::Zero(1);
	return volumes;
}

VectorXd FuelRod::surfaces(VectorXd &boundaries, std::string dim)
{
	VectorXd volumes = VectorXd::Zero(1);
	return volumes;
}

double FuelRod::externalSurface(VectorXd &boundaries, std::string dim)
{
	VectorXd s = surfaces(boundaries, dim);
	return s(Eigen::last);
}