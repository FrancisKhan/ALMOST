#include "gtest/gtest.h"
#include "TestHelper.h"

class PlotIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(PlotIntegrationTests, neutronfluxDiff1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/plotDiff1.txt";
  const std::string outputPath = "outputs/Out_plotDiff1.txt";
  const std::string traceLevel = "DEBUG";

  const std::string plotName  = "plotDiff1_neutronflux_1.pdf";
  
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  EXPECT_TRUE(TestHelper::fileExists(plotName));
}

TEST_F(PlotIntegrationTests, adjointfluxDiff22)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/plotDiff22.txt";
  const std::string outputPath = "outputs/Out_plotDiff22.txt";
  const std::string traceLevel = "DEBUG";

  const std::string plotName1  = "plotDiff22_adjointflux_1.pdf";
  const std::string plotName2  = "plotDiff22_adjointflux_2.pdf";
  
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  bool files = TestHelper::fileExists(plotName1) && TestHelper::fileExists(plotName2);

  EXPECT_TRUE(files);
}

TEST_F(PlotIntegrationTests, neutronfluxCPM2)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/plotCPM2.txt";
  const std::string outputPath = "outputs/Out_plotCPM2.txt";
  const std::string traceLevel = "DEBUG";

  const std::string plotName  = "plotCPM2_neutronflux_1.pdf";
  
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  EXPECT_TRUE(TestHelper::fileExists(plotName));
}

TEST_F(PlotIntegrationTests, temperatureHeat1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/plotHeat1.txt";
  const std::string outputPath = "outputs/Out_plotHeat1.txt";
  const std::string traceLevel = "DEBUG";

  const std::string plotName  = "plotHeat1_temperature.pdf";
  
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  EXPECT_TRUE(TestHelper::fileExists(plotName));
}
