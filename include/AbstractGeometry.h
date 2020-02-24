#ifndef ABSTRACTGEOMETRY_H
#define ABSTRACTGEOMETRY_H

#include "GeomKind.h"

#include <vector>

class AbstractGeometry
{
public:
    static AbstractGeometry *setGeometry(GeomKind choice);
	virtual ~AbstractGeometry(){}
	virtual std::vector<double> volumes(std::vector<double> &boundaries) = 0;
	virtual double surface(std::vector<double> &boundaries) = 0;
};

#endif