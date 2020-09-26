#ifndef CALCULATIONKIND_H
#define CALCULATIONKIND_H

#include <iostream>

enum class SolverKind {UNDEFINED, COUPLED, NEUTRONICS, KINETICS, HEAT, DIFFUSION};

inline std::ostream& operator << (std::ostream& stm, SolverKind calc)
{
    switch(calc)
    {
        case SolverKind::UNDEFINED  : return stm << "UNDEFINED";
        case SolverKind::COUPLED    : return stm << "COUPLED";
        case SolverKind::NEUTRONICS : return stm << "NEUTRONICS";
        case SolverKind::KINETICS   : return stm << "KINETICS";
        case SolverKind::HEAT       : return stm << "HEAT";
        case SolverKind::DIFFUSION  : return stm << "DIFFUSION";
        default : return stm << "solver{" << int(calc) << "}"; 
    }
}

inline std::string get_name(SolverKind solver) 
{
  switch (solver) 
  {
    case SolverKind::UNDEFINED  : return std::string("UNDEFINED");
    case SolverKind::COUPLED    : return std::string("COUPLED");
    case SolverKind::NEUTRONICS : return std::string("NEUTRONICS");
    case SolverKind::KINETICS   : return std::string("KINETICS");
    case SolverKind::HEAT       : return std::string("HEAT");
    case SolverKind::DIFFUSION  : return std::string("DIFFUSION");
    default : return std::string(""); 
  }
}

#endif