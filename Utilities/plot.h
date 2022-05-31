#ifndef PLOT_H
#define PLOT_H

#include "Input.h"
#include "numeric_tools.h"
#include <sciplot/sciplot.hpp>

namespace PlotFuncs
{
    void plot3DEigenTensor(const Eigen::VectorXd& xx, const Numerics::Tensor3d& t, 
                           PlotKind kind, unsigned nModes = std::numeric_limits<unsigned>::max());

    void plotEigenMatrixXd(const Eigen::VectorXd& xx, const Eigen::MatrixXd& mat, PlotKind kind);

    void plotEigenVectorXd(const Eigen::VectorXd& xx, const Eigen::VectorXd& vec, PlotKind kind);

    sciplot::Vec toSciplotVec(const Numerics::Tensor1d& t);
    sciplot::Vec toSciplotVec(const Eigen::VectorXd& vec);
    sciplot::Vec toSciplotVec(const std::vector<double>& stdVec);

    void generatePlots(const std::vector<PlotKind>& vec, Reactor& reactor);
    bool plotsContain(const std::vector<PlotKind>& vec, const PlotKind& kind);
}

#endif