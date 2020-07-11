#ifndef CALCULATIONKIND_H
#define CALCULATIONKIND_H

#include <iostream>

enum class SolverKind {UNDEFINED, NEUTRONICS, KINETICS, HEAT};

inline std::ostream& operator << (std::ostream& stm, SolverKind calc)
{
    switch(calc)
    {
        case SolverKind::UNDEFINED  : return stm << "UNDEFINED";
        case SolverKind::NEUTRONICS : return stm << "NEUTRONICS";
        case SolverKind::KINETICS   : return stm << "KINETICS";
        case SolverKind::HEAT       : return stm << "HEAT";
        default : return stm << "solver{" << int(calc) << "}"; 
    }
}

#endif