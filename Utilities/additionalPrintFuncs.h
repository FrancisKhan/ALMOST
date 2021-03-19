#ifndef ADDITIONALPRINTFUNCS_H
#define ADDITIONALPRINTFUNCS_H

#include "numeric_tools.h"

namespace PrintFuncs
{
    void printMatrix(Numerics::Tensor3d A, Output output, TraceLevel level, std::string str);
    void printMatrix(Eigen::MatrixXd A, Output output, TraceLevel level, bool asVector = false);
    void printVector(Eigen::VectorXd vec, Output output, TraceLevel level, bool isVertical = true, bool endline = true);
    void printVector(std::vector<std::string> vec, Output output, TraceLevel level, bool isVertical = true);
    void printVector(std::vector<double> vec, Output output, TraceLevel level);

    std::string stringFormat(double number, std::string format);
    std::string stringFormat(unsigned number, std::string format);
    std::string stringFormat(std::string numberStr, std::string format);

    bool isFloat(const std::string& s);
    bool isInteger(const std::string& s);
    bool isString(const std::string& s);
}

#endif