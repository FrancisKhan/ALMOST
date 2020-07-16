#include "BaseCalculation.h"
#include "SingleCalculation.h"
#include "DoubleCalculation.h"

using namespace Eigen;

std::shared_ptr<BaseCalculation> BaseCalculation::setCalculation(Reactor &reactor, 
        Library &library, std::vector<SolverKind> &solvers)
{
  if (solvers.size() == 1)
  {
    return std::make_shared<SingleCalculation>(reactor, library, solvers[0]);
  }
  else if (solvers.size() == 2)
  {
    return std::make_shared<DoubleCalculation>(reactor, library, solvers);
  }
  else
  {
	  return std::shared_ptr<BaseCalculation>(nullptr);
  }
}

double BaseCalculation::getDifference(std::variant<double, VectorXd, MatrixXd> &New,
                                      std::variant<double, VectorXd, MatrixXd> &Old)
{
	if(std::get_if<double>(&New))
    {
		return fabs((std::get<double>(New) - std::get<double>(Old)) / 
		       std::get<double>(New));
	}
    else if(std::get_if<VectorXd>(&New))
	{
		VectorXd diffV = (std::get<VectorXd>(New) - std::get<VectorXd>(Old));
		diffV.cwiseQuotient(std::get<VectorXd>(New));
		return diffV.cwiseAbs().maxCoeff();
	}
	else
	{
		MatrixXd diffV = (std::get<MatrixXd>(New) - std::get<MatrixXd>(Old));
		diffV.cwiseQuotient(std::get<MatrixXd>(New));
		return diffV.cwiseAbs().maxCoeff();
	}
}