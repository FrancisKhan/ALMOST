#include "numeric_tools.h"
#include "Uranium.h"

#include <cmath>

// Global static pointer used to ensure a single instance of the class. 
std::shared_ptr<Uranium> Uranium::m_pInstance = std::shared_ptr<Uranium>(nullptr);
   
std::shared_ptr<Uranium> Uranium::instance()
{
   if (!m_pInstance)   // Only allow one instance of class to be generated.
      m_pInstance.reset(new Uranium());

   return m_pInstance;
}

std::string Uranium::whatAmI()
{
    return "I am Uranium!"; 
}

// Thermophysical Properties of Materials For Nuclear Engineering: 
// A Tutorial and Collection of Data (2012)
// Temperature in Kelvin
// Density in Kg/m3

double Uranium::density(double T)
{   
    double Tc = T + 273.15;

    if (is_lower(Tc, 273.0))
    {
        return 0.0;
    }
    else if (is_greater(Tc, 273.0) && is_lower(Tc, 942.0)) // alpha phase
    {
       return 19.36 * 1000 - 1.03347 * Tc; 
    }
    else if (is_greater(Tc, 942.0) && is_lower(Tc, 1049.0)) // beta phase
    {
        return 19.092 * 1000 - 0.9807 * Tc;
    }
    else if (is_greater(Tc, 1049.0) && is_lower(Tc, 1405.0)) // gamma phase
    {
        return 18.447 * 1000 - 0.5166 * Tc;
    }
    else
    {
        return 0.0;
    }
}

// Thermophysical Properties of Materials For Nuclear Engineering: 
// A Tutorial and Collection of Data (2012)
// Temperature in Kelvin
// Heat capacity in J/(Kg*K)

double Uranium::heatCapacity(double T)
{   
    double Tc = T + 273.15;

    if (is_lower(Tc, 273.0))
    {
        return 0.0;
    }
    else if (is_greater(Tc, 273.0) && is_lower(Tc, 942.0)) // alpha phase
    {
       return 104.82 + 5.3686 * 0.001 * Tc + 10.1823 * 0.00001 * pow(Tc, 2); 
    }
    else if (is_greater(Tc, 942.0) && is_lower(Tc, 1049.0)) // beta phase
    {
        return 176.4;
    }
    else if (is_greater(Tc, 1049.0) && is_lower(Tc, 1405.0)) // gamma phase
    {
        return 156.8;
    }
    else
    {
        return 0.0;
    }
}
// Thermophysical Properties of Materials For Nuclear Engineering: 
// A Tutorial and Collection of Data (2012)
// Temperature in Kelvin
// Thermal conductivity in W/(m*K)

double Uranium::thermalConductivity(double T)
{   
    double Tc = T + 273.15;

    if (is_lower(Tc, 273.0))
    {
        return 0.0;
    }
    else if (is_greater(Tc, 273.0) && is_lower(Tc, 1405.0)) 
    {
        return 22.0 + 0.023 * (Tc - 273.0);
    }
    else
    {
        return 0.0;
    }
}