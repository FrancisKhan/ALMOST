#include "BaseDiffusionCode.h"

using namespace Eigen;

VectorXd BaseDiffusionCode::getInterfaceThermalConductivities()
{
    VectorXd materialLambda  = m_mesh.getThermalConductivities();
    VectorXd interfaceLambda = m_mesh.getThermalConductivities();
    VectorXd cellSizes       = m_mesh.getCellSizes("m");

    for(int i = 1; i < materialLambda.size() - 1; i++)
    {
        double f = cellSizes(i - 1) / (cellSizes(i) + cellSizes(i - 1));

        interfaceLambda(i) = 1.0 / ((1.0 - f) / materialLambda(i - 1) +
                             f / materialLambda(i));
    }

    return interfaceLambda;
}

void BaseDiffusionCode::solveSystem(MatrixXd &T, VectorXd &source)
{
    VectorXd temperatures = VectorXd::Zero(source.size());
    temperatures = T.colPivHouseholderQr().solve(source);
    m_mesh.setTemperatures(temperatures);
}