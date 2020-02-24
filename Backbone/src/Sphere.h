#ifndef SPHERE_H
#define SPHERE_H

#include "AbstractGeometry.h"

class Sphere : public AbstractGeometry
{
public:
	Eigen::VectorXd volumes(Eigen::VectorXd &boundaries);
	double surface(Eigen::VectorXd &boundaries);
};

#endif