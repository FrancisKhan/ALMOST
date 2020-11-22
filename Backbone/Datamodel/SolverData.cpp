#include "SolverData.h"
#include "Output.h"

#include <algorithm>

using namespace Eigen;

void SolverData::setHeatBoundaryConditions(std::vector<std::string> &values)
{
    m_heatBoundaryConditions = VectorXd::Zero(values.size() - 1);

    std::transform(values.begin() + 1, values.end(), m_heatBoundaryConditions.begin(), 
                   [](std::string &i){return std::stod(i);});
}

std::pair<VectorXd, VectorXd> SolverData::getHeatBoundaryConditions()
{
	VectorXd left(3);
	VectorXd right(3);

	if (m_heatBoundaryConditions.size() == 3)
	{
		left << 0.0, 1.0, 0.0; // reflective boundary

	    right(0) = m_heatBoundaryConditions(0);
		right(1) = m_heatBoundaryConditions(1);
		right(2) = m_heatBoundaryConditions(2);

	}
	else if(m_heatBoundaryConditions.size() == 6)
	{
		left(0) = m_heatBoundaryConditions(0);
		left(1) = m_heatBoundaryConditions(1);
		left(2) = m_heatBoundaryConditions(2);

		right(0) = m_heatBoundaryConditions(3);
		right(1) = m_heatBoundaryConditions(4);
		right(2) = m_heatBoundaryConditions(5);
	}
	else
	{
		out.print(TraceLevel::CRITICAL, "Error with getHeatBoundaryConditions()");
		exit(-1);
	}

	return std::make_pair(left, right);
}