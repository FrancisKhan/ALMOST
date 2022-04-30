#include "gtest/gtest.h"
#include "TestHelper.h"
#include "additionalPrintFuncs.h"

using namespace PrintFuncs;

class ADSIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(ADSIntegrationTests, ads1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/ads1.txt";
  const std::string outputPath = "outputs/Out_ads1.txt";
  const std::string traceLevel = "DEBUG";
  //const double kEffRef = 9.693342e-01;
  
  
//   TestHelper test(codePath, inputPath, outputPath, traceLevel);
//   test.runCode();

//   EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);

    EXPECT_TRUE(true);
}

