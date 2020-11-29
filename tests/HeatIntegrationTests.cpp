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
  const std::string codePath   = "app/almost";
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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat1.txt";
  const std::string outputPath = "outputs/Out_heat1.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat2.txt";
  const std::string outputPath = "outputs/Out_heat2.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat3.txt";
  const std::string outputPath = "outputs/Out_heat3.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat4.txt";
  const std::string outputPath = "outputs/Out_heat4.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat5.txt";
  const std::string outputPath = "outputs/Out_heat5.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat6.txt";
  const std::string outputPath = "outputs/Out_heat6.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat7.txt";
  const std::string outputPath = "outputs/Out_heat7.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat8.txt";
  const std::string outputPath = "outputs/Out_heat8.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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

// Steady-state, constant parameters, slab geometry
// non-uniform grid
// with internal generation
// Boundary conditions:
// T(0) = T1
// T(L) = T2


TEST_F(HeatIntegrationTests, heat9)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat9.txt";
  const std::string outputPath = "outputs/Out_heat9.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {2.066667e+01,
                                 2.200000e+01,
                                 2.333333e+01,
                                 2.466667e+01,
                                 2.600000e+01,
                                 2.733333e+01,
                                 2.866667e+01,
                                 3.000000e+01,
                                 3.133333e+01,
                                 3.266667e+01,
                                 3.400000e+01,
                                 3.533333e+01,
                                 3.666667e+01,
                                 3.800000e+01,
                                 3.933333e+01,
                                 4.066667e+01,
                                 4.200000e+01,
                                 4.333333e+01,
                                 4.466667e+01,
                                 4.600000e+01,
                                 4.800000e+01,
                                 5.066667e+01,
                                 5.333333e+01,
                                 5.600000e+01,
                                 5.866667e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}

// Steady-state, constant conductivity, slab geometry
// 2 materials with the same cell sizes with internal generation
// Boundary conditions:
// T(0) = T1
// T(L) = T2

TEST_F(HeatIntegrationTests, heat10)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat10.txt";
  const std::string outputPath = "outputs/Out_heat10.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {2.300000e+01,
                                 2.875000e+01,
                                 3.425000e+01,
                                 3.950000e+01,
                                 4.450000e+01,
                                 4.925000e+01,
                                 5.375000e+01,
                                 5.800000e+01,
                                 6.200000e+01,
                                 6.575000e+01,
                                 6.925000e+01,
                                 7.250000e+01,
                                 7.550000e+01,
                                 7.825000e+01,
                                 8.075000e+01,
                                 8.300000e+01,
                                 8.500000e+01,
                                 8.675000e+01,
                                 8.825000e+01,
                                 8.950000e+01,
                                 9.200000e+01,
                                 9.200000e+01,
                                 8.800000e+01,
                                 8.000000e+01,
                                 6.800000e+01};

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
  const std::string codePath   = "app/almost";
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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat11.txt";
  const std::string outputPath = "outputs/Out_heat11.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat12.txt";
  const std::string outputPath = "outputs/Out_heat12.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {8.781818e+01,
                                 8.753409e+01,
                                 8.696591e+01,
                                 8.611364e+01,
                                 8.497727e+01,
                                 8.355682e+01,
                                 8.185227e+01,
                                 7.986364e+01,
                                 7.759091e+01,
                                 7.503409e+01,
                                 7.219318e+01,
                                 6.906818e+01,
                                 6.565909e+01,
                                 6.196591e+01,
                                 5.798864e+01,
                                 5.372727e+01,
                                 4.918182e+01,
                                 4.435227e+01,
                                 3.923864e+01,
                                 3.384091e+01};
                                 
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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat13.txt";
  const std::string outputPath = "outputs/Out_heat13.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {1.118182e+02,
                                 1.115341e+02,
                                 1.109659e+02,
                                 1.101136e+02,
                                 1.089773e+02,
                                 1.075568e+02,
                                 1.058523e+02,
                                 1.038636e+02,
                                 1.015909e+02,
                                 9.903409e+01,
                                 9.619318e+01,
                                 9.306818e+01,
                                 8.965909e+01,
                                 8.596591e+01,
                                 8.198864e+01,
                                 7.772727e+01,
                                 7.318182e+01,
                                 6.835227e+01,
                                 6.323864e+01,
                                 5.784091e+01,
                                 5.386364e+01,
                                 5.154545e+01,
                                 4.918182e+01,
                                 4.677273e+01,
                                 4.431818e+01,
                                 4.181818e+01,
                                 3.927273e+01,
                                 3.668182e+01,
                                 3.404545e+01,
                                 3.136364e+01};

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat14.txt";
  const std::string outputPath = "outputs/Out_heat14.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat15.txt";
  const std::string outputPath = "outputs/Out_heat15.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

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
  const std::string codePath   = "app/almost";
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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat16.txt";
  const std::string outputPath = "outputs/Out_heat16.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {1.715152e+02,
                                 1.707576e+02,
                                 1.692424e+02,
                                 1.669697e+02,
                                 1.639394e+02,
                                 1.601515e+02,
                                 1.556061e+02,
                                 1.503030e+02,
                                 1.442424e+02,
                                 1.374242e+02,
                                 1.298485e+02,
                                 1.215152e+02,
                                 1.124242e+02,
                                 1.025758e+02,
                                 9.196970e+01,
                                 8.060606e+01,
                                 6.848485e+01,
                                 5.560606e+01,
                                 4.196970e+01,
                                 2.757576e+01};

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat17.txt";
  const std::string outputPath = "outputs/Out_heat17.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {1.748485e+02,
                                 1.740909e+02,
                                 1.725758e+02,
                                 1.703030e+02,
                                 1.672727e+02,
                                 1.634848e+02,
                                 1.589394e+02,
                                 1.536364e+02,
                                 1.475758e+02,
                                 1.407576e+02,
                                 1.331818e+02,
                                 1.248485e+02,
                                 1.157576e+02,
                                 1.059091e+02,
                                 9.530303e+01,
                                 8.393939e+01,
                                 7.181818e+01,
                                 5.893939e+01,
                                 4.530303e+01,
                                 3.090909e+01};

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat18.txt";
  const std::string outputPath = "outputs/Out_heat18.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {5.654545e+02,
                                 5.651515e+02,
                                 5.645455e+02,
                                 5.636364e+02,
                                 5.624242e+02,
                                 5.609091e+02,
                                 5.590909e+02,
                                 5.569697e+02,
                                 5.545455e+02,
                                 5.518182e+02,
                                 5.427273e+02,
                                 5.200000e+02,
                                 4.896970e+02,
                                 4.518182e+02,
                                 4.063636e+02,
                                 3.533333e+02,
                                 2.927273e+02,
                                 2.245455e+02,
                                 1.487879e+02,
                                 6.545455e+01};

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat19.txt";
  const std::string outputPath = "outputs/Out_heat19.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {8.300000e+02,
                                 8.266667e+02,
                                 8.200000e+02,
                                 8.100000e+02,
                                 7.966667e+02,
                                 7.800000e+02,
                                 7.600000e+02,
                                 7.366667e+02,
                                 7.100000e+02,
                                 6.800000e+02,
                                 5.950000e+02,
                                 5.700000e+02,
                                 5.366667e+02,
                                 4.950000e+02,
                                 4.450000e+02,
                                 3.866667e+02,
                                 3.200000e+02,
                                 2.450000e+02,
                                 1.616667e+02,
                                 7.000000e+01};

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
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/heat20.txt";
  const std::string outputPath = "outputs/Out_heat20.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  std::vector<double> temp = test.getVector("Final temperatures");

  std::vector<double> refTemp = {5.642277e+01,
                                 5.624394e+01,
                                 5.588618e+01,
                                 5.534930e+01,
                                 5.463301e+01,
                                 5.373694e+01,
                                 5.266061e+01,
                                 5.140344e+01,
                                 4.996474e+01,
                                 4.834375e+01,
                                 4.653958e+01,
                                 4.455123e+01,
                                 4.237761e+01,
                                 4.001751e+01,
                                 3.746959e+01,
                                 3.473241e+01,
                                 3.180440e+01,
                                 2.868385e+01,
                                 2.536893e+01,
                                 2.185136e+01};

  bool areEqual = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual);
}