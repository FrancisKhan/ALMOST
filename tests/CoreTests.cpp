#include "Kinetics.h"
#include "gtest/gtest.h"
#include "numeric_tools.h"

#include <iostream>

class KineticsTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(KineticsTests, roots)
{	
  std::vector<double> ref = {0.0012229987, -0.014223669, -0.067131758,
                            -0.1925891, -1.0140574, -2.8690312,
                            -13.25309};

	std::vector<double> lambda = {0.0124, 0.0305, 0.111, 0.301, 1.14, 3.01};
  std::vector<double> beta = {0.000215, 0.001424, 0.001274, 0.002568, 0.000748, 0.000273};
  double alpha = 0.0005;
  double rho   = 0.0001;
  double power = 1.0;

  Kinetics kin(lambda, beta, alpha, power);
  std::vector<double> result = kin.inHourEqRoots(rho);

  for(size_t i = 0; i < ref.size(); i++)
  {
     //std::cout << result[i] << std::endl;
     EXPECT_FLOAT_EQ(ref[i], result[i]);
  }
}

TEST_F(KineticsTests, power)
{	
  double ref = 1.011372;

	std::vector<double> lambda = {0.0124, 0.0305, 0.111, 0.301, 1.14, 3.01};
  std::vector<double> beta = {0.000215, 0.001424, 0.001274, 0.002568, 0.000748, 0.000273};
  double alpha  = 0.0005;
  double rho    = 0.0001;
  double power  = 1.0;
  double deltaT = 0.1; 

  Kinetics kin(lambda, beta, alpha, power);
  double result = kin.power(rho, deltaT);

  EXPECT_FLOAT_EQ(ref, result);
}

// CORE: A numerical algorithm to solve the point kinetics equations
// first test rho = (beta / 10.0) * power

TEST_F(KineticsTests, coreTest1)
{	
  double ref = 1.2258961;

  std::vector<double> lambda = {0.0124, 0.0305, 0.111, 0.301, 1.14, 3.01};
  std::vector<double> beta = {0.000215, 0.001424, 0.001274, 0.002568, 0.000748, 0.000273};
	
  double alpha  = 0.0005;
  double power  = 1.0;
  double deltaT = 0.1; 

  Kinetics kin(lambda, beta, alpha, power);

  double betaT = std::accumulate (beta.begin(), beta.end(), 0.0);
  double rho;

  for (unsigned i = 0; i < 25; i++)
  {
    rho   = (betaT / 10.0) * power;
    power = kin.power(rho, deltaT);
  }

  EXPECT_FLOAT_EQ(ref, power);
}

// CORE: A numerical algorithm to solve the point kinetics equations
// second test rho = -(beta / 10.0) * power

TEST_F(KineticsTests, coreTest2)
{	
  double ref = 0.87788737;

  std::vector<double> lambda = {0.0124, 0.0305, 0.111, 0.301, 1.14, 3.01};
  std::vector<double> beta = {0.000215, 0.001424, 0.001274, 0.002568, 0.000748, 0.000273};

  double alpha  = 0.0005;
  double power  = 1.0;
  double deltaT = 0.1; 

  Kinetics kin(lambda, beta, alpha, power);

  double betaT = std::accumulate (beta.begin(), beta.end(), 0.0);
  double rho;

  for (unsigned i = 0; i < 25; i++)
  {
    rho   = - (betaT / 10.0) * power;
    power = kin.power(rho, deltaT);
  }

  EXPECT_FLOAT_EQ(ref, power);
}

// CORE: A numerical algorithm to solve the point kinetics equations
// third test rho = beta * sin(pi * t / 5) 6g

TEST_F(KineticsTests, coreTest3)
{	
  double ref = 22.318512;

  std::vector<double> lambda = {0.0124, 0.0305, 0.111, 0.301, 1.14, 3.01};
  std::vector<double> beta = {0.000215, 0.001424, 0.001274, 0.002568, 0.000748, 0.000273};
  double alpha  = 0.0005;
  double power  = 1.0;
  double deltaT = 0.1; 

  Kinetics kin(lambda, beta, alpha, power);

  double betaT = std::accumulate (beta.begin(), beta.end(), 0.0);
  double rho;

  for (unsigned i = 0; i < 55; i++)
  {
    rho   = betaT * sin(M_PI * i * deltaT / 5.0);
    power = kin.power(rho, deltaT);
  }

  EXPECT_FLOAT_EQ(ref, power);
}

// CORE: A numerical algorithm to solve the point kinetics equations
// third test rho = beta * sin(pi * t / 5) 1g A

TEST_F(KineticsTests, coreTest4)
{	
  double ref = 72.74053;

  std::vector<double> lambda = {0.405249};
  std::vector<double> beta6g = {0.000215, 0.001424, 0.001274, 0.002568, 0.000748, 0.000273};
  double betaDouble = std::accumulate (beta6g.begin(), beta6g.end(), 0.0);
  std::vector<double> beta = {betaDouble};

  double alpha  = 0.0005;
  double power  = 1.0;
  double deltaT = 0.1; 

  Kinetics kin(lambda, beta, alpha, power);

  double rho;

  for (unsigned i = 0; i < 55; i++)
  {
    rho   = betaDouble * sin(M_PI * i * deltaT / 5.0);
    power = kin.power(rho, deltaT);
  }

  EXPECT_FLOAT_EQ(ref, power);
}

// CORE: A numerical algorithm to solve the point kinetics equations
// third test rho = beta * sin(pi * t / 5) 1g B

TEST_F(KineticsTests, coreTest5)
{	
  double ref = 3.377551;

  std::vector<double> lambda = {0.076690};
  std::vector<double> beta6g = {0.000215, 0.001424, 0.001274, 0.002568, 0.000748, 0.000273};
  double betaDouble = std::accumulate (beta6g.begin(), beta6g.end(), 0.0);
  std::vector<double> beta = {betaDouble};

  double alpha  = 0.0005;
  double power  = 1.0;
  double deltaT = 0.1; 

  Kinetics kin(lambda, beta, alpha, power);

  double rho;

  for (unsigned i = 0; i < 55; i++)
  {
    rho   = betaDouble * sin(M_PI * i * deltaT / 5.0);
    power = kin.power(rho, deltaT);
  }

  EXPECT_FLOAT_EQ(ref, power);
}

TEST_F(KineticsTests, coreTest6)
{	
  double ref = 1.343349;

	std::vector<double> lambda = {0.0127, 0.0317, 0.115, 0.311, 1.4, 3.87};
  std::vector<double> beta = {0.000266, 0.001491, 0.001316, 0.002849, 0.000896, 0.000182};
  double alpha  = 0.00002;
  double power  = 1.0;
  double deltaT = 0.1; 

  Kinetics kin(lambda, beta, alpha, power);

  double betaT = std::accumulate (beta.begin(), beta.end(), 0.0);
  double rho;

  for (unsigned i = 0; i < 21; i++)
  {
    rho   = (betaT / 10.0) * i * deltaT;
    power = kin.power(rho, deltaT);
  }

  EXPECT_FLOAT_EQ(ref, power);
}

TEST_F(KineticsTests, coreTest7)
{	
  double ref = 1.339143;

	std::vector<double> lambda = {0.0127, 0.0317, 0.115, 0.311, 1.4, 3.87};
  std::vector<double> beta = {0.000266, 0.001491, 0.001316, 0.002849, 0.000896, 0.000182};
  double alpha  = 0.00002;
  double power  = 1.0;
  double deltaT = 0.01; 

  Kinetics kin(lambda, beta, alpha, power);

  double betaT = std::accumulate (beta.begin(), beta.end(), 0.0);
  double rho;

  for (unsigned i = 0; i < 201; i++)
  {
    rho   = (betaT / 10.0) * i * deltaT;
    power = kin.power(rho, deltaT);
  }

  EXPECT_FLOAT_EQ(ref, power);
}