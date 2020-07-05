#ifndef GEOMKIND_H
#define GEOMKIND_H

#include <iostream>

enum class GeomKind {UNDEFINED, SLAB, CYLINDER, SPHERE};

inline std::ostream& operator << (std::ostream& stm, GeomKind geom)
{
    switch(geom)
    {
        case GeomKind::UNDEFINED : return stm << "UNDEFINED";
        case GeomKind::SLAB      : return stm << "SLAB";
        case GeomKind::CYLINDER  : return stm << "CYLINDER";
        case GeomKind::SPHERE    : return stm << "SPHERE";
        default : return stm << "GeomKind{" << int(geom) << "}"; 
    }
}

#endif