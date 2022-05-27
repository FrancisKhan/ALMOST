#include "plot.h"
#include "Output.h"

using namespace sciplot;
using namespace Numerics;
using namespace Eigen;

namespace PlotFuncs
{
    Vec toSciplotVec(const std::vector<double>& stdVec)
    {
        return std::valarray(stdVec.data(), stdVec.size());
    }

    Vec toSciplotVec(const VectorXd& vec)
    {
        std::vector<double> stdVec(vec.data(), vec.data() + vec.size());
        return toSciplotVec(stdVec);
    }

    Vec toSciplotVec(const Tensor1d& t)
    {
        Eigen::VectorXd eigenVec = fromTensor1dToVectorXd(t);
        return toSciplotVec(eigenVec);
    }

	void plot3DNeutronFluxes(const VectorXd& xx, const Tensor3d& t, unsigned nModes)
	{
        std::valarray<double> y(0.0, t.dimension(1));

        Vec x = toSciplotVec(xx);

        std::vector<Plot> plots;
        plots.resize(t.dimension(0));

        std::string inputName = out.getInputNameNoExt();

        for(auto e = 0; e < t.dimension(0); e++)
        {
            plots[e].palette("set2");

            plots[e].xlabel("x [m]");
            plots[e].ylabel("Neutron Flux [1/cm2/s]");

            unsigned modesLimit = nModes == std::numeric_limits<unsigned>::max() ? t.dimension(2) : nModes;
            if(modesLimit > t.dimension(2)) modesLimit = t.dimension(2);

            for(auto n = 0; n < modesLimit; n++)
            {
                 for(auto m = 0; m < t.dimension(1); m++)
                    y[m] = t(e, m, n);

                std::string label = n == 0 ? "fundamental" : "";
                plots[e].drawCurve(x, y).label(label).lineWidth(2);
            }

            std::string fileName = inputName + "_EnergyGroup" + std::to_string(e + 1) + ".pdf";
            plots[e].save(fileName);
        }
	}
}
