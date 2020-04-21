#ifndef ABSTRACTMATERIAL_H
#define ABSTRACTMATERIAL_H

#include "MaterialKind.h"

#include <memory>
#include <string>

class AbstractMaterial
{
public:
    static std::shared_ptr<AbstractMaterial> setMaterial(MaterialKind choice);
	virtual ~AbstractMaterial(){}
	virtual double density(double T) = 0;
	virtual double heatCapacity(double T) = 0;
	virtual double thermalConductivity(double T) = 0;
	virtual std::string whatAmI() = 0;

};

#endif