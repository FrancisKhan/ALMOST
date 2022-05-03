#include "gtest/gtest.h"
#include "TestHelper.h"
#include "additionalPrintFuncs.h"

using namespace PrintFuncs;

class DiffIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

// PrintFuncs::createCppVector(flux, "%7.6e");

// SLAB TESTS //

// Graphite reactor with graphite reflector, slab geometry
// Zero in-current at both boundaries
// One energy groups

TEST_F(DiffIntegrationTests, diff1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff1.txt";
  const std::string outputPath = "outputs/Out_diff1.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 9.693342e-01;
  std::vector<double> refFlux = {7.933976e-04,
                                 1.198040e-03,
                                 1.602875e-03,
                                 2.007970e-03,
                                 2.413389e-03,
                                 2.819197e-03,
                                 3.225461e-03,
                                 3.632245e-03,
                                 4.039617e-03,
                                 4.447640e-03,
                                 4.856382e-03,
                                 5.265908e-03,
                                 5.676285e-03,
                                 6.087578e-03,
                                 6.499854e-03,
                                 6.913181e-03,
                                 7.327623e-03,
                                 7.743249e-03,
                                 8.160125e-03,
                                 8.578319e-03,
                                 8.997899e-03,
                                 9.418931e-03,
                                 9.841485e-03,
                                 1.026563e-02,
                                 1.069143e-02,
                                 1.109939e-02,
                                 1.147572e-02,
                                 1.183957e-02,
                                 1.219054e-02,
                                 1.252826e-02,
                                 1.285235e-02,
                                 1.316246e-02,
                                 1.345826e-02,
                                 1.373944e-02,
                                 1.400567e-02,
                                 1.425669e-02,
                                 1.449221e-02,
                                 1.471198e-02,
                                 1.491577e-02,
                                 1.510335e-02,
                                 1.527453e-02,
                                 1.542912e-02,
                                 1.556695e-02,
                                 1.568788e-02,
                                 1.579178e-02,
                                 1.587853e-02,
                                 1.594804e-02,
                                 1.600024e-02,
                                 1.603507e-02,
                                 1.605249e-02,
                                 1.605249e-02,
                                 1.603507e-02,
                                 1.600024e-02,
                                 1.594804e-02,
                                 1.587853e-02,
                                 1.579178e-02,
                                 1.568788e-02,
                                 1.556695e-02,
                                 1.542912e-02,
                                 1.527453e-02,
                                 1.510335e-02,
                                 1.491577e-02,
                                 1.471198e-02,
                                 1.449221e-02,
                                 1.425669e-02,
                                 1.400567e-02,
                                 1.373944e-02,
                                 1.345826e-02,
                                 1.316246e-02,
                                 1.285235e-02,
                                 1.252826e-02,
                                 1.219054e-02,
                                 1.183957e-02,
                                 1.147572e-02,
                                 1.109939e-02,
                                 1.069143e-02,
                                 1.026563e-02,
                                 9.841485e-03,
                                 9.418931e-03,
                                 8.997899e-03,
                                 8.578319e-03,
                                 8.160125e-03,
                                 7.743249e-03,
                                 7.327623e-03,
                                 6.913181e-03,
                                 6.499854e-03,
                                 6.087578e-03,
                                 5.676285e-03,
                                 5.265908e-03,
                                 4.856382e-03,
                                 4.447640e-03,
                                 4.039617e-03,
                                 3.632245e-03,
                                 3.225461e-03,
                                 2.819197e-03,
                                 2.413389e-03,
                                 2.007970e-03,
                                 1.602875e-03,
                                 1.198040e-03,
                                 7.933976e-04};
  
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor with graphite reflector, slab geometry
// Left reflective boundary condition 
// One energy groups

TEST_F(DiffIntegrationTests, diff2)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff2.txt";
  const std::string outputPath = "outputs/Out_diff2.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 9.693342e-01;
  std::vector<double> refFlux = {3.210693e-02,
                                 3.207205e-02,
                                 3.200234e-02,
                                 3.189787e-02,
                                 3.175875e-02,
                                 3.158513e-02,
                                 3.137721e-02,
                                 3.113520e-02,
                                 3.085937e-02,
                                 3.055002e-02,
                                 3.020748e-02,
                                 2.983212e-02,
                                 2.942436e-02,
                                 2.898463e-02,
                                 2.851341e-02,
                                 2.801121e-02,
                                 2.747857e-02,
                                 2.691609e-02,
                                 2.632435e-02,
                                 2.570402e-02,
                                 2.505575e-02,
                                 2.438026e-02,
                                 2.367827e-02,
                                 2.295056e-02,
                                 2.219791e-02,
                                 2.138201e-02,
                                 2.053044e-02,
                                 1.968219e-02,
                                 1.883712e-02,
                                 1.799509e-02,
                                 1.715596e-02,
                                 1.631961e-02,
                                 1.548589e-02,
                                 1.465467e-02,
                                 1.382581e-02,
                                 1.299920e-02,
                                 1.217467e-02,
                                 1.135212e-02,
                                 1.053140e-02,
                                 9.712380e-03,
                                 8.894929e-03,
                                 8.078914e-03,
                                 7.264204e-03,
                                 6.450667e-03,
                                 5.638171e-03,
                                 4.826586e-03,
                                 4.015781e-03,
                                 3.205624e-03,
                                 2.395985e-03,
                                 1.586732e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor with graphite reflector, slab geometry
// Right reflective boundary condition 
// One energy groups

TEST_F(DiffIntegrationTests, diff3)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff3.txt";
  const std::string outputPath = "outputs/Out_diff3.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 9.693342e-01;
  std::vector<double> refFlux = {1.586732e-03,
                                 2.395985e-03,
                                 3.205624e-03,
                                 4.015781e-03,
                                 4.826586e-03,
                                 5.638171e-03,
                                 6.450667e-03,
                                 7.264204e-03,
                                 8.078914e-03,
                                 8.894929e-03,
                                 9.712380e-03,
                                 1.053140e-02,
                                 1.135212e-02,
                                 1.217467e-02,
                                 1.299920e-02,
                                 1.382581e-02,
                                 1.465467e-02,
                                 1.548589e-02,
                                 1.631961e-02,
                                 1.715596e-02,
                                 1.799509e-02,
                                 1.883712e-02,
                                 1.968219e-02,
                                 2.053044e-02,
                                 2.138201e-02,
                                 2.219791e-02,
                                 2.295056e-02,
                                 2.367827e-02,
                                 2.438026e-02,
                                 2.505575e-02,
                                 2.570402e-02,
                                 2.632435e-02,
                                 2.691609e-02,
                                 2.747857e-02,
                                 2.801121e-02,
                                 2.851341e-02,
                                 2.898463e-02,
                                 2.942436e-02,
                                 2.983212e-02,
                                 3.020748e-02,
                                 3.055002e-02,
                                 3.085937e-02,
                                 3.113520e-02,
                                 3.137721e-02,
                                 3.158513e-02,
                                 3.175875e-02,
                                 3.189787e-02,
                                 3.200234e-02,
                                 3.207205e-02,
                                 3.210693e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor with graphite reflector, slab geometry
// Reflective boundary at both ends
// One energy groups

TEST_F(DiffIntegrationTests, diff4)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff4.txt";
  const std::string outputPath = "outputs/Out_diff4.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 1.216267e+00;
  std::vector<double> refFlux = {9.366905e-03,
                                 9.368986e-03,
                                 9.373148e-03,
                                 9.379393e-03,
                                 9.387721e-03,
                                 9.398135e-03,
                                 9.410636e-03,
                                 9.425229e-03,
                                 9.441915e-03,
                                 9.460698e-03,
                                 9.481584e-03,
                                 9.504575e-03,
                                 9.529678e-03,
                                 9.556899e-03,
                                 9.586242e-03,
                                 9.617715e-03,
                                 9.651325e-03,
                                 9.687078e-03,
                                 9.724984e-03,
                                 9.765050e-03,
                                 9.807286e-03,
                                 9.851700e-03,
                                 9.898303e-03,
                                 9.947104e-03,
                                 9.998116e-03,
                                 1.004797e-02,
                                 1.009265e-02,
                                 1.013553e-02,
                                 1.017660e-02,
                                 1.021585e-02,
                                 1.025328e-02,
                                 1.028888e-02,
                                 1.032264e-02,
                                 1.035455e-02,
                                 1.038462e-02,
                                 1.041283e-02,
                                 1.043919e-02,
                                 1.046368e-02,
                                 1.048630e-02,
                                 1.050705e-02,
                                 1.052593e-02,
                                 1.054293e-02,
                                 1.055804e-02,
                                 1.057127e-02,
                                 1.058262e-02,
                                 1.059208e-02,
                                 1.059965e-02,
                                 1.060532e-02,
                                 1.060911e-02,
                                 1.061100e-02,
                                 1.061100e-02,
                                 1.060911e-02,
                                 1.060532e-02,
                                 1.059965e-02,
                                 1.059208e-02,
                                 1.058262e-02,
                                 1.057127e-02,
                                 1.055804e-02,
                                 1.054293e-02,
                                 1.052593e-02,
                                 1.050705e-02,
                                 1.048630e-02,
                                 1.046368e-02,
                                 1.043919e-02,
                                 1.041283e-02,
                                 1.038462e-02,
                                 1.035455e-02,
                                 1.032264e-02,
                                 1.028888e-02,
                                 1.025328e-02,
                                 1.021585e-02,
                                 1.017660e-02,
                                 1.013553e-02,
                                 1.009265e-02,
                                 1.004797e-02,
                                 9.998116e-03,
                                 9.947104e-03,
                                 9.898303e-03,
                                 9.851700e-03,
                                 9.807286e-03,
                                 9.765050e-03,
                                 9.724984e-03,
                                 9.687078e-03,
                                 9.651325e-03,
                                 9.617715e-03,
                                 9.586242e-03,
                                 9.556899e-03,
                                 9.529678e-03,
                                 9.504575e-03,
                                 9.481584e-03,
                                 9.460698e-03,
                                 9.441915e-03,
                                 9.425229e-03,
                                 9.410636e-03,
                                 9.398135e-03,
                                 9.387721e-03,
                                 9.379393e-03,
                                 9.373148e-03,
                                 9.368986e-03,
                                 9.366905e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor, slab geometry
// Reflective boundary on the right
// Two energy groups

TEST_F(DiffIntegrationTests, diff5)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff5.txt";
  const std::string outputPath = "outputs/Out_diff5.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 1.332284e+00;
  std::vector<double> refFlux = {7.341561e-03,
                                 7.334526e-03,
                                 7.320462e-03,
                                 7.299383e-03,
                                 7.271309e-03,
                                 7.236268e-03,
                                 7.194292e-03,
                                 7.145422e-03,
                                 7.089705e-03,
                                 7.027194e-03,
                                 6.957949e-03,
                                 6.882038e-03,
                                 6.799532e-03,
                                 6.710510e-03,
                                 6.615059e-03,
                                 6.513271e-03,
                                 6.405242e-03,
                                 6.291077e-03,
                                 6.170886e-03,
                                 6.044785e-03,
                                 5.912894e-03,
                                 5.775343e-03,
                                 5.632262e-03,
                                 5.483791e-03,
                                 5.330073e-03,
                                 5.171258e-03,
                                 5.007500e-03,
                                 4.838959e-03,
                                 4.665798e-03,
                                 4.488188e-03,
                                 4.306304e-03,
                                 4.120325e-03,
                                 3.930436e-03,
                                 3.736827e-03,
                                 3.539691e-03,
                                 3.339229e-03,
                                 3.135646e-03,
                                 2.929153e-03,
                                 2.719966e-03,
                                 2.508307e-03,
                                 2.294405e-03,
                                 2.078498e-03,
                                 1.860829e-03,
                                 1.641651e-03,
                                 1.421229e-03,
                                 1.199836e-03,
                                 9.777605e-04,
                                 7.553061e-04,
                                 5.327939e-04,
                                 3.105656e-04,
                                 2.362174e-02,
                                 2.359910e-02,
                                 2.355384e-02,
                                 2.348601e-02,
                                 2.339567e-02,
                                 2.328291e-02,
                                 2.314784e-02,
                                 2.299058e-02,
                                 2.281128e-02,
                                 2.261013e-02,
                                 2.238730e-02,
                                 2.214302e-02,
                                 2.187751e-02,
                                 2.159103e-02,
                                 2.128386e-02,
                                 2.095629e-02,
                                 2.060863e-02,
                                 2.024122e-02,
                                 1.985440e-02,
                                 1.944855e-02,
                                 1.902405e-02,
                                 1.858131e-02,
                                 1.812076e-02,
                                 1.764283e-02,
                                 1.714797e-02,
                                 1.663667e-02,
                                 1.610941e-02,
                                 1.556669e-02,
                                 1.500902e-02,
                                 1.443694e-02,
                                 1.385099e-02,
                                 1.325173e-02,
                                 1.263971e-02,
                                 1.201553e-02,
                                 1.137977e-02,
                                 1.073302e-02,
                                 1.007589e-02,
                                 9.408985e-03,
                                 8.732932e-03,
                                 8.048351e-03,
                                 7.355866e-03,
                                 6.656106e-03,
                                 5.949696e-03,
                                 5.237263e-03,
                                 4.519427e-03,
                                 3.796804e-03,
                                 3.069996e-03,
                                 2.339597e-03,
                                 1.606180e-03,
                                 8.702998e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor with graphite reflector, slab geometry
// Reflective boundary at both ends
// Two energy groups

TEST_F(DiffIntegrationTests, diff6)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff6.txt";
  const std::string outputPath = "outputs/Out_diff6.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 1.390236e+00;
  std::vector<double> refFlux = {9.734548e-03,
                                 9.728275e-03,
                                 9.715643e-03,
                                 9.696477e-03,
                                 9.670512e-03,
                                 9.637392e-03,
                                 9.596662e-03,
                                 9.547767e-03,
                                 9.490041e-03,
                                 9.422704e-03,
                                 9.344848e-03,
                                 9.255432e-03,
                                 9.153265e-03,
                                 9.036995e-03,
                                 8.905094e-03,
                                 8.755838e-03,
                                 8.587287e-03,
                                 8.397266e-03,
                                 8.183337e-03,
                                 7.942771e-03,
                                 7.672517e-03,
                                 7.369168e-03,
                                 7.028918e-03,
                                 6.647522e-03,
                                 6.220246e-03,
                                 5.722867e-03,
                                 5.251641e-03,
                                 4.821769e-03,
                                 4.429835e-03,
                                 4.072725e-03,
                                 3.747603e-03,
                                 3.451886e-03,
                                 3.183224e-03,
                                 2.939484e-03,
                                 2.718730e-03,
                                 2.519207e-03,
                                 2.339332e-03,
                                 2.177676e-03,
                                 2.032954e-03,
                                 1.904018e-03,
                                 1.789843e-03,
                                 1.689522e-03,
                                 1.602260e-03,
                                 1.527363e-03,
                                 1.464236e-03,
                                 1.412379e-03,
                                 1.371378e-03,
                                 1.340909e-03,
                                 1.320730e-03,
                                 1.310680e-03,
                                 9.943159e-03,
                                 9.951614e-03,
                                 9.968607e-03,
                                 9.994310e-03,
                                 1.002898e-02,
                                 1.007297e-02,
                                 1.012671e-02,
                                 1.019076e-02,
                                 1.026576e-02,
                                 1.035247e-02,
                                 1.045177e-02,
                                 1.056469e-02,
                                 1.069239e-02,
                                 1.083618e-02,
                                 1.099755e-02,
                                 1.117819e-02,
                                 1.137998e-02,
                                 1.160505e-02,
                                 1.185578e-02,
                                 1.213481e-02,
                                 1.244514e-02,
                                 1.279007e-02,
                                 1.317331e-02,
                                 1.359900e-02,
                                 1.407176e-02,
                                 1.459446e-02,
                                 1.506342e-02,
                                 1.548560e-02,
                                 1.586529e-02,
                                 1.620639e-02,
                                 1.651247e-02,
                                 1.678678e-02,
                                 1.703225e-02,
                                 1.725157e-02,
                                 1.744716e-02,
                                 1.762122e-02,
                                 1.777573e-02,
                                 1.791249e-02,
                                 1.803310e-02,
                                 1.813900e-02,
                                 1.823148e-02,
                                 1.831166e-02,
                                 1.838054e-02,
                                 1.843899e-02,
                                 1.848776e-02,
                                 1.852746e-02,
                                 1.855861e-02,
                                 1.858163e-02,
                                 1.859680e-02,
                                 1.860434e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor, slab geometry
// Reflective boundary on the left
// Three energy groups


TEST_F(DiffIntegrationTests, diff7)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff7.txt";
  const std::string outputPath = "outputs/Out_diff7.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 8.465743e-01;
  std::vector<double> refFlux = {4.444588e-03,
                                 4.441038e-03,
                                 4.433934e-03,
                                 4.423271e-03,
                                 4.409043e-03,
                                 4.391239e-03,
                                 4.369848e-03,
                                 4.344856e-03,
                                 4.316247e-03,
                                 4.284005e-03,
                                 4.248114e-03,
                                 4.208556e-03,
                                 4.165312e-03,
                                 4.118367e-03,
                                 4.067705e-03,
                                 4.013311e-03,
                                 3.955173e-03,
                                 3.893282e-03,
                                 3.827631e-03,
                                 3.758219e-03,
                                 3.685046e-03,
                                 3.608121e-03,
                                 3.527455e-03,
                                 3.443067e-03,
                                 3.354981e-03,
                                 3.263229e-03,
                                 3.167851e-03,
                                 3.068893e-03,
                                 2.966409e-03,
                                 2.860464e-03,
                                 2.751129e-03,
                                 2.638486e-03,
                                 2.522622e-03,
                                 2.403639e-03,
                                 2.281643e-03,
                                 2.156752e-03,
                                 2.029091e-03,
                                 1.898796e-03,
                                 1.766009e-03,
                                 1.630882e-03,
                                 1.493576e-03,
                                 1.354259e-03,
                                 1.213111e-03,
                                 1.070329e-03,
                                 9.261473e-04,
                                 7.808915e-04,
                                 6.351215e-04,
                                 4.900087e-04,
                                 3.482959e-04,
                                 2.166849e-04,
                                 7.972525e-03,
                                 7.966149e-03,
                                 7.953392e-03,
                                 7.934244e-03,
                                 7.908694e-03,
                                 7.876723e-03,
                                 7.838310e-03,
                                 7.793432e-03,
                                 7.742062e-03,
                                 7.684171e-03,
                                 7.619728e-03,
                                 7.548703e-03,
                                 7.471066e-03,
                                 7.386786e-03,
                                 7.295836e-03,
                                 7.198191e-03,
                                 7.093830e-03,
                                 6.982737e-03,
                                 6.864901e-03,
                                 6.740320e-03,
                                 6.608996e-03,
                                 6.470944e-03,
                                 6.326187e-03,
                                 6.174757e-03,
                                 6.016700e-03,
                                 5.852073e-03,
                                 5.680948e-03,
                                 5.503408e-03,
                                 5.319552e-03,
                                 5.129495e-03,
                                 4.933366e-03,
                                 4.731309e-03,
                                 4.523487e-03,
                                 4.310077e-03,
                                 4.091272e-03,
                                 3.867283e-03,
                                 3.638334e-03,
                                 3.404669e-03,
                                 3.166542e-03,
                                 2.924228e-03,
                                 2.678011e-03,
                                 2.428192e-03,
                                 2.175088e-03,
                                 1.919027e-03,
                                 1.660350e-03,
                                 1.399399e-03,
                                 1.136449e-03,
                                 8.714889e-04,
                                 6.034508e-04,
                                 3.277755e-04,
                                 1.770625e-02,
                                 1.769207e-02,
                                 1.766369e-02,
                                 1.762109e-02,
                                 1.756426e-02,
                                 1.749315e-02,
                                 1.740771e-02,
                                 1.730789e-02,
                                 1.719363e-02,
                                 1.706488e-02,
                                 1.692156e-02,
                                 1.676362e-02,
                                 1.659097e-02,
                                 1.640357e-02,
                                 1.620135e-02,
                                 1.598425e-02,
                                 1.575224e-02,
                                 1.550528e-02,
                                 1.524335e-02,
                                 1.496644e-02,
                                 1.467456e-02,
                                 1.436775e-02,
                                 1.404607e-02,
                                 1.370957e-02,
                                 1.335838e-02,
                                 1.299262e-02,
                                 1.261244e-02,
                                 1.221804e-02,
                                 1.180963e-02,
                                 1.138748e-02,
                                 1.095187e-02,
                                 1.050312e-02,
                                 1.004159e-02,
                                 9.567679e-03,
                                 9.081816e-03,
                                 8.584466e-03,
                                 8.076131e-03,
                                 7.557345e-03,
                                 7.028678e-03,
                                 6.490729e-03,
                                 5.944125e-03,
                                 5.389509e-03,
                                 4.827519e-03,
                                 4.258728e-03,
                                 3.683496e-03,
                                 3.101601e-03,
                                 2.511324e-03,
                                 1.907285e-03,
                                 1.275464e-03,
                                 5.823668e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor, slab geometry
// Reflective boundary on the left
// Four energy groups

TEST_F(DiffIntegrationTests, diff8)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff8.txt";
  const std::string outputPath = "outputs/Out_diff8.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 8.465990e-01;
  std::vector<double> refFlux = {4.435527e-03,
                                 4.431979e-03,
                                 4.424879e-03,
                                 4.414224e-03,
                                 4.400006e-03,
                                 4.382215e-03,
                                 4.360840e-03,
                                 4.335868e-03,
                                 4.307283e-03,
                                 4.275070e-03,
                                 4.239213e-03,
                                 4.199694e-03,
                                 4.156497e-03,
                                 4.109606e-03,
                                 4.059005e-03,
                                 4.004680e-03,
                                 3.946621e-03,
                                 3.884818e-03,
                                 3.819267e-03,
                                 3.749965e-03,
                                 3.676915e-03,
                                 3.600124e-03,
                                 3.519606e-03,
                                 3.435380e-03,
                                 3.347470e-03,
                                 3.255909e-03,
                                 3.160736e-03,
                                 3.061999e-03,
                                 2.959752e-03,
                                 2.854059e-03,
                                 2.744992e-03,
                                 2.632632e-03,
                                 2.517068e-03,
                                 2.398400e-03,
                                 2.276734e-03,
                                 2.152188e-03,
                                 2.024886e-03,
                                 1.894963e-03,
                                 1.762561e-03,
                                 1.627832e-03,
                                 1.490934e-03,
                                 1.352033e-03,
                                 1.211307e-03,
                                 1.068946e-03,
                                 9.251695e-04,
                                 7.802750e-04,
                                 6.347744e-04,
                                 4.897735e-04,
                                 3.479784e-04,
                                 2.162228e-04,
                                 4.064574e-03,
                                 4.061321e-03,
                                 4.054812e-03,
                                 4.045044e-03,
                                 4.032009e-03,
                                 4.015699e-03,
                                 3.996103e-03,
                                 3.973209e-03,
                                 3.947005e-03,
                                 3.917475e-03,
                                 3.884604e-03,
                                 3.848377e-03,
                                 3.808778e-03,
                                 3.765794e-03,
                                 3.719410e-03,
                                 3.669613e-03,
                                 3.616395e-03,
                                 3.559746e-03,
                                 3.499661e-03,
                                 3.436141e-03,
                                 3.369186e-03,
                                 3.298804e-03,
                                 3.225008e-03,
                                 3.147814e-03,
                                 3.067245e-03,
                                 2.983333e-03,
                                 2.896111e-03,
                                 2.805625e-03,
                                 2.711924e-03,
                                 2.615067e-03,
                                 2.515120e-03,
                                 2.412157e-03,
                                 2.306260e-03,
                                 2.197520e-03,
                                 2.086034e-03,
                                 1.971911e-03,
                                 1.855265e-03,
                                 1.736218e-03,
                                 1.614902e-03,
                                 1.491454e-03,
                                 1.366021e-03,
                                 1.238755e-03,
                                 1.109817e-03,
                                 9.793795e-04,
                                 8.476305e-04,
                                 7.147913e-04,
                                 5.811433e-04,
                                 4.470576e-04,
                                 3.129142e-04,
                                 1.783700e-04,
                                 3.957006e-03,
                                 3.953837e-03,
                                 3.947496e-03,
                                 3.937979e-03,
                                 3.925281e-03,
                                 3.909391e-03,
                                 3.890301e-03,
                                 3.867999e-03,
                                 3.842472e-03,
                                 3.813705e-03,
                                 3.781685e-03,
                                 3.746396e-03,
                                 3.707824e-03,
                                 3.665955e-03,
                                 3.620776e-03,
                                 3.572274e-03,
                                 3.520441e-03,
                                 3.465268e-03,
                                 3.406751e-03,
                                 3.344889e-03,
                                 3.279685e-03,
                                 3.211145e-03,
                                 3.139282e-03,
                                 3.064114e-03,
                                 2.985661e-03,
                                 2.903955e-03,
                                 2.819030e-03,
                                 2.730928e-03,
                                 2.639700e-03,
                                 2.545401e-03,
                                 2.448096e-03,
                                 2.347858e-03,
                                 2.244766e-03,
                                 2.138908e-03,
                                 2.030381e-03,
                                 1.919289e-03,
                                 1.805743e-03,
                                 1.689864e-03,
                                 1.571777e-03,
                                 1.451618e-03,
                                 1.329529e-03,
                                 1.205659e-03,
                                 1.080166e-03,
                                 9.532186e-04,
                                 8.249994e-04,
                                 6.957033e-04,
                                 5.654942e-04,
                                 4.342759e-04,
                                 3.007281e-04,
                                 1.587392e-04,
                                 1.766666e-02,
                                 1.765249e-02,
                                 1.762413e-02,
                                 1.758158e-02,
                                 1.752479e-02,
                                 1.745375e-02,
                                 1.736839e-02,
                                 1.726867e-02,
                                 1.715453e-02,
                                 1.702592e-02,
                                 1.688277e-02,
                                 1.672501e-02,
                                 1.655259e-02,
                                 1.636544e-02,
                                 1.616350e-02,
                                 1.594672e-02,
                                 1.571507e-02,
                                 1.546851e-02,
                                 1.520703e-02,
                                 1.493061e-02,
                                 1.463928e-02,
                                 1.433307e-02,
                                 1.401204e-02,
                                 1.367626e-02,
                                 1.332584e-02,
                                 1.296090e-02,
                                 1.258162e-02,
                                 1.218817e-02,
                                 1.178079e-02,
                                 1.135973e-02,
                                 1.092527e-02,
                                 1.047774e-02,
                                 1.001749e-02,
                                 9.544932e-03,
                                 9.060479e-03,
                                 8.564600e-03,
                                 8.057793e-03,
                                 7.540593e-03,
                                 7.013566e-03,
                                 6.477308e-03,
                                 5.932446e-03,
                                 5.379624e-03,
                                 4.819486e-03,
                                 4.252617e-03,
                                 3.679386e-03,
                                 3.099528e-03,
                                 2.511096e-03,
                                 1.907965e-03,
                                 1.274539e-03,
                                 5.767434e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor with water reflector, slab geometry
// Reflective boundary on the left
// Four energy groups

TEST_F(DiffIntegrationTests, diff9)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff9.txt";
  const std::string outputPath = "outputs/Out_diff9.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 8.079188e-01;
  std::vector<double> refFlux = {7.648793e-03,
                                 7.626735e-03,
                                 7.582679e-03,
                                 7.516748e-03,
                                 7.429124e-03,
                                 7.320051e-03,
                                 7.189832e-03,
                                 7.038829e-03,
                                 6.867464e-03,
                                 6.676215e-03,
                                 6.465618e-03,
                                 6.236260e-03,
                                 5.988780e-03,
                                 5.723862e-03,
                                 5.442222e-03,
                                 5.144596e-03,
                                 4.831706e-03,
                                 4.504208e-03,
                                 4.162599e-03,
                                 3.807056e-03,
                                 3.437149e-03,
                                 3.051364e-03,
                                 2.646277e-03,
                                 2.215181e-03,
                                 1.745821e-03,
                                 1.297178e-03,
                                 1.010386e-03,
                                 7.870014e-04,
                                 6.130044e-04,
                                 4.774763e-04,
                                 3.719120e-04,
                                 2.896870e-04,
                                 2.256412e-04,
                                 1.757554e-04,
                                 1.368991e-04,
                                 1.066339e-04,
                                 8.306043e-05,
                                 6.469941e-05,
                                 5.039857e-05,
                                 3.926048e-05,
                                 3.058617e-05,
                                 2.383129e-05,
                                 1.857193e-05,
                                 1.447804e-05,
                                 1.129273e-05,
                                 8.816078e-06,
                                 6.892681e-06,
                                 5.401832e-06,
                                 4.249973e-06,
                                 3.364819e-06,
                                 6.985454e-03,
                                 6.965306e-03,
                                 6.925066e-03,
                                 6.864845e-03,
                                 6.784810e-03,
                                 6.685184e-03,
                                 6.566243e-03,
                                 6.428318e-03,
                                 6.271794e-03,
                                 6.097107e-03,
                                 5.904744e-03,
                                 5.695240e-03,
                                 5.469175e-03,
                                 5.227168e-03,
                                 4.969872e-03,
                                 4.697959e-03,
                                 4.412103e-03,
                                 4.112948e-03,
                                 3.801066e-03,
                                 3.476888e-03,
                                 3.140600e-03,
                                 2.792008e-03,
                                 2.430356e-03,
                                 2.054130e-03,
                                 1.660925e-03,
                                 1.226756e-03,
                                 9.079304e-04,
                                 6.799572e-04,
                                 5.140388e-04,
                                 3.914711e-04,
                                 2.998174e-04,
                                 2.306109e-04,
                                 1.779546e-04,
                                 1.376551e-04,
                                 1.066747e-04,
                                 8.277809e-05,
                                 6.429893e-05,
                                 4.998224e-05,
                                 3.887494e-05,
                                 3.024861e-05,
                                 2.354379e-05,
                                 1.832901e-05,
                                 1.427034e-05,
                                 1.110830e-05,
                                 8.639994e-06,
                                 6.705004e-06,
                                 5.173536e-06,
                                 3.935605e-06,
                                 2.889690e-06,
                                 1.928748e-06,
                                 6.763269e-03,
                                 6.743758e-03,
                                 6.704790e-03,
                                 6.646472e-03,
                                 6.568967e-03,
                                 6.472490e-03,
                                 6.357310e-03,
                                 6.223746e-03,
                                 6.072169e-03,
                                 5.903002e-03,
                                 5.716711e-03,
                                 5.513809e-03,
                                 5.294850e-03,
                                 5.060421e-03,
                                 4.811133e-03,
                                 4.547612e-03,
                                 4.270479e-03,
                                 3.980335e-03,
                                 3.677745e-03,
                                 3.363237e-03,
                                 3.037363e-03,
                                 2.700888e-03,
                                 2.355286e-03,
                                 2.003904e-03,
                                 1.654489e-03,
                                 1.319802e-03,
                                 1.023586e-03,
                                 7.850593e-04,
                                 5.998308e-04,
                                 4.582970e-04,
                                 3.507899e-04,
                                 2.691777e-04,
                                 2.070957e-04,
                                 1.597200e-04,
                                 1.234419e-04,
                                 9.557124e-05,
                                 7.409802e-05,
                                 5.751387e-05,
                                 4.468038e-05,
                                 3.473344e-05,
                                 2.701360e-05,
                                 2.101498e-05,
                                 1.634751e-05,
                                 1.270846e-05,
                                 9.860604e-06,
                                 7.614890e-06,
                                 5.815863e-06,
                                 4.328515e-06,
                                 3.025290e-06,
                                 1.772383e-06,
                                 2.985878e-02,
                                 2.977260e-02,
                                 2.960049e-02,
                                 2.934293e-02,
                                 2.900063e-02,
                                 2.857455e-02,
                                 2.806588e-02,
                                 2.747607e-02,
                                 2.680676e-02,
                                 2.605987e-02,
                                 2.523755e-02,
                                 2.434219e-02,
                                 2.337649e-02,
                                 2.234344e-02,
                                 2.124649e-02,
                                 2.008965e-02,
                                 1.887781e-02,
                                 1.761721e-02,
                                 1.631626e-02,
                                 1.498694e-02,
                                 1.364702e-02,
                                 1.232358e-02,
                                 1.105857e-02,
                                 9.916985e-03,
                                 8.998488e-03,
                                 8.448167e-03,
                                 7.557967e-03,
                                 6.543373e-03,
                                 5.534170e-03,
                                 4.601266e-03,
                                 3.777002e-03,
                                 3.070331e-03,
                                 2.477124e-03,
                                 1.986725e-03,
                                 1.585913e-03,
                                 1.261150e-03,
                                 9.997603e-04,
                                 7.904721e-04,
                                 6.235776e-04,
                                 4.908983e-04,
                                 3.856466e-04,
                                 3.022468e-04,
                                 2.361484e-04,
                                 1.836481e-04,
                                 1.417279e-04,
                                 1.079134e-04,
                                 8.015128e-05,
                                 5.670543e-05,
                                 3.607405e-05,
                                 1.692934e-05};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// CYLINDER TESTS //

// Water reactor, cylindrical geometry
// Vacuum boundary on the right
// One energy group

TEST_F(DiffIntegrationTests, diff10)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff10.txt";
  const std::string outputPath = "outputs/Out_diff10.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 0.82008791;

	std::vector<double> refFlux {3.241593e-02, 3.237782e-02, 3.230168e-02, 
	3.218769e-02, 3.203609e-02, 3.184719e-02, 3.162142e-02, 3.135925e-02, 
	3.106124e-02, 3.072803e-02, 3.036032e-02, 2.995887e-02, 2.952452e-02, 
	2.905818e-02, 2.856078e-02, 2.803335e-02, 2.747693e-02, 2.689264e-02, 
	2.628162e-02, 2.564506e-02, 2.498417e-02, 2.430023e-02, 2.359450e-02, 
	2.286829e-02, 2.212292e-02, 2.135973e-02, 2.058007e-02, 1.978532e-02, 
	1.897683e-02, 1.815597e-02, 1.732412e-02, 1.648265e-02, 1.563291e-02, 
	1.477627e-02, 1.391408e-02, 1.304766e-02, 1.217834e-02, 1.130742e-02, 
	1.043620e-02, 9.565954e-03, 8.697927e-03, 7.833356e-03, 6.973451e-03, 
	6.119405e-03, 5.272384e-03, 4.433533e-03, 3.603974e-03, 2.784801e-03, 
	1.977087e-03, 1.181879e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor, cylindrical geometry
// Vacuum boundary on the right
// Two energy groups

TEST_F(DiffIntegrationTests, diff11)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff11.txt";
  const std::string outputPath = "outputs/Out_diff11.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.81752592;

  	std::vector<double> refFlux {1.318573e-02, 1.317130e-02, 1.314247e-02, 
	1.309927e-02, 1.304179e-02, 1.297011e-02, 1.288435e-02, 1.278466e-02, 
	1.267120e-02, 1.254415e-02, 1.240373e-02, 1.225016e-02, 1.208369e-02, 
	1.190461e-02, 1.171319e-02, 1.150976e-02, 1.129464e-02, 1.106818e-02, 
	1.083077e-02, 1.058277e-02, 1.032460e-02, 1.005667e-02, 9.779411e-03, 
	9.493281e-03, 9.198738e-03, 8.896256e-03, 8.586321e-03, 8.269432e-03, 
	7.946094e-03, 7.616826e-03, 7.282152e-03, 6.942605e-03, 6.598723e-03, 
	6.251052e-03, 5.900140e-03, 5.546543e-03, 5.190819e-03, 4.833530e-03, 
	4.475245e-03, 4.116541e-03, 3.758008e-03, 3.400261e-03, 3.043953e-03, 
	2.689810e-03, 2.338678e-03, 1.991617e-03, 1.650050e-03, 1.316031e-03, 
	9.926871e-04, 6.849928e-04, 1.866853e-02, 1.864810e-02, 1.860727e-02, 
	1.854611e-02, 1.846472e-02, 1.836324e-02, 1.824183e-02, 1.810069e-02, 
	1.794005e-02, 1.776018e-02, 1.756137e-02, 1.734395e-02, 1.710827e-02, 
	1.685472e-02, 1.658371e-02, 1.629569e-02, 1.599113e-02, 1.567052e-02, 
	1.533438e-02, 1.498327e-02, 1.461775e-02, 1.423841e-02, 1.384587e-02, 
	1.344077e-02, 1.302375e-02, 1.259550e-02, 1.215669e-02, 1.170803e-02, 
	1.125024e-02, 1.078406e-02, 1.031022e-02, 9.829472e-03, 9.342581e-03, 
	8.850312e-03, 8.353434e-03, 7.852717e-03, 7.348926e-03, 6.842815e-03, 
	6.335116e-03, 5.826519e-03, 5.317647e-03, 4.809006e-03, 4.300899e-03, 
	3.793296e-03, 3.285589e-03, 2.776195e-03, 2.261874e-03, 1.736555e-03, 
	1.189345e-03, 6.011226e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor, cylindrical geometry
// Reflective boundary on the right
// Two energy groups

TEST_F(DiffIntegrationTests, diff12)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff12.txt";
  const std::string outputPath = "outputs/Out_diff12.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.84995472;

	std::vector<double> refFlux {8.185633e-03, 8.185627e-03, 8.185616e-03, 
	8.185598e-03, 8.185575e-03, 8.185546e-03, 8.185512e-03, 8.185472e-03, 
	8.185428e-03, 8.185378e-03, 8.185323e-03, 8.185264e-03, 8.185201e-03, 
	8.185134e-03, 8.185063e-03, 8.184989e-03, 8.184912e-03, 8.184832e-03, 
	8.184750e-03, 8.184665e-03, 8.184579e-03, 8.184492e-03, 8.184404e-03, 
	8.184315e-03, 8.184226e-03, 8.184137e-03, 8.184049e-03, 8.183961e-03, 
	8.183875e-03, 8.183791e-03, 8.183708e-03, 8.183628e-03, 8.183550e-03, 
	8.183475e-03, 8.183403e-03, 8.183335e-03, 8.183270e-03, 8.183209e-03, 
	8.183152e-03, 8.183100e-03, 8.183052e-03, 8.183008e-03, 8.182969e-03, 
	8.182935e-03, 8.182906e-03, 8.182882e-03, 8.182862e-03, 8.182848e-03, 
	8.182838e-03, 8.182833e-03, 1.181777e-02, 1.181776e-02, 1.181775e-02, 
	1.181772e-02, 1.181769e-02, 1.181765e-02, 1.181760e-02, 1.181755e-02, 
	1.181749e-02, 1.181742e-02, 1.181734e-02, 1.181726e-02, 1.181717e-02, 
	1.181708e-02, 1.181698e-02, 1.181688e-02, 1.181677e-02, 1.181666e-02, 
	1.181655e-02, 1.181643e-02, 1.181631e-02, 1.181619e-02, 1.181607e-02, 
	1.181594e-02, 1.181582e-02, 1.181570e-02, 1.181558e-02, 1.181545e-02, 
	1.181533e-02, 1.181522e-02, 1.181510e-02, 1.181499e-02, 1.181488e-02, 
	1.181478e-02, 1.181468e-02, 1.181458e-02, 1.181450e-02, 1.181441e-02, 
	1.181433e-02, 1.181426e-02, 1.181419e-02, 1.181413e-02, 1.181408e-02, 
	1.181403e-02, 1.181399e-02, 1.181396e-02, 1.181393e-02, 1.181391e-02, 
	1.181390e-02, 1.181389e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor with water reflector, cylindrical geometry
// Vacuum boundary on the right
// Two energy groups

TEST_F(DiffIntegrationTests, diff13)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff13.txt";
  const std::string outputPath = "outputs/Out_diff13.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.82190269;

  	std::vector<double> refFlux {1.228003e-02, 1.226792e-02, 1.224371e-02, 
	1.220745e-02, 1.215918e-02, 1.209898e-02, 1.202693e-02, 1.194315e-02, 
	1.184775e-02, 1.174088e-02, 1.162270e-02, 1.149338e-02, 1.135311e-02, 
	1.120210e-02, 1.104058e-02, 1.086877e-02, 1.068694e-02, 1.049535e-02, 
	1.029428e-02, 1.008403e-02, 9.864900e-03, 9.637221e-03, 9.401322e-03, 
	9.157547e-03, 8.906252e-03, 8.647802e-03, 8.382572e-03, 8.110948e-03, 
	7.833323e-03, 7.550097e-03, 7.261678e-03, 6.968481e-03, 6.670926e-03, 
	6.369438e-03, 6.064446e-03, 5.756379e-03, 5.445671e-03, 5.132752e-03, 
	4.818045e-03, 4.501967e-03, 4.184912e-03, 3.867239e-03, 3.549251e-03, 
	3.231144e-03, 2.912942e-03, 2.594372e-03, 2.274648e-03, 1.952113e-03, 
	1.623616e-03, 1.283448e-03, 9.501955e-04, 7.197185e-04, 5.452619e-04, 
	4.131772e-04, 3.131499e-04, 2.373827e-04, 1.799797e-04, 1.364810e-04, 
	1.035123e-04, 7.852004e-05, 5.957097e-05, 4.520142e-05, 3.430286e-05, 
	2.603558e-05, 1.976335e-05, 1.500406e-05, 1.139225e-05, 8.650893e-06, 
	6.569945e-06, 4.990111e-06, 3.790572e-06, 2.879679e-06, 2.187896e-06, 
	1.662460e-06, 1.263330e-06, 9.601124e-07, 7.297365e-07, 5.546869e-07, 
	4.216644e-07, 3.205698e-07, 2.437334e-07, 1.853296e-07, 1.409333e-07, 
	1.071830e-07, 8.152453e-08, 6.201745e-08, 4.718730e-08, 3.591376e-08, 
	2.734566e-08, 2.083637e-08, 1.589488e-08, 1.214856e-08, 9.314989e-09, 
	7.180551e-09, 5.584293e-09, 4.405742e-09, 3.555778e-09, 2.969876e-09, 
	2.603196e-09, 2.427144e-09, 1.758684e-02, 1.756949e-02, 1.753483e-02, 
	1.748289e-02, 1.741376e-02, 1.732754e-02, 1.722437e-02, 1.710438e-02, 
	1.696776e-02, 1.681471e-02, 1.664546e-02, 1.646026e-02, 1.625938e-02, 
	1.604311e-02, 1.581179e-02, 1.556574e-02, 1.530533e-02, 1.503095e-02, 
	1.474299e-02, 1.444188e-02, 1.412806e-02, 1.380200e-02, 1.346416e-02, 
	1.311504e-02, 1.275515e-02, 1.238501e-02, 1.200517e-02, 1.161617e-02, 
	1.121857e-02, 1.081295e-02, 1.039990e-02, 9.980015e-03, 9.553894e-03, 
	9.122156e-03, 8.685425e-03, 8.244338e-03, 7.799545e-03, 7.351718e-03, 
	6.901562e-03, 6.449832e-03, 5.997374e-03, 5.545181e-03, 5.094502e-03, 
	4.647021e-03, 4.205175e-03, 3.772687e-03, 3.355489e-03, 2.963306e-03, 
	2.612373e-03, 2.330098e-03, 2.161680e-03, 1.909146e-03, 1.632903e-03, 
	1.365372e-03, 1.122709e-03, 9.114054e-04, 7.324437e-04, 5.838744e-04, 
	4.623745e-04, 3.641614e-04, 2.855013e-04, 2.229699e-04, 1.735636e-04, 
	1.347257e-04, 1.043257e-04, 8.061634e-05, 6.218212e-05, 4.788728e-05, 
	3.682761e-05, 2.828788e-05, 2.170526e-05, 1.663884e-05, 1.274452e-05, 
	9.754583e-06, 7.461323e-06, 5.703978e-06, 4.358366e-06, 3.328733e-06, 
	2.541363e-06, 1.939578e-06, 1.479856e-06, 1.128810e-06, 8.608505e-07, 
	6.563838e-07, 5.004150e-07, 3.814773e-07, 2.908074e-07, 2.217116e-07, 
	1.690803e-07, 1.290153e-07, 9.854520e-08, 7.540739e-08, 5.788156e-08, 
	4.466306e-08, 3.476648e-08, 2.745264e-08, 2.217376e-08, 1.853261e-08, 
	1.625281e-08, 1.515792e-08};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// SPHERE TESTS //

// Water reactor, spherical geometry
// Vacuum boundary on the right
// One energy group

TEST_F(DiffIntegrationTests, diff14)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff14.txt";
  const std::string outputPath = "outputs/Out_diff14.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.79503548;

  	std::vector<double> refFlux {3.322464e-02, 3.318274e-02, 3.309902e-02, 
	3.297369e-02, 3.280702e-02, 3.259940e-02, 3.235129e-02, 3.206326e-02, 
	3.173596e-02, 3.137012e-02, 3.096658e-02, 3.052624e-02, 3.005010e-02, 
	2.953923e-02, 2.899477e-02, 2.841794e-02, 2.781002e-02, 2.717238e-02, 
	2.650643e-02, 2.581364e-02, 2.509555e-02, 2.435373e-02, 2.358981e-02, 
	2.280546e-02, 2.200238e-02, 2.118232e-02, 2.034704e-02, 1.949834e-02, 
	1.863803e-02, 1.776792e-02, 1.688986e-02, 1.600569e-02, 1.511725e-02, 
	1.422637e-02, 1.333489e-02, 1.244461e-02, 1.155733e-02, 1.067481e-02, 
	9.798819e-03, 8.931052e-03, 8.073189e-03, 7.226868e-03, 6.393682e-03, 
	5.575174e-03, 4.772838e-03, 3.988113e-03, 3.222377e-03, 2.476950e-03, 
	1.753085e-03, 1.051969e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor, spherical geometry
// Vacuum boundary on the right
// Two energy groups

TEST_F(DiffIntegrationTests, diff15)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff15.txt";
  const std::string outputPath = "outputs/Out_diff15.txt";
  const std::string traceLevel = "DEBUG";
  
  const double kEffRef = 0.79273742;

  std::vector<double> refFlux {1.384906e-02, 1.383188e-02, 1.379754e-02, 
	1.374614e-02, 1.367777e-02, 1.359260e-02, 1.349082e-02, 1.337265e-02, 
	1.323836e-02, 1.308824e-02, 1.292263e-02, 1.274190e-02, 1.254644e-02, 
	1.233669e-02, 1.211311e-02, 1.187619e-02, 1.162647e-02, 1.136447e-02, 
	1.109077e-02, 1.080598e-02, 1.051071e-02, 1.020560e-02, 9.891314e-03, 
	9.568519e-03, 9.237910e-03, 8.900194e-03, 8.556086e-03, 8.206315e-03, 
	7.851615e-03, 7.492729e-03, 7.130402e-03, 6.765384e-03, 6.398423e-03, 
	6.030269e-03, 5.661668e-03, 5.293362e-03, 4.926087e-03, 4.560575e-03, 
	4.197552e-03, 3.837740e-03, 3.481862e-03, 3.130647e-03, 2.784849e-03, 
	2.445271e-03, 2.112808e-03, 1.788522e-03, 1.473774e-03, 1.170433e-03, 
	8.812491e-04, 6.104600e-04, 1.913515e-02, 1.911141e-02, 1.906397e-02, 
	1.899294e-02, 1.889848e-02, 1.878081e-02, 1.864018e-02, 1.847690e-02, 
	1.829135e-02, 1.808394e-02, 1.785512e-02, 1.760540e-02, 1.733534e-02, 
	1.704553e-02, 1.673662e-02, 1.640927e-02, 1.606423e-02, 1.570223e-02, 
	1.532407e-02, 1.493058e-02, 1.452261e-02, 1.410104e-02, 1.366679e-02, 
	1.322079e-02, 1.276399e-02, 1.229737e-02, 1.182192e-02, 1.133864e-02, 
	1.084855e-02, 1.035268e-02, 9.852047e-03, 9.347691e-03, 8.840642e-03, 
	8.331930e-03, 7.822577e-03, 7.313591e-03, 6.805964e-03, 6.300664e-03, 
	5.798620e-03, 5.300705e-03, 4.807711e-03, 4.320303e-03, 3.838942e-03, 
	3.363763e-03, 2.894371e-03, 2.429496e-03, 1.966417e-03, 1.499994e-03, 
	1.021039e-03, 5.135808e-04};
 
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor, spherical geometry
// Reflective boundary on the right
// Two energy groups

TEST_F(DiffIntegrationTests, diff16)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff16.txt";
  const std::string outputPath = "outputs/Out_diff16.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.8495993;

	std::vector<double> refFlux {8.185273e-03, 8.185273e-03, 8.185271e-03, 
	8.185270e-03, 8.185267e-03, 8.185264e-03, 8.185261e-03, 8.185257e-03, 
	8.185252e-03, 8.185247e-03, 8.185241e-03, 8.185235e-03, 8.185229e-03, 
	8.185222e-03, 8.185215e-03, 8.185207e-03, 8.185199e-03, 8.185191e-03, 
	8.185183e-03, 8.185174e-03, 8.185166e-03, 8.185157e-03, 8.185148e-03, 
	8.185139e-03, 8.185130e-03, 8.185122e-03, 8.185113e-03, 8.185104e-03, 
	8.185096e-03, 8.185088e-03, 8.185080e-03, 8.185072e-03, 8.185065e-03, 
	8.185058e-03, 8.185051e-03, 8.185044e-03, 8.185038e-03, 8.185033e-03, 
	8.185027e-03, 8.185023e-03, 8.185018e-03, 8.185014e-03, 8.185011e-03, 
	8.185008e-03, 8.185005e-03, 8.185003e-03, 8.185001e-03, 8.185000e-03, 
	8.184999e-03, 8.184999e-03, 1.181505e-02, 1.181505e-02, 1.181505e-02, 
	1.181505e-02, 1.181504e-02, 1.181504e-02, 1.181504e-02, 1.181503e-02, 
	1.181502e-02, 1.181502e-02, 1.181501e-02, 1.181500e-02, 1.181499e-02, 
	1.181499e-02, 1.181498e-02, 1.181497e-02, 1.181496e-02, 1.181495e-02, 
	1.181494e-02, 1.181492e-02, 1.181491e-02, 1.181490e-02, 1.181489e-02, 
	1.181488e-02, 1.181487e-02, 1.181486e-02, 1.181485e-02, 1.181484e-02, 
	1.181482e-02, 1.181481e-02, 1.181480e-02, 1.181479e-02, 1.181478e-02, 
	1.181478e-02, 1.181477e-02, 1.181476e-02, 1.181475e-02, 1.181474e-02, 
	1.181474e-02, 1.181473e-02, 1.181472e-02, 1.181472e-02, 1.181472e-02, 
	1.181471e-02, 1.181471e-02, 1.181471e-02, 1.181470e-02, 1.181470e-02, 
	1.181470e-02, 1.181470e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Water reactor with water reflector, spherical geometry
// Vacuum boundary on the right
// Two energy groups

TEST_F(DiffIntegrationTests, diff17)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff17.txt";
  const std::string outputPath = "outputs/Out_diff17.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.80248177;

  	std::vector<double> refFlux {1.281795e-02, 1.280355e-02, 1.277478e-02, 
	1.273170e-02, 1.267439e-02, 1.260297e-02, 1.251759e-02, 1.241842e-02, 
	1.230565e-02, 1.217952e-02, 1.204028e-02, 1.188820e-02, 1.172360e-02, 
	1.154681e-02, 1.135817e-02, 1.115806e-02, 1.094689e-02, 1.072508e-02, 
	1.049305e-02, 1.025128e-02, 1.000024e-02, 9.740423e-03, 9.472339e-03, 
	9.196512e-03, 8.913479e-03, 8.623791e-03, 8.328006e-03, 8.026694e-03, 
	7.720432e-03, 7.409804e-03, 7.095399e-03, 6.777809e-03, 6.457631e-03, 
	6.135458e-03, 5.811887e-03, 5.487510e-03, 5.162912e-03, 4.838674e-03, 
	4.515361e-03, 4.193525e-03, 3.873687e-03, 3.556331e-03, 3.241877e-03, 
	2.930645e-03, 2.622790e-03, 2.318198e-03, 2.016303e-03, 1.715782e-03, 
	1.414032e-03, 1.106283e-03, 8.099283e-04, 6.074008e-04, 4.557018e-04, 
	3.420229e-04, 2.567982e-04, 1.928787e-04, 1.449193e-04, 1.089211e-04, 
	8.189102e-05, 6.158767e-05, 4.633185e-05, 3.486498e-05, 2.624332e-05, 
	1.975894e-05, 1.488058e-05, 1.120945e-05, 8.446033e-06, 6.365353e-06, 
	4.798330e-06, 3.617867e-06, 2.728395e-06, 2.058027e-06, 1.552678e-06, 
	1.171645e-06, 8.842859e-07, 6.675267e-07, 5.039900e-07, 3.805838e-07, 
	2.874430e-07, 2.171322e-07, 1.640460e-07, 1.239578e-07, 9.367991e-08, 
	7.080775e-08, 5.352705e-08, 4.046870e-08, 3.059932e-08, 2.313874e-08, 
	1.749789e-08, 1.323185e-08, 1.000452e-08, 7.561878e-09, 5.711913e-09, 
	4.309354e-09, 3.244211e-09, 2.433077e-09, 1.812557e-09, 1.334272e-09, 
	9.610679e-10, 6.641026e-10, 1.824241e-02, 1.822192e-02, 1.818097e-02, 
	1.811966e-02, 1.803810e-02, 1.793646e-02, 1.781495e-02, 1.767381e-02, 
	1.751332e-02, 1.733381e-02, 1.713565e-02, 1.691922e-02, 1.668496e-02, 
	1.643335e-02, 1.616488e-02, 1.588010e-02, 1.557957e-02, 1.526388e-02, 
	1.493367e-02, 1.458959e-02, 1.423231e-02, 1.386254e-02, 1.348101e-02, 
	1.308845e-02, 1.268565e-02, 1.227336e-02, 1.185241e-02, 1.142359e-02, 
	1.098772e-02, 1.054564e-02, 1.009819e-02, 9.646213e-03, 9.190560e-03, 
	8.732085e-03, 8.271645e-03, 7.810101e-03, 7.348319e-03, 6.887176e-03, 
	6.427565e-03, 5.970419e-03, 5.516735e-03, 5.067628e-03, 4.624426e-03, 
	4.188817e-03, 3.763122e-03, 3.350743e-03, 2.956934e-03, 2.590113e-03, 
	2.264102e-03, 2.001933e-03, 1.840992e-03, 1.611197e-03, 1.365527e-03, 
	1.131461e-03, 9.220217e-04, 7.418515e-04, 5.909657e-04, 4.670288e-04, 
	3.666985e-04, 2.863882e-04, 2.226741e-04, 1.724892e-04, 1.331930e-04, 
	1.025727e-04, 7.881015e-05, 6.043282e-05, 4.626179e-05, 3.536154e-05, 
	2.699508e-05, 2.058525e-05, 1.568228e-05, 1.193708e-05, 9.079683e-06, 
	6.901895e-06, 5.243573e-06, 3.981798e-06, 3.022402e-06, 2.293351e-06, 
	1.739626e-06, 1.319250e-06, 1.000232e-06, 7.582138e-07, 5.746608e-07, 
	4.354824e-07, 3.299711e-07, 2.499948e-07, 1.893799e-07, 1.434410e-07, 
	1.086233e-07, 8.222990e-08, 6.221450e-08, 4.702403e-08, 3.547854e-08, 
	2.667992e-08, 1.994210e-08, 1.473751e-08, 1.065556e-08, 7.369892e-09, 
	4.611743e-09, 2.147230e-09};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor, slab geometry
// Reflective boundary on the right
// One energy group
// non uniform grid test

TEST_F(DiffIntegrationTests, diff18)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff18.txt";
  const std::string outputPath = "outputs/Out_diff18.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 1.224089e+00;

	std::vector<double> refFlux {5.598294e-02, 5.576760e-02, 5.533776e-02, 
	5.469506e-02, 5.384199e-02, 5.278181e-02, 5.151860e-02, 5.005724e-02, 
	4.840332e-02, 4.656322e-02, 4.454401e-02, 4.235347e-02, 4.000000e-02, 
	3.749267e-02, 3.484112e-02, 3.205555e-02, 2.914667e-02, 2.612567e-02, 
	2.300417e-02, 1.979419e-02, 1.760343e-02, 1.650053e-02, 1.539058e-02, 
	1.427405e-02, 1.315141e-02, 1.202316e-02, 1.088977e-02, 9.751720e-03, 
	8.609505e-03, 7.463609e-03, 6.314524e-03, 5.162740e-03, 4.008748e-03, 
	2.853044e-03, 1.696120e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor, cylindrical geometry
// Vacuum boundary
// One energy group
// non uniform grid test

TEST_F(DiffIntegrationTests, diff19)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff19.txt";
  const std::string outputPath = "outputs/Out_diff19.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 1.156731e+00;

  std::vector<double> refFlux {5.896301e-02, 5.869733e-02, 5.816775e-02, 
	5.737787e-02, 5.633300e-02, 5.504020e-02, 5.350819e-02, 5.174726e-02, 
	4.976926e-02, 4.758743e-02, 4.521637e-02, 4.267190e-02, 3.997094e-02, 
	3.713138e-02, 3.417197e-02, 3.111216e-02, 2.797198e-02, 2.477184e-02, 
	2.153245e-02, 1.827461e-02, 1.610426e-02, 1.502088e-02, 1.394006e-02, 
	1.286254e-02, 1.178909e-02, 1.072043e-02, 9.657312e-03, 8.600464e-03, 
	7.550608e-03, 6.508462e-03, 5.474734e-03, 4.450121e-03, 3.435314e-03, 
	2.430993e-03, 1.437825e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor, spherical geometry
// Vacuum boundary
// One energy group
// non uniform grid test

TEST_F(DiffIntegrationTests, diff20)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff20.txt";
  const std::string outputPath = "outputs/Out_diff20.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 1.083326e+00;

  std::vector<double> refFlux {6.176523e-02, 6.144873e-02, 6.081858e-02, 
	5.988060e-02, 5.864342e-02, 5.711841e-02, 5.531954e-02, 5.326322e-02, 
	5.096814e-02, 4.845508e-02, 4.574662e-02, 4.286698e-02, 3.984171e-02, 
	3.669739e-02, 3.346143e-02, 3.016170e-02, 2.682625e-02, 2.348307e-02, 
	2.015972e-02, 1.688312e-02, 1.474717e-02, 1.368915e-02, 1.264198e-02, 
	1.160654e-02, 1.058368e-02, 9.574251e-03, 8.579074e-03, 7.598947e-03, 
	6.634645e-03, 5.686922e-03, 4.756508e-03, 3.844109e-03, 2.950402e-03, 
	2.076042e-03, 1.221656e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor with graphite reflector, slab geometry
// Zero in-current at both boundaries
// One energy groups
// Adjoint calculation

TEST_F(DiffIntegrationTests, diff21)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff21.txt";
  const std::string outputPath = "outputs/Out_diff21.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 9.693342e-01;
  std::vector<double> refFlux = {7.933976e-04,
                                 1.198040e-03,
                                 1.602875e-03,
                                 2.007970e-03,
                                 2.413389e-03,
                                 2.819197e-03,
                                 3.225461e-03,
                                 3.632245e-03,
                                 4.039617e-03,
                                 4.447640e-03,
                                 4.856382e-03,
                                 5.265908e-03,
                                 5.676285e-03,
                                 6.087578e-03,
                                 6.499854e-03,
                                 6.913181e-03,
                                 7.327623e-03,
                                 7.743249e-03,
                                 8.160125e-03,
                                 8.578319e-03,
                                 8.997899e-03,
                                 9.418931e-03,
                                 9.841485e-03,
                                 1.026563e-02,
                                 1.069143e-02,
                                 1.109939e-02,
                                 1.147572e-02,
                                 1.183957e-02,
                                 1.219054e-02,
                                 1.252826e-02,
                                 1.285235e-02,
                                 1.316246e-02,
                                 1.345826e-02,
                                 1.373944e-02,
                                 1.400567e-02,
                                 1.425669e-02,
                                 1.449221e-02,
                                 1.471198e-02,
                                 1.491577e-02,
                                 1.510335e-02,
                                 1.527453e-02,
                                 1.542912e-02,
                                 1.556695e-02,
                                 1.568788e-02,
                                 1.579178e-02,
                                 1.587853e-02,
                                 1.594804e-02,
                                 1.600024e-02,
                                 1.603507e-02,
                                 1.605249e-02,
                                 1.605249e-02,
                                 1.603507e-02,
                                 1.600024e-02,
                                 1.594804e-02,
                                 1.587853e-02,
                                 1.579178e-02,
                                 1.568788e-02,
                                 1.556695e-02,
                                 1.542912e-02,
                                 1.527453e-02,
                                 1.510335e-02,
                                 1.491577e-02,
                                 1.471198e-02,
                                 1.449221e-02,
                                 1.425669e-02,
                                 1.400567e-02,
                                 1.373944e-02,
                                 1.345826e-02,
                                 1.316246e-02,
                                 1.285235e-02,
                                 1.252826e-02,
                                 1.219054e-02,
                                 1.183957e-02,
                                 1.147572e-02,
                                 1.109939e-02,
                                 1.069143e-02,
                                 1.026563e-02,
                                 9.841485e-03,
                                 9.418931e-03,
                                 8.997899e-03,
                                 8.578319e-03,
                                 8.160125e-03,
                                 7.743249e-03,
                                 7.327623e-03,
                                 6.913181e-03,
                                 6.499854e-03,
                                 6.087578e-03,
                                 5.676285e-03,
                                 5.265908e-03,
                                 4.856382e-03,
                                 4.447640e-03,
                                 4.039617e-03,
                                 3.632245e-03,
                                 3.225461e-03,
                                 2.819197e-03,
                                 2.413389e-03,
                                 2.007970e-03,
                                 1.602875e-03,
                                 1.198040e-03,
                                 7.933976e-04};
                                 
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  
  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(DiffIntegrationTests, diff22)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff22.txt";
  const std::string outputPath = "outputs/Out_diff22.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 1.332284e+00;
  std::vector<double> refFlux = {1.445836e-02,
                                 1.444450e-02,
                                 1.441680e-02,
                                 1.437529e-02,
                                 1.432000e-02,
                                 1.425098e-02,
                                 1.416831e-02,
                                 1.407206e-02,
                                 1.396232e-02,
                                 1.383920e-02,
                                 1.370282e-02,
                                 1.355332e-02,
                                 1.339082e-02,
                                 1.321549e-02,
                                 1.302750e-02,
                                 1.282703e-02,
                                 1.261427e-02,
                                 1.238942e-02,
                                 1.215271e-02,
                                 1.190435e-02,
                                 1.164460e-02,
                                 1.137370e-02,
                                 1.109191e-02,
                                 1.079950e-02,
                                 1.049677e-02,
                                 1.018399e-02,
                                 9.861485e-03,
                                 9.529557e-03,
                                 9.188534e-03,
                                 8.838750e-03,
                                 8.480549e-03,
                                 8.114285e-03,
                                 7.740321e-03,
                                 7.359032e-03,
                                 6.970800e-03,
                                 6.576019e-03,
                                 6.175093e-03,
                                 5.768436e-03,
                                 5.356474e-03,
                                 4.939647e-03,
                                 4.518404e-03,
                                 4.093212e-03,
                                 3.664551e-03,
                                 3.232921e-03,
                                 2.798839e-03,
                                 2.362846e-03,
                                 1.925511e-03,
                                 1.487430e-03,
                                 1.049234e-03,
                                 6.115988e-04,
                                 1.649772e-02,
                                 1.648191e-02,
                                 1.645030e-02,
                                 1.640293e-02,
                                 1.633983e-02,
                                 1.626108e-02,
                                 1.616674e-02,
                                 1.605690e-02,
                                 1.593168e-02,
                                 1.579118e-02,
                                 1.563556e-02,
                                 1.546494e-02,
                                 1.527950e-02,
                                 1.507942e-02,
                                 1.486489e-02,
                                 1.463610e-02,
                                 1.439329e-02,
                                 1.413668e-02,
                                 1.386651e-02,
                                 1.358306e-02,
                                 1.328658e-02,
                                 1.297736e-02,
                                 1.265570e-02,
                                 1.232191e-02,
                                 1.197629e-02,
                                 1.161919e-02,
                                 1.125094e-02,
                                 1.087190e-02,
                                 1.048241e-02,
                                 1.008286e-02,
                                 9.673630e-03,
                                 9.255096e-03,
                                 8.827660e-03,
                                 8.391724e-03,
                                 7.947699e-03,
                                 7.496002e-03,
                                 7.037055e-03,
                                 6.571286e-03,
                                 6.099126e-03,
                                 5.621009e-03,
                                 5.137373e-03,
                                 4.648656e-03,
                                 4.155295e-03,
                                 3.657728e-03,
                                 3.156388e-03,
                                 2.651704e-03,
                                 2.144098e-03,
                                 1.633984e-03,
                                 1.121763e-03,
                                 6.078209e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  
  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Graphite reactor with graphite reflector, slab geometry
// Zero in-current at both boundaries
// One energy groups
// All eigenmodes calculation

TEST_F(DiffIntegrationTests, diff23)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff23.txt";
  const std::string outputPath = "outputs/Out_diff23.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 9.693342e-01;

	std::vector<double> refFlux {7.121772e-03, 1.075396e-02, 1.438788e-02, 
	1.802413e-02, 2.166329e-02, 2.530595e-02, 2.895269e-02, 3.260411e-02, 
	3.626080e-02, 3.992334e-02, 4.359232e-02, 4.726835e-02, 5.095201e-02, 
	5.464390e-02, 5.834462e-02, 6.205476e-02, 6.577491e-02, 6.950569e-02, 
	7.324770e-02, 7.700153e-02, 8.076780e-02, 8.454712e-02, 8.834008e-02, 
	9.214732e-02, 9.596943e-02, 9.963144e-02, 1.030096e-01, 1.062759e-01, 
	1.094267e-01, 1.124586e-01, 1.153684e-01, 1.181528e-01, 1.208089e-01, 
	1.233337e-01, 1.257245e-01, 1.279788e-01, 1.300940e-01, 1.320679e-01, 
	1.338983e-01, 1.355833e-01, 1.371209e-01, 1.385096e-01, 1.397478e-01, 
	1.408342e-01, 1.417676e-01, 1.425470e-01, 1.431716e-01, 1.436406e-01, 
	1.439535e-01, 1.441101e-01, 1.441101e-01, 1.439535e-01, 1.436406e-01, 
	1.431716e-01, 1.425470e-01, 1.417676e-01, 1.408342e-01, 1.397478e-01, 
	1.385096e-01, 1.371209e-01, 1.355833e-01, 1.338983e-01, 1.320679e-01, 
	1.300940e-01, 1.279788e-01, 1.257245e-01, 1.233337e-01, 1.208089e-01, 
	1.181528e-01, 1.153684e-01, 1.124586e-01, 1.094267e-01, 1.062759e-01, 
	1.030096e-01, 9.963144e-02, 9.596943e-02, 9.214732e-02, 8.834008e-02, 
	8.454712e-02, 8.076780e-02, 7.700153e-02, 7.324770e-02, 6.950569e-02, 
	6.577491e-02, 6.205476e-02, 5.834462e-02, 5.464390e-02, 5.095201e-02, 
	4.726835e-02, 4.359232e-02, 3.992334e-02, 3.626080e-02, 3.260411e-02, 
	2.895269e-02, 2.530595e-02, 2.166329e-02, 1.802413e-02, 1.438788e-02, 
	1.075396e-02, 7.121772e-03};
  
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// slab geometry, memory test

TEST_F(DiffIntegrationTests, memTestDiffSlab)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff1.txt";
  const std::string outputPath = "outputs/Out_diff1MEM.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

// cylindrical geometry, memory test

TEST_F(DiffIntegrationTests, memTestDiffCylinder)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff10.txt";
  const std::string outputPath = "outputs/Out_diff10MEM.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

// spherical geometry, memory test

TEST_F(DiffIntegrationTests, memTestDiffSpherical)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff14.txt";
  const std::string outputPath = "outputs/Out_diff14MEM.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}