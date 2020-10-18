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
  const double kEffRef = 9.693388e-01;
  std::vector<double> refFlux = {7.753613e-04, 1.180446e-03, 1.585779e-03, 
                                 1.991444e-03, 2.397528e-03, 2.804114e-03, 
                                 3.211289e-03, 3.619138e-03, 4.027746e-03, 
                                 4.437199e-03, 4.847583e-03, 5.258985e-03, 
                                 5.671490e-03, 6.085185e-03, 6.500157e-03, 
                                 6.916494e-03, 7.334281e-03, 7.753608e-03, 
                                 8.174561e-03, 8.597230e-03, 9.021703e-03, 
                                 9.448069e-03, 9.876417e-03, 1.030684e-02, 
                                 1.073942e-02, 1.114805e-02, 1.151854e-02, 
                                 1.187671e-02, 1.222217e-02, 1.255454e-02, 
                                 1.287348e-02, 1.317865e-02, 1.346972e-02, 
                                 1.374637e-02, 1.400831e-02, 1.425526e-02, 
                                 1.448697e-02, 1.470317e-02, 1.490364e-02, 
                                 1.508816e-02, 1.525654e-02, 1.540861e-02, 
                                 1.554418e-02, 1.566313e-02, 1.576532e-02, 
                                 1.585065e-02, 1.591902e-02, 1.597036e-02, 
                                 1.600462e-02, 1.602176e-02, 1.602176e-02, 
                                 1.600462e-02, 1.597036e-02, 1.591902e-02, 
                                 1.585065e-02, 1.576532e-02, 1.566313e-02, 
                                 1.554418e-02, 1.540861e-02, 1.525654e-02, 
                                 1.508816e-02, 1.490364e-02, 1.470317e-02, 
                                 1.448697e-02, 1.425526e-02, 1.400831e-02, 
                                 1.374637e-02, 1.346972e-02, 1.317865e-02, 
                                 1.287348e-02, 1.255454e-02, 1.222217e-02, 
                                 1.187671e-02, 1.151854e-02, 1.114805e-02, 
                                 1.073942e-02, 1.030684e-02, 9.876417e-03, 
                                 9.448069e-03, 9.021703e-03, 8.597230e-03, 
                                 8.174561e-03, 7.753608e-03, 7.334281e-03, 
                                 6.916494e-03, 6.500157e-03, 6.085185e-03, 
                                 5.671490e-03, 5.258985e-03, 4.847583e-03, 
                                 4.437199e-03, 4.027746e-03, 3.619138e-03, 
                                 3.211289e-03, 2.804114e-03, 2.397528e-03, 
                                 1.991444e-03, 1.585779e-03, 1.180446e-03, 
                                 7.753613e-04};

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
  const double kEffRef = 0.9696182;
  std::vector<double> refFlux = {3.211193e-02, 3.207703e-02, 3.200727e-02, 
                                 3.190272e-02, 3.176350e-02, 3.158976e-02, 
                                 3.138168e-02, 3.113950e-02, 3.086347e-02, 
                                 3.055389e-02, 3.021111e-02, 2.983548e-02, 
                                 2.942743e-02, 2.898738e-02, 2.851583e-02,
                                 2.801327e-02, 2.748026e-02, 2.691738e-02, 
                                 2.632524e-02, 2.570447e-02, 2.505576e-02, 
                                 2.437980e-02, 2.367735e-02, 2.294914e-02, 
                                 2.219599e-02, 2.137966e-02, 2.052781e-02, 
                                 1.967931e-02, 1.883404e-02, 1.799185e-02, 
                                 1.715261e-02, 1.631617e-02, 1.548242e-02, 
                                 1.465119e-02, 1.382237e-02, 1.299581e-02, 
                                 1.217138e-02, 1.134894e-02, 1.052836e-02, 
                                 9.709510e-03, 8.892247e-03, 8.076440e-03, 
                                 7.261956e-03, 6.448661e-03, 5.636423e-03, 
                                 4.825108e-03, 4.014583e-03, 3.204716e-03, 
                                 2.395373e-03, 1.586424e-03};

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
  const double kEffRef = 9.696182e-01;
  std::vector<double> refFlux = {1.586424e-03, 2.395373e-03, 3.204716e-03, 
                                 4.014583e-03, 4.825108e-03, 5.636423e-03, 
                                 6.448661e-03, 7.261956e-03, 8.076440e-03, 
                                 8.892247e-03, 9.709510e-03, 1.052836e-02, 
                                 1.134894e-02, 1.217138e-02, 1.299581e-02, 
                                 1.382237e-02, 1.465119e-02, 1.548242e-02, 
                                 1.631617e-02, 1.715261e-02, 1.799185e-02, 
                                 1.883404e-02, 1.967931e-02, 2.052781e-02, 
                                 2.137966e-02, 2.219599e-02, 2.294914e-02, 
                                 2.367735e-02, 2.437980e-02, 2.505576e-02, 
                                 2.570447e-02, 2.632524e-02, 2.691738e-02, 
                                 2.748026e-02, 2.801327e-02, 2.851583e-02, 
                                 2.898738e-02, 2.942743e-02, 2.983548e-02, 
                                 3.021111e-02, 3.055389e-02, 3.086347e-02, 
                                 3.113950e-02, 3.138168e-02, 3.158976e-02, 
                                 3.176350e-02, 3.190272e-02, 3.200727e-02, 
                                 3.207703e-02, 3.211193e-02};

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
  const double kEffRef = 1.213588e+00;
  std::vector<double> refFlux = {9.399132e-03, 9.401104e-03, 9.405049e-03, 
                                 9.410968e-03, 9.418861e-03, 9.428731e-03, 
                                 9.440579e-03, 9.454409e-03, 9.470222e-03, 
                                 9.488022e-03, 9.507814e-03, 9.529600e-03, 
                                 9.553387e-03, 9.579177e-03, 9.606978e-03, 
                                 9.636795e-03, 9.668635e-03, 9.702502e-03, 
                                 9.738406e-03, 9.776354e-03, 9.816353e-03, 
                                 9.858412e-03, 9.902539e-03, 9.948744e-03, 
                                 9.997037e-03, 1.004439e-02, 1.008699e-02, 
                                 1.012787e-02, 1.016703e-02, 1.020445e-02, 
                                 1.024012e-02, 1.027405e-02, 1.030623e-02, 
                                 1.033665e-02, 1.036530e-02, 1.039219e-02, 
                                 1.041730e-02, 1.044064e-02, 1.046220e-02, 
                                 1.048197e-02, 1.049996e-02, 1.051615e-02, 
                                 1.053055e-02, 1.054316e-02, 1.055397e-02, 
                                 1.056298e-02, 1.057019e-02, 1.057560e-02, 
                                 1.057921e-02, 1.058101e-02, 1.058101e-02, 
                                 1.057921e-02, 1.057560e-02, 1.057019e-02, 
                                 1.056298e-02, 1.055397e-02, 1.054316e-02, 
                                 1.053055e-02, 1.051615e-02, 1.049996e-02, 
                                 1.048197e-02, 1.046220e-02, 1.044064e-02, 
                                 1.041730e-02, 1.039219e-02, 1.036530e-02, 
                                 1.033665e-02, 1.030623e-02, 1.027405e-02, 
                                 1.024012e-02, 1.020445e-02, 1.016703e-02, 
                                 1.012787e-02, 1.008699e-02, 1.004439e-02, 
                                 9.997037e-03, 9.948744e-03, 9.902539e-03, 
                                 9.858412e-03, 9.816353e-03, 9.776354e-03, 
                                 9.738406e-03, 9.702502e-03, 9.668635e-03, 
                                 9.636795e-03, 9.606978e-03, 9.579177e-03, 
                                 9.553387e-03, 9.529600e-03, 9.507814e-03, 
                                 9.488022e-03, 9.470222e-03, 9.454409e-03,
                                 9.440579e-03, 9.428731e-03, 9.418861e-03, 
                                 9.410968e-03, 9.405049e-03, 9.401104e-03, 
                                 9.399132e-03};

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