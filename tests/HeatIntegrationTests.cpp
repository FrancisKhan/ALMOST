#include "gtest/gtest.h"
#include "TestHelper.h"

class HeatIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

// Steady-state, constant parameters, slab geometry (memory test)
// Boundary conditions:
// T(0) = T1
// T(L) = T2

TEST_F(HeatIntegrationTests, memTest)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat1.txt";
  const std::string outputPath = "outputs/Out_heat1_mem.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

// Steady-state, constant parameters, slab geometry
// Boundary conditions:
// T(0) = T1
// T(L) = T2

TEST_F(HeatIntegrationTests, heat1)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat1.txt";
  const std::string outputPath = "outputs/Out_heat1.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {12.0000, 16.0000, 20.0000,
                                 24.0000, 28.0000};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, slab geometry
// Boundary conditions
// T(0) = T1
// q(L) = h(T2 - Tinf2)

TEST_F(HeatIntegrationTests, heat2)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat2.txt";
  const std::string outputPath = "outputs/Out_heat2.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {1.027513e+01, 1.082538e+01, 1.137564e+01,
                                 1.192590e+01, 1.247615e+01, 1.302641e+01, 
                                 1.357666e+01, 1.412692e+01, 1.467718e+01, 
                                 1.522743e+01, 1.577769e+01, 1.632794e+01, 
                                 1.687820e+01, 1.742845e+01, 1.797871e+01, 
                                 1.852897e+01, 1.907922e+01, 1.962948e+01, 
                                 2.017973e+01, 2.072999e+01, 2.128025e+01, 
                                 2.183050e+01, 2.238076e+01, 2.293101e+01, 
                                 2.348127e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, slab geometry
// Boundary conditions:
// q(0) = h(T1 - Tinf1)
// T(L) = T2

TEST_F(HeatIntegrationTests, heat3)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat3.txt";
  const std::string outputPath = "outputs/Out_heat3.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {2.348127e+01, 2.293101e+01, 2.238076e+01, 
                                 2.183050e+01, 2.128025e+01, 2.072999e+01, 
                                 2.017973e+01, 1.962948e+01, 1.907922e+01, 
                                 1.852897e+01, 1.797871e+01, 1.742845e+01,
                                 1.687820e+01, 1.632794e+01, 1.577769e+01,
                                 1.522743e+01, 1.467718e+01, 1.412692e+01,
                                 1.357666e+01, 1.302641e+01, 1.247615e+01, 
                                 1.192590e+01, 1.137564e+01, 1.082538e+01, 
                                 1.027513e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, slab geometry
// Boundary conditions:
// q(0) = h1(T1 - Tinf1)
// q(L) = h2(T2 - Tinf2)

TEST_F(HeatIntegrationTests, heat4)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat4.txt";
  const std::string outputPath = "outputs/Out_heat4.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {2.799345e+01, 2.782407e+01, 2.765469e+01,
                                 2.748532e+01, 2.731594e+01, 2.714657e+01,
                                 2.697719e+01, 2.680781e+01, 2.663844e+01, 
                                 2.646906e+01, 2.629968e+01, 2.613031e+01, 
                                 2.596093e+01, 2.579156e+01, 2.562218e+01, 
                                 2.545280e+01, 2.528343e+01, 2.511405e+01, 
                                 2.494468e+01, 2.477530e+01, 2.460592e+01, 
                                 2.443655e+01, 2.426717e+01, 2.409779e+01, 
                                 2.392842e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, slab geometry
// Boundary conditions:
// T(0) = T1
// q(L) = q2

TEST_F(HeatIntegrationTests, heat5)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat5.txt";
  const std::string outputPath = "outputs/Out_heat5.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {3.044066e+01, 3.132197e+01, 3.220328e+01, 
                                 3.308459e+01, 3.396590e+01, 3.484721e+01,
                                 3.572853e+01, 3.660984e+01, 3.749115e+01, 
                                 3.837246e+01, 3.925377e+01, 4.013508e+01, 
                                 4.101639e+01, 4.189771e+01, 4.277902e+01, 
                                 4.366033e+01, 4.454164e+01, 4.542295e+01, 
                                 4.630426e+01, 4.718558e+01, 4.806689e+01, 
                                 4.894820e+01, 4.982951e+01, 5.071082e+01, 
                                 5.159213e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, slab geometry
// Boundary conditions:
// q(0) = q1
// T(L) = T2


TEST_F(HeatIntegrationTests, heat6)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat6.txt";
  const std::string outputPath = "outputs/Out_heat6.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {4.159213e+01, 4.071082e+01, 3.982951e+01, 
                                 3.894820e+01, 3.806689e+01, 3.718558e+01, 
                                 3.630426e+01, 3.542295e+01, 3.454164e+01,
                                 3.366033e+01, 3.277902e+01, 3.189771e+01, 
                                 3.101639e+01, 3.013508e+01, 2.925377e+01, 
                                 2.837246e+01, 2.749115e+01, 2.660984e+01, 
                                 2.572853e+01, 2.484721e+01, 2.396590e+01, 
                                 2.308459e+01, 2.220328e+01, 2.132197e+01, 
                                 2.044066e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, slab geometry
// Boundary conditions:
// T(0) = T1
// T(L) = T2

TEST_F(HeatIntegrationTests, heat7)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat7.txt";
  const std::string outputPath = "outputs/Out_heat7.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {3.112919e+01, 5.116173e+01, 6.896844e+01,
                                 8.454930e+01, 9.790433e+01, 1.090335e+02, 
                                 1.179369e+02, 1.246144e+02, 1.290661e+02,
                                 1.312919e+02, 1.312919e+02, 1.290661e+02, 
                                 1.246144e+02, 1.179369e+02, 1.090335e+02, 
                                 9.790433e+01, 8.454930e+01, 6.896844e+01, 
                                 5.116173e+01, 3.112919e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, temperature-dependent conductivity, slab geometry
// with internal generation
// Boundary conditions:
// T(0) = T1
// T(L) = T2

TEST_F(HeatIntegrationTests, heat8)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat8.txt";
  const std::string outputPath = "outputs/Out_heat8.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperature");

  std::vector<double> refTemp = {3.085607e+01, 4.943671e+01, 6.585663e+01, 
                                 8.015053e+01, 9.234772e+01, 1.024726e+02, 
                                 1.105449e+02, 1.165802e+02, 1.205900e+02, 
                                 1.225818e+02, 1.225593e+02, 1.205225e+02, 
                                 1.164675e+02, 1.103868e+02, 1.022688e+02,
                                 9.209787e+01, 7.985411e+01, 6.551304e+01,
                                 4.904523e+01, 3.041586e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}