#include "BaseDiffusionCode.h"
#include "SphDiffusionCode.h"
#include "numeric_tools.h"

using namespace Eigen;
using namespace PrintFuncs;

MatrixXd SphDiffusionCode::calcMMatrix()
{
    MatrixXd T = MatrixXd::Zero(m_cells, m_cells);

    // m_temperatures     = m_mesh.getTemperatures("C");
    // m_heatSources      = m_mesh.getHeatSources();
    // VectorXd lambda    = getInterfaceDiffusionConstants();
    // VectorXd cellSizes = m_mesh.getCellSizes("m");

    // for(int i = 0; i < m_cells; i++)
    // {
    //     if(i == 0)
    //     {
    //         T(i, i)     = + lambda[i + 1] * pow(m_radii(i + 1), 2) / cellSizes(i + 1);
    //         T(i, i + 1) = - lambda[i + 1] * pow(m_radii(i + 1), 2) / cellSizes(i + 1);
    //     }
    //     else if(i == m_cells - 1)
    //     {
    //         T(i, i)     = + lambda[i] * pow(m_radii(i), 2) / cellSizes(i - 1);
    //         T(i, i - 1) = - lambda[i] * pow(m_radii(i), 2) / cellSizes(i - 1);
    //     }
    //     else
    //     {
    //         T(i, i)     = + lambda[i] * pow(m_radii(i), 2) / cellSizes(i - 1) + 
    //                         lambda[i + 1] * pow(m_radii(i + 1), 2) / cellSizes(i + 1);

    //         T(i, i - 1) = - lambda[i] * pow(m_radii(i), 2) / cellSizes(i - 1);
    //         T(i, i + 1) = - lambda[i + 1] * pow(m_radii(i + 1), 2) / cellSizes(i + 1);
    //     }
    // }

    return T;
}