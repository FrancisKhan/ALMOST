#ifndef SPHERE_H
#define SPHERE_H

#include "AbstractGeometry.h"

class Sphere : public AbstractGeometry
{
public:
	Eigen::VectorXd surfaces(Eigen::VectorXd &boundaries, std::string dim);
	Eigen::VectorXd volumes(Eigen::VectorXd &boundaries, std::string dim);
	double externalSurface(Eigen::VectorXd &boundaries, std::string dim);
};

#endif