#ifndef EIGENMODESKIND_H
#define EIGENMODESKIND_H

#include <iostream>

enum class EigenmodesKind {UNDEFINED, FIRST, ALL};

inline std::ostream& operator << (std::ostream& stm, EigenmodesKind modes)
{
    switch(modes)
    {
        case EigenmodesKind::UNDEFINED : return stm << "UNDEFINED";
        case EigenmodesKind::FIRST     : return stm << "FIRST";
        case EigenmodesKind::ALL       : return stm << "ALL";
        default : return stm << "EigenmodesKind{" << int(modes) << "}"; 
    }
}

#endif