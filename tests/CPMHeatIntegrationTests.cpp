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

  const double kEffRef = 7.902155e-01;

  std::vector<double> refFlux = {3.574788e-02,
                                 4.229355e-02,
                                 4.714349e-02,
                                 5.086872e-02,
                                 5.365866e-02,
                                 5.560775e-02,
                                 5.676093e-02,
                                 5.712346e-02,
                                 5.665948e-02,
                                 5.528038e-02,
                                 5.280530e-02,
                                 4.873925e-02,
                                 4.285913e-02,
                                 3.898883e-02,
                                 3.593949e-02,
                                 3.329972e-02,
                                 3.092884e-02,
                                 2.875267e-02,
                                 2.672464e-02,
                                 2.481214e-02,
                                 2.299024e-02,
                                 2.123817e-02,
                                 1.953691e-02,
                                 1.786663e-02,
                                 1.620270e-02,
                                 1.450537e-02,
                                 1.266569e-02};

  std::vector<double> refTemp = {6.199373e+01,
                                 1.187930e+02,
                                 1.670878e+02,
                                 2.059029e+02,
                                 2.344894e+02,
                                 2.522860e+02,
                                 2.589011e+02,
                                 2.541025e+02,
                                 2.378176e+02,
                                 2.101395e+02,
                                 1.713455e+02,
                                 1.219334e+02,
                                 9.470042e+01,
                                 9.023832e+01,
                                 8.577623e+01,
                                 8.131413e+01,
                                 7.685203e+01,
                                 7.238993e+01,
                                 6.792783e+01,
                                 6.346574e+01,
                                 5.900364e+01,
                                 5.454154e+01,
                                 5.007944e+01,
                                 4.561734e+01,
                                 4.115525e+01,
                                 3.669315e+01,
                                 3.223105e+01};

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