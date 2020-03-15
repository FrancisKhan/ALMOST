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
    void setReactivities(std::vector<double> &reacts) {m_reactivities = reacts;}
    void setTimes(std::vector<double> &times) {m_times = times;}

    double getAlpha() {return m_alpha;}
    double getPower() {return m_power;}
    std::vector<double> getLambda() {return m_lambda;}
    std::vector<double> getBeta() {return m_beta;}
    std::vector<double> getReactivities() {return m_reactivities;}
    std::vector<double> getTimes() {return m_times;}

private:
	double m_alpha;
    double m_power;
    std::vector<double> m_lambda;
    std::vector<double> m_beta;
    std::vector<double> m_reactivities;
    std::vector<double> m_times;
	
};

#endif