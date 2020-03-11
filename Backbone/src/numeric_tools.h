#ifndef NUMERIC_TOOLS_H
#define NUMERIC_TOOLS_H

#include "Output.h"

#include <unsupported/Eigen/CXX11/Tensor>
#include <Eigen/Dense>
#include <functional>
#include <exception>
#include <cmath>
#include <limits>
#include <vector>

typedef Eigen::Tensor<double, 3> Tensor3d;
typedef Eigen::Tensor<double, 4> Tensor4d;

double bickley3f(double x);
double bickley3f_old(const double x);
double delk(int a, int b);
bool equality(double x, double y);
bool fplt(double x, double y);
bool fpgt(double x, double y);
void printMatrix(Tensor3d A, Output output, TraceLevel level, std::string str);
void printMatrix(Eigen::MatrixXd A, Output output, TraceLevel level);
void printVector(Eigen::VectorXd vec, Output output, TraceLevel level);
void printVector(std::vector<std::string> vec, Output output, TraceLevel level);
void printVector(std::vector<double> vec, Output output, TraceLevel level);
void diagonalDominanceCheck(Eigen::MatrixXd &matrix);
void sourceIteration(Eigen::MatrixXd &Mmatrix, Eigen::MatrixXd &Fmatrix, 
                     int max_iter_number, double accuracy);

std::vector<double> multiply_poly(std::vector<double> &a, 
                                  std::vector<double> &b);
std::vector<double> prod_poly(std::vector<double> &a);
std::vector<double> prod_poly_i(std::vector<double> &a, size_t i);
std::vector<double> poly_roots(std::vector<double> &p);

template <typename T>
inline bool is_equal(const T &x, const T &y)
{
	return fabs(x - y) < 10.0 * std::numeric_limits<double>::epsilon();
}

template <typename T>
inline bool not_equal(const T &x, const T &y)
{
	return !is_equal(x, y);
}

template <typename T>
inline bool is_greater(const T &x, const T &y)
{
	return x > y + 10.0 * std::numeric_limits<double>::epsilon();
}

template <typename T>
inline bool is_greater_equal(const T &x, const T &y)
{
	return x > y - 10.0 * std::numeric_limits<double>::epsilon();
}

template <typename T>
inline bool is_lower(const T &x, const T &y)
{
	return x < y - 10.0 * std::numeric_limits<double>::epsilon();
}

template <typename T>
inline bool is_lower_equal(const T &x, const T &y)
{
	return x < y + 10.0 * std::numeric_limits<double>::epsilon();
}

template <typename T>
inline std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b)
{
    if(a.size() != b.size())
        throw std::length_error("vectors have different lengths");

    std::vector<T> result;
    result.reserve(a.size());

    std::transform(a.begin(), a.end(), b.begin(), 
                   std::back_inserter(result), std::plus<T>());
    return result;
}

template <typename T>
inline std::vector<T> operator-(const std::vector<T>& a, const std::vector<T>& b)
{
    if(a.size() != b.size())
        throw std::length_error("vectors have different lengths");

    std::vector<T> result;
    result.reserve(a.size());

    std::transform(a.begin(), a.end(), b.begin(), 
                   std::back_inserter(result), std::minus<T>());
    return result;
}

template <typename T>
inline std::vector<T> operator*(const std::vector<T>& a, const T m)
{
    std::vector<T> result;
    result.resize(a.size());

    std::transform(a.begin(), a.end(), result.begin(), [m](auto i){return i * m;});
    return result;
}

template <typename T>
inline std::vector<T> operator/(const std::vector<T>& a, const T d)
{
    if(is_equal(d, 0.0))
        throw std::overflow_error("division by zero");

    std::vector<T> result;
    result.resize(a.size());

    std::transform(a.begin(), a.end(), result.begin(), [d](auto i){return i / d;});
    return result;
}

template <typename T>
inline std::vector<T>& operator+=(std::vector<T> &a, const std::vector<T>& b)
{
    if(a.size() != b.size())
        throw std::length_error("vectors have different lengths");

    for (size_t i = 0; i < a.size(); i++)
        a[i] += b[i];

    return a;
}

template <typename T>
inline std::vector<T>& operator-=(std::vector<T> &a, const std::vector<T>& b)
{
    if(a.size() != b.size())
        throw std::length_error("vectors have different lengths");

    for (size_t i = 0; i < a.size(); i++)
        a[i] -= b[i];

    return a;
}

template <typename T>
inline std::vector<T>& operator*=(std::vector<T> &a, const T m)
{
    
    for (size_t i = 0; i < a.size(); i++)
        a[i] *= m;

    return a;
}

template <typename T>
inline std::vector<T>& operator/=(std::vector<T> &a, const T d)
{
    if(is_equal(d, 0.0))
        throw std::overflow_error("division by zero");

    for (size_t i = 0; i < a.size(); i++)
        a[i] /= d;

    return a;
}

bool isFloat(const std::string& s);
bool isInteger(const std::string& s);
bool isString(const std::string& s);

#endif