#ifndef BASECALCULATION_H
#define BASECALCULATION_H

#include "Reactor.h"
#include "Library.h"
#include "SolverKind.h"
#include "AbstractSolver.h"

#include <memory>
#include <variant>

class BaseCalculation
{
public:
    static std::shared_ptr<BaseCalculation> setCalculation(Reactor &reactor, 
        Library &library, std::vector<SolverKind> &solvers);

	virtual ~BaseCalculation(){}

	virtual void solve(int max_iter_number = 20, double accuracy = 0.000001) = 0;

protected:
    virtual double getDifference(std::variant<double, Eigen::VectorXd, Eigen::MatrixXd> &New,
                                 std::variant<double, Eigen::VectorXd, Eigen::MatrixXd> &Old);
};

#endif