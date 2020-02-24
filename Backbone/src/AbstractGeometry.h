#ifndef ABSTRACTGEOMETRY_H
#define ABSTRACTGEOMETRY_H

#include "GeomKind.h"

#include <Eigen/Dense>

class AbstractGeometry
{
public:
    static AbstractGeometry *setGeometry(GeomKind choice);
	virtual ~AbstractGeometry(){}
	virtual Eigen::VectorXd volumes(Eigen::VectorXd &boundaries) = 0;
	virtual double surface(Eigen::VectorXd &boundaries) = 0;
};

#endif