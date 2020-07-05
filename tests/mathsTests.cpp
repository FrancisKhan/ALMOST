#include <iostream>

#include "gtest/gtest.h"
#include "numeric_tools.h"

using namespace Numerics;

TEST(bickey, bickeyTests)
{
	EXPECT_DOUBLE_EQ(bickley3f(0.97612246652610635), 0.24447301841277816);
	EXPECT_DOUBLE_EQ(bickley3f(0.25237528469791648), 0.57412250598751469);
    EXPECT_DOUBLE_EQ(bickley3f(1.1481454791121939),  0.2006952223249025);
	EXPECT_DOUBLE_EQ(bickley3f(1.8330029835349728),  0.092687656082251893);
} 

TEST(delk, delkTests)
{
    EXPECT_DOUBLE_EQ(delk(1, 1), 1.0);
	EXPECT_DOUBLE_EQ(delk(0, 0), 1.0);
	EXPECT_DOUBLE_EQ(delk(-1, -1), 1.0);
	EXPECT_DOUBLE_EQ(delk(0, 1), 0.0);
	EXPECT_DOUBLE_EQ(delk(1, 0), 0.0);
	EXPECT_DOUBLE_EQ(delk(-1, 0), 0.0);
}

TEST(multPolyTests, test1)
{
    std::vector<double> ref = {1, 2, 4, 0};

	std::vector<double> a = {1, 0}; 
	std::vector<double> b = {1, 2, 4}; 

	std::vector<double> result = multiply_poly(a, b);

	bool areEqual = std::equal(ref.begin(), ref.end(), result.begin());
    EXPECT_TRUE(areEqual);
}

TEST(multPolyTests, test2)
{
    std::vector<double> ref = {5, 10, 30, 26, 52, 24};

	std::vector<double> a = {5, 0, 10, 6}; 
	std::vector<double> b = {1, 2, 4}; 

	std::vector<double> result = multiply_poly(a, b);

	bool areEqual = std::equal(ref.begin(), ref.end(), result.begin());
    EXPECT_TRUE(areEqual);
}

TEST(multPolyTests, test3)
{
    std::vector<double> ref = {0, 5, 1, 10, 6};

	std::vector<double> a = {5, 1, 10, 6}; 
	std::vector<double> b = {0, 1}; 

	std::vector<double> result = multiply_poly(a, b);

	bool areEqual = std::equal(ref.begin(), ref.end(), result.begin());
    EXPECT_TRUE(areEqual);
}

TEST(ProdPoly, test1)
{
    std::vector<double> ref = {6, 11, 6, 1};

	std::vector<double> a = {1, 2, 3}; 

	std::vector<double> result = prod_poly(a);

	bool areEqual = std::equal(ref.begin(), ref.end(), result.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, plusEqual)
{
    std::vector<double> ref = {5, 7, 9};

	std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {4, 5, 6}; 

    a += b;

	bool areEqual = std::equal(ref.begin(), ref.end(), a.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, minusEqual)
{
    std::vector<double> ref = {-3, -3, -3};

	std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {4, 5, 6}; 

    a -= b;

	bool areEqual = std::equal(ref.begin(), ref.end(), a.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, plus1)
{
    std::vector<double> ref = {5, 7, 9};

	std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {4, 5, 6};
	std::vector<double> c = {0, 0, 0}; 

    c = a + b;

	bool areEqual = std::equal(ref.begin(), ref.end(), c.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, plus2)
{
	std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {4, 5};
	std::vector<double> c = {0, 0, 0}; 

	try 
	{
        c = a + b;
        FAIL() << "Expected length_error";
    }
	catch(std::length_error const & err) 
	{
        EXPECT_EQ(err.what(),std::string("vectors have different lengths"));
    }
    catch(...) 
	{
        FAIL() << "Expected std::length_error";
    }
}

TEST(vectorOpOverloading, minus)
{
    std::vector<double> ref = {-3, -3, -3};

	std::vector<double> a = {1, 2, 3};
    std::vector<double> b = {4, 5, 6};
	std::vector<double> c = {0, 0, 0}; 

    c = a - b;

	bool areEqual = std::equal(ref.begin(), ref.end(), c.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, multiplication)
{
    std::vector<double> ref = {2.5, 5.0, 7.5};

	std::vector<double> a = {1, 2, 3};
	std::vector<double> b; 

	double m = 2.5;

    b = a * m;

	bool areEqual = std::equal(ref.begin(), ref.end(), b.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, division1)
{
    std::vector<double> ref = {2.0, 4.0, 6.0};

	std::vector<double> a = {1, 2, 3};
	std::vector<double> b; 

	double m = 0.5;

    b = a / m;

	bool areEqual = std::equal(ref.begin(), ref.end(), b.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, division2)
{
    std::vector<double> a = {1, 2, 3};
	std::vector<double> b; 

	double m = 0.0;

	try 
	{
        b = a / m;
        FAIL() << "Expected std::overflow_error";
    }
	catch(std::overflow_error const & err) 
	{
        EXPECT_EQ(err.what(),std::string("division by zero"));
    }
    catch(...) 
	{
        FAIL() << "Expected std::overflow_error";
    }
}

TEST(vectorOpOverloading, multEqual)
{
    std::vector<double> ref = {0.5, 1.0, 1.5};

	std::vector<double> a = {1, 2, 3};
    double m = 0.5; 

    a *= m;

	bool areEqual = std::equal(ref.begin(), ref.end(), a.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, divEqual1)
{
    std::vector<double> ref = {2.0, 4.0, 6.0};

	std::vector<double> a = {1, 2, 3};
    double d = 0.5; 

    a /= d;

	bool areEqual = std::equal(ref.begin(), ref.end(), a.begin());
    EXPECT_TRUE(areEqual);
}

TEST(vectorOpOverloading, divEqual2)
{
    std::vector<double> a = {1, 2, 3};

	double d = 0.0;

	try 
	{
        a /= d;
        FAIL() << "Expected std::overflow_error";
    }
	catch(std::overflow_error const & err) 
	{
        EXPECT_EQ(err.what(),std::string("division by zero"));
    }
    catch(...) 
	{
        FAIL() << "Expected std::overflow_error";
    }
}

TEST(polyRoots, test1)
{
    std::vector<double> ref = {-0.5, -0.5};
	std::vector<double> a = {1.0, 1.0, 1.0};

    std::vector<double> result = poly_roots(a);

    bool areEqual = std::equal(ref.begin(), ref.end(), result.begin());
    EXPECT_TRUE(areEqual);
}

TEST(polyRoots, test2)
{
    std::vector<double> ref = {-0.25, -0.25};
	std::vector<double> a = {1.0, 1.0, 2.0};

    std::vector<double> result = poly_roots(a);

    bool areEqual = std::equal(ref.begin(), ref.end(), result.begin());
    EXPECT_TRUE(areEqual);
}