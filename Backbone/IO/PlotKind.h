#ifndef PLOTKIND_H
#define PLOTKIND_H

#include <iostream>

enum class PlotKind {UNDEFINED, NEUTRONFLUX, ADJOINTFLUX, TOTALFLUX};

inline std::ostream& operator << (std::ostream& stm, PlotKind kind)
{
    switch(kind)
    {
        case PlotKind::UNDEFINED   : return stm << "UNDEFINED";
        case PlotKind::NEUTRONFLUX : return stm << "NEUTRONFLUX";
        case PlotKind::ADJOINTFLUX : return stm << "ADJOINTFLUX";
        case PlotKind::TOTALFLUX   : return stm << "TOTALFLUX";
        default : return stm << "PlotKind{" << int(kind) << "}"; 
    }
}

inline std::string get_plot_name(PlotKind plot) 
{
  switch(plot) 
  {
    case PlotKind::UNDEFINED   : return std::string("UNDEFINED");
    case PlotKind::NEUTRONFLUX : return std::string("neutronflux");
    case PlotKind::ADJOINTFLUX : return std::string("adjointflux");
    case PlotKind::TOTALFLUX   : return std::string("totalflux");
    default : return std::string(""); 
  }
}

#endif