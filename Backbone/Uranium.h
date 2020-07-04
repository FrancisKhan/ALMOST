#ifndef URANIUM_H
#define URANIUM_H

#include "AbstractMaterial.h"

class Uranium : public AbstractMaterial
{
public:
    static std::shared_ptr<Uranium> instance();
	std::string whatAmI() override;
	double density(double T) override;
	double heatCapacity(double T) override;
	double thermalConductivity(double T) override;

private:
	Uranium(){};
    static std::shared_ptr<Uranium> m_pInstance;

};

#endif