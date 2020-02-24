#ifndef SLAB_H
#define SLAB_H

#include "AbstractGeometry.h"

class Slab : public AbstractGeometry
{
public:
	Eigen::VectorXd volumes(Eigen::VectorXd &boundaries);
	double surface(Eigen::VectorXd &boundaries);
};

#endif