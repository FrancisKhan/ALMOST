#ifndef MATERIALKIND_H
#define MATERIALKIND_H

#include <iostream>

enum class MaterialKind {UNDEFINED, U, NEW};

inline std::ostream& operator << (std::ostream& stm, MaterialKind mat)
{
    switch(mat)
    {
        case MaterialKind::UNDEFINED : return stm << "UNDEFINED";
        case MaterialKind::U         : return stm << "U";
        case MaterialKind::NEW       : return stm << "NEW";
        default : return stm << "matProperties{" << int(mat) << "}"; 
    }
}

#endif