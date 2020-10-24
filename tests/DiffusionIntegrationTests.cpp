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

TEST_F(DiffIntegrationTests, diff5)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff5.txt";
  const std::string outputPath = "outputs/Out_diff5.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 1.332507e+00;
  std::vector<double> refFlux = {7.338337e-03,
                                 7.331305e-03,
                                 7.317248e-03,
                                 7.296178e-03,
                                 7.268117e-03,
                                 7.233090e-03,
                                 7.191133e-03,
                                 7.142284e-03,
                                 7.086592e-03,
                                 7.024108e-03,
                                 6.954894e-03,
                                 6.879015e-03,
                                 6.796545e-03,
                                 6.707563e-03,
                                 6.612154e-03,
                                 6.510410e-03,
                                 6.402428e-03,
                                 6.288314e-03,
                                 6.168175e-03,
                                 6.042129e-03,
                                 5.910296e-03,
                                 5.772805e-03,
                                 5.629787e-03,
                                 5.481381e-03,
                                 5.327730e-03,
                                 5.168985e-03,
                                 5.005298e-03,
                                 4.836830e-03,
                                 4.663746e-03,
                                 4.486214e-03,
                                 4.304409e-03,
                                 4.118511e-03,
                                 3.928705e-03,
                                 3.735180e-03,
                                 3.538131e-03,
                                 3.337756e-03,
                                 3.134263e-03,
                                 2.927859e-03,
                                 2.718763e-03,
                                 2.507197e-03,
                                 2.293389e-03,
                                 2.077575e-03,
                                 1.860001e-03,
                                 1.640919e-03,
                                 1.420593e-03,
                                 1.199296e-03,
                                 9.773177e-04,
                                 7.549603e-04,
                                 5.325450e-04,
                                 3.104135e-04,
                                 2.362498e-02,
                                 2.360234e-02,
                                 2.355708e-02,
                                 2.348924e-02,
                                 2.339889e-02,
                                 2.328611e-02,
                                 2.315102e-02,
                                 2.299374e-02,
                                 2.281442e-02,
                                 2.261323e-02,
                                 2.239037e-02,
                                 2.214606e-02,
                                 2.188051e-02,
                                 2.159400e-02,
                                 2.128678e-02,
                                 2.095917e-02,
                                 2.061146e-02,
                                 2.024399e-02,
                                 1.985712e-02,
                                 1.945121e-02,
                                 1.902666e-02,
                                 1.858386e-02,
                                 1.812324e-02,
                                 1.764524e-02,
                                 1.715032e-02,
                                 1.663895e-02,
                                 1.611161e-02,
                                 1.556881e-02,
                                 1.501107e-02,
                                 1.443891e-02,
                                 1.385288e-02,
                                 1.325354e-02,
                                 1.264144e-02,
                                 1.201717e-02,
                                 1.138132e-02,
                                 1.073448e-02,
                                 1.007726e-02,
                                 9.410264e-03,
                                 8.734119e-03,
                                 8.049444e-03,
                                 7.356864e-03,
                                 6.657008e-03,
                                 5.950502e-03,
                                 5.237972e-03,
                                 4.520039e-03,
                                 3.797317e-03,
                                 3.070411e-03,
                                 2.339913e-03,
                                 1.606398e-03,
                                 8.704193e-04};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(DiffIntegrationTests, diff6)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/diff6.txt";
  const std::string outputPath = "outputs/Out_diff6.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 1.387815e+00;
  std::vector<double> refFlux = {9.742062e-03,
                                 9.735790e-03,
                                 9.723160e-03,
                                 9.703996e-03,
                                 9.678034e-03,
                                 9.644917e-03,
                                 9.604190e-03,
                                 9.555298e-03,
                                 9.497574e-03,
                                 9.430237e-03,
                                 9.352380e-03,
                                 9.262959e-03,
                                 9.160784e-03,
                                 9.044501e-03,
                                 8.912581e-03,
                                 8.763298e-03,
                                 8.594711e-03,
                                 8.404643e-03,
                                 8.190654e-03,
                                 7.950011e-03,
                                 7.679660e-03,
                                 7.376192e-03,
                                 7.035795e-03,
                                 6.654222e-03,
                                 6.226731e-03,
                                 5.729146e-03,
                                 5.257752e-03,
                                 4.827699e-03,
                                 4.435578e-03,
                                 4.078276e-03,
                                 3.752960e-03,
                                 3.457049e-03,
                                 3.188198e-03,
                                 2.944272e-03,
                                 2.723338e-03,
                                 2.523643e-03,
                                 2.343604e-03,
                                 2.181793e-03,
                                 2.036926e-03,
                                 1.907855e-03,
                                 1.793557e-03,
                                 1.693125e-03,
                                 1.605763e-03,
                                 1.530778e-03,
                                 1.467576e-03,
                                 1.415655e-03,
                                 1.374603e-03,
                                 1.344096e-03,
                                 1.323892e-03,
                                 1.313829e-03,
                                 9.935105e-03,
                                 9.943559e-03,
                                 9.960550e-03,
                                 9.986251e-03,
                                 1.002092e-02,
                                 1.006490e-02,
                                 1.011864e-02,
                                 1.018269e-02,
                                 1.025768e-02,
                                 1.034439e-02,
                                 1.044370e-02,
                                 1.055663e-02,
                                 1.068433e-02,
                                 1.082813e-02,
                                 1.098953e-02,
                                 1.117020e-02,
                                 1.137203e-02,
                                 1.159716e-02,
                                 1.184795e-02,
                                 1.212707e-02,
                                 1.243751e-02,
                                 1.278257e-02,
                                 1.316598e-02,
                                 1.359187e-02,
                                 1.406487e-02,
                                 1.458786e-02,
                                 1.505712e-02,
                                 1.547959e-02,
                                 1.585957e-02,
                                 1.620096e-02,
                                 1.650733e-02,
                                 1.678191e-02,
                                 1.702764e-02,
                                 1.724721e-02,
                                 1.744304e-02,
                                 1.761733e-02,
                                 1.777206e-02,
                                 1.790902e-02,
                                 1.802982e-02,
                                 1.813589e-02,
                                 1.822852e-02,
                                 1.830884e-02,
                                 1.837785e-02,
                                 1.843641e-02,
                                 1.848526e-02,
                                 1.852504e-02,
                                 1.855626e-02,
                                 1.857932e-02,
                                 1.859453e-02,
                                 1.860208e-02};

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