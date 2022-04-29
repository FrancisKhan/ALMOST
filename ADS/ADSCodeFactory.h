#ifndef ADSCODEFACTORY_H
#define ADSCODEFACTORY_H

#include "BaseADSCode.h"

class ADSCodeFactory
{
public:
	static std::shared_ptr<BaseADSCode> setADSCode(Reactor &reactor, Library &library, SolverData &solverData);
};

#endif