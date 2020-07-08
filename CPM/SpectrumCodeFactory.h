#ifndef SPECTRUMCODEFACTORY_H
#define SPECTRUMCODEFACTORY_H

#include "BaseSpectrumCode.h"

class SpectrumCodeFactory
{
public:
	static std::shared_ptr<BaseSpectrumCode> setSpectrumCode(Reactor &reactor, Library &library);
};

#endif