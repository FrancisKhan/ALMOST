#ifndef DIRECTIONKIND_H
#define DIRECTIONKIND_H

#include <iostream>

enum class DirectionKind {UNDEFINED, FORWARD, ADJOINT};

inline std::ostream& operator << (std::ostream& stm, DirectionKind calc)
{
    switch(calc)
    {
        case DirectionKind::UNDEFINED : return stm << "UNDEFINED";
        case DirectionKind::FORWARD   : return stm << "FORWARD";
        case DirectionKind::ADJOINT   : return stm << "ADJOINT";
        default : return stm << "DirectionKind{" << int(calc) << "}"; 
    }
}

#endif