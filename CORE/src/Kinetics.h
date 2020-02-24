#ifndef KINETICS_H
#define KINETICS_H

#include <vector>

class Kinetics
{
public:
   
    Kinetics(std::vector<double> &lambda, std::vector<double> &beta, 
             double alpha, double power):
     m_lambda(lambda), m_beta(beta), m_concDev(lambda.size(), 0.0), 
     m_alpha(alpha), m_power(power) 
     {
        setCumTime(0.0);

        for(size_t i = 0; i < m_lambda.size(); i++)
        {
            m_conc.push_back(m_beta[i] * m_power / (m_lambda[i] * m_alpha));
        }
     }

	std::vector<double> inHourEqRoots(double rho);
    double power(double rho, double deltaT);
    double getCumTime() {return m_cumTime;}

private: 
    void setCumTime(double t) {m_cumTime = t;}
    void advanceCumTime(double t) {m_cumTime += t;}

    std::vector<double> m_lambda;
    std::vector<double> m_beta;
    std::vector<double> m_concDev;
    std::vector<double> m_conc;
    double m_alpha;
    double m_power;
    double m_cumTime;
};

#endif