#include "gtest/gtest.h"
#include "TestHelper.h"
#include "additionalPrintFuncs.h"

using namespace PrintFuncs;

class CPMIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

// PrintFuncs::createCppVector(flux, "%7.6e");

// CYLINDER TESTS //

// PUa-l-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem1CY)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem1CY.txt";
  const std::string outputPath = "outputs/Out_CPMProblem1CY.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.6129031;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux"); 
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(CPMIntegrationTests, Problem5CY)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem5CY.txt";
  const std::string outputPath = "outputs/Out_CPMProblem5CY.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.2903225806451606;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Pub-l-0-CY
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem7)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem7.txt";
  const std::string outputPath = "outputs/Out_CPMProblem7.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99673135097656018;
  std::vector<double> refFlux = {1.314791e-01, 1.293948e-01, 1.252738e-01, 
                                 1.191990e-01, 1.112912e-01, 1.017000e-01,
                                 9.058898e-02, 7.810650e-02, 6.430084e-02, 
                                 4.866578e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// Pub-H20(1)-I-0-CY
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem9)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem9.txt";
  const std::string outputPath = "outputs/Out_CPMProblem9.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99520893671732791;
  std::vector<double> refFlux = {1.436631e-01, 1.396365e-01, 1.317217e-01,
                                 1.201432e-01, 1.051435e-01, 8.654573e-02, 
                                 6.640681e-02, 5.379688e-02, 4.430917e-02,
                                 3.652798e-02, 2.986499e-02, 2.393622e-02, 
                                 1.830424e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// Pub-H20(10)-l-O-CY
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem10)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem10.txt";
  const std::string outputPath = "outputs/Out_CPMProblem10.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.98028468508336697;
  std::vector<double> refFlux = {1.025809e-01, 1.016682e-01, 9.985176e-02,
                                 9.714552e-02, 9.356870e-02, 8.914197e-02,
                                 8.388009e-02, 7.777473e-02, 7.074259e-02,
                                 6.233584e-02, 4.109603e-02, 2.519130e-02,
                                 1.658453e-02, 1.128713e-02, 7.834532e-03,
                                 5.509697e-03, 3.911119e-03, 2.795843e-03,
                                 2.009415e-03, 1.450315e-03, 1.050213e-03,
                                 7.623100e-04, 5.541167e-04, 4.028372e-04,
                                 2.923288e-04, 2.110624e-04, 1.507260e-04,
                                 1.052414e-04, 7.001543e-05, 4.101337e-05};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// PU-2-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem44CY)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem44CY.txt";
  const std::string outputPath = "outputs/Out_CPMProblem44CY.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 2.683767478813559;
  std::vector<double> refFlux = {4.030668e-02, 4.030668e-02, 4.030668e-02,
                                 4.030668e-02, 4.030668e-02, 4.030668e-02, 
                                 4.030668e-02, 4.030668e-02, 4.030668e-02,
                                 4.030668e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// URR-3-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem74)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem74.txt";
  const std::string outputPath = "outputs/Out_CPMProblem74.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 1.60;
  std::vector<double> refFlux = {6.134969e-02, 6.134969e-02, 6.134969e-02,
                                 6.134969e-02, 6.134969e-02, 6.134969e-02,
                                 6.134969e-02, 6.134969e-02, 6.134969e-02,
                                 6.134969e-02, 2.944785e-02, 2.944785e-02,
                                 2.944785e-02, 2.944785e-02, 2.944785e-02,
                                 2.944785e-02, 2.944785e-02, 2.944785e-02,
                                 2.944785e-02, 2.944785e-02, 9.202454e-03,
                                 9.202454e-03, 9.202454e-03, 9.202454e-03, 
                                 9.202454e-03, 9.202454e-03, 9.202454e-03,
                                 9.202454e-03, 9.202454e-03, 9.202454e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// URR-3-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem75)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem75.txt";
  const std::string outputPath = "outputs/Out_CPMProblem75.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 1.60;
  std::vector<double> refFlux = {3.067485e-02, 3.067485e-02, 3.067485e-02, 
                                 3.067485e-02, 3.067485e-02, 3.067485e-02,
                                 3.067485e-02, 3.067485e-02, 3.067485e-02,
                                 3.067485e-02, 1.472393e-02, 1.472393e-02,
                                 1.472393e-02, 1.472393e-02, 1.472393e-02, 
                                 1.472393e-02, 1.472393e-02, 1.472393e-02, 
                                 1.472393e-02, 1.472393e-02, 4.601227e-03, 
                                 4.601227e-03, 4.601227e-03, 4.601227e-03, 
                                 4.601227e-03, 4.601227e-03, 4.601227e-03, 
                                 4.601227e-03, 4.601227e-03, 4.601227e-03, 
                                 4.601227e-03, 4.601227e-03, 4.601227e-03, 
                                 4.601227e-03, 4.601227e-03, 4.601227e-03,
                                 4.601227e-03, 4.601227e-03, 4.601227e-03,
                                 4.601227e-03, 1.472393e-02, 1.472393e-02,
                                 1.472393e-02, 1.472393e-02, 1.472393e-02,
                                 1.472393e-02, 1.472393e-02, 1.472393e-02, 
                                 1.472393e-02, 1.472393e-02, 3.067485e-02, 
                                 3.067485e-02, 3.067485e-02, 3.067485e-02, 
                                 3.067485e-02, 3.067485e-02, 3.067485e-02, 
                                 3.067485e-02, 3.067485e-02, 3.067485e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// SPHERE TESTS //

// PUa-l-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem1SP)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem1SP.txt";
  const std::string outputPath = "outputs/Out_CPMProblem1SP.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.6129031;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// PUb-l-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem5SP)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem5SP.txt";
  const std::string outputPath = "outputs/Out_CPMProblem5SP.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.2903225806451601;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Pub-l-0-SP
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem8)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem8.txt";
  const std::string outputPath = "outputs/Out_CPMProblem8.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 9.950726e-01;
  std::vector<double> refFlux = {1.179613e-01, 1.161960e-01, 1.128046e-01, 
                                 1.078323e-01, 1.013988e-01, 9.366012e-02,
                                 8.480047e-02, 7.502297e-02, 6.453708e-02,
                                 5.353626e-02, 4.214170e-02, 3.010844e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// Ub-H20(1)-l-0-SP
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem16)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem16.txt";
  const std::string outputPath = "outputs/Out_CPMProblem16.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 9.962318e-01;
  std::vector<double> refFlux = {9.175995e-02, 9.070247e-02, 8.866452e-02, 
                                 8.566145e-02, 8.174804e-02, 7.699680e-02, 
                                 7.149417e-02, 6.533666e-02, 5.862521e-02, 
                                 5.145482e-02, 4.388771e-02, 3.581785e-02, 
                                 2.860648e-02, 2.436631e-02, 2.100628e-02, 
                                 1.817408e-02, 1.572332e-02, 1.356472e-02, 
                                 1.163435e-02, 9.879865e-03, 8.248339e-03,
                                 6.646612e-03};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// PU-2-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem44SP)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem44SP.txt";
  const std::string outputPath = "outputs/Out_CPMProblem44SP.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 2.683767478813559;
  std::vector<double> refFlux = {4.030668e-02, 4.030668e-02, 4.030668e-02,
                                 4.030668e-02, 4.030668e-02, 4.030668e-02, 
                                 4.030668e-02, 4.030668e-02, 4.030668e-02,
                                 4.030668e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// U-2-o-SP
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem49)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem49.txt";
  const std::string outputPath = "outputs/Out_CPMProblem49.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 9.914234e-01;
  std::vector<double> refFlux = {5.674903e-02, 5.551142e-02, 5.314938e-02, 
                                 4.972400e-02, 4.535967e-02, 4.021427e-02, 
                                 3.446774e-02, 2.830683e-02, 2.189408e-02, 
                                 1.522764e-02, 8.598166e-02, 8.405967e-02, 
                                 8.039069e-02, 7.506711e-02, 6.827756e-02, 
                                 6.026081e-02, 5.128749e-02, 4.163448e-02, 
                                 3.153057e-02, 2.090590e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// UD20-2-O-SP
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem69)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem69.txt";
  const std::string outputPath = "outputs/Out_CPMProblem69.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 9.977171e-01;
  std::vector<double> refFlux = {5.646345e-02, 5.646280e-02, 5.646111e-02, 
                                 5.645740e-02, 5.644950e-02, 5.643295e-02,
                                 5.639889e-02, 5.633034e-02, 5.619601e-02, 
                                 5.594113e-02, 5.547495e-02, 5.465664e-02,
                                 5.328419e-02, 5.109435e-02, 4.778484e-02,
                                 4.306823e-02, 3.675765e-02, 2.886691e-02,
                                 1.968823e-02, 9.803286e-03, 2.105016e-03, 
                                 2.104991e-03, 2.104926e-03, 2.104785e-03,
                                 2.104484e-03, 2.103856e-03, 2.102565e-03,
                                 2.099970e-03, 2.094896e-03, 2.085284e-03,
                                 2.067735e-03, 2.036984e-03, 1.985496e-03,
                                 1.903475e-03, 1.779705e-03, 1.603557e-03,
                                 1.368172e-03, 1.074159e-03, 7.324412e-04,
                                 3.646455e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// SLAB TESTS //

// PUa-l-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem1SL)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem1SL.txt";
  const std::string outputPath = "outputs/Out_CPMProblem1SL.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.6129031;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// PUb-l-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem5SL)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem5SL.txt";
  const std::string outputPath = "outputs/Out_CPMProblem5SL.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.2903225806451601;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// PUa-l-O-SL
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem2)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem2.txt";
  const std::string outputPath = "outputs/Out_CPMProblem2.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99758944633443514;
  std::vector<double> refFlux = {7.446645e-02, 9.197925e-02, 1.043644e-01,
                                 1.125485e-01, 1.166414e-01, 1.166414e-01,
                                 1.125485e-01, 1.043644e-01, 9.197925e-02,
                                 7.446645e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// PUa-l-O-SL
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem2All)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem2All.txt";
  const std::string outputPath = "outputs/Out_CPMProblem2All.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.143151;
  std::vector<double> refFlux {1.361528e-01, 6.353176e-02, -7.950818e-02, 
	-1.478667e-01, -7.294054e-02, 7.294054e-02, 1.478667e-01, 7.950818e-02, 
	-6.353176e-02, -1.361528e-01};
 
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux 4");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getEigenvalue(4),  kEffRef);
}

// PUa-H20(1)-l-0-SL
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem3)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem3.txt";
  const std::string outputPath = "outputs/Out_CPMProblem3.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99893783602164843;
  std::vector<double> refFlux = {3.459852e-02, 4.104590e-02, 4.606452e-02,
                                 5.006744e-02, 5.314379e-02, 5.531440e-02,
                                 5.657745e-02, 5.692185e-02, 5.632938e-02,
                                 5.476727e-02, 5.215814e-02, 4.821146e-02,
                                 4.290733e-02, 3.927816e-02, 3.636867e-02,
                                 3.382072e-02, 3.150980e-02, 2.936991e-02,
                                 2.735965e-02, 2.544999e-02, 2.361873e-02,
                                 2.184724e-02, 2.011815e-02, 1.841294e-02,
                                 1.670779e-02, 1.496310e-02, 1.306769e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// PUa-H20(0.5)-l-0-SL
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem4)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem4.txt";
  const std::string outputPath = "outputs/Out_CPMProblem4.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99930420924023056;
  std::vector<double> refFlux = {1.567910e-02, 1.756549e-02, 1.931725e-02,
                                 2.104435e-02, 2.279108e-02, 2.459011e-02,
                                 2.647527e-02, 2.849185e-02, 3.071787e-02,
                                 3.336773e-02, 3.735883e-02, 4.077014e-02,
                                 4.330396e-02, 4.515765e-02, 4.638036e-02,
                                 4.698896e-02, 4.698896e-02, 4.638036e-02,
                                 4.515765e-02, 4.330396e-02, 4.077014e-02,
                                 3.735883e-02, 3.336773e-02, 3.071787e-02,
                                 2.849185e-02, 2.647527e-02, 2.459011e-02,
                                 2.279108e-02, 2.104435e-02, 1.931725e-02,
                                 1.756549e-02, 1.567910e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// Pub-l-0-SL
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem6)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem6.txt";
  const std::string outputPath = "outputs/Out_CPMProblem6.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99638161118620527;
  std::vector<double> refFlux = {8.166772e-02, 1.041356e-01, 1.195236e-01,
                                 1.287531e-01, 1.318400e-01, 1.287531e-01,
                                 1.195236e-01, 1.041356e-01, 8.166772e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// PU-2-O-IN
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem44SL)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem44SL.txt";
  const std::string outputPath = "outputs/Out_CPMProblem44SL.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 2.6837674788135604;
  std::vector<double> refFlux = {4.030668e-02, 4.030668e-02, 4.030668e-02,
                                 4.030668e-02, 4.030668e-02, 4.030668e-02,
                                 4.030668e-02, 4.030668e-02, 4.030668e-02,
                                 4.030668e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02, 5.969332e-02,
                                 5.969332e-02, 5.969332e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// U-2-o-SL
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem48)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem48.txt";
  const std::string outputPath = "outputs/Out_CPMProblem48.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99608037636503111;
  std::vector<double> refFlux = {3.022565e-02, 3.781283e-02, 4.331994e-02,
                                 4.701051e-02, 4.887009e-02, 4.887009e-02,
                                 4.701051e-02, 4.331994e-02, 3.781283e-02,
                                 3.022565e-02, 4.015125e-02, 5.266957e-02,
                                 6.165228e-02, 6.763956e-02, 7.064832e-02,
                                 7.064832e-02, 6.763956e-02, 6.165228e-02,
                                 5.266957e-02, 4.015125e-02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// UD20-2-O-SP
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem68)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem68.txt";
  const std::string outputPath = "outputs/Out_CPMProblem68.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 9.956694e-01;
  std::vector<double> refFlux = {1.258118e-02, 2.449323e-02, 3.517485e-02, 
                                 4.425045e-02, 5.155982e-02, 5.713839e-02, 
                                 6.116152e-02, 6.387333e-02, 6.551855e-02,
                                 6.628905e-02, 6.628905e-02, 6.551855e-02, 
                                 6.387333e-02, 6.116152e-02, 5.713839e-02, 
                                 5.155982e-02, 4.425045e-02, 3.517485e-02, 
                                 2.449323e-02, 1.258118e-02, 4.684385e-04, 
                                 9.120281e-04, 1.309912e-03, 1.648115e-03, 
                                 1.920648e-03, 2.128779e-03, 2.278985e-03, 
                                 2.380303e-03, 2.441811e-03, 2.470630e-03, 
                                 2.470630e-03, 2.441811e-03, 2.380303e-03, 
                                 2.278985e-03, 2.128779e-03, 1.920648e-03, 
                                 1.648115e-03, 1.309912e-03, 9.120281e-04, 
                                 4.684385e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// URRb-H20a(l)-2-0-SL
// Analytical Benchmark Test Set for Criticality Code Verification LA-13511

TEST_F(CPMIntegrationTests, Problem58)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem58.txt";
  const std::string outputPath = "outputs/Out_CPMProblem58.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99239516125086513;
  std::vector<double> refFlux = {9.676826e-04, 1.020269e-03, 1.067122e-03,
                                 1.111234e-03, 1.153597e-03, 1.194722e-03,
                                 1.234918e-03, 1.274394e-03, 1.313298e-03,
                                 1.351741e-03, 1.389810e-03, 1.427574e-03,
                                 1.465088e-03, 1.502399e-03, 1.539547e-03,
                                 1.576567e-03, 1.613487e-03, 1.650335e-03,
                                 1.687133e-03, 1.723903e-03, 1.760664e-03,
                                 1.797433e-03, 1.834229e-03, 1.871065e-03,
                                 1.907957e-03, 1.944920e-03, 1.981966e-03,
                                 2.019109e-03, 2.056362e-03, 2.093739e-03,
                                 2.131253e-03, 2.168917e-03, 2.206746e-03,
                                 2.244753e-03, 2.282955e-03, 2.321369e-03, 
                                 2.360011e-03, 2.398901e-03, 2.438063e-03,
                                 2.477522e-03, 2.517306e-03, 2.557452e-03,
                                 2.598002e-03, 2.639011e-03, 2.680553e-03,
                                 2.722726e-03, 2.765680e-03, 2.809662e-03,
                                 2.855154e-03, 2.903650e-03, 3.177754e-03,
                                 3.650003e-03, 4.102228e-03, 4.538942e-03,
                                 4.961209e-03, 5.369077e-03, 5.762170e-03,
                                 6.139911e-03, 6.501625e-03, 6.846594e-03,
                                 7.174087e-03, 7.483379e-03, 7.773770e-03,
                                 8.044585e-03, 8.295188e-03, 8.524983e-03,
                                 8.733419e-03, 8.919993e-03, 9.084254e-03, 
                                 9.225802e-03, 9.344292e-03, 9.439435e-03,
                                 9.510996e-03, 9.558802e-03, 9.582734e-03,
                                 9.582734e-03, 9.558802e-03, 9.510996e-03,
                                 9.439435e-03, 9.344292e-03, 9.225802e-03,
                                 9.084254e-03, 8.919993e-03, 8.733419e-03,
                                 8.524983e-03, 8.295188e-03, 8.044585e-03,
                                 7.773770e-03, 7.483379e-03, 7.174087e-03,
                                 6.846594e-03, 6.501625e-03, 6.139911e-03,
                                 5.762170e-03, 5.369077e-03, 4.961209e-03,
                                 4.538942e-03, 4.102228e-03, 3.650003e-03, 
                                 3.177754e-03, 2.903650e-03, 2.855154e-03,
                                 2.809662e-03, 2.765680e-03, 2.722726e-03,
                                 2.680553e-03, 2.639011e-03, 2.598002e-03,
                                 2.557452e-03, 2.517306e-03, 2.477522e-03,
                                 2.438063e-03, 2.398901e-03, 2.360011e-03,
                                 2.321369e-03, 2.282955e-03, 2.244753e-03,
                                 2.206746e-03, 2.168917e-03, 2.131253e-03,
                                 2.093739e-03, 2.056362e-03, 2.019109e-03,
                                 1.981966e-03, 1.944920e-03, 1.907957e-03,
                                 1.871065e-03, 1.834229e-03, 1.797433e-03,
                                 1.760664e-03, 1.723903e-03, 1.687133e-03,
                                 1.650335e-03, 1.613487e-03, 1.576567e-03,
                                 1.539547e-03, 1.502399e-03, 1.465088e-03,
                                 1.427574e-03, 1.389810e-03, 1.351741e-03,
                                 1.313298e-03, 1.274394e-03, 1.234918e-03,
                                 1.194722e-03, 1.153597e-03, 1.111234e-03,
                                 1.067122e-03, 1.020269e-03, 9.676826e-04,
                                 4.411781e-04, 5.061068e-04, 5.635767e-04,
                                 6.176589e-04, 6.696314e-04, 7.201167e-04,
                                 7.694737e-04, 8.179301e-04, 8.656398e-04,
                                 9.127112e-04, 9.592235e-04, 1.005236e-03,
                                 1.050792e-03, 1.095928e-03, 1.140669e-03,
                                 1.185037e-03, 1.229048e-03, 1.272715e-03,
                                 1.316048e-03, 1.359055e-03, 1.401741e-03,
                                 1.444112e-03, 1.486169e-03, 1.527915e-03,
                                 1.569351e-03, 1.610477e-03, 1.651294e-03,
                                 1.691800e-03, 1.731994e-03, 1.771874e-03,
                                 1.811439e-03, 1.850685e-03, 1.889611e-03,
                                 1.928214e-03, 1.966491e-03, 2.004438e-03,
                                 2.042054e-03, 2.079336e-03, 2.116281e-03,
                                 2.152887e-03, 2.189155e-03, 2.225083e-03,
                                 2.260677e-03, 2.295943e-03, 2.330895e-03,
                                 2.365559e-03, 2.399985e-03, 2.434276e-03,
                                 2.468680e-03, 2.504117e-03, 2.670581e-03,
                                 2.996545e-03, 3.324903e-03, 3.649002e-03,
                                 3.966637e-03, 4.276347e-03, 4.576927e-03,
                                 4.867314e-03, 5.146542e-03, 5.413724e-03,
                                 5.668043e-03, 5.908743e-03, 6.135125e-03,
                                 6.346547e-03, 6.542416e-03, 6.722194e-03,
                                 6.885389e-03, 7.031562e-03, 7.160321e-03,
                                 7.271323e-03, 7.364274e-03, 7.438930e-03,
                                 7.495093e-03, 7.532617e-03, 7.551404e-03,
                                 7.551404e-03, 7.532617e-03, 7.495093e-03,
                                 7.438930e-03, 7.364274e-03, 7.271323e-03,
                                 7.160321e-03, 7.031562e-03, 6.885389e-03,
                                 6.722194e-03, 6.542416e-03, 6.346547e-03,
                                 6.135125e-03, 5.908743e-03, 5.668043e-03,
                                 5.413724e-03, 5.146542e-03, 4.867314e-03,
                                 4.576927e-03, 4.276347e-03, 3.966637e-03,
                                 3.649002e-03, 3.324903e-03, 2.996545e-03,
                                 2.670581e-03, 2.504117e-03, 2.468680e-03,
                                 2.434276e-03, 2.399985e-03, 2.365559e-03,
                                 2.330895e-03, 2.295943e-03, 2.260677e-03,
                                 2.225083e-03, 2.189155e-03, 2.152887e-03,
                                 2.116281e-03, 2.079336e-03, 2.042054e-03,
                                 2.004438e-03, 1.966491e-03, 1.928214e-03,
                                 1.889611e-03, 1.850685e-03, 1.811439e-03,
                                 1.771874e-03, 1.731994e-03, 1.691800e-03, 
                                 1.651294e-03, 1.610477e-03, 1.569351e-03, 
                                 1.527915e-03, 1.486169e-03, 1.444112e-03, 
                                 1.401741e-03, 1.359055e-03, 1.316048e-03, 
                                 1.272715e-03, 1.229048e-03, 1.185037e-03, 
                                 1.140669e-03, 1.095928e-03, 1.050792e-03, 
                                 1.005236e-03, 9.592235e-04, 9.127112e-04, 
                                 8.656398e-04, 8.179301e-04, 7.694737e-04, 
                                 7.201167e-04, 6.696314e-04, 6.176589e-04, 
                                 5.635767e-04, 5.061068e-04, 4.411781e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");

  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(),  kEffRef);
}

// slab geometry, memory test

TEST_F(CPMIntegrationTests, memTestCPMslab)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem1SL.txt";
  const std::string outputPath = "outputs/Out_CPMProblem1SL.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

// cylindrical geometry, memory test

TEST_F(CPMIntegrationTests, memTestCPMcyl)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem1CY.txt";
  const std::string outputPath = "outputs/Out_CPMProblem1CY.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}

// spherical geometry, memory test

TEST_F(CPMIntegrationTests, memTestCPMsph)
{	
  const std::string valgrind   = "valgrind --leak-check=yes --quiet --error-exitcode=-1";
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/CPMProblem1CY.txt";
  const std::string outputPath = "outputs/Out_CPMProblem1CY.txt";
  const std::string traceLevel = "DEBUG";

  TestHelper test(valgrind, codePath, inputPath, outputPath, traceLevel);
  
  EXPECT_TRUE((test.runCode() == 0));
}
