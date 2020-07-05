#include "gtest/gtest.h"
#include "TestHelper.h"

class CoreIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(CoreIntegrationTests, memTestCORE)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/kinetics1.txt";
  const std::string outputPath = "outputs/Out_kinetics1.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

// CORE: A numerical algorithm to solve the point kinetics equations
TEST_F(CoreIntegrationTests, Kinetics1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/kinetics1.txt";
  const std::string outputPath = "outputs/Out_kinetics1.txt";
  const std::string traceLevel = "DEBUG";

  const double powerRef = 1.339143;

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  
  EXPECT_DOUBLE_EQ(test.getVector("Output power").back(),  powerRef);
}
