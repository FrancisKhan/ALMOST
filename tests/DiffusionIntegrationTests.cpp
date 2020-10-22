#include "gtest/gtest.h"
#include "TestHelper.h"

class DiffIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

// SLAB TESTS //

TEST_F(DiffIntegrationTests, diff1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff1.txt";
  const std::string outputPath = "outputs/Out_diff1.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 9.735291e-01;
  std::vector<double> refFlux = {7.717911e-04,
                                 1.177238e-03,
                                 1.582940e-03,
                                 1.988985e-03,
                                 2.395460e-03,
                                 2.802454e-03,
                                 3.210054e-03,
                                 3.618350e-03,
                                 4.027428e-03,
                                 4.437379e-03,
                                 4.848290e-03,
                                 5.260250e-03,
                                 5.673349e-03,
                                 6.087677e-03,
                                 6.503322e-03,
                                 6.920375e-03,
                                 7.338926e-03,
                                 7.759065e-03,
                                 8.180885e-03,
                                 8.604475e-03,
                                 9.029928e-03,
                                 9.457335e-03,
                                 9.886790e-03,
                                 1.031838e-02,
                                 1.075221e-02,
                                 1.116061e-02,
                                 1.152936e-02,
                                 1.188582e-02,
                                 1.222963e-02,
                                 1.256040e-02,
                                 1.287779e-02,
                                 1.318147e-02,
                                 1.347110e-02,
                                 1.374638e-02,
                                 1.400702e-02,
                                 1.425274e-02,
                                 1.448328e-02,
                                 1.469839e-02,
                                 1.489784e-02,
                                 1.508143e-02,
                                 1.524895e-02,
                                 1.540023e-02,
                                 1.553511e-02,
                                 1.565345e-02,
                                 1.575512e-02,
                                 1.584000e-02,
                                 1.590802e-02,
                                 1.595910e-02,
                                 1.599318e-02,
                                 1.601023e-02,
                                 1.601023e-02,
                                 1.599318e-02,
                                 1.595910e-02,
                                 1.590802e-02,
                                 1.584000e-02,
                                 1.575512e-02,
                                 1.565345e-02,
                                 1.553511e-02,
                                 1.540023e-02,
                                 1.524895e-02,
                                 1.508143e-02,
                                 1.489784e-02,
                                 1.469839e-02,
                                 1.448328e-02,
                                 1.425274e-02,
                                 1.400702e-02,
                                 1.374638e-02,
                                 1.347110e-02,
                                 1.318147e-02,
                                 1.287779e-02,
                                 1.256040e-02,
                                 1.222963e-02,
                                 1.188582e-02,
                                 1.152936e-02,
                                 1.116061e-02,
                                 1.075221e-02,
                                 1.031838e-02,
                                 9.886790e-03,
                                 9.457335e-03,
                                 9.029928e-03,
                                 8.604475e-03,
                                 8.180885e-03,
                                 7.759065e-03,
                                 7.338926e-03,
                                 6.920375e-03,
                                 6.503322e-03,
                                 6.087677e-03,
                                 5.673349e-03,
                                 5.260250e-03,
                                 4.848290e-03,
                                 4.437379e-03,
                                 4.027428e-03,
                                 3.618350e-03,
                                 3.210054e-03,
                                 2.802454e-03,
                                 2.395460e-03,
                                 1.988985e-03,
                                 1.582940e-03,
                                 1.177238e-03,
                                 7.717911e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(DiffIntegrationTests, diff2)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff2.txt";
  const std::string outputPath = "outputs/Out_diff2.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 9.735291e-01;
  std::vector<double> refFlux = {3.202046e-02,
                                 3.198636e-02,
                                 3.191819e-02,
                                 3.181604e-02,
                                 3.168001e-02,
                                 3.151023e-02,
                                 3.130690e-02,
                                 3.107023e-02,
                                 3.080047e-02,
                                 3.049790e-02,
                                 3.016286e-02,
                                 2.979568e-02,
                                 2.939677e-02,
                                 2.896655e-02,
                                 2.850548e-02,
                                 2.801404e-02,
                                 2.749277e-02,
                                 2.694220e-02,
                                 2.636294e-02,
                                 2.575559e-02,
                                 2.512080e-02,
                                 2.445925e-02,
                                 2.377165e-02,
                                 2.305872e-02,
                                 2.232122e-02,
                                 2.150443e-02,
                                 2.063677e-02,
                                 1.977358e-02,
                                 1.891467e-02,
                                 1.805986e-02,
                                 1.720895e-02,
                                 1.636177e-02,
                                 1.551813e-02,
                                 1.467785e-02,
                                 1.384075e-02,
                                 1.300664e-02,
                                 1.217535e-02,
                                 1.134670e-02,
                                 1.052050e-02,
                                 9.696579e-03,
                                 8.874757e-03,
                                 8.054857e-03,
                                 7.236699e-03,
                                 6.420109e-03,
                                 5.604908e-03,
                                 4.790920e-03,
                                 3.977970e-03,
                                 3.165881e-03,
                                 2.354477e-03,
                                 1.543582e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(DiffIntegrationTests, diff3)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff3.txt";
  const std::string outputPath = "outputs/Out_diff3.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 9.735291e-01;
  std::vector<double> refFlux = {1.543582e-03,
                                 2.354477e-03,
                                 3.165881e-03,
                                 3.977970e-03,
                                 4.790920e-03,
                                 5.604908e-03,
                                 6.420109e-03,
                                 7.236699e-03,
                                 8.054857e-03,
                                 8.874757e-03,
                                 9.696579e-03,
                                 1.052050e-02,
                                 1.134670e-02,
                                 1.217535e-02,
                                 1.300664e-02,
                                 1.384075e-02,
                                 1.467785e-02,
                                 1.551813e-02,
                                 1.636177e-02,
                                 1.720895e-02,
                                 1.805986e-02,
                                 1.891467e-02,
                                 1.977358e-02,
                                 2.063677e-02,
                                 2.150443e-02,
                                 2.232122e-02,
                                 2.305872e-02,
                                 2.377165e-02,
                                 2.445925e-02,
                                 2.512080e-02,
                                 2.575559e-02,
                                 2.636294e-02,
                                 2.694220e-02,
                                 2.749277e-02,
                                 2.801404e-02,
                                 2.850548e-02,
                                 2.896655e-02,
                                 2.939677e-02,
                                 2.979568e-02,
                                 3.016286e-02,
                                 3.049790e-02,
                                 3.080047e-02,
                                 3.107023e-02,
                                 3.130690e-02,
                                 3.151023e-02,
                                 3.168001e-02,
                                 3.181604e-02,
                                 3.191819e-02,
                                 3.198636e-02,
                                 3.202046e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(DiffIntegrationTests, diff4)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff4.txt";
  const std::string outputPath = "outputs/Out_diff4.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 1.216490e+00;
  std::vector<double> refFlux = {9.382420e-03,
                                 9.384451e-03,
                                 9.388514e-03,
                                 9.394609e-03,
                                 9.402737e-03,
                                 9.412901e-03,
                                 9.425103e-03,
                                 9.439345e-03,
                                 9.455630e-03,
                                 9.473962e-03,
                                 9.494345e-03,
                                 9.516783e-03,
                                 9.541281e-03,
                                 9.567845e-03,
                                 9.596480e-03,
                                 9.627192e-03,
                                 9.659988e-03,
                                 9.694876e-03,
                                 9.731862e-03,
                                 9.770954e-03,
                                 9.812162e-03,
                                 9.855494e-03,
                                 9.900959e-03,
                                 9.948568e-03,
                                 9.998330e-03,
                                 1.004695e-02,
                                 1.009052e-02,
                                 1.013232e-02,
                                 1.017236e-02,
                                 1.021063e-02,
                                 1.024712e-02,
                                 1.028182e-02,
                                 1.031473e-02,
                                 1.034584e-02,
                                 1.037515e-02,
                                 1.040265e-02,
                                 1.042834e-02,
                                 1.045221e-02,
                                 1.047426e-02,
                                 1.049448e-02,
                                 1.051288e-02,
                                 1.052945e-02,
                                 1.054418e-02,
                                 1.055708e-02,
                                 1.056814e-02,
                                 1.057735e-02,
                                 1.058473e-02,
                                 1.059026e-02,
                                 1.059395e-02,
                                 1.059580e-02,
                                 1.059580e-02,
                                 1.059395e-02,
                                 1.059026e-02,
                                 1.058473e-02,
                                 1.057735e-02,
                                 1.056814e-02,
                                 1.055708e-02,
                                 1.054418e-02,
                                 1.052945e-02,
                                 1.051288e-02,
                                 1.049448e-02,
                                 1.047426e-02,
                                 1.045221e-02,
                                 1.042834e-02,
                                 1.040265e-02,
                                 1.037515e-02,
                                 1.034584e-02,
                                 1.031473e-02,
                                 1.028182e-02,
                                 1.024712e-02,
                                 1.021063e-02,
                                 1.017236e-02,
                                 1.013232e-02,
                                 1.009052e-02,
                                 1.004695e-02,
                                 9.998330e-03,
                                 9.948568e-03,
                                 9.900959e-03,
                                 9.855494e-03,
                                 9.812162e-03,
                                 9.770954e-03,
                                 9.731862e-03,
                                 9.694876e-03,
                                 9.659988e-03,
                                 9.627192e-03,
                                 9.596480e-03,
                                 9.567845e-03,
                                 9.541281e-03,
                                 9.516783e-03,
                                 9.494345e-03,
                                 9.473962e-03,
                                 9.455630e-03,
                                 9.439345e-03,
                                 9.425103e-03,
                                 9.412901e-03,
                                 9.402737e-03,
                                 9.394609e-03,
                                 9.388514e-03,
                                 9.384451e-03,
                                 9.382420e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(DiffIntegrationTests, memTestDiffslab)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff1.txt";
  const std::string outputPath = "outputs/Out_diff1MEM.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}