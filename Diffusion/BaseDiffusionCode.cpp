#include "BaseDiffusionCode.h"

using namespace Eigen;

VectorXd BaseDiffusionCode::getInterfaceDiffusionConstants()
{
    VectorXd materialD  = m_mesh.getThermalConductivities();
    VectorXd interfaceD = m_mesh.getThermalConductivities();
    VectorXd cellSizes  = m_mesh.getCellSizes("m");

    for(int i = 1; i < materialD.size() - 1; i++)
    {
        double f = cellSizes(i - 1) / (cellSizes(i) + cellSizes(i - 1));

        interfaceD(i) = 1.0 / ((1.0 - f) / materialD(i - 1) +
                        f / materialD(i));
    }

    return interfaceD;
}

void BaseDiffusionCode::solveSystem(MatrixXd &T, VectorXd &source)
{
    VectorXd temperatures = VectorXd::Zero(source.size());
    temperatures = T.colPivHouseholderQr().solve(source);
    m_mesh.setTemperatures(temperatures);
}