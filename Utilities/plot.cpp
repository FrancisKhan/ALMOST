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

    void plotEigenVectorXd(const VectorXd& xx, const VectorXd& vec, PlotKind kind)
	{
        // the vector is empty!
        if(is_equal(vec.minCoeff(), 0.0)) return;

        Vec x = toSciplotVec(xx);

        Plot plot;

        std::string inputName = out.getInputNameNoExt();

        plot.palette("set2");

        plot.xlabel("x [m]");

        if(kind == PlotKind::TEMPERATURE)
            plot.ylabel("Temperature [C]");
        else if(kind == PlotKind::POWERDENSITY)
            plot.ylabel("Thermal Power Density [W/m3]");
        else
            plot.ylabel("");

        Vec y = toSciplotVec(vec);

        plot.drawCurve(x, y).label("").lineWidth(2);

        std::string fileName = inputName + "_" + get_plot_name(kind) + ".pdf";
        plot.save(fileName);
	}

    void plotEigenMatrixXd(const VectorXd& xx, const MatrixXd& mat, PlotKind kind)
	{
        // the matrix is empty!
        if(is_equal(mat.minCoeff(), 0.0)) return;

        std::valarray<double> y(0.0, mat.cols());

        Vec x = toSciplotVec(xx);

        std::vector<Plot> plots;
        plots.resize(mat.rows());

        std::string inputName = out.getInputNameNoExt();

        for(auto e = 0; e < mat.rows(); e++)
        {
            plots[e].palette("set2");

            plots[e].xlabel("x [m]");

            plots[e].ylabel("Total Flux [1/cm2/s]");

            for(auto m = 0; m < mat.cols(); m++)
                y[m] = mat(e, m);

            plots[e].drawCurve(x, y).label("").lineWidth(2);

            std::string fileName = inputName + "_" + get_plot_name(kind) + "_" + std::to_string(e + 1) + ".pdf";
            plots[e].save(fileName);
        }
	}

	void plot3DEigenTensor(const VectorXd& xx, const Tensor3d& t, PlotKind kind, unsigned nModes)
	{
        // the tensor is empty!
        if(t.dimension(2) == 0) return;

        std::valarray<double> y(0.0, t.dimension(1));

        Vec x = toSciplotVec(xx);

        std::vector<Plot> plots;
        plots.resize(t.dimension(0));

        std::string inputName = out.getInputNameNoExt();

        for(auto e = 0; e < t.dimension(0); e++)
        {
            plots[e].palette("set2");

            plots[e].xlabel("x [m]");

            if(kind == PlotKind::NEUTRONFLUX)
                plots[e].ylabel("Neutron Flux [1/cm2/s]");
            else if(kind == PlotKind::ADJOINTFLUX)
                plots[e].ylabel("Adjoint Flux [arbitrary]");
            else
                plots[e].ylabel("");

            unsigned modesLimit = nModes == std::numeric_limits<unsigned>::max() ? t.dimension(2) : nModes;
            if(modesLimit > t.dimension(2)) modesLimit = t.dimension(2);

            for(auto n = 0; n < modesLimit; n++)
            {
                 for(auto m = 0; m < t.dimension(1); m++)
                    y[m] = t(e, m, n);

                std::string label = n == 0 ? "fundamental" : std::to_string(n+1);
                plots[e].drawCurve(x, y).label(label).lineWidth(2);
            }

            std::string fileName = inputName + "_" + get_plot_name(kind) + "_" + std::to_string(e + 1) + ".pdf";
            plots[e].save(fileName);
        }
	}

    bool plotsContain(const std::vector<PlotKind>& vec, const PlotKind& kind)
    {
        if (std::find(vec.begin(), vec.end(), kind) != vec.end())
            return true;
        else
            return false;
    }
}


