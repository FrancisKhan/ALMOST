#ifndef DIFFUSIONCODEFACTORY_H
#define DIFFUSIONCODEFACTORY_H

#include "BaseDiffusionCode.h"

class DiffusionCodeFactory
{
public:
	static std::shared_ptr<BaseDiffusionCode> setDiffusionCode(Reactor &reactor, Library &library, SolverData &solverData);
};

#endif