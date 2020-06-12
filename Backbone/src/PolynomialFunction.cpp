#include "PolynomialFunction.h"

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