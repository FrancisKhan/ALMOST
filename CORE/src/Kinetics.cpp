#include "Output.h"
#include "Kinetics.h"
#include "numeric_tools.h"

#include <unsupported/Eigen/Polynomials>
#include <iostream>

std::vector<double> Kinetics::inHourEqRoots(double rho)
{	
    std::vector<double> lambdaProd = prod_poly(m_lambda);

    // First term of in-hour equation, rho * lambdaProd 
    double betaT = std::accumulate(m_beta.begin(), m_beta.end(), 0.0);
    std::vector<double> firstTerm = lambdaProd;
    firstTerm.push_back(0.0);
    firstTerm *= rho - betaT;

    // Second term of in-hour equation, alpha * s * lambdaProd
    std::vector<double> s = {0.0, 1.0};
    std::vector<double> secondTerm = multiply_poly(lambdaProd, s);
    secondTerm *= m_alpha;

    // Third term of in-hour equation, sum(lambda_i * beta_i * lambdaProd_i)
    std::vector<double> thirdTerm(m_lambda.size(), 0.0);
    for(size_t i = 0; i < m_lambda.size(); i++)
    {
        thirdTerm += prod_poly_i(m_lambda, i) * m_lambda[i] * m_beta[i];
    }

    thirdTerm.push_back(0.0);
    thirdTerm.push_back(0.0);

    std::vector<double> inHourEq = firstTerm - secondTerm + thirdTerm;
    std::vector<double> roots = poly_roots(inHourEq);

    return roots;
}

double Kinetics::power(double rho, double deltaT)
{
    advanceCumTime(deltaT);

    std::vector<double> roots = inHourEqRoots(rho);
    std::vector<double> R(roots.size(), 0.0);

    for(size_t i = 0; i < roots.size(); i++)
    {
        double sum1 = 0.0;
        double sum2 = 0.0;
        double sum3 = 0.0;

        for(size_t j = 0; j < m_lambda.size(); j++)
        {
            sum1 += m_beta[j] / (roots[i] + m_lambda[j]);
            sum2 += m_concDev[j] / (roots[i] + m_lambda[j]);
            sum3 += m_beta[j] * m_lambda[j] / (pow(roots[i] + m_lambda[j], 2));
        }

        R[i] = (m_power * (1.0 + (1.0 / m_alpha) * sum1) - sum2) / (1.0 + (1.0 / m_alpha) * sum3);

    }

    m_power = 0.0;

    for(size_t i = 0; i < roots.size(); i++)
    {
        m_power += R[i] * exp(roots[i] * deltaT);
    }

    for(size_t i = 0; i < m_lambda.size(); i++)
    {
        double sum4 = 0.0;

        for(size_t j = 0; j < roots.size(); j++)
        {
            sum4 += R[j] * (exp(roots[j] * deltaT) - exp(-m_lambda[i] * deltaT)) / (m_lambda[i] + roots[j]);
        }

        m_conc[i] = (m_beta[i] / m_alpha) * sum4 + m_conc[i] * exp(-m_lambda[i] * deltaT);

        m_concDev[i] = (m_beta[i] / m_alpha) * m_power - m_lambda[i] * m_conc[i];
    }

    return m_power;
}

