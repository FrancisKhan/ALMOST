#ifndef SPECTRUMCODEFACTORY_H
#define SPECTRUMCODEFACTORY_H

#include "AbstractSpectrumCode.h"

class SpectrumCodeFactory
{
public:
	static AbstractSpectrumCode *setSpectrumCode(Mesh &mesh, Library &library);
};

#endif