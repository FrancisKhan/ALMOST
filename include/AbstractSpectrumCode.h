#ifndef ABSTRACTSPECTRUMCODE_H
#define ABSTRACTSPECTRUMCODE_H

#include "Mesh.h"
#include "Library.h"

class AbstractSpectrumCode
{
public:
    AbstractSpectrumCode(Mesh &mesh, Library &library){};
	virtual ~AbstractSpectrumCode(){};
	virtual void calcTracks() = 0;
	virtual void calcCPs() = 0;
};

#endif