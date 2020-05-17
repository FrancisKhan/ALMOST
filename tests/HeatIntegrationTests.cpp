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