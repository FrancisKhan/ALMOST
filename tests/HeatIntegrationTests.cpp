#include "gtest/gtest.h"
#include "TestHelper.h"

class HeatIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(HeatIntegrationTests, memTest)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/steady-stateSL.txt";
  const std::string outputPath = "outputs/Out_steady-stateSL.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

TEST_F(HeatIntegrationTests, steadyStateSL)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/steady-stateSL.txt";
  const std::string outputPath = "outputs/Out_steady-stateSL.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {12.0000, 16.0000, 20.0000,
                                 24.0000, 28.0000};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

TEST_F(HeatIntegrationTests, steadyStateConvRightSL)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/steady-state_conv_rightSL.txt";
  const std::string outputPath = "outputs/Out_steady-state_conv_rightSL.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {1.027513e+01, 1.082538e+01, 1.137564e+01,
                                 1.192590e+01, 1.247615e+01, 1.302641e+01, 
                                 1.357666e+01, 1.412692e+01, 1.467718e+01, 
                                 1.522743e+01, 1.577769e+01, 1.632794e+01, 
                                 1.687820e+01, 1.742845e+01, 1.797871e+01, 
                                 1.852897e+01, 1.907922e+01, 1.962948e+01, 
                                 2.017973e+01, 2.072999e+01, 2.128025e+01, 
                                 2.183050e+01, 2.238076e+01, 2.293101e+01, 
                                 2.348127e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

TEST_F(HeatIntegrationTests, steadyStateConvLeftSL)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/steady-state_conv_leftSL.txt";
  const std::string outputPath = "outputs/Out_steady-state_conv_leftSL.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {2.348127e+01, 2.293101e+01, 2.238076e+01, 
                                 2.183050e+01, 2.128025e+01, 2.072999e+01, 
                                 2.017973e+01, 1.962948e+01, 1.907922e+01, 
                                 1.852897e+01, 1.797871e+01, 1.742845e+01,
                                 1.687820e+01, 1.632794e+01, 1.577769e+01,
                                 1.522743e+01, 1.467718e+01, 1.412692e+01,
                                 1.357666e+01, 1.302641e+01, 1.247615e+01, 
                                 1.192590e+01, 1.137564e+01, 1.082538e+01, 
                                 1.027513e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}