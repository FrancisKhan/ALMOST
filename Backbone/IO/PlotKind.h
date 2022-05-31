#ifndef PLOTKIND_H
#define PLOTKIND_H

#include <iostream>

enum class PlotKind {UNDEFINED, NEUTRONFLUX, ADJOINTFLUX, TOTALFLUX, 
                     TEMPERATURE, POWERDENSITY};

inline std::ostream& operator << (std::ostream& stm, PlotKind kind)
{
    switch(kind)
    {
        case PlotKind::UNDEFINED    : return stm << "UNDEFINED";
        case PlotKind::NEUTRONFLUX  : return stm << "neutronflux";
        case PlotKind::ADJOINTFLUX  : return stm << "adjointflux";
        case PlotKind::TOTALFLUX    : return stm << "totalflux";
        case PlotKind::TEMPERATURE  : return stm << "temperature";
        case PlotKind::POWERDENSITY : return stm << "powerdensity";
        default : return stm << "PlotKind{" << int(kind) << "}"; 
    }
}

inline std::string get_plot_name(PlotKind plot) 
{
  switch(plot) 
  {
    case PlotKind::UNDEFINED    : return std::string("UNDEFINED");
    case PlotKind::NEUTRONFLUX  : return std::string("neutronflux");
    case PlotKind::ADJOINTFLUX  : return std::string("adjointflux");
    case PlotKind::TOTALFLUX    : return std::string("totalflux");
    case PlotKind::TEMPERATURE  : return std::string("temperature");
    case PlotKind::POWERDENSITY : return std::string("powerdensity");
    default : return std::string(""); 
  }
}

#endif