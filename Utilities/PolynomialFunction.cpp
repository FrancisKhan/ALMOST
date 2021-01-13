#include "PolynomialFunction.h"
#include "numeric_tools.h"

#include <cmath>

double PolynomialFunction::calc(double x)
{
    double result = 0.0;

    for(size_t i = 0; i < m_coefficients.size(); i++)
    {
        result += m_coefficients[i] * pow(x, i);
    }

    return result;
}

double PolynomialFunction::calc(double x, double base)
{
    double result = 0.0;
    double value = Numerics::round_to(x - base, std::numeric_limits<float>::digits10); 

    if (Numerics::is_lower(value, 0.0))
    {
        out.print(TraceLevel::CRITICAL, "ERROR: x: {} lower than base value: {}", x, base);
	    exit(-1);
    }

    for(size_t i = 0; i < m_coefficients.size(); i++)
    {
        result += m_coefficients[i] * pow(value, i);
    }

    return result;
}