#include "KineticsSolver.h"
#include "KineticsSet.h"
#include "Kinetics.h"

void KineticsSolver::solve(int max_iter_number, double accuracy)
{
    KineticsSet kinSet = m_reactor.getKineticsSet();

    std::vector<double> lambda = kinSet.getLambda();
    std::vector<double> beta   = kinSet.getBeta();
	
	double alpha = kinSet.getAlpha();
    double power = kinSet.getPower();

	Kinetics kin(lambda, beta, alpha, power);

	std::vector<double> rhos  = kinSet.getReactivities();
    std::vector<double> times = kinSet.getTimes();

	kin.power(rhos, times);
}