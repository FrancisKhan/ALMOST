#include "gtest/gtest.h"
#include "TestHelper.h"

class CPMHeatIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST_F(CPMHeatIntegrationTests, coupledTest1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMHeatTest1.txt";
  const std::string outputPath = "outputs/Out_CPMHeatTest1.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 9.444236e-01;

  std::vector<double> refFlux = {7.432935e-02, 9.198792e-02, 1.044142e-01,
                                 1.125939e-01, 1.166746e-01, 1.166746e-01, 
                                 1.125939e-01, 1.044142e-01, 9.198792e-02, 
                                 7.432935e-02};

  std::vector<double> refTemp = {3.421300e+01, 4.138640e+01, 4.700962e+01, 
                                 5.087326e+01, 5.283946e+01, 5.283946e+01, 
                                 5.087326e+01, 4.700962e+01, 4.138640e+01, 
                                 3.421300e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(CPMHeatIntegrationTests, coupledTest2)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMHeatTest2.txt";
  const std::string outputPath = "outputs/Out_CPMHeatTest2.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 9.444236e-01;

  std::vector<double> refFlux = {7.432935e-02, 9.198792e-02, 1.044142e-01,
                                 1.125939e-01, 1.166746e-01, 1.166746e-01, 
                                 1.125939e-01, 1.044142e-01, 9.198792e-02, 
                                 7.432935e-02};

  std::vector<double> refTemp = {3.421300e+01, 4.138641e+01, 4.700964e+01, 
                                 5.087328e+01, 5.283949e+01, 5.283949e+01, 
                                 5.087328e+01, 4.700964e+01, 4.138641e+01, 
                                 3.421300e+01};


  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(CPMHeatIntegrationTests, coupledTest3)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMHeatTest3.txt";
  const std::string outputPath = "outputs/Out_CPMHeatTest3.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 9.371118e-01;

  std::vector<double> refFlux = {3.053910e-02, 3.825740e-02, 4.380981e-02, 
                                 4.750541e-02, 4.935945e-02, 4.935945e-02, 
                                 4.750541e-02, 4.380981e-02, 3.825740e-02, 
                                 3.053910e-02, 3.989040e-02, 5.234246e-02, 
                                 6.120611e-02, 6.707613e-02, 7.001372e-02, 
                                 7.001372e-02, 6.707613e-02, 6.120611e-02, 
                                 5.234246e-02, 3.989040e-02};

  std::vector<double> refTemp = {3.683267e+01, 4.857619e+01, 5.784446e+01, 
                                 6.424202e+01, 6.750651e+01, 6.750651e+01, 
                                 6.424202e+01, 5.784446e+01, 4.857619e+01, 
                                 3.683267e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(CPMHeatIntegrationTests, coupledTest4)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMHeatTest4.txt";
  const std::string outputPath = "outputs/Out_CPMHeatTest4.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 9.376760e-01;

  std::vector<double> refFlux = {3.053286e-02, 3.825121e-02, 4.380521e-02, 
                                 4.750272e-02, 4.935796e-02, 4.935784e-02, 
                                 4.750239e-02, 4.380472e-02, 3.825064e-02, 
                                 3.053245e-02, 3.988967e-02, 5.234360e-02, 
                                 6.121073e-02, 6.708424e-02, 7.002393e-02, 
                                 7.002378e-02, 6.708382e-02, 6.121011e-02, 
                                 5.234292e-02, 3.988919e-02};

  std::vector<double> refTemp = {3.672199e+01, 4.824630e+01, 5.730079e+01, 
                                 6.353067e+01, 6.670445e+01, 6.670736e+01, 
                                 6.353942e+01, 5.731544e+01, 4.826694e+01,
                                 3.671900e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(CPMHeatIntegrationTests, coupledTest5)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMHeatTest5.txt";
  const std::string outputPath = "outputs/Out_CPMHeatTest5.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 7.962047e-01;

  std::vector<double> refFlux = {3.551120e-02, 4.201962e-02, 4.685862e-02, 
                                 5.059223e-02, 5.340634e-02, 5.539246e-02, 
                                 5.659278e-02, 5.700985e-02, 5.660507e-02, 
                                 5.528686e-02, 5.287093e-02, 4.885731e-02, 
                                 4.299682e-02, 3.912892e-02, 3.608052e-02, 
                                 3.343964e-02, 3.106584e-02, 2.888524e-02, 
                                 2.685156e-02, 2.493244e-02, 2.310315e-02, 
                                 2.134313e-02, 1.963347e-02, 1.795446e-02, 
                                 1.628151e-02, 1.457485e-02, 1.272516e-02};

  std::vector<double> refTemp = {6.141763e+01, 1.170926e+02, 1.642948e+02, 
                                 2.020487e+02, 2.296014e+02, 2.463855e+02, 
                                 2.520005e+02, 2.462044e+02, 2.289130e+02, 
                                 2.002080e+02, 1.603552e+02, 1.098418e+02, 
                                 8.467569e+01, 8.090496e+01, 7.713422e+01, 
                                 7.336348e+01, 6.959274e+01, 6.582201e+01, 
                                 6.205127e+01, 5.828053e+01, 5.450979e+01, 
                                 5.073906e+01, 4.696832e+01, 4.319758e+01, 
                                 3.942684e+01, 3.565611e+01, 3.188537e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}