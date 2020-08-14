#ifndef NUMERIC_TOOLS_H
#define NUMERIC_TOOLS_H

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>

#include "Output.h"

#include <unsupported/Eigen/CXX11/Tensor>
#include <Eigen/Dense>
#include <functional>
#include <exception>

#include <limits>
#include <vector>

namespace Numerics
{
    typedef Eigen::Tensor<double, 2> Tensor2d;
    typedef Eigen::Tensor<double, 3> Tensor3d;
    typedef Eigen::Tensor<double, 4> Tensor4d;

    double bickley3f(double x);
    double bickley3f_old(const double x);
    double delk(int a, int b);

    void diagonalDominanceCheck(Eigen::MatrixXd &matrix);

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

    template <typename T>
    inline Eigen::VectorXd operator-(const Eigen::VectorXd& a, const T m)
    {
        Eigen::VectorXd result = Eigen::VectorXd::Zero(a.size());
        std::transform(a.begin(), a.end(), result.begin(), [m](auto i){return i - m;});
        return result;
    }

    template <typename T>
    inline Eigen::VectorXd operator+(const Eigen::VectorXd& a, const T p)
    {
        Eigen::VectorXd result = Eigen::VectorXd::Zero(a.size());
        std::transform(a.begin(), a.end(), result.begin(), [p](auto i){return i + p;});
        return result;
    }

    template<typename T>
    std::vector<T> slice(std::vector<T> const &v, int m, int n) 
    {
       auto first = v.begin() + m;
       auto last = v.begin() + n + 1;
       std::vector<T> vector(first, last);
       return vector;
    }

    Eigen::VectorXd tridiag_solver(const Eigen::VectorXd &a, 
                                   const Eigen::VectorXd &b, 
                  	               const Eigen::VectorXd &c, 
                                   const Eigen::VectorXd &d);
}

#endif