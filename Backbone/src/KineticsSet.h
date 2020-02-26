#ifndef KINECTISSET_H
#define KINECTISSET_H

#include <vector>

class KineticsSet
{
public:
	KineticsSet(){}
    void setAlpha(double alpha) {m_alpha = alpha;}
    void setPower(double power) {m_power = power;}
    void setLambda(std::vector<double> &lambda) {m_lambda = lambda;}
    void setBeta(std::vector<double> &beta) {m_beta = beta;}

    double getAlpha() {return m_alpha;}
    double getPower() {return m_power;}
    std::vector<double> getLambda() {return m_lambda;}
    std::vector<double> getBeta() {return m_beta;}

private:
	double m_alpha;
    double m_power;
    std::vector<double> m_lambda;
    std::vector<double> m_beta;
	
};

#endif