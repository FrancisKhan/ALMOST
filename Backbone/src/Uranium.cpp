#include "numeric_tools.h"
#include "Uranium.h"

#include <cmath>

// Global static pointer used to ensure a single instance of the class.
Uranium* Uranium::m_pInstance = NULL; 
   
Uranium* Uranium::instance()
{
   if (!m_pInstance)   // Only allow one instance of class to be generated.
      m_pInstance = new Uranium;

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
    if (is_lower(T, 273.0))
    {
        return 0.0;
    }
    else if (is_greater(T, 273.0) && is_lower(T, 942.0)) // alpha phase
    {
       return 19.36 * 1000 - 1.03347 * T; 
    }
    else if (is_greater(T, 942.0) && is_lower(T, 1049.0)) // beta phase
    {
        return 19.092 * 1000 - 0.9807 * T;
    }
    else if (is_greater(T, 1049.0) && is_lower(T, 1405.0)) // gamma phase
    {
        return 18.447 * 1000 - 0.5166 * T;
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
    if (is_lower(T, 273.0))
    {
        return 0.0;
    }
    else if (is_greater(T, 273.0) && is_lower(T, 942.0)) // alpha phase
    {
       return 104.82 + 5.3686 * 0.001 * T + 10.1823 * 0.00001 * pow(T, 2); 
    }
    else if (is_greater(T, 942.0) && is_lower(T, 1049.0)) // beta phase
    {
        return 176.4;
    }
    else if (is_greater(T, 1049.0) && is_lower(T, 1405.0)) // gamma phase
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
    if (is_lower(T, 273.0))
    {
        return 0.0;
    }
    else if (is_greater(T, 273.0) && is_lower(T, 1405.0)) 
    {
        return 22.0 + 0.023 * (T - 273.0);
    }
    else
    {
        return 0.0;
    }
}