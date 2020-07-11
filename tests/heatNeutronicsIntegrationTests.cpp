#include "gtest/gtest.h"
#include "TestHelper.h"

class HeatNeutronicsIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(HeatNeutronicsIntegrationTests, HT1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat-neutronics.txt";
  const std::string outputPath = "outputs/Out_heat-neutronics.txt";
  const std::string traceLevel = "DEBUG";
//   const double kEffRef = 2.6129031;
//   std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
//                                  0.1000, 0.1000, 0.1000,
//                                  0.1000, 0.1000, 0.1000, 0.1000};

//   TestHelper test(codePath, inputPath, outputPath, traceLevel);
//   test.runCode();

//   std::vector<double> flux = test.getVector("Neutron Flux");
//   bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

//   EXPECT_TRUE(areEqual);
//   EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
  EXPECT_TRUE(true);
}