#ifndef NUMERIC_TOOLS_H
#define NUMERIC_TOOLS_H

#include <cmath>
#include <limits>
#include <vector>

double bickley3f(double x);
double bickley3f_old(const double x);
double delk(int a, int b);
double delta(const int a, const int b, const std::vector<double> &vec);
bool equality(double x, double y);
bool fplt(double x, double y);
bool fpgt(double x, double y);

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
	return x < y + 10.0 * std::numeric_limits<double>::epsilon();
}

template <typename T>
inline bool is_lower_equal(const T &x, const T &y)
{
	return x < y - 10.0 * std::numeric_limits<double>::epsilon();
}

#endif