#ifndef HEATCODEFACTORY_H
#define HEATCODEFACTORY_H

#include "BaseHeatCode.h"

class HeatCodeFactory
{
public:
	static BaseHeatCode *setHeatCode(Mesh &mesh, Library &library);
};

#endif