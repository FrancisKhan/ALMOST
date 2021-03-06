#include "gtest/gtest.h"
#include "TestHelper.h"

class DiffIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

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
  const double kEffRef = 1.332284e+00 ;
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
  const double kEffRef = 8.190919e-01;
  std::vector<double> refFlux = {3.229032e-02,
                                 3.225312e-02,
                                 3.217879e-02,
                                 3.206749e-02,
                                 3.191942e-02,
                                 3.173489e-02,
                                 3.151426e-02,
                                 3.125796e-02,
                                 3.096650e-02,
                                 3.064044e-02,
                                 3.028043e-02,
                                 2.988716e-02,
                                 2.946139e-02,
                                 2.900394e-02,
                                 2.851567e-02,
                                 2.799752e-02,
                                 2.745046e-02,
                                 2.687551e-02,
                                 2.627374e-02,
                                 2.564625e-02,
                                 2.499420e-02,
                                 2.431875e-02,
                                 2.362111e-02,
                                 2.290254e-02,
                                 2.216429e-02,
                                 2.140764e-02,
                                 2.063391e-02,
                                 1.984441e-02,
                                 1.904047e-02,
                                 1.822345e-02,
                                 1.739468e-02,
                                 1.655554e-02,
                                 1.570737e-02,
                                 1.485154e-02,
                                 1.398939e-02,
                                 1.312229e-02,
                                 1.225158e-02,
                                 1.137858e-02,
                                 1.050463e-02,
                                 9.631041e-03,
                                 8.759107e-03,
                                 7.890111e-03,
                                 7.025320e-03,
                                 6.165979e-03,
                                 5.313316e-03,
                                 4.468537e-03,
                                 3.632825e-03,
                                 2.807340e-03,
                                 1.993218e-03,
                                 1.191570e-03};

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
  const double kEffRef = 8.175169e-01;
  std::vector<double> refFlux = {1.318542e-02,
                                 1.317099e-02,
                                 1.314215e-02,
                                 1.309896e-02,
                                 1.304149e-02,
                                 1.296982e-02,
                                 1.288408e-02,
                                 1.278440e-02,
                                 1.267096e-02,
                                 1.254393e-02,
                                 1.240352e-02,
                                 1.224997e-02,
                                 1.208353e-02,
                                 1.190446e-02,
                                 1.171307e-02,
                                 1.150966e-02,
                                 1.129456e-02,
                                 1.106813e-02,
                                 1.083074e-02,
                                 1.058276e-02,
                                 1.032461e-02,
                                 1.005670e-02,
                                 9.779471e-03,
                                 9.493361e-03,
                                 9.198837e-03,
                                 8.896372e-03,
                                 8.586453e-03,
                                 8.269577e-03,
                                 7.946252e-03,
                                 7.616995e-03,
                                 7.282329e-03,
                                 6.942789e-03,
                                 6.598912e-03,
                                 6.251244e-03,
                                 5.900333e-03,
                                 5.546735e-03,
                                 5.191008e-03,
                                 4.833715e-03,
                                 4.475423e-03,
                                 4.116712e-03,
                                 3.758170e-03,
                                 3.400412e-03,
                                 3.044092e-03,
                                 2.689936e-03,
                                 2.338789e-03,
                                 1.991713e-03,
                                 1.650131e-03,
                                 1.316096e-03,
                                 9.927368e-04,
                                 6.850272e-04,
                                 1.866810e-02,
                                 1.864767e-02,
                                 1.860685e-02,
                                 1.854570e-02,
                                 1.846432e-02,
                                 1.836286e-02,
                                 1.824146e-02,
                                 1.810034e-02,
                                 1.793973e-02,
                                 1.775988e-02,
                                 1.756109e-02,
                                 1.734370e-02,
                                 1.710805e-02,
                                 1.685453e-02,
                                 1.658355e-02,
                                 1.629556e-02,
                                 1.599103e-02,
                                 1.567045e-02,
                                 1.533435e-02,
                                 1.498326e-02,
                                 1.461777e-02,
                                 1.423847e-02,
                                 1.384596e-02,
                                 1.344088e-02,
                                 1.302389e-02,
                                 1.259566e-02,
                                 1.215687e-02,
                                 1.170823e-02,
                                 1.125046e-02,
                                 1.078429e-02,
                                 1.031046e-02,
                                 9.829725e-03,
                                 9.342841e-03,
                                 8.850575e-03,
                                 8.353699e-03,
                                 7.852981e-03,
                                 7.349186e-03,
                                 6.843069e-03,
                                 6.335361e-03,
                                 5.826753e-03,
                                 5.317868e-03,
                                 4.809212e-03,
                                 4.301089e-03,
                                 3.793467e-03,
                                 3.285740e-03,
                                 2.776325e-03,
                                 2.261982e-03,
                                 1.736638e-03,
                                 1.189402e-03,
                                 6.011519e-04};

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
  const double kEffRef = 8.499455e-01;
  std::vector<double> refFlux = {8.184848e-03,
                                 8.184845e-03,
                                 8.184840e-03,
                                 8.184832e-03,
                                 8.184821e-03,
                                 8.184808e-03,
                                 8.184793e-03,
                                 8.184775e-03,
                                 8.184754e-03,
                                 8.184732e-03,
                                 8.184707e-03,
                                 8.184680e-03,
                                 8.184652e-03,
                                 8.184621e-03,
                                 8.184589e-03,
                                 8.184555e-03,
                                 8.184520e-03,
                                 8.184484e-03,
                                 8.184446e-03,
                                 8.184408e-03,
                                 8.184369e-03,
                                 8.184329e-03,
                                 8.184289e-03,
                                 8.184248e-03,
                                 8.184208e-03,
                                 8.184168e-03,
                                 8.184127e-03,
                                 8.184088e-03,
                                 8.184048e-03,
                                 8.184010e-03,
                                 8.183972e-03,
                                 8.183936e-03,
                                 8.183900e-03,
                                 8.183866e-03,
                                 8.183834e-03,
                                 8.183803e-03,
                                 8.183773e-03,
                                 8.183745e-03,
                                 8.183720e-03,
                                 8.183696e-03,
                                 8.183674e-03,
                                 8.183654e-03,
                                 8.183636e-03,
                                 8.183621e-03,
                                 8.183608e-03,
                                 8.183597e-03,
                                 8.183588e-03,
                                 8.183581e-03,
                                 8.183577e-03,
                                 8.183575e-03,
                                 1.181670e-02,
                                 1.181670e-02,
                                 1.181669e-02,
                                 1.181668e-02,
                                 1.181666e-02,
                                 1.181665e-02,
                                 1.181662e-02,
                                 1.181660e-02,
                                 1.181657e-02,
                                 1.181654e-02,
                                 1.181651e-02,
                                 1.181647e-02,
                                 1.181643e-02,
                                 1.181639e-02,
                                 1.181634e-02,
                                 1.181629e-02,
                                 1.181625e-02,
                                 1.181620e-02,
                                 1.181614e-02,
                                 1.181609e-02,
                                 1.181604e-02,
                                 1.181598e-02,
                                 1.181593e-02,
                                 1.181587e-02,
                                 1.181581e-02,
                                 1.181576e-02,
                                 1.181570e-02,
                                 1.181565e-02,
                                 1.181559e-02,
                                 1.181554e-02,
                                 1.181549e-02,
                                 1.181544e-02,
                                 1.181539e-02,
                                 1.181534e-02,
                                 1.181529e-02,
                                 1.181525e-02,
                                 1.181521e-02,
                                 1.181517e-02,
                                 1.181514e-02,
                                 1.181510e-02,
                                 1.181507e-02,
                                 1.181505e-02,
                                 1.181502e-02,
                                 1.181500e-02,
                                 1.181498e-02,
                                 1.181497e-02,
                                 1.181495e-02,
                                 1.181494e-02,
                                 1.181494e-02,
                                 1.181493e-02};

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
  const double kEffRef = 8.218924e-01;
  std::vector<double> refFlux = {1.227968e-02,
                                 1.226757e-02,
                                 1.224337e-02,
                                 1.220711e-02,
                                 1.215885e-02,
                                 1.209866e-02,
                                 1.202662e-02,
                                 1.194286e-02,
                                 1.184747e-02,
                                 1.174062e-02,
                                 1.162246e-02,
                                 1.149316e-02,
                                 1.135291e-02,
                                 1.120193e-02,
                                 1.104042e-02,
                                 1.086864e-02,
                                 1.068683e-02,
                                 1.049526e-02,
                                 1.029422e-02,
                                 1.008399e-02,
                                 9.864887e-03,
                                 9.637232e-03,
                                 9.401355e-03,
                                 9.157601e-03,
                                 8.906326e-03,
                                 8.647896e-03,
                                 8.382684e-03,
                                 8.111077e-03,
                                 7.833467e-03,
                                 7.550254e-03,
                                 7.261847e-03,
                                 6.968661e-03,
                                 6.671114e-03,
                                 6.369633e-03,
                                 6.064645e-03,
                                 5.756581e-03,
                                 5.445874e-03,
                                 5.132953e-03,
                                 4.818244e-03,
                                 4.502161e-03,
                                 4.185100e-03,
                                 3.867420e-03,
                                 3.549422e-03,
                                 3.231304e-03,
                                 2.913091e-03,
                                 2.594507e-03,
                                 2.274769e-03,
                                 1.952219e-03,
                                 1.623706e-03,
                                 1.283519e-03,
                                 9.502481e-04,
                                 7.197583e-04,
                                 5.452921e-04,
                                 4.132001e-04,
                                 3.131672e-04,
                                 2.373959e-04,
                                 1.799896e-04,
                                 1.364885e-04,
                                 1.035181e-04,
                                 7.852439e-05,
                                 5.957427e-05,
                                 4.520392e-05,
                                 3.430476e-05,
                                 2.603702e-05,
                                 1.976445e-05,
                                 1.500489e-05,
                                 1.139288e-05,
                                 8.651372e-06,
                                 6.570309e-06,
                                 4.990387e-06,
                                 3.790782e-06,
                                 2.879838e-06,
                                 2.188017e-06,
                                 1.662552e-06,
                                 1.263400e-06,
                                 9.601656e-07,
                                 7.297769e-07,
                                 5.547176e-07,
                                 4.216877e-07,
                                 3.205875e-07,
                                 2.437468e-07,
                                 1.853398e-07,
                                 1.409411e-07,
                                 1.071889e-07,
                                 8.152905e-08,
                                 6.202088e-08,
                                 4.718991e-08,
                                 3.591575e-08,
                                 2.734717e-08,
                                 2.083752e-08,
                                 1.589576e-08,
                                 1.214923e-08,
                                 9.315505e-09,
                                 7.180948e-09,
                                 5.584602e-09,
                                 4.405986e-09,
                                 3.555975e-09,
                                 2.970041e-09,
                                 2.603340e-09,
                                 2.427279e-09,
                                 1.758636e-02,
                                 1.756902e-02,
                                 1.753436e-02,
                                 1.748243e-02,
                                 1.741331e-02,
                                 1.732711e-02,
                                 1.722395e-02,
                                 1.710398e-02,
                                 1.696738e-02,
                                 1.681436e-02,
                                 1.664513e-02,
                                 1.645996e-02,
                                 1.625911e-02,
                                 1.604287e-02,
                                 1.581158e-02,
                                 1.556556e-02,
                                 1.530519e-02,
                                 1.503083e-02,
                                 1.474291e-02,
                                 1.444184e-02,
                                 1.412805e-02,
                                 1.380202e-02,
                                 1.346421e-02,
                                 1.311512e-02,
                                 1.275526e-02,
                                 1.238515e-02,
                                 1.200533e-02,
                                 1.161635e-02,
                                 1.121877e-02,
                                 1.081317e-02,
                                 1.040014e-02,
                                 9.980265e-03,
                                 9.554156e-03,
                                 9.122426e-03,
                                 8.685702e-03,
                                 8.244618e-03,
                                 7.799826e-03,
                                 7.351998e-03,
                                 6.901838e-03,
                                 6.450102e-03,
                                 5.997636e-03,
                                 5.545432e-03,
                                 5.094740e-03,
                                 4.647245e-03,
                                 4.205384e-03,
                                 3.772878e-03,
                                 3.355662e-03,
                                 2.963462e-03,
                                 2.612513e-03,
                                 2.330224e-03,
                                 2.161798e-03,
                                 1.909250e-03,
                                 1.632992e-03,
                                 1.365447e-03,
                                 1.122771e-03,
                                 9.114555e-04,
                                 7.324840e-04,
                                 5.839065e-04,
                                 4.624000e-04,
                                 3.641815e-04,
                                 2.855171e-04,
                                 2.229822e-04,
                                 1.735732e-04,
                                 1.347331e-04,
                                 1.043314e-04,
                                 8.062079e-05,
                                 6.218556e-05,
                                 4.788992e-05,
                                 3.682965e-05,
                                 2.828944e-05,
                                 2.170646e-05,
                                 1.663976e-05,
                                 1.274523e-05,
                                 9.755122e-06,
                                 7.461736e-06,
                                 5.704294e-06,
                                 4.358607e-06,
                                 3.328917e-06,
                                 2.541503e-06,
                                 1.939685e-06,
                                 1.479938e-06,
                                 1.128872e-06,
                                 8.608981e-07,
                                 6.564201e-07,
                                 5.004427e-07,
                                 3.814984e-07,
                                 2.908235e-07,
                                 2.217239e-07,
                                 1.690896e-07,
                                 1.290224e-07,
                                 9.855066e-08,
                                 7.541156e-08,
                                 5.788476e-08,
                                 4.466553e-08,
                                 3.476840e-08,
                                 2.745416e-08,
                                 2.217499e-08,
                                 1.853364e-08,
                                 1.625371e-08,
                                 1.515875e-08};

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
  const double kEffRef = 7.950283e-01;
  std::vector<double> refFlux = {3.322403e-02,
                                 3.318213e-02,
                                 3.309843e-02,
                                 3.297311e-02,
                                 3.280646e-02,
                                 3.259886e-02,
                                 3.235078e-02,
                                 3.206277e-02,
                                 3.173550e-02,
                                 3.136970e-02,
                                 3.096620e-02,
                                 3.052590e-02,
                                 3.004981e-02,
                                 2.953898e-02,
                                 2.899456e-02,
                                 2.841777e-02,
                                 2.780990e-02,
                                 2.717231e-02,
                                 2.650640e-02,
                                 2.581366e-02,
                                 2.509561e-02,
                                 2.435383e-02,
                                 2.358995e-02,
                                 2.280563e-02,
                                 2.200259e-02,
                                 2.118256e-02,
                                 2.034731e-02,
                                 1.949863e-02,
                                 1.863834e-02,
                                 1.776825e-02,
                                 1.689021e-02,
                                 1.600605e-02,
                                 1.511761e-02,
                                 1.422673e-02,
                                 1.333525e-02,
                                 1.244496e-02,
                                 1.155767e-02,
                                 1.067515e-02,
                                 9.799138e-03,
                                 8.931354e-03,
                                 8.073471e-03,
                                 7.227129e-03,
                                 6.393918e-03,
                                 5.575385e-03,
                                 4.773022e-03,
                                 3.988269e-03,
                                 3.222506e-03,
                                 2.477050e-03,
                                 1.753156e-03,
                                 1.052012e-03};

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
  const double kEffRef = 7.927303e-01;
  std::vector<double> refFlux = {1.384880e-02,
                                 1.383161e-02,
                                 1.379728e-02,
                                 1.374588e-02,
                                 1.367753e-02,
                                 1.359237e-02,
                                 1.349060e-02,
                                 1.337244e-02,
                                 1.323816e-02,
                                 1.308806e-02,
                                 1.292246e-02,
                                 1.274174e-02,
                                 1.254630e-02,
                                 1.233657e-02,
                                 1.211301e-02,
                                 1.187612e-02,
                                 1.162641e-02,
                                 1.136443e-02,
                                 1.109076e-02,
                                 1.080599e-02,
                                 1.051073e-02,
                                 1.020564e-02,
                                 9.891368e-03,
                                 9.568589e-03,
                                 9.237995e-03,
                                 8.900292e-03,
                                 8.556197e-03,
                                 8.206436e-03,
                                 7.851746e-03,
                                 7.492867e-03,
                                 7.130547e-03,
                                 6.765533e-03,
                                 6.398576e-03,
                                 6.030423e-03,
                                 5.661822e-03,
                                 5.293513e-03,
                                 4.926236e-03,
                                 4.560719e-03,
                                 4.197691e-03,
                                 3.837872e-03,
                                 3.481985e-03,
                                 3.130761e-03,
                                 2.784954e-03,
                                 2.445366e-03,
                                 2.112891e-03,
                                 1.788594e-03,
                                 1.473833e-03,
                                 1.170481e-03,
                                 8.812854e-04,
                                 6.104853e-04,
                                 1.913481e-02,
                                 1.911107e-02,
                                 1.906363e-02,
                                 1.899261e-02,
                                 1.889817e-02,
                                 1.878050e-02,
                                 1.863989e-02,
                                 1.847663e-02,
                                 1.829110e-02,
                                 1.808370e-02,
                                 1.785490e-02,
                                 1.760521e-02,
                                 1.733517e-02,
                                 1.704539e-02,
                                 1.673650e-02,
                                 1.640918e-02,
                                 1.606416e-02,
                                 1.570219e-02,
                                 1.532406e-02,
                                 1.493059e-02,
                                 1.452264e-02,
                                 1.410110e-02,
                                 1.366687e-02,
                                 1.322089e-02,
                                 1.276411e-02,
                                 1.229751e-02,
                                 1.182207e-02,
                                 1.133881e-02,
                                 1.084873e-02,
                                 1.035287e-02,
                                 9.852243e-03,
                                 9.347892e-03,
                                 8.840847e-03,
                                 8.332137e-03,
                                 7.822783e-03,
                                 7.313795e-03,
                                 6.806164e-03,
                                 6.300858e-03,
                                 5.798805e-03,
                                 5.300881e-03,
                                 4.807877e-03,
                                 4.320456e-03,
                                 3.839081e-03,
                                 3.363888e-03,
                                 2.894481e-03,
                                 2.429590e-03,
                                 1.966494e-03,
                                 1.500053e-03,
                                 1.021080e-03,
                                 5.136014e-04};
 
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
  const double kEffRef = 8.495969e-01;
  std::vector<double> refFlux = {8.185164e-03,
                                 8.185164e-03,
                                 8.185164e-03,
                                 8.185163e-03,
                                 8.185163e-03,
                                 8.185162e-03,
                                 8.185161e-03,
                                 8.185160e-03,
                                 8.185159e-03,
                                 8.185157e-03,
                                 8.185156e-03,
                                 8.185154e-03,
                                 8.185153e-03,
                                 8.185151e-03,
                                 8.185149e-03,
                                 8.185147e-03,
                                 8.185145e-03,
                                 8.185143e-03,
                                 8.185141e-03,
                                 8.185138e-03,
                                 8.185136e-03,
                                 8.185134e-03,
                                 8.185131e-03,
                                 8.185129e-03,
                                 8.185127e-03,
                                 8.185124e-03,
                                 8.185122e-03,
                                 8.185120e-03,
                                 8.185118e-03,
                                 8.185115e-03,
                                 8.185113e-03,
                                 8.185111e-03,
                                 8.185109e-03,
                                 8.185107e-03,
                                 8.185106e-03,
                                 8.185104e-03,
                                 8.185102e-03,
                                 8.185101e-03,
                                 8.185100e-03,
                                 8.185098e-03,
                                 8.185097e-03,
                                 8.185096e-03,
                                 8.185095e-03,
                                 8.185094e-03,
                                 8.185094e-03,
                                 8.185093e-03,
                                 8.185093e-03,
                                 8.185092e-03,
                                 8.185092e-03,
                                 8.185092e-03,
                                 1.181492e-02,
                                 1.181492e-02,
                                 1.181492e-02,
                                 1.181492e-02,
                                 1.181492e-02,
                                 1.181492e-02,
                                 1.181492e-02,
                                 1.181492e-02,
                                 1.181491e-02,
                                 1.181491e-02,
                                 1.181491e-02,
                                 1.181491e-02,
                                 1.181491e-02,
                                 1.181490e-02,
                                 1.181490e-02,
                                 1.181490e-02,
                                 1.181490e-02,
                                 1.181489e-02,
                                 1.181489e-02,
                                 1.181489e-02,
                                 1.181488e-02,
                                 1.181488e-02,
                                 1.181488e-02,
                                 1.181488e-02,
                                 1.181487e-02,
                                 1.181487e-02,
                                 1.181487e-02,
                                 1.181486e-02,
                                 1.181486e-02,
                                 1.181486e-02,
                                 1.181486e-02,
                                 1.181485e-02,
                                 1.181485e-02,
                                 1.181485e-02,
                                 1.181485e-02,
                                 1.181484e-02,
                                 1.181484e-02,
                                 1.181484e-02,
                                 1.181484e-02,
                                 1.181484e-02,
                                 1.181484e-02,
                                 1.181483e-02,
                                 1.181483e-02,
                                 1.181483e-02,
                                 1.181483e-02,
                                 1.181483e-02,
                                 1.181483e-02,
                                 1.181483e-02,
                                 1.181483e-02,
                                 1.181483e-02};

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
  const double kEffRef = 8.024734e-01;
  std::vector<double> refFlux = {1.281755e-02,
                                 1.280315e-02,
                                 1.277439e-02,
                                 1.273131e-02,
                                 1.267402e-02,
                                 1.260261e-02,
                                 1.251725e-02,
                                 1.241809e-02,
                                 1.230534e-02,
                                 1.217923e-02,
                                 1.204001e-02,
                                 1.188796e-02,
                                 1.172338e-02,
                                 1.154661e-02,
                                 1.135800e-02,
                                 1.115792e-02,
                                 1.094678e-02,
                                 1.072499e-02,
                                 1.049300e-02,
                                 1.025125e-02,
                                 1.000024e-02,
                                 9.740445e-03,
                                 9.472386e-03,
                                 9.196582e-03,
                                 8.913572e-03,
                                 8.623905e-03,
                                 8.328139e-03,
                                 8.026845e-03,
                                 7.720599e-03,
                                 7.409985e-03,
                                 7.095592e-03,
                                 6.778012e-03,
                                 6.457841e-03,
                                 6.135675e-03,
                                 5.812107e-03,
                                 5.487731e-03,
                                 5.163133e-03,
                                 4.838892e-03,
                                 4.515575e-03,
                                 4.193732e-03,
                                 3.873886e-03,
                                 3.556521e-03,
                                 3.242056e-03,
                                 2.930811e-03,
                                 2.622943e-03,
                                 2.318336e-03,
                                 2.016426e-03,
                                 1.715888e-03,
                                 1.414120e-03,
                                 1.106353e-03,
                                 8.099793e-04,
                                 6.074391e-04,
                                 4.557305e-04,
                                 3.420445e-04,
                                 2.568144e-04,
                                 1.928909e-04,
                                 1.449285e-04,
                                 1.089280e-04,
                                 8.189618e-05,
                                 6.159155e-05,
                                 4.633477e-05,
                                 3.486718e-05,
                                 2.624497e-05,
                                 1.976018e-05,
                                 1.488152e-05,
                                 1.121015e-05,
                                 8.446566e-06,
                                 6.365755e-06,
                                 4.798633e-06,
                                 3.618096e-06,
                                 2.728567e-06,
                                 2.058157e-06,
                                 1.552776e-06,
                                 1.171719e-06,
                                 8.843416e-07,
                                 6.675688e-07,
                                 5.040217e-07,
                                 3.806078e-07,
                                 2.874611e-07,
                                 2.171459e-07,
                                 1.640563e-07,
                                 1.239656e-07,
                                 9.368581e-08,
                                 7.081221e-08,
                                 5.353043e-08,
                                 4.047126e-08,
                                 3.060125e-08,
                                 2.314020e-08,
                                 1.749899e-08,
                                 1.323269e-08,
                                 1.000515e-08,
                                 7.562355e-09,
                                 5.712273e-09,
                                 4.309626e-09,
                                 3.244416e-09,
                                 2.433231e-09,
                                 1.812671e-09,
                                 1.334356e-09,
                                 9.611285e-10,
                                 6.641444e-10,
                                 1.824188e-02,
                                 1.822139e-02,
                                 1.818045e-02,
                                 1.811915e-02,
                                 1.803761e-02,
                                 1.793598e-02,
                                 1.781449e-02,
                                 1.767337e-02,
                                 1.751291e-02,
                                 1.733343e-02,
                                 1.713529e-02,
                                 1.691890e-02,
                                 1.668468e-02,
                                 1.643310e-02,
                                 1.616467e-02,
                                 1.587992e-02,
                                 1.557943e-02,
                                 1.526378e-02,
                                 1.493360e-02,
                                 1.458955e-02,
                                 1.423231e-02,
                                 1.386258e-02,
                                 1.348108e-02,
                                 1.308856e-02,
                                 1.268578e-02,
                                 1.227353e-02,
                                 1.185260e-02,
                                 1.142380e-02,
                                 1.098796e-02,
                                 1.054590e-02,
                                 1.009846e-02,
                                 9.646497e-03,
                                 9.190854e-03,
                                 8.732386e-03,
                                 8.271951e-03,
                                 7.810409e-03,
                                 7.348626e-03,
                                 6.887478e-03,
                                 6.427862e-03,
                                 5.970706e-03,
                                 5.517011e-03,
                                 5.067891e-03,
                                 4.624673e-03,
                                 4.189048e-03,
                                 3.763335e-03,
                                 3.350937e-03,
                                 2.957108e-03,
                                 2.590269e-03,
                                 2.264240e-03,
                                 2.002056e-03,
                                 1.841106e-03,
                                 1.611297e-03,
                                 1.365612e-03,
                                 1.131532e-03,
                                 9.220794e-04,
                                 7.418979e-04,
                                 5.910027e-04,
                                 4.670582e-04,
                                 3.667216e-04,
                                 2.864062e-04,
                                 2.226881e-04,
                                 1.725001e-04,
                                 1.332014e-04,
                                 1.025792e-04,
                                 7.881511e-05,
                                 6.043662e-05,
                                 4.626470e-05,
                                 3.536377e-05,
                                 2.699678e-05,
                                 2.058655e-05,
                                 1.568327e-05,
                                 1.193783e-05,
                                 9.080255e-06,
                                 6.902330e-06,
                                 5.243903e-06,
                                 3.982049e-06,
                                 3.022592e-06,
                                 2.293495e-06,
                                 1.739735e-06,
                                 1.319333e-06,
                                 1.000295e-06,
                                 7.582616e-07,
                                 5.746970e-07,
                                 4.355098e-07,
                                 3.299919e-07,
                                 2.500106e-07,
                                 1.893918e-07,
                                 1.434501e-07,
                                 1.086302e-07,
                                 8.223508e-08,
                                 6.221842e-08,
                                 4.702699e-08,
                                 3.548078e-08,
                                 2.668160e-08,
                                 1.994336e-08,
                                 1.473844e-08,
                                 1.065624e-08,
                                 7.370357e-09,
                                 4.612034e-09,
                                 2.147365e-09};

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
  std::vector<double> refFlux = {5.598311e-02,
                                 5.576777e-02,
                                 5.533792e-02,
                                 5.469522e-02,
                                 5.384212e-02,
                                 5.278193e-02,
                                 5.151870e-02,
                                 5.005731e-02,
                                 4.840338e-02,
                                 4.656325e-02,
                                 4.454402e-02,
                                 4.235345e-02,
                                 3.999997e-02,
                                 3.749262e-02,
                                 3.484106e-02,
                                 3.205548e-02,
                                 2.914659e-02,
                                 2.612559e-02,
                                 2.300409e-02,
                                 1.979411e-02,
                                 1.760336e-02,
                                 1.650046e-02,
                                 1.539051e-02,
                                 1.427398e-02,
                                 1.315136e-02,
                                 1.202311e-02,
                                 1.088972e-02,
                                 9.751675e-03,
                                 8.609464e-03,
                                 7.463574e-03,
                                 6.314494e-03,
                                 5.162714e-03,
                                 4.008729e-03,
                                 2.853030e-03,
                                 1.696112e-03};

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
  std::vector<double> refFlux = {5.896301e-02,
                                 5.869732e-02,
                                 5.816775e-02,
                                 5.737786e-02,
                                 5.633299e-02,
                                 5.504020e-02,
                                 5.350819e-02,
                                 5.174726e-02,
                                 4.976926e-02,
                                 4.758743e-02,
                                 4.521637e-02,
                                 4.267190e-02,
                                 3.997094e-02,
                                 3.713138e-02,
                                 3.417197e-02,
                                 3.111217e-02,
                                 2.797198e-02,
                                 2.477184e-02,
                                 2.153245e-02,
                                 1.827461e-02,
                                 1.610426e-02,
                                 1.502088e-02,
                                 1.394006e-02,
                                 1.286255e-02,
                                 1.178909e-02,
                                 1.072043e-02,
                                 9.657314e-03,
                                 8.600465e-03,
                                 7.550610e-03,
                                 6.508463e-03,
                                 5.474735e-03,
                                 4.450122e-03,
                                 3.435315e-03,
                                 2.430993e-03,
                                 1.437825e-03};

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
  std::vector<double> refFlux = {6.176522e-02,
                                 6.144873e-02,
                                 6.081858e-02,
                                 5.988059e-02,
                                 5.864342e-02,
                                 5.711841e-02,
                                 5.531953e-02,
                                 5.326321e-02,
                                 5.096814e-02,
                                 4.845507e-02,
                                 4.574662e-02,
                                 4.286698e-02,
                                 3.984171e-02,
                                 3.669740e-02,
                                 3.346143e-02,
                                 3.016170e-02,
                                 2.682625e-02,
                                 2.348307e-02,
                                 2.015972e-02,
                                 1.688312e-02,
                                 1.474718e-02,
                                 1.368915e-02,
                                 1.264198e-02,
                                 1.160654e-02,
                                 1.058368e-02,
                                 9.574252e-03,
                                 8.579075e-03,
                                 7.598947e-03,
                                 6.634645e-03,
                                 5.686923e-03,
                                 4.756509e-03,
                                 3.844109e-03,
                                 2.950402e-03,
                                 2.076042e-03,
                                 1.221656e-03};

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