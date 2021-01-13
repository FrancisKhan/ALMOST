#ifndef POLYNOMIALFUNCTION_H
#define POLYNOMIALFUNCTION_H

#include <vector>
#include <string>

class PolynomialFunction
{
public:
	PolynomialFunction(std::vector<double>& coeffs) : 
	m_coefficients(coeffs){}

    double calc(double x);
	double calc(double x, double base);

private:
	std::vector<double> m_coefficients;
};

#endif