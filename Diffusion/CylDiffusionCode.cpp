#include "BaseDiffusionCode.h"
#include "CylDiffusionCode.h"
#include "numeric_tools.h"

using namespace Eigen;
using namespace PrintFuncs;

MatrixXd CylDiffusionCode::calcMMatrix()
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
    //         T(i, i)     = + lambda[i + 1] * m_radii(i + 1) / cellSizes(i + 1);
    //         T(i, i + 1) = - lambda[i + 1] * m_radii(i + 1) / cellSizes(i + 1);
    //     }
    //     else if(i == m_cells - 1)
    //     {
    //         T(i, i)     = + lambda[i] * m_radii(i) / cellSizes(i - 1);
    //         T(i, i - 1) = - lambda[i] * m_radii(i) / cellSizes(i - 1);
    //     }
    //     else
    //     {
    //         T(i, i)     = + lambda[i] * m_radii(i) / cellSizes(i - 1) + 
    //                         lambda[i + 1] * m_radii(i + 1) / cellSizes(i + 1);

    //         T(i, i - 1) = - lambda[i] * m_radii(i) / cellSizes(i - 1);
    //         T(i, i + 1) = - lambda[i + 1] * m_radii(i + 1) / cellSizes(i + 1);
    //     }
    // }

    return T;
}