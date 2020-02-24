#ifndef SPECTRUMCODEFACTORY_H
#define SPECTRUMCODEFACTORY_H

#include "BaseSpectrumCode.h"

class SpectrumCodeFactory
{
public:
	static BaseSpectrumCode *setSpectrumCode(Mesh &mesh, Library &library);
};

#endif