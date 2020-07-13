#ifndef BASECALCULATION_H
#define BASECALCULATION_H

#include "SolverKind.h"

#include <memory>
#include <Eigen/Dense>

class BaseCalculation
{
public:
    static std::shared_ptr<BaseCalculation> 
    setCalculation(std::vector<SolverKind> &solvers);
    
	~BaseCalculation(){}
};

#endif