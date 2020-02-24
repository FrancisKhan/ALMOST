#ifndef CYLINDER_H
#define CYLINDER_H

#include "AbstractGeometry.h"

class Cylinder : public AbstractGeometry
{
public:
	std::vector<double> volumes(std::vector<double> &boundaries);
	double surface(std::vector<double> &boundaries);
};

#endif