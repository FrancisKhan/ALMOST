#ifndef ABSTRACTGEOMETRY_H
#define ABSTRACTGEOMETRY_H

#include "GeomKind.h"

#include <memory>
#include <Eigen/Dense>

class AbstractGeometry
{
public:
    static std::shared_ptr<AbstractGeometry> setGeometry(GeomKind choice);
	virtual ~AbstractGeometry(){}
	virtual Eigen::VectorXd volumes(Eigen::VectorXd &boundaries, std::string dim) = 0;
	virtual Eigen::VectorXd surfaces(Eigen::VectorXd &boundaries, std::string dim) = 0;
	virtual double externalSurface(Eigen::VectorXd &boundaries, std::string dim) = 0;
};

#endif