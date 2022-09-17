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

  std::vector<double> refFlux {1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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
  
  std::vector<double> refFlux {1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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

	std::vector<double> refFlux {1.000000e+00, 9.841472e-01, 9.528035e-01, 
	9.066004e-01, 8.464557e-01, 7.735065e-01, 6.889990e-01, 5.940601e-01, 
	4.890574e-01, 3.701407e-01};

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
  
	std::vector<double> refFlux {1.000000e+00, 9.719719e-01, 9.168789e-01, 
	8.362845e-01, 7.318758e-01, 6.024215e-01, 4.622399e-01, 3.744655e-01, 
	3.084242e-01, 2.542614e-01, 2.078822e-01, 1.666136e-01, 1.274109e-01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  // PrintFuncs::createCppVector(flux, "%7.6e");

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
  
  std::vector<double> refFlux {1.000000e+00, 9.911029e-01, 9.733957e-01, 
	9.470142e-01, 9.121458e-01, 8.689922e-01, 8.176973e-01, 7.581797e-01, 
	6.896276e-01, 6.076752e-01, 4.006208e-01, 2.455750e-01, 1.616728e-01, 
	1.100315e-01, 7.637421e-02, 5.371077e-02, 3.812718e-02, 2.725501e-02, 
	1.958860e-02, 1.413826e-02, 1.023791e-02, 7.431309e-03, 5.401756e-03, 
	3.927021e-03, 2.849740e-03, 2.057523e-03, 1.469338e-03, 1.025936e-03, 
	6.825390e-04, 3.998150e-04};

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

  std::vector<double> refFlux {6.752294e-01, 6.752294e-01, 6.752294e-01, 
	6.752294e-01, 6.752294e-01, 6.752294e-01, 6.752294e-01, 6.752294e-01, 
	6.752294e-01, 6.752294e-01, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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
  
  std::vector<double> refFlux {1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 4.800000e-01, 4.800000e-01, 4.800000e-01, 
	4.800000e-01, 4.800000e-01, 4.800000e-01, 4.800000e-01, 4.800000e-01, 
	4.800000e-01, 4.800000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 
	1.500000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 
	1.500000e-01, 1.500000e-01};

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
  
	std::vector<double> refFlux {1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 4.800000e-01, 4.800000e-01, 4.800000e-01, 
	4.800000e-01, 4.800000e-01, 4.800000e-01, 4.800000e-01, 4.800000e-01, 
	4.800000e-01, 4.800000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 
	1.500000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 
	1.500000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 
	1.500000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 1.500000e-01, 
	1.500000e-01, 1.500000e-01, 4.800000e-01, 4.800000e-01, 4.800000e-01, 
	4.800000e-01, 4.800000e-01, 4.800000e-01, 4.800000e-01, 4.800000e-01, 
	4.800000e-01, 4.800000e-01, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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

  std::vector<double> refFlux {1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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

  std::vector<double> refFlux {1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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
  
  std::vector<double> refFlux {1.000000e+00, 9.850355e-01, 9.562849e-01, 
	9.141330e-01, 8.595937e-01, 7.939904e-01, 7.188840e-01, 6.359966e-01, 
	5.471040e-01, 4.538461e-01, 3.572503e-01, 2.552401e-01};

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
  
  std::vector<double> refFlux {1.000000e+00, 9.884756e-01, 9.662660e-01, 
	9.335386e-01, 8.908903e-01, 8.391112e-01, 7.791435e-01, 7.120389e-01, 
	6.388976e-01, 5.607547e-01, 4.782883e-01, 3.903429e-01, 3.117535e-01, 
	2.655440e-01, 2.289264e-01, 1.980612e-01, 1.713528e-01, 1.478283e-01, 
	1.267911e-01, 1.076708e-01, 8.989040e-02, 7.243478e-02};

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
  
  std::vector<double> refFlux {6.752294e-01, 6.752294e-01, 6.752294e-01, 
	6.752294e-01, 6.752294e-01, 6.752294e-01, 6.752294e-01, 6.752294e-01, 
	6.752294e-01, 6.752294e-01, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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
  
  std::vector<double> refFlux {6.600132e-01, 6.456193e-01, 6.181479e-01, 
	5.783093e-01, 5.275506e-01, 4.677076e-01, 4.008731e-01, 3.292194e-01, 
	2.546366e-01, 1.771033e-01, 1.000000e+00, 9.776466e-01, 9.349748e-01, 
	8.730596e-01, 7.940944e-01, 7.008566e-01, 5.964934e-01, 4.842251e-01, 
	3.667128e-01, 2.431438e-01};

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
  
  std::vector<double> refFlux {1.000000e+00, 9.999884e-01, 9.999586e-01, 
	9.998928e-01, 9.997529e-01, 9.994598e-01, 9.988567e-01, 9.976425e-01, 
	9.952635e-01, 9.907495e-01, 9.824930e-01, 9.680004e-01, 9.436935e-01, 
	9.049102e-01, 8.462968e-01, 7.627629e-01, 6.509991e-01, 5.112496e-01, 
	3.486899e-01, 1.736218e-01, 3.728103e-02, 3.728059e-02, 3.727945e-02, 
	3.727694e-02, 3.727162e-02, 3.726049e-02, 3.723762e-02, 3.719167e-02, 
	3.710180e-02, 3.693158e-02, 3.662078e-02, 3.607616e-02, 3.516428e-02, 
	3.371164e-02, 3.151959e-02, 2.839991e-02, 2.423112e-02, 1.902396e-02, 
	1.297195e-02, 6.458081e-03};
 
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

  std::vector<double> refFlux {1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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

  std::vector<double> refFlux {1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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
  
	std::vector<double> refFlux {6.384221e-01, 7.885642e-01, 8.947454e-01, 
	9.649104e-01, 1.000000e+00, 1.000000e+00, 9.649104e-01, 8.947454e-01, 
	7.885642e-01, 6.384221e-01};

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
 
	std::vector<double> refFlux {9.207810e-01, 4.296557e-01, -5.377018e-01, 
	-1.000000e+00, -4.932858e-01, 4.932858e-01, 1.000000e+00, 5.377018e-01, 
	-4.296557e-01, -9.207810e-01};
 
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

  std::vector<double> refFlux {6.078250e-01, 7.210922e-01, 8.092591e-01, 
	8.795822e-01, 9.336274e-01, 9.717606e-01, 9.939496e-01, 1.000000e+00, 
	9.895917e-01, 9.621485e-01, 9.163116e-01, 8.469765e-01, 7.537937e-01, 
	6.900367e-01, 6.389229e-01, 5.941607e-01, 5.535624e-01, 5.159691e-01, 
	4.806528e-01, 4.471041e-01, 4.149326e-01, 3.838111e-01, 3.534347e-01, 
	3.234775e-01, 2.935216e-01, 2.628710e-01, 2.295725e-01};

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

	std::vector<double> refFlux {3.336762e-01, 3.738216e-01, 4.111019e-01, 
	4.478573e-01, 4.850305e-01, 5.233168e-01, 5.634360e-01, 6.063520e-01, 
	6.537253e-01, 7.101184e-01, 7.950555e-01, 8.676535e-01, 9.215772e-01, 
	9.610267e-01, 9.870480e-01, 1.000000e+00, 1.000000e+00, 9.870480e-01, 
	9.610267e-01, 9.215772e-01, 8.676535e-01, 7.950555e-01, 7.101184e-01, 
	6.537253e-01, 6.063520e-01, 5.634360e-01, 5.233168e-01, 4.850305e-01, 
	4.478573e-01, 4.111019e-01, 3.738216e-01, 3.336762e-01};

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
  
	std::vector<double> refFlux {6.194455e-01, 7.898631e-01, 9.065801e-01, 
	9.765857e-01, 1.000000e+00, 9.765857e-01, 9.065801e-01, 7.898631e-01, 
	6.194455e-01};

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
  
  std::vector<double> refFlux {6.752294e-01, 6.752294e-01, 6.752294e-01, 
	6.752294e-01, 6.752294e-01, 6.752294e-01, 6.752294e-01, 6.752294e-01, 
	6.752294e-01, 6.752294e-01, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 1.000000e+00, 
	1.000000e+00, 1.000000e+00};

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
  
  std::vector<double> refFlux {4.278325e-01, 5.352261e-01, 6.131771e-01, 
	6.654158e-01, 6.917374e-01, 6.917374e-01, 6.654158e-01, 6.131771e-01, 
	5.352261e-01, 4.278325e-01, 5.683256e-01, 7.455176e-01, 8.726645e-01, 
	9.574122e-01, 1.000000e+00, 1.000000e+00, 9.574122e-01, 8.726645e-01, 
	7.455176e-01, 5.683256e-01};

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
  
  std::vector<double> refFlux {1.897927e-01, 3.694914e-01, 5.306284e-01, 
	6.675378e-01, 7.778030e-01, 8.619582e-01, 9.226489e-01, 9.635578e-01, 
	9.883767e-01, 1.000000e+00, 1.000000e+00, 9.883767e-01, 9.635578e-01, 
	9.226489e-01, 8.619582e-01, 7.778030e-01, 6.675378e-01, 5.306284e-01, 
	3.694914e-01, 1.897927e-01, 7.066605e-03, 1.375835e-02, 1.976061e-02, 
	2.486256e-02, 2.897383e-02, 3.211359e-02, 3.437951e-02, 3.590795e-02, 
	3.683582e-02, 3.727056e-02, 3.727056e-02, 3.683582e-02, 3.590795e-02, 
	3.437951e-02, 3.211359e-02, 2.897383e-02, 2.486256e-02, 1.976061e-02, 
	1.375835e-02, 7.066605e-03};

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
  
  	std::vector<double> refFlux {1.009819e-01, 1.064695e-01, 1.113589e-01, 
	1.159621e-01, 1.203829e-01, 1.246744e-01, 1.288691e-01, 1.329886e-01, 
	1.370484e-01, 1.410601e-01, 1.450328e-01, 1.489735e-01, 1.528883e-01, 
	1.567819e-01, 1.606585e-01, 1.645216e-01, 1.683744e-01, 1.722196e-01, 
	1.760596e-01, 1.798967e-01, 1.837329e-01, 1.875700e-01, 1.914098e-01, 
	1.952538e-01, 1.991037e-01, 2.029608e-01, 2.068268e-01, 2.107028e-01, 
	2.145903e-01, 2.184908e-01, 2.224055e-01, 2.263360e-01, 2.302835e-01, 
	2.342498e-01, 2.382363e-01, 2.422449e-01, 2.462774e-01, 2.503358e-01, 
	2.544225e-01, 2.585402e-01, 2.626918e-01, 2.668812e-01, 2.711128e-01, 
	2.753923e-01, 2.797274e-01, 2.841283e-01, 2.886108e-01, 2.932005e-01, 
	2.979478e-01, 3.030085e-01, 3.316124e-01, 3.808937e-01, 4.280854e-01, 
	4.736584e-01, 5.177238e-01, 5.602866e-01, 6.013076e-01, 6.407265e-01, 
	6.784729e-01, 7.144719e-01, 7.486472e-01, 7.809232e-01, 8.112268e-01, 
	8.394875e-01, 8.656390e-01, 8.896191e-01, 9.113703e-01, 9.308402e-01, 
	9.479815e-01, 9.627527e-01, 9.751176e-01, 9.850461e-01, 9.925139e-01, 
	9.975026e-01, 1.000000e+00, 1.000000e+00, 9.975026e-01, 9.925139e-01, 
	9.850461e-01, 9.751176e-01, 9.627527e-01, 9.479815e-01, 9.308402e-01, 
	9.113703e-01, 8.896191e-01, 8.656390e-01, 8.394875e-01, 8.112268e-01, 
	7.809232e-01, 7.486472e-01, 7.144719e-01, 6.784729e-01, 6.407265e-01, 
	6.013076e-01, 5.602866e-01, 5.177238e-01, 4.736584e-01, 4.280854e-01, 
	3.808937e-01, 3.316124e-01, 3.030085e-01, 2.979478e-01, 2.932005e-01, 
	2.886108e-01, 2.841283e-01, 2.797274e-01, 2.753923e-01, 2.711128e-01, 
	2.668812e-01, 2.626918e-01, 2.585402e-01, 2.544225e-01, 2.503358e-01, 
	2.462774e-01, 2.422449e-01, 2.382363e-01, 2.342498e-01, 2.302835e-01, 
	2.263360e-01, 2.224055e-01, 2.184908e-01, 2.145903e-01, 2.107028e-01, 
	2.068268e-01, 2.029608e-01, 1.991037e-01, 1.952538e-01, 1.914098e-01, 
	1.875700e-01, 1.837329e-01, 1.798967e-01, 1.760596e-01, 1.722196e-01, 
	1.683744e-01, 1.645216e-01, 1.606585e-01, 1.567819e-01, 1.528883e-01, 
	1.489735e-01, 1.450328e-01, 1.410601e-01, 1.370484e-01, 1.329886e-01, 
	1.288691e-01, 1.246744e-01, 1.203829e-01, 1.159621e-01, 1.113589e-01, 
	1.064695e-01, 1.009819e-01, 4.603885e-02, 5.281445e-02, 5.881168e-02, 
	6.445540e-02, 6.987896e-02, 7.514732e-02, 8.029793e-02, 8.535457e-02, 
	9.033328e-02, 9.524539e-02, 1.000991e-01, 1.049007e-01, 1.096547e-01, 
	1.143648e-01, 1.190338e-01, 1.236638e-01, 1.282565e-01, 1.328134e-01, 
	1.373354e-01, 1.418233e-01, 1.462778e-01, 1.506993e-01, 1.550882e-01, 
	1.594445e-01, 1.637686e-01, 1.680603e-01, 1.723197e-01, 1.765467e-01, 
	1.807411e-01, 1.849028e-01, 1.890315e-01, 1.931271e-01, 1.971892e-01, 
	2.012175e-01, 2.052119e-01, 2.091719e-01, 2.130973e-01, 2.169878e-01, 
	2.208431e-01, 2.246632e-01, 2.284478e-01, 2.321972e-01, 2.359115e-01, 
	2.395916e-01, 2.432390e-01, 2.468563e-01, 2.504489e-01, 2.540274e-01, 
	2.576175e-01, 2.613156e-01, 2.786868e-01, 3.127026e-01, 3.469681e-01, 
	3.807893e-01, 4.139359e-01, 4.462554e-01, 4.776223e-01, 5.079254e-01, 
	5.370641e-01, 5.649457e-01, 5.914850e-01, 6.166030e-01, 6.402270e-01, 
	6.622898e-01, 6.827296e-01, 7.014902e-01, 7.185204e-01, 7.337742e-01, 
	7.472107e-01, 7.587943e-01, 7.684941e-01, 7.762847e-01, 7.821456e-01, 
	7.860614e-01, 7.880219e-01, 7.880219e-01, 7.860614e-01, 7.821456e-01, 
	7.762847e-01, 7.684941e-01, 7.587943e-01, 7.472107e-01, 7.337742e-01, 
	7.185204e-01, 7.014902e-01, 6.827296e-01, 6.622898e-01, 6.402270e-01, 
	6.166030e-01, 5.914850e-01, 5.649457e-01, 5.370641e-01, 5.079254e-01, 
	4.776223e-01, 4.462554e-01, 4.139359e-01, 3.807893e-01, 3.469681e-01, 
	3.127026e-01, 2.786868e-01, 2.613156e-01, 2.576175e-01, 2.540274e-01, 
	2.504489e-01, 2.468563e-01, 2.432390e-01, 2.395916e-01, 2.359115e-01, 
	2.321972e-01, 2.284478e-01, 2.246632e-01, 2.208431e-01, 2.169878e-01, 
	2.130973e-01, 2.091719e-01, 2.052119e-01, 2.012175e-01, 1.971892e-01, 
	1.931271e-01, 1.890315e-01, 1.849028e-01, 1.807411e-01, 1.765467e-01, 
	1.723197e-01, 1.680603e-01, 1.637686e-01, 1.594445e-01, 1.550882e-01, 
	1.506993e-01, 1.462778e-01, 1.418233e-01, 1.373354e-01, 1.328134e-01, 
	1.282565e-01, 1.236638e-01, 1.190338e-01, 1.143648e-01, 1.096547e-01, 
	1.049007e-01, 1.000991e-01, 9.524539e-02, 9.033328e-02, 8.535457e-02, 
	8.029793e-02, 7.514732e-02, 6.987896e-02, 6.445540e-02, 5.881168e-02, 
	5.281445e-02, 4.603885e-02};

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
