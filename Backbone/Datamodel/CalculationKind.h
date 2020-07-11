#ifndef CALCULATIONKIND_H
#define CALCULATIONKIND_H

#include <iostream>

enum class CalculationKind {UNDEFINED, NEUTRONICS, KINETICS, HEAT};

inline std::ostream& operator << (std::ostream& stm, CalculationKind calc)
{
    switch(calc)
    {
        case CalculationKind::UNDEFINED  : return stm << "UNDEFINED";
        case CalculationKind::NEUTRONICS : return stm << "NEUTRONICS";
        case CalculationKind::KINETICS   : return stm << "KINETICS";
        case CalculationKind::HEAT       : return stm << "HEAT";
        default : return stm << "calculation{" << int(calc) << "}"; 
    }
}

#endif