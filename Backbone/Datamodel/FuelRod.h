#ifndef FUEL_ROD_H
#define FUEL_ROD_H

#include "AbstractGeometry.h"

class FuelRod : public AbstractGeometry
{
public:
	Eigen::VectorXd volumes(Eigen::VectorXd &boundaries, std::string dim);
	Eigen::VectorXd surfaces(Eigen::VectorXd &boundaries, std::string dim);
	double externalSurface(Eigen::VectorXd &boundaries, std::string dim);
};

#endif