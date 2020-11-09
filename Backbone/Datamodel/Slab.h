#ifndef SLAB_H
#define SLAB_H

#include "AbstractGeometry.h"

class Slab : public AbstractGeometry
{
public:
	Eigen::VectorXd volumes(Eigen::VectorXd &boundaries, std::string dim);
	Eigen::VectorXd surfaces(Eigen::VectorXd &boundaries, std::string dim);
	double externalSurface(Eigen::VectorXd &boundaries, std::string dim);
};

#endif