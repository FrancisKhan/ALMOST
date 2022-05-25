#ifndef PLOT_H
#define PLOT_H

#include "numeric_tools.h"
#include <sciplot/sciplot.hpp>

namespace PlotFuncs
{
    void plot3DNeutronFluxes(const Eigen::VectorXd& xx, const Numerics::Tensor3d& t, 
    unsigned nModes = std::numeric_limits<unsigned>::max());

    sciplot::Vec fromTensor1dToSciplotVec(const Numerics::Tensor1d& t);
    sciplot::Vec fromVectorXdToSciplotVec(const Eigen::VectorXd& vec);
    sciplot::Vec fromSTDVecToSciplotVec(const std::vector<double>& stdVec);
}

#endif