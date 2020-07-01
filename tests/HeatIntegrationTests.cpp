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

TEST_F(HeatIntegrationTests, slabMemTest)
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
  std::vector<double> temp = test.getVector("Temperatures");

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
  std::vector<double> temp = test.getVector("Temperatures");

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
  std::vector<double> temp = test.getVector("Temperatures");

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
  std::vector<double> temp = test.getVector("Temperatures");

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
  std::vector<double> temp = test.getVector("Temperatures");

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
  std::vector<double> temp = test.getVector("Temperatures");

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
  std::vector<double> temp = test.getVector("Temperatures");

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
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {3.101004e+01, 5.063603e+01, 6.776638e+01,
                                 8.252469e+01, 9.501097e+01, 1.053055e+02, 
                                 1.134715e+02, 1.195576e+02, 1.235989e+02, 
                                 1.256184e+02, 1.256274e+02, 1.236259e+02, 
                                 1.196027e+02, 1.135350e+02, 1.053878e+02,
                                 9.511254e+01, 8.264616e+01, 6.790856e+01, 
                                 5.079992e+01, 3.100032e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, temperature-dependent conductivity, slab geometry with different cell sizes
// Boundary conditions:
// T(0) = T1
// T(L) = T2

TEST_F(HeatIntegrationTests, heat9)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat9.txt";
  const std::string outputPath = "outputs/Out_heat9.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {2.050633e+01, 2.151899e+01, 2.253165e+01, 
                                 2.354430e+01, 2.455696e+01, 2.556962e+01, 
                                 2.658228e+01, 2.759494e+01, 2.860759e+01, 
                                 2.962025e+01, 3.063291e+01, 3.164557e+01, 
                                 3.265823e+01, 3.367089e+01, 3.468354e+01, 
                                 3.569620e+01, 3.670886e+01, 3.772152e+01, 
                                 3.873418e+01, 3.974684e+01, 4.177215e+01, 
                                 4.582278e+01, 4.987342e+01, 5.392405e+01, 
                                 5.797468e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, tconstant conductivity, slab geometry
// 2 materials with the same cell sizes with internal generation
// Boundary conditions:
// T(0) = T1
// T(L) = T2

TEST_F(HeatIntegrationTests, heat10)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat10.txt";
  const std::string outputPath = "outputs/Out_heat10.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {2.241661e+01, 2.699983e+01, 3.133306e+01, 
                                 3.541628e+01, 3.924950e+01, 4.283272e+01, 
                                 4.616594e+01, 4.924917e+01, 5.208239e+01, 
                                 5.466561e+01, 5.699883e+01, 5.908205e+01, 
                                 6.091528e+01, 6.249850e+01, 6.383172e+01, 
                                 6.491494e+01, 6.574817e+01, 6.633139e+01, 
                                 6.666461e+01, 6.674783e+01, 6.620080e+01, 
                                 6.553396e+01, 6.446711e+01, 6.300027e+01, 
                                 6.113342e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, cylindrical geometry (memory test)
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, cylMemTest)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat11.txt";
  const std::string outputPath = "outputs/Out_heat11_mem.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

// Steady-state, constant parameters, cylindrical geometry
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, heat11)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat11.txt";
  const std::string outputPath = "outputs/Out_heat11.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {8.681818e+01, 8.653409e+01, 8.596591e+01,
                                 8.511364e+01, 8.397727e+01, 8.255682e+01,
                                 8.085227e+01, 7.886364e+01, 7.659091e+01, 
                                 7.403409e+01, 7.119318e+01, 6.806818e+01, 
                                 6.465909e+01, 6.096591e+01, 5.698864e+01, 
                                 5.272727e+01, 4.818182e+01, 4.335227e+01, 
                                 3.823864e+01, 3.284091e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, cylindrical geometry
// Boundary conditions:
// q(0) = 0.0
// q dT/dr = h (T(L) -Tf)

TEST_F(HeatIntegrationTests, heat12)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat12.txt";
  const std::string outputPath = "outputs/Out_heat12.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {8.806818e+01, 8.778409e+01, 8.721591e+01,
                                 8.636364e+01, 8.522727e+01, 8.380682e+01,
                                 8.210227e+01, 8.011364e+01, 7.784091e+01, 
                                 7.528409e+01, 7.244318e+01, 6.931818e+01, 
                                 6.590909e+01, 6.221591e+01, 5.823864e+01, 
                                 5.397727e+01, 4.943182e+01, 4.460227e+01, 
                                 3.948864e+01, 3.409091e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, tconstant conductivity, cylindrical geometry
// non-uniform cell sizes with internal generation
// Boundary conditions:
// q(0) = 0
// T(L) = T2

TEST_F(HeatIntegrationTests, heat13)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat13.txt";
  const std::string outputPath = "outputs/Out_heat13.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {9.836374e+01, 9.807965e+01, 9.751147e+01, 
                                 9.665920e+01, 9.552284e+01, 9.410238e+01, 
                                 9.239784e+01, 9.040920e+01, 8.813647e+01, 
                                 8.557965e+01, 8.273874e+01, 7.961374e+01, 
                                 7.620465e+01, 7.251147e+01, 6.853420e+01, 
                                 6.427284e+01, 5.972738e+01, 5.489784e+01, 
                                 4.978420e+01, 4.438647e+01, 4.211374e+01, 
                                 4.113246e+01, 4.008001e+01, 3.895737e+01, 
                                 3.776545e+01, 3.650512e+01, 3.517720e+01, 
                                 3.378246e+01, 3.232165e+01, 3.079545e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, cylindrical geometry
// non-uniform cell sizes with internal generation
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, heat14)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat14.txt";
  const std::string outputPath = "outputs/Out_heat14.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {2.237500e+02, 2.236250e+02, 2.233750e+02, 
                                 2.230000e+02, 2.225000e+02, 2.218750e+02, 
                                 2.211250e+02, 2.202500e+02, 2.192500e+02, 
                                 2.181250e+02, 2.112500e+02, 1.975000e+02, 
                                 1.825000e+02, 1.662500e+02, 1.487500e+02, 
                                 1.300000e+02, 1.100000e+02, 8.875000e+01, 
                                 6.625000e+01, 4.250000e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, temperatiure-dependent parameters, cylindrical geometry
// uniform cell, internal generation
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, heat15)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat15.txt";
  const std::string outputPath = "outputs/Out_heat15.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {7.415498e+01, 7.389133e+01, 7.336384e+01,
                                 7.257209e+01, 7.151547e+01, 7.019317e+01, 
                                 6.860416e+01, 6.674720e+01, 6.462082e+01, 
                                 6.222334e+01, 5.955284e+01, 5.660715e+01, 
                                 5.338388e+01, 4.988036e+01, 4.609364e+01, 
                                 4.202050e+01, 3.765743e+01, 3.300059e+01, 
                                 2.804581e+01, 2.277442e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, spherical geometry (memory test)
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, csphMemTest)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat16.txt";
  const std::string outputPath = "outputs/Out_heat16_mem.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

// Steady-state, constant parameters, spherical geometry
// with and internal generation
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, heat16)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat16.txt";
  const std::string outputPath = "outputs/Out_heat16.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {1.708385e+02, 1.702703e+02, 1.688499e+02, 
                                 1.666403e+02, 1.636573e+02, 1.599073e+02, 
                                 1.553934e+02, 1.501174e+02, 1.440805e+02, 
                                 1.372834e+02, 1.297266e+02, 1.214104e+02, 
                                 1.123353e+02, 1.025014e+02, 9.190887e+01, 
                                 8.055786e+01, 6.844848e+01, 5.558084e+01, 
                                 4.195499e+01, 2.757102e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, spherical geometry
// with and internal generation
// Boundary conditions:
// q(0) = 0.0
// q dT/dr = h (T(L) -Tf)

TEST_F(HeatIntegrationTests, heat17)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat17.txt";
  const std::string outputPath = "outputs/Out_heat17.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {1.711716e+02, 1.706034e+02, 1.691830e+02, 
                                 1.669734e+02, 1.639904e+02, 1.602404e+02, 
                                 1.557265e+02, 1.504506e+02, 1.444136e+02, 
                                 1.376165e+02, 1.300597e+02, 1.217436e+02, 
                                 1.126684e+02, 1.028345e+02, 9.224199e+01, 
                                 8.089098e+01, 6.878161e+01, 5.591396e+01, 
                                 4.228812e+01, 2.790415e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, spherical geometry
// non-uniform cell sizes with internal generation
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, heat18)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat18.txt";
  const std::string outputPath = "outputs/Out_heat18.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {6.447657e+02, 6.445384e+02, 6.439702e+02, 
                                 6.430864e+02, 6.418932e+02, 6.403932e+02, 
                                 6.385876e+02, 6.364772e+02, 6.340625e+02, 
                                 6.313436e+02, 6.162300e+02, 5.668613e+02, 
                                 5.216908e+02, 4.743727e+02, 4.224156e+02, 
                                 3.646466e+02, 3.004420e+02, 2.294403e+02, 
                                 1.514176e+02, 6.622790e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant parameters, spherical geometry
// uniform cell sizes, 2 materials, with internal generation
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, heat19)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat19.txt";
  const std::string outputPath = "outputs/Out_heat19.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {9.648080e+02, 9.623080e+02, 9.560580e+02, 
                                 9.463358e+02, 9.332108e+02, 9.167108e+02, 
                                 8.968497e+02, 8.736354e+02, 8.470729e+02, 
                                 8.171655e+02, 6.758530e+02, 6.215474e+02, 
                                 5.718599e+02, 5.198099e+02, 4.626571e+02, 
                                 3.991112e+02, 3.284862e+02, 2.503844e+02, 
                                 1.645594e+02, 7.085069e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, temperatiure-dependent parameters, spherical geometry
// uniform cell, internal generation
// Boundary conditions:
// q(0) = 0.0
// T(L) = T2

TEST_F(HeatIntegrationTests, heat20)
{	
  const std::string codePath   = "app/app";
  const std::string inputPath  = "inputs/heat20.txt";
  const std::string outputPath = "outputs/Out_heat20.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Temperatures");

  std::vector<double> refTemp = {5.626304e+01, 5.612889e+01, 5.579346e+01,
                                 5.527145e+01, 5.456630e+01, 5.367914e+01, 
                                 5.261022e+01, 5.135941e+01, 4.992627e+01, 
                                 4.831023e+01, 4.651051e+01, 4.452621e+01,
                                 4.235632e+01, 3.999966e+01, 3.745495e+01, 
                                 3.472078e+01, 3.179559e+01, 2.867772e+01, 
                                 2.536534e+01, 2.185020e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}