#include "gtest/gtest.h"
#include "TestHelper.h"
#include "additionalPrintFuncs.h"

using namespace PrintFuncs;

class CoupledIntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

// Steady-state, cylinder geometry, heat-diffusion coupled calculation
// One neutron energy group
// Reactor thermal power = 0.0 W
// Constant thermal conductivity
// Heat boundary condition: T(L) = T2 (300K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest1)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled1.txt";
  const std::string outputPath = "outputs/Out_Coupled1.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 0.81980258;

	std::vector<double> refFlux {1.000000e+00, 9.988834e-01, 9.966521e-01, 
	9.933099e-01, 9.888626e-01, 9.833177e-01, 9.766848e-01, 9.689752e-01, 
	9.602020e-01, 9.503803e-01, 9.395266e-01, 9.276597e-01, 9.147995e-01, 
	9.009679e-01, 8.861883e-01, 8.704858e-01, 8.538868e-01, 8.364193e-01, 
	8.181127e-01, 7.989976e-01, 7.791060e-01, 7.584712e-01, 7.371274e-01, 
	7.151101e-01, 6.924557e-01, 6.692016e-01, 6.453860e-01, 6.210481e-01, 
	5.962275e-01, 5.709647e-01, 5.453007e-01, 5.192770e-01, 4.929355e-01, 
	4.663184e-01, 4.394683e-01, 4.124279e-01, 3.852401e-01, 3.579477e-01, 
	3.305936e-01, 3.032205e-01, 2.758710e-01, 2.485874e-01, 2.214117e-01, 
	1.943853e-01, 1.675496e-01, 1.409450e-01, 1.146115e-01, 8.858841e-02, 
	6.291431e-02, 3.762697e-02};

	std::vector<double> refTemp {2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, cylinder geometry, heat-diffusion coupled calculation
// One neutron energy group
// Reactor thermal power = 0.0 W
// Constant thermal conductivity
// Heat boundary condition: T(L) = T2 (600K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest2)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled2.txt";
  const std::string outputPath = "outputs/Out_Coupled2.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 0.7917704;

	std::vector<double> refFlux {1.000000e+00, 9.988782e-01, 9.966366e-01, 
	9.932790e-01, 9.888111e-01, 9.832407e-01, 9.765772e-01, 9.688321e-01, 
	9.600187e-01, 9.501520e-01, 9.392489e-01, 9.273279e-01, 9.144094e-01, 
	9.005154e-01, 8.856694e-01, 8.698967e-01, 8.532240e-01, 8.356793e-01, 
	8.172923e-01, 7.980940e-01, 7.781165e-01, 7.573933e-01, 7.359590e-01, 
	7.138493e-01, 6.911010e-01, 6.677517e-01, 6.438399e-01, 6.194052e-01, 
	5.944875e-01, 5.691276e-01, 5.433669e-01, 5.172472e-01, 4.908108e-01, 
	4.641003e-01, 4.371586e-01, 4.100288e-01, 3.827541e-01, 3.553777e-01, 
	3.279429e-01, 3.004928e-01, 2.730702e-01, 2.457178e-01, 2.184780e-01, 
	1.913927e-01, 1.645033e-01, 1.378506e-01, 1.114750e-01, 8.541615e-02, 
	5.971277e-02, 3.440292e-02};

	std::vector<double> refTemp {3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02};
 
  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, cylinder geometry, heat-diffusion coupled calculation
// One neutron energy group
// Reactor thermal power = 100.0 kW
// Constant thermal conductivity
// Heat boundary condition: T(L) = T2
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest3)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled3.txt";
  const std::string outputPath = "outputs/Out_Coupled3.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 0.78571641;

	std::vector<double> refFlux {1.000000e+00, 9.990544e-01, 9.971642e-01, 
	9.943313e-01, 9.905585e-01, 9.858495e-01, 9.802090e-01, 9.736422e-01, 
	9.661553e-01, 9.577552e-01, 9.484492e-01, 9.382455e-01, 9.271526e-01, 
	9.151794e-01, 9.023355e-01, 8.886304e-01, 8.740745e-01, 8.586780e-01, 
	8.424518e-01, 8.254070e-01, 8.075551e-01, 7.889080e-01, 7.694783e-01, 
	7.492791e-01, 7.283244e-01, 7.066289e-01, 6.842088e-01, 6.610815e-01, 
	6.372657e-01, 6.127824e-01, 5.876543e-01, 5.619066e-01, 5.355673e-01, 
	5.086672e-01, 4.812402e-01, 4.533240e-01, 4.249600e-01, 3.961934e-01, 
	3.670740e-01, 3.376557e-01, 3.079972e-01, 2.781618e-01, 2.482175e-01, 
	2.182367e-01, 1.882967e-01, 1.584791e-01, 1.288695e-01, 9.955745e-02, 
	7.063587e-02, 4.220063e-02};

	std::vector<double> refTemp {5.484115e+02, 5.478724e+02, 5.467949e+02, 
	5.451800e+02, 5.430295e+02, 5.403459e+02, 5.371319e+02, 5.333911e+02, 
	5.291276e+02, 5.243459e+02, 5.190514e+02, 5.132496e+02, 5.069470e+02, 
	5.001504e+02, 4.928671e+02, 4.851052e+02, 4.768731e+02, 4.681800e+02, 
	4.590353e+02, 4.494492e+02, 4.394326e+02, 4.289965e+02, 4.181531e+02, 
	4.069146e+02, 3.952942e+02, 3.833057e+02, 3.709633e+02, 3.582822e+02, 
	3.452781e+02, 3.319675e+02, 3.183676e+02, 3.044964e+02, 2.903727e+02, 
	2.760162e+02, 2.614473e+02, 2.466875e+02, 2.317590e+02, 2.166849e+02, 
	2.014893e+02, 1.861973e+02, 1.708347e+02, 1.554285e+02, 1.400061e+02, 
	1.245962e+02, 1.092281e+02, 9.393170e+01, 7.873773e+01, 6.367736e+01, 
	4.878225e+01, 3.408432e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2); 

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, cylinder geometry, heat-diffusion coupled calculation
// One neutron energy group
// Reactor thermal power = 100.0 kW
// Temperature-dependent thermal conductivity
// Heat boundary condition: T(L) = T2
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest4)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled4.txt";
  const std::string outputPath = "outputs/Out_Coupled4.txt";
  const std::string traceLevel = "CRITICAL";

  const double kEffRef = 0.78244781;

	std::vector<double> refFlux {1.000000e+00, 9.986069e-01, 9.958264e-01, 
	9.916696e-01, 9.861530e-01, 9.792985e-01, 9.711327e-01, 9.616872e-01, 
	9.509980e-01, 9.391049e-01, 9.260515e-01, 9.118844e-01, 8.966532e-01, 
	8.804095e-01, 8.632068e-01, 8.450999e-01, 8.261446e-01, 8.063970e-01, 
	7.859132e-01, 7.647490e-01, 7.429594e-01, 7.205984e-01, 6.977185e-01, 
	6.743708e-01, 6.506045e-01, 6.264670e-01, 6.020037e-01, 5.772578e-01, 
	5.522706e-01, 5.270813e-01, 5.017273e-01, 4.762440e-01, 4.506652e-01, 
	4.250235e-01, 3.993499e-01, 3.736744e-01, 3.480265e-01, 3.224349e-01, 
	2.969281e-01, 2.715347e-01, 2.462834e-01, 2.212034e-01, 1.963247e-01, 
	1.716781e-01, 1.472954e-01, 1.232100e-01, 9.945607e-02, 7.606967e-02, 
	5.308805e-02, 3.054997e-02};

	std::vector<double> refTemp {8.781492e+02, 8.775004e+02, 8.762043e+02, 
	8.742636e+02, 8.716825e+02, 8.684665e+02, 8.646225e+02, 8.601585e+02, 
	8.550839e+02, 8.494092e+02, 8.431459e+02, 8.363068e+02, 8.289054e+02, 
	8.209562e+02, 8.124747e+02, 8.034769e+02, 7.939796e+02, 7.840004e+02, 
	7.735570e+02, 7.626682e+02, 7.513527e+02, 7.396299e+02, 7.275194e+02, 
	7.150412e+02, 7.022153e+02, 6.890622e+02, 6.756024e+02, 6.618567e+02, 
	6.478460e+02, 6.335912e+02, 6.191134e+02, 6.044340e+02, 5.895744e+02, 
	5.745560e+02, 5.594006e+02, 5.441299e+02, 5.287659e+02, 5.133308e+02, 
	4.978468e+02, 4.823365e+02, 4.668226e+02, 4.513281e+02, 4.358760e+02, 
	4.204897e+02, 4.051926e+02, 3.900086e+02, 3.749615e+02, 3.600752e+02, 
	3.453739e+02, 3.308771e+02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, cylinder geometry, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 0.0
// Constant thermal conductivity
// Heat boundary condition: T(L) = T2 (300K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest5)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled5.txt";
  const std::string outputPath = "outputs/Out_Coupled5.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.81795228;

	std::vector<double> refFlux {7.059577e-01, 7.051816e-01, 7.036307e-01, 
	7.013075e-01, 6.982161e-01, 6.943615e-01, 6.897503e-01, 6.843903e-01, 
	6.782904e-01, 6.714608e-01, 6.639131e-01, 6.556598e-01, 6.467147e-01, 
	6.370927e-01, 6.268099e-01, 6.158834e-01, 6.043313e-01, 5.921728e-01, 
	5.794280e-01, 5.661178e-01, 5.522643e-01, 5.378901e-01, 5.230188e-01, 
	5.076747e-01, 4.918828e-01, 4.756688e-01, 4.590590e-01, 4.420801e-01, 
	4.247595e-01, 4.071250e-01, 3.892048e-01, 3.710276e-01, 3.526221e-01, 
	3.340175e-01, 3.152433e-01, 2.963290e-01, 2.773044e-01, 2.581995e-01, 
	2.390446e-01, 2.198704e-01, 2.007083e-01, 1.815909e-01, 1.625528e-01, 
	1.436327e-01, 1.248755e-01, 1.063375e-01, 8.809449e-02, 7.025585e-02, 
	5.298834e-02, 3.655720e-02, 1.000000e+00, 9.989008e-01, 9.967043e-01, 
	9.934141e-01, 9.890359e-01, 9.835769e-01, 9.770463e-01, 9.694550e-01, 
	9.608159e-01, 9.511434e-01, 9.404537e-01, 9.287646e-01, 9.160957e-01, 
	9.024680e-01, 8.879044e-01, 8.724289e-01, 8.560673e-01, 8.388466e-01, 
	8.207953e-01, 8.019432e-01, 7.823213e-01, 7.619618e-01, 7.408980e-01, 
	7.191643e-01, 6.967962e-01, 6.738299e-01, 6.503027e-01, 6.262525e-01, 
	6.017180e-01, 5.767386e-01, 5.513542e-01, 5.256050e-01, 4.995320e-01, 
	4.731761e-01, 4.465785e-01, 4.197803e-01, 3.928225e-01, 3.657451e-01, 
	3.385871e-01, 3.113853e-01, 2.841729e-01, 2.569765e-01, 2.298122e-01, 
	2.026781e-01, 1.755415e-01, 1.483176e-01, 1.208331e-01, 9.276386e-02, 
	6.352815e-02, 3.210534e-02};

	std::vector<double> refTemp {2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, cylinder geometry, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 0.0
// Constant thermal conductivity
// Heat boundary condition: T(L) = T2 (600K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest6)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled6.txt";
  const std::string outputPath = "outputs/Out_Coupled6.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.78986758;

	std::vector<double> refFlux {5.027450e-01, 5.021906e-01, 5.010827e-01, 
	4.994231e-01, 4.972148e-01, 4.944613e-01, 4.911673e-01, 4.873383e-01, 
	4.829808e-01, 4.781020e-01, 4.727102e-01, 4.668143e-01, 4.604242e-01, 
	4.535506e-01, 4.462049e-01, 4.383993e-01, 4.301467e-01, 4.214610e-01, 
	4.123563e-01, 4.028479e-01, 3.929513e-01, 3.826828e-01, 3.720593e-01, 
	3.610981e-01, 3.498171e-01, 3.382348e-01, 3.263699e-01, 3.142417e-01, 
	3.018697e-01, 2.892738e-01, 2.764743e-01, 2.634917e-01, 2.503467e-01, 
	2.370603e-01, 2.236536e-01, 2.101480e-01, 1.965650e-01, 1.829264e-01, 
	1.692544e-01, 1.555716e-01, 1.419015e-01, 1.282688e-01, 1.147005e-01, 
	1.012270e-01, 8.788475e-02, 7.471939e-02, 6.179205e-02, 4.918883e-02, 
	3.703632e-02, 2.552668e-02, 1.000000e+00, 9.988974e-01, 9.966942e-01, 
	9.933939e-01, 9.890022e-01, 9.835263e-01, 9.769756e-01, 9.693610e-01, 
	9.606951e-01, 9.509927e-01, 9.402698e-01, 9.285445e-01, 9.158362e-01, 
	9.021661e-01, 8.875571e-01, 8.720333e-01, 8.556206e-01, 8.383461e-01, 
	8.202385e-01, 8.013275e-01, 7.816443e-01, 7.612213e-01, 7.400919e-01, 
	7.182908e-01, 6.958535e-01, 6.728164e-01, 6.492171e-01, 6.250936e-01, 
	6.004848e-01, 5.754304e-01, 5.499703e-01, 5.241452e-01, 4.979960e-01, 
	4.715637e-01, 4.448897e-01, 4.180149e-01, 3.909800e-01, 3.638247e-01, 
	3.365871e-01, 3.093028e-01, 2.820032e-01, 2.547131e-01, 2.274463e-01, 
	2.001995e-01, 1.729416e-01, 1.455971e-01, 1.180189e-01, 8.994442e-02, 
	6.092533e-02, 3.021343e-02};

	std::vector<double> refTemp {3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, cylinder geometry, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// Constant thermal conductivity
// Heat boundary condition: T(L) = T2
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest7)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled7.txt";
  const std::string outputPath = "outputs/Out_Coupled7.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.7857883;

	std::vector<double> refFlux {4.231344e-01, 4.228180e-01, 4.221855e-01, 
	4.212377e-01, 4.199755e-01, 4.184003e-01, 4.165135e-01, 4.143169e-01, 
	4.118121e-01, 4.090011e-01, 4.058855e-01, 4.024669e-01, 3.987466e-01, 
	3.947257e-01, 3.904046e-01, 3.857833e-01, 3.808611e-01, 3.756368e-01, 
	3.701083e-01, 3.642726e-01, 3.581259e-01, 3.516637e-01, 3.448806e-01, 
	3.377703e-01, 3.303259e-01, 3.225400e-01, 3.144045e-01, 3.059112e-01, 
	2.970520e-01, 2.878188e-01, 2.782040e-01, 2.682010e-01, 2.578041e-01, 
	2.470094e-01, 2.358147e-01, 2.242203e-01, 2.122291e-01, 1.998472e-01, 
	1.870843e-01, 1.739543e-01, 1.604757e-01, 1.466725e-01, 1.325753e-01, 
	1.182227e-01, 1.036643e-01, 8.896459e-02, 7.421081e-02, 5.952579e-02, 
	4.509047e-02, 3.118347e-02, 1.000000e+00, 9.989868e-01, 9.969604e-01, 
	9.939208e-01, 9.898677e-01, 9.848014e-01, 9.787218e-01, 9.716293e-01, 
	9.635247e-01, 9.544090e-01, 9.442841e-01, 9.331526e-01, 9.210180e-01, 
	9.078851e-01, 8.937603e-01, 8.786517e-01, 8.625694e-01, 8.455259e-01, 
	8.275364e-01, 8.086190e-01, 7.887951e-01, 7.680896e-01, 7.465314e-01, 
	7.241532e-01, 7.009920e-01, 6.770892e-01, 6.524904e-01, 6.272455e-01, 
	6.014088e-01, 5.750385e-01, 5.481964e-01, 5.209478e-01, 4.933609e-01, 
	4.655062e-01, 4.374557e-01, 4.092828e-01, 3.810609e-01, 3.528629e-01, 
	3.247599e-01, 2.968199e-01, 2.691060e-01, 2.416738e-01, 2.145673e-01, 
	1.878118e-01, 1.614034e-01, 1.352897e-01, 1.093376e-01, 8.327754e-02, 
	5.660672e-02, 2.841986e-02};

	std::vector<double> refTemp {5.501180e+02, 5.495751e+02, 5.484900e+02, 
	5.468637e+02, 5.446982e+02, 5.419959e+02, 5.387596e+02, 5.349930e+02, 
	5.307003e+02, 5.258862e+02, 5.205560e+02, 5.147156e+02, 5.083715e+02, 
	5.015307e+02, 4.942007e+02, 4.863897e+02, 4.781064e+02, 4.693601e+02, 
	4.601606e+02, 4.505183e+02, 4.404442e+02, 4.299499e+02, 4.190475e+02, 
	4.077499e+02, 3.960705e+02, 3.840234e+02, 3.716233e+02, 3.588856e+02, 
	3.458266e+02, 3.324631e+02, 3.188126e+02, 3.048936e+02, 2.907252e+02, 
	2.763272e+02, 2.617206e+02, 2.469266e+02, 2.319677e+02, 2.168670e+02, 
	2.016485e+02, 1.863368e+02, 1.709574e+02, 1.555365e+02, 1.401011e+02, 
	1.246790e+02, 1.092986e+02, 9.398904e+01, 7.878059e+01, 6.370454e+01, 
	4.879391e+01, 3.408432e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, cylinder geometry, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// Temperature-dependent thermal conductivity
// Heat boundary condition: T(L) = T2
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest8)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled8.txt";
  const std::string outputPath = "outputs/Out_Coupled8.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.78616017;

	std::vector<double> refFlux {4.257309e-01, 4.254143e-01, 4.247816e-01, 
	4.238331e-01, 4.225698e-01, 4.209925e-01, 4.191026e-01, 4.169013e-01, 
	4.143899e-01, 4.115698e-01, 4.084423e-01, 4.050084e-01, 4.012691e-01, 
	3.972248e-01, 3.928756e-01, 3.882212e-01, 3.832606e-01, 3.779922e-01, 
	3.724138e-01, 3.665223e-01, 3.603140e-01, 3.537845e-01, 3.469284e-01, 
	3.397401e-01, 3.322128e-01, 3.243397e-01, 3.161134e-01, 3.075264e-01, 
	2.985711e-01, 2.892403e-01, 2.795273e-01, 2.694262e-01, 2.589323e-01, 
	2.480422e-01, 2.367547e-01, 2.250706e-01, 2.129934e-01, 2.005297e-01, 
	1.876897e-01, 1.744874e-01, 1.609416e-01, 1.470762e-01, 1.329218e-01, 
	1.185170e-01, 1.039108e-01, 8.916762e-02, 7.437428e-02, 5.965322e-02, 
	4.518505e-02, 3.124821e-02, 1.000000e+00, 9.989838e-01, 9.969515e-01, 
	9.939030e-01, 9.898386e-01, 9.847585e-01, 9.786633e-01, 9.715536e-01, 
	9.634306e-01, 9.542959e-01, 9.441520e-01, 9.330019e-01, 9.208500e-01, 
	9.077015e-01, 8.935636e-01, 8.784448e-01, 8.623560e-01, 8.453100e-01, 
	8.273225e-01, 8.084119e-01, 7.886000e-01, 7.679116e-01, 7.463755e-01, 
	7.240244e-01, 7.008949e-01, 6.770277e-01, 6.524679e-01, 6.272646e-01, 
	6.014711e-01, 5.751447e-01, 5.483461e-01, 5.211396e-01, 4.935921e-01, 
	4.657733e-01, 4.377542e-01, 4.096074e-01, 3.814057e-01, 3.532213e-01, 
	3.251252e-01, 2.971851e-01, 2.694644e-01, 2.420189e-01, 2.148928e-01, 
	1.881122e-01, 1.616735e-01, 1.355250e-01, 1.095340e-01, 8.343113e-02, 
	5.671332e-02, 2.847420e-02};

	std::vector<double> refTemp {5.375243e+02, 5.370059e+02, 5.359697e+02, 
	5.344166e+02, 5.323481e+02, 5.297662e+02, 5.266735e+02, 5.230729e+02, 
	5.189679e+02, 5.143624e+02, 5.092610e+02, 5.036686e+02, 4.975908e+02, 
	4.910333e+02, 4.840027e+02, 4.765060e+02, 4.685506e+02, 4.601444e+02, 
	4.512961e+02, 4.420146e+02, 4.323095e+02, 4.221910e+02, 4.116698e+02, 
	4.007573e+02, 3.894654e+02, 3.778067e+02, 3.657944e+02, 3.534426e+02, 
	3.407659e+02, 3.277797e+02, 3.145002e+02, 3.009443e+02, 2.871297e+02, 
	2.730751e+02, 2.587999e+02, 2.443243e+02, 2.296696e+02, 2.148577e+02, 
	1.999115e+02, 1.848548e+02, 1.697123e+02, 1.545094e+02, 1.392724e+02, 
	1.240287e+02, 1.088062e+02, 9.363398e+01, 7.854204e+01, 6.356177e+01, 
	4.872634e+01, 3.406198e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, water reactor with water reflector, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// Temperature-dependent thermal conductivity
// Heat boundary condition: T(L) = T2 (300K)
// Diffusion boundary condition: Reflective

TEST_F(CoupledIntegrationTests, coupledTest9)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled9.txt";
  const std::string outputPath = "outputs/Out_Coupled9.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.82452291;

	std::vector<double> refFlux {1.000000e+00, 9.990485e-01, 9.971469e-01, 
	9.942979e-01, 9.905059e-01, 9.857763e-01, 9.801162e-01, 9.735338e-01, 
	9.660389e-01, 9.576424e-01, 9.483567e-01, 9.381952e-01, 9.271730e-01, 
	9.153061e-01, 9.026117e-01, 8.891083e-01, 8.748156e-01, 8.597541e-01, 
	8.439458e-01, 8.274133e-01, 8.101805e-01, 7.922721e-01, 7.737136e-01, 
	7.545315e-01, 7.347532e-01, 7.144067e-01, 6.935206e-01, 6.721245e-01, 
	6.502484e-01, 6.279228e-01, 6.051790e-01, 5.820484e-01, 5.585631e-01, 
	5.347555e-01, 5.106583e-01, 4.863044e-01, 4.617270e-01, 4.369593e-01, 
	4.120350e-01, 3.869873e-01, 3.618500e-01, 3.366564e-01, 3.114399e-01, 
	2.862339e-01, 2.610713e-01, 2.359851e-01, 2.110079e-01, 1.861718e-01, 
	1.615089e-01, 1.370505e-01, 1.102968e-01, 8.717262e-02, 6.890898e-02, 
	5.448129e-02, 4.308161e-02, 3.407272e-02, 2.695192e-02, 2.132250e-02, 
	1.687136e-02, 1.335128e-02, 1.056709e-02, 8.364596e-03, 6.622015e-03, 
	5.243111e-03, 4.151835e-03, 3.288075e-03, 2.604308e-03, 2.062959e-03, 
	1.634312e-03, 1.294865e-03, 1.026024e-03, 8.130803e-04, 6.443928e-04, 
	5.107501e-04, 4.048609e-04, 3.209536e-04, 2.544586e-04, 2.017579e-04, 
	1.599863e-04, 1.268747e-04, 1.006259e-04, 7.981625e-05, 6.331797e-05, 
	5.023759e-05, 3.986720e-05, 3.164597e-05, 2.512957e-05, 1.996603e-05, 
	1.587660e-05, 1.264061e-05, 1.008354e-05, 8.067490e-06, 6.483753e-06, 
	5.246897e-06, 4.290142e-06, 3.561738e-06, 3.022151e-06, 2.641908e-06, 
	2.399985e-06, 2.282641e-06};

	std::vector<double> refTemp {2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, water reactor with water reflector, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// Temperature-dependent thermal conductivity
// Heat boundary condition: T(L) = T2 (600K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest10)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled10.txt";
  const std::string outputPath = "outputs/Out_Coupled10.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.79760653;

	std::vector<double> refFlux {1.000000e+00, 9.990620e-01, 9.971873e-01, 
	9.943786e-01, 9.906401e-01, 9.859771e-01, 9.803964e-01, 9.739061e-01, 
	9.665155e-01, 9.582353e-01, 9.490775e-01, 9.390553e-01, 9.281830e-01, 
	9.164763e-01, 9.039520e-01, 8.906280e-01, 8.765233e-01, 8.616581e-01, 
	8.460535e-01, 8.297316e-01, 8.127156e-01, 7.950296e-01, 7.766983e-01, 
	7.577477e-01, 7.382042e-01, 7.180952e-01, 6.974487e-01, 6.762933e-01, 
	6.546583e-01, 6.325736e-01, 6.100696e-01, 5.871771e-01, 5.639273e-01, 
	5.403520e-01, 5.164829e-01, 4.923524e-01, 4.679929e-01, 4.434369e-01, 
	4.187174e-01, 3.938670e-01, 3.689187e-01, 3.439053e-01, 3.188594e-01, 
	2.938139e-01, 2.688012e-01, 2.438536e-01, 2.190031e-01, 1.942816e-01, 
	1.697203e-01, 1.453503e-01, 1.184496e-01, 9.475118e-02, 7.580785e-02, 
	6.066238e-02, 4.855092e-02, 3.886385e-02, 3.111444e-02, 2.491401e-02, 
	1.995210e-02, 1.598065e-02, 1.280147e-02, 1.025610e-02, 8.217883e-03, 
	6.585541e-03, 5.278068e-03, 4.230669e-03, 3.391502e-03, 2.719084e-03, 
	2.180216e-03, 1.748321e-03, 1.402125e-03, 1.124591e-03, 9.020788e-04, 
	7.236607e-04, 5.805845e-04, 4.658387e-04, 3.738049e-04, 2.999813e-04, 
	2.407599e-04, 1.932489e-04, 1.551303e-04, 1.245458e-04, 1.000057e-04, 
	8.031541e-05, 6.451737e-05, 5.184371e-05, 4.167887e-05, 3.352944e-05, 
	2.700005e-05, 2.177411e-05, 1.759829e-05, 1.427021e-05, 1.162854e-05, 
	9.545189e-06, 7.918992e-06, 6.670817e-06, 5.739681e-06, 5.079756e-06, 
	4.658110e-06, 4.453059e-06};

	std::vector<double> refTemp {3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, water reactor with water reflector, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// Temperature-dependent thermal conductivity
// Heat boundary condition: T(L) = T2 (600K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest11)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled11.txt";
  const std::string outputPath = "outputs/Out_Coupled11.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.8025105;

	std::vector<double> refFlux {1.000000e+00, 9.984548e-01, 9.953726e-01, 
	9.907694e-01, 9.846693e-01, 9.771039e-01, 9.681120e-01, 9.577391e-01, 
	9.460372e-01, 9.330638e-01, 9.188816e-01, 9.035578e-01, 8.871633e-01, 
	8.697721e-01, 8.514605e-01, 8.323065e-01, 8.123887e-01, 7.917863e-01, 
	7.705778e-01, 7.488408e-01, 7.266510e-01, 7.040823e-01, 6.812056e-01, 
	6.580889e-01, 6.347968e-01, 6.113902e-01, 5.879259e-01, 5.644570e-01, 
	5.410320e-01, 5.176953e-01, 4.944870e-01, 4.714433e-01, 4.485959e-01, 
	4.259727e-01, 4.035979e-01, 3.814922e-01, 3.596726e-01, 3.381533e-01, 
	3.169457e-01, 2.960584e-01, 2.754980e-01, 2.552689e-01, 2.353741e-01, 
	2.158147e-01, 1.965912e-01, 1.777030e-01, 1.591486e-01, 1.409267e-01, 
	1.230354e-01, 1.054729e-01, 8.622781e-02, 6.915740e-02, 5.545517e-02, 
	4.445833e-02, 3.563429e-02, 2.855508e-02, 2.287682e-02, 1.832324e-02, 
	1.467237e-02, 1.174594e-02, 9.400756e-03, 7.521826e-03, 6.016831e-03, 
	4.811661e-03, 3.846838e-03, 3.074633e-03, 2.456759e-03, 1.962505e-03, 
	1.567248e-03, 1.251247e-03, 9.986799e-04, 7.968701e-04, 6.356626e-04, 
	5.069253e-04, 4.041474e-04, 3.221177e-04, 2.566666e-04, 2.044586e-04, 
	1.628263e-04, 1.296371e-04, 1.031868e-04, 8.211348e-05, 6.532961e-05, 
	5.196666e-05, 4.133142e-05, 3.287078e-05, 2.614360e-05, 2.079824e-05, 
	1.655457e-05, 1.318961e-05, 1.052606e-05, 8.423206e-06, 6.769588e-06, 
	5.477268e-06, 4.477239e-06, 3.715833e-06, 3.151907e-06, 2.754679e-06, 
	2.502100e-06, 2.379675e-06};

	std::vector<double> refTemp {1.090879e+03, 1.090178e+03, 1.088777e+03, 
	1.086682e+03, 1.083898e+03, 1.080432e+03, 1.076294e+03, 1.071497e+03, 
	1.066052e+03, 1.059974e+03, 1.053280e+03, 1.045987e+03, 1.038113e+03, 
	1.029678e+03, 1.020702e+03, 1.011207e+03, 1.001215e+03, 9.907486e+02, 
	9.798300e+02, 9.684826e+02, 9.567299e+02, 9.445952e+02, 9.321020e+02, 
	9.192734e+02, 9.061326e+02, 8.927023e+02, 8.790051e+02, 8.650632e+02, 
	8.508981e+02, 8.365312e+02, 8.219834e+02, 8.072749e+02, 7.924257e+02, 
	7.774551e+02, 7.623820e+02, 7.472249e+02, 7.320016e+02, 7.167297e+02, 
	7.014263e+02, 6.861081e+02, 6.707914e+02, 6.554921e+02, 6.402260e+02, 
	6.250082e+02, 6.098539e+02, 5.947780e+02, 5.797950e+02, 5.649193e+02, 
	5.501653e+02, 5.355469e+02, 5.210783e+02, 5.068934e+02, 4.929812e+02, 
	4.793316e+02, 4.659347e+02, 4.527814e+02, 4.398630e+02, 4.271712e+02, 
	4.146982e+02, 4.024367e+02, 3.903795e+02, 3.785200e+02, 3.668517e+02, 
	3.553687e+02, 3.440651e+02, 3.329353e+02, 3.219743e+02, 3.111768e+02, 
	3.005381e+02, 2.900536e+02, 2.797188e+02, 2.695296e+02, 2.594820e+02, 
	2.495720e+02, 2.397959e+02, 2.301501e+02, 2.206313e+02, 2.112361e+02, 
	2.019613e+02, 1.928039e+02, 1.837610e+02, 1.748298e+02, 1.660074e+02, 
	1.572914e+02, 1.486791e+02, 1.401682e+02, 1.317562e+02, 1.234409e+02, 
	1.152200e+02, 1.070916e+02, 9.905347e+01, 9.110367e+01, 8.324029e+01, 
	7.546145e+01, 6.776537e+01, 6.015030e+01, 5.261456e+01, 4.515650e+01, 
	3.777455e+01, 3.046716e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, water reactor with water reflector, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// M1 with temperature-dependent thermal conductivity and M2 with constant thermal conductivity
// Heat boundary condition: T(L) = T2 (600K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest12)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled12.txt";
  const std::string outputPath = "outputs/Out_Coupled12.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.80082339;

	std::vector<double> refFlux {1.000000e+00, 9.985077e-01, 9.955306e-01, 
	9.910834e-01, 9.851883e-01, 9.778741e-01, 9.691766e-01, 9.591377e-01, 
	9.478050e-01, 9.352318e-01, 9.214758e-01, 9.065991e-01, 8.906673e-01, 
	8.737491e-01, 8.559153e-01, 8.372384e-01, 8.177920e-01, 7.976501e-01, 
	7.768864e-01, 7.555739e-01, 7.337841e-01, 7.115871e-01, 6.890503e-01, 
	6.662387e-01, 6.432144e-01, 6.200361e-01, 5.967592e-01, 5.734351e-01, 
	5.501119e-01, 5.268335e-01, 5.036401e-01, 4.805681e-01, 4.576500e-01, 
	4.349148e-01, 4.123879e-01, 3.900915e-01, 3.680445e-01, 3.462629e-01, 
	3.247603e-01, 3.035475e-01, 2.826332e-01, 2.620245e-01, 2.417264e-01, 
	2.217430e-01, 2.020767e-01, 1.827297e-01, 1.637029e-01, 1.449973e-01, 
	1.266134e-01, 1.085520e-01, 8.874537e-02, 7.117656e-02, 5.707427e-02, 
	4.575636e-02, 3.667469e-02, 2.938879e-02, 2.354474e-02, 1.885821e-02, 
	1.510075e-02, 1.208888e-02, 9.675225e-03, 7.741437e-03, 6.192502e-03, 
	4.952145e-03, 3.959152e-03, 3.164402e-03, 2.528488e-03, 2.019804e-03, 
	1.613007e-03, 1.287779e-03, 1.027838e-03, 8.201360e-04, 6.542218e-04, 
	5.217258e-04, 4.159471e-04, 3.315225e-04, 2.641604e-04, 2.104281e-04, 
	1.675802e-04, 1.334221e-04, 1.061995e-04, 8.451091e-05, 6.723701e-05, 
	5.348391e-05, 4.253816e-05, 3.383049e-05, 2.690690e-05, 2.140548e-05, 
	1.703791e-05, 1.357470e-05, 1.083339e-05, 8.669135e-06, 6.967237e-06, 
	5.637185e-06, 4.607959e-06, 3.824323e-06, 3.243932e-06, 2.835107e-06, 
	2.575153e-06, 2.449154e-06};

	std::vector<double> refTemp {1.066356e+03, 1.065703e+03, 1.064399e+03, 
	1.062446e+03, 1.059851e+03, 1.056619e+03, 1.052760e+03, 1.048282e+03, 
	1.043198e+03, 1.037519e+03, 1.031260e+03, 1.024435e+03, 1.017061e+03, 
	1.009154e+03, 1.000733e+03, 9.918167e+02, 9.824235e+02, 9.725736e+02, 
	9.622872e+02, 9.515848e+02, 9.404874e+02, 9.290158e+02, 9.171909e+02, 
	9.050339e+02, 8.925656e+02, 8.798068e+02, 8.667781e+02, 8.534999e+02, 
	8.399921e+02, 8.262748e+02, 8.123671e+02, 7.982884e+02, 7.840573e+02, 
	7.696923e+02, 7.552113e+02, 7.406322e+02, 7.259721e+02, 7.112480e+02, 
	6.964768e+02, 6.816746e+02, 6.668577e+02, 6.520417e+02, 6.372423e+02, 
	6.224747e+02, 6.077542e+02, 5.930957e+02, 5.785139e+02, 5.640235e+02, 
	5.496391e+02, 5.353751e+02, 5.210783e+02, 5.068934e+02, 4.929812e+02, 
	4.793316e+02, 4.659347e+02, 4.527814e+02, 4.398630e+02, 4.271712e+02, 
	4.146982e+02, 4.024367e+02, 3.903795e+02, 3.785200e+02, 3.668517e+02, 
	3.553687e+02, 3.440651e+02, 3.329353e+02, 3.219743e+02, 3.111768e+02, 
	3.005381e+02, 2.900536e+02, 2.797188e+02, 2.695296e+02, 2.594820e+02, 
	2.495720e+02, 2.397959e+02, 2.301501e+02, 2.206313e+02, 2.112361e+02, 
	2.019613e+02, 1.928039e+02, 1.837610e+02, 1.748298e+02, 1.660074e+02, 
	1.572914e+02, 1.486791e+02, 1.401682e+02, 1.317562e+02, 1.234409e+02, 
	1.152200e+02, 1.070916e+02, 9.905347e+01, 9.110367e+01, 8.324029e+01, 
	7.546145e+01, 6.776537e+01, 6.015030e+01, 5.261456e+01, 4.515650e+01, 
	3.777455e+01, 3.046716e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, water reactor with water reflector, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// M2 with temperature-dependent thermal conductivity and M1 with constant thermal conductivity
// Heat boundary condition: T(L) = T2 (600K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest13)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled13.txt";
  const std::string outputPath = "outputs/Out_Coupled13.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.80327058;

	std::vector<double> refFlux {1.000000e+00, 9.984433e-01, 9.953380e-01, 
	9.907007e-01, 9.845557e-01, 9.769350e-01, 9.678780e-01, 9.574311e-01, 
	9.456468e-01, 9.325836e-01, 9.183053e-01, 9.028799e-01, 8.863794e-01, 
	8.688789e-01, 8.504557e-01, 8.311890e-01, 8.111586e-01, 7.904446e-01, 
	7.691267e-01, 7.472835e-01, 7.249919e-01, 7.023263e-01, 6.793589e-01, 
	6.561583e-01, 6.327899e-01, 6.093153e-01, 5.857920e-01, 5.622733e-01, 
	5.388084e-01, 5.154420e-01, 4.922145e-01, 4.691621e-01, 4.463168e-01, 
	4.237066e-01, 4.013556e-01, 3.792842e-01, 3.575095e-01, 3.360453e-01, 
	3.149028e-01, 2.940902e-01, 2.736137e-01, 2.534772e-01, 2.336832e-01, 
	2.142322e-01, 1.951241e-01, 1.763576e-01, 1.579306e-01, 1.398408e-01, 
	1.220857e-01, 1.046628e-01, 8.557584e-02, 6.864271e-02, 5.504881e-02, 
	4.413744e-02, 3.538084e-02, 2.835485e-02, 2.271860e-02, 1.819818e-02, 
	1.457349e-02, 1.166774e-02, 9.338890e-03, 7.472867e-03, 5.978074e-03, 
	4.780971e-03, 3.822528e-03, 3.055370e-03, 2.441491e-03, 1.950400e-03, 
	1.557648e-03, 1.243631e-03, 9.926371e-04, 7.920740e-04, 6.318553e-04, 
	5.039022e-04, 4.017466e-04, 3.202108e-04, 2.551518e-04, 2.032551e-04, 
	1.618700e-04, 1.288772e-04, 1.025829e-04, 8.163354e-05, 6.494816e-05, 
	5.166347e-05, 4.109041e-05, 3.267917e-05, 2.599123e-05, 2.067703e-05, 
	1.645808e-05, 1.311272e-05, 1.046468e-05, 8.374073e-06, 6.730088e-06, 
	5.445297e-06, 4.451098e-06, 3.694132e-06, 3.133496e-06, 2.738587e-06, 
	2.487483e-06, 2.365773e-06};

	std::vector<double> refTemp {1.099030e+03, 1.098324e+03, 1.096914e+03, 
	1.094805e+03, 1.092001e+03, 1.088512e+03, 1.084347e+03, 1.079518e+03, 
	1.074038e+03, 1.067921e+03, 1.061185e+03, 1.053846e+03, 1.045924e+03, 
	1.037439e+03, 1.028411e+03, 1.018862e+03, 1.008814e+03, 9.982912e+02, 
	9.873155e+02, 9.759107e+02, 9.641005e+02, 9.519086e+02, 9.393587e+02, 
	9.264744e+02, 9.132788e+02, 8.997952e+02, 8.860462e+02, 8.720542e+02, 
	8.578410e+02, 8.434281e+02, 8.288364e+02, 8.140865e+02, 7.991982e+02, 
	7.841911e+02, 7.690841e+02, 7.538956e+02, 7.386436e+02, 7.233456e+02, 
	7.080187e+02, 6.926795e+02, 6.773443e+02, 6.620290e+02, 6.467491e+02, 
	6.315198e+02, 6.163561e+02, 6.012727e+02, 5.862841e+02, 5.714045e+02, 
	5.566480e+02, 5.420285e+02, 5.273822e+02, 5.128538e+02, 4.986143e+02, 
	4.846527e+02, 4.709584e+02, 4.575215e+02, 4.443328e+02, 4.313833e+02, 
	4.186646e+02, 4.061688e+02, 3.938883e+02, 3.818159e+02, 3.699449e+02, 
	3.582686e+02, 3.467809e+02, 3.354759e+02, 3.243479e+02, 3.133916e+02, 
	3.026019e+02, 2.919737e+02, 2.815025e+02, 2.711837e+02, 2.610130e+02, 
	2.509863e+02, 2.410997e+02, 2.313492e+02, 2.217314e+02, 2.122425e+02, 
	2.028794e+02, 1.936388e+02, 1.845175e+02, 1.755126e+02, 1.666211e+02, 
	1.578403e+02, 1.491675e+02, 1.406001e+02, 1.321357e+02, 1.237717e+02, 
	1.155060e+02, 1.073361e+02, 9.926009e+01, 9.127572e+01, 8.338100e+01, 
	7.557396e+01, 6.785271e+01, 6.021541e+01, 5.266028e+01, 4.518560e+01, 
	3.778970e+01, 3.047217e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, water reactor with water reflector, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// M2 with temperature-dependent thermal conductivity and M1 with constant thermal conductivity
// Heat boundary condition: T(L) = T2 (600K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest14)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled14.txt";
  const std::string outputPath = "outputs/Out_Coupled14.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.801525;

	std::vector<double> refFlux {1.000000e+00, 9.984970e-01, 9.954985e-01, 
	9.910197e-01, 9.850828e-01, 9.777173e-01, 9.689594e-01, 9.588516e-01, 
	9.474424e-01, 9.347857e-01, 9.209401e-01, 9.059686e-01, 8.899379e-01, 
	8.729174e-01, 8.549792e-01, 8.361967e-01, 8.166445e-01, 7.963977e-01, 
	7.755309e-01, 7.541181e-01, 7.322319e-01, 7.099430e-01, 6.873198e-01, 
	6.644282e-01, 6.413308e-01, 6.180871e-01, 5.947529e-01, 5.713804e-01, 
	5.480178e-01, 5.247096e-01, 5.014963e-01, 4.784144e-01, 4.554966e-01, 
	4.327719e-01, 4.102659e-01, 3.880004e-01, 3.659945e-01, 3.442639e-01, 
	3.228218e-01, 3.016788e-01, 2.808432e-01, 2.603216e-01, 2.401187e-01, 
	2.202378e-01, 2.006811e-01, 1.814496e-01, 1.625440e-01, 1.439643e-01, 
	1.257104e-01, 1.077822e-01, 8.812666e-02, 7.068880e-02, 5.668968e-02, 
	4.545308e-02, 3.643546e-02, 2.920004e-02, 2.339579e-02, 1.874062e-02, 
	1.500790e-02, 1.201553e-02, 9.617261e-03, 7.695616e-03, 6.156267e-03, 
	4.923481e-03, 3.936468e-03, 3.146444e-03, 2.514266e-03, 2.008537e-03, 
	1.604078e-03, 1.280701e-03, 1.022225e-03, 8.156839e-04, 6.506894e-04, 
	5.189224e-04, 4.137217e-04, 3.297556e-04, 2.627573e-04, 2.093137e-04, 
	1.666950e-04, 1.327187e-04, 1.056406e-04, 8.406684e-05, 6.688411e-05, 
	5.320344e-05, 4.231522e-05, 3.365326e-05, 2.676597e-05, 2.129336e-05, 
	1.694866e-05, 1.350358e-05, 1.077661e-05, 8.623685e-06, 6.930696e-06, 
	5.607609e-06, 4.583775e-06, 3.804246e-06, 3.226898e-06, 2.820218e-06, 
	2.561629e-06, 2.436291e-06};

	std::vector<double> refTemp {1.074155e+03, 1.073498e+03, 1.072186e+03, 
	1.070222e+03, 1.067611e+03, 1.064360e+03, 1.060478e+03, 1.055975e+03, 
	1.050861e+03, 1.045150e+03, 1.038856e+03, 1.031994e+03, 1.024581e+03, 
	1.016633e+03, 1.008169e+03, 9.992079e+02, 9.897692e+02, 9.798730e+02, 
	9.695397e+02, 9.587902e+02, 9.476456e+02, 9.361270e+02, 9.242557e+02, 
	9.120530e+02, 8.995399e+02, 8.867376e+02, 8.736666e+02, 8.603477e+02, 
	8.468010e+02, 8.330464e+02, 8.191036e+02, 8.049918e+02, 7.907297e+02, 
	7.763359e+02, 7.618285e+02, 7.472252e+02, 7.325433e+02, 7.177998e+02, 
	7.030114e+02, 6.881944e+02, 6.733649e+02, 6.585385e+02, 6.437307e+02, 
	6.289569e+02, 6.142319e+02, 5.995708e+02, 5.849880e+02, 5.704982e+02, 
	5.561156e+02, 5.418546e+02, 5.273822e+02, 5.128538e+02, 4.986143e+02, 
	4.846527e+02, 4.709584e+02, 4.575215e+02, 4.443328e+02, 4.313833e+02, 
	4.186646e+02, 4.061688e+02, 3.938883e+02, 3.818159e+02, 3.699449e+02, 
	3.582686e+02, 3.467809e+02, 3.354759e+02, 3.243479e+02, 3.133916e+02, 
	3.026019e+02, 2.919737e+02, 2.815025e+02, 2.711837e+02, 2.610130e+02, 
	2.509863e+02, 2.410997e+02, 2.313492e+02, 2.217314e+02, 2.122425e+02, 
	2.028794e+02, 1.936388e+02, 1.845175e+02, 1.755126e+02, 1.666211e+02, 
	1.578403e+02, 1.491675e+02, 1.406001e+02, 1.321357e+02, 1.237717e+02, 
	1.155060e+02, 1.073361e+02, 9.926009e+01, 9.127572e+01, 8.338100e+01, 
	7.557396e+01, 6.785271e+01, 6.021541e+01, 5.266028e+01, 4.518560e+01, 
	3.778970e+01, 3.047217e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, water reactor with water reflector, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// M2 with temperature-dependent thermal conductivity and M1 with constant thermal conductivity
// Heat boundary condition: T(L) = T2 (300K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest15)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled15.txt";
  const std::string outputPath = "outputs/Out_Coupled15.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.82185149;

	std::vector<double> refFlux {6.983740e-01, 6.976812e-01, 6.962967e-01, 
	6.942226e-01, 6.914620e-01, 6.880192e-01, 6.838994e-01, 6.791089e-01, 
	6.736550e-01, 6.675460e-01, 6.607912e-01, 6.534008e-01, 6.453861e-01, 
	6.367591e-01, 6.275330e-01, 6.177216e-01, 6.073397e-01, 5.964029e-01, 
	5.849276e-01, 5.729311e-01, 5.604311e-01, 5.474464e-01, 5.339962e-01, 
	5.201004e-01, 5.057796e-01, 4.910549e-01, 4.759479e-01, 4.604807e-01, 
	4.446760e-01, 4.285566e-01, 4.121460e-01, 3.954679e-01, 3.785462e-01, 
	3.614052e-01, 3.440692e-01, 3.265628e-01, 3.089104e-01, 2.911364e-01, 
	2.732649e-01, 2.553194e-01, 2.373220e-01, 2.192930e-01, 2.012494e-01, 
	1.832022e-01, 1.651526e-01, 1.470846e-01, 1.289536e-01, 1.106654e-01, 
	9.204102e-02, 7.275640e-02, 5.386490e-02, 4.079957e-02, 3.090994e-02, 
	2.342230e-02, 1.775192e-02, 1.345682e-02, 1.020274e-02, 7.736877e-03, 
	5.867942e-03, 4.451171e-03, 3.376981e-03, 2.562395e-03, 1.944574e-03, 
	1.475916e-03, 1.120354e-03, 8.505567e-04, 6.458090e-04, 4.904061e-04, 
	3.724404e-04, 2.828821e-04, 2.148821e-04, 1.632449e-04, 1.240287e-04, 
	9.424253e-05, 7.161638e-05, 5.442737e-05, 4.136764e-05, 3.144426e-05, 
	2.390332e-05, 1.817231e-05, 1.381643e-05, 1.050544e-05, 7.988473e-06, 
	6.074945e-06, 4.620056e-06, 3.513778e-06, 2.672497e-06, 2.032664e-06, 
	1.545973e-06, 1.175703e-06, 8.939288e-07, 6.794143e-07, 5.160002e-07, 
	3.913845e-07, 2.961921e-07, 2.232675e-07, 1.671344e-07, 1.235836e-07, 
	8.935586e-08, 6.189744e-08, 1.000000e+00, 9.990082e-01, 9.970262e-01, 
	9.940569e-01, 9.901048e-01, 9.851761e-01, 9.792783e-01, 9.724202e-01, 
	9.646123e-01, 9.558666e-01, 9.461963e-01, 9.356160e-01, 9.241418e-01, 
	9.117910e-01, 8.985823e-01, 8.845356e-01, 8.696721e-01, 8.540140e-01, 
	8.375848e-01, 8.204092e-01, 8.025126e-01, 7.839218e-01, 7.646644e-01, 
	7.447689e-01, 7.242646e-01, 7.031818e-01, 6.815515e-01, 6.594053e-01, 
	6.367755e-01, 6.136952e-01, 5.901978e-01, 5.663174e-01, 5.420886e-01, 
	5.175463e-01, 4.927261e-01, 4.676642e-01, 4.423975e-01, 4.169641e-01, 
	3.914039e-01, 3.657596e-01, 3.400789e-01, 3.144180e-01, 2.888475e-01, 
	2.634627e-01, 2.384013e-01, 2.138742e-01, 1.902173e-01, 1.679820e-01, 
	1.480883e-01, 1.320902e-01, 1.225507e-01, 1.082391e-01, 9.258112e-02, 
	7.741542e-02, 6.365850e-02, 5.167878e-02, 4.153223e-02, 3.310853e-02, 
	2.621943e-02, 2.065054e-02, 1.619024e-02, 1.264441e-02, 9.842779e-03, 
	7.640394e-03, 5.916469e-03, 4.571935e-03, 3.526532e-03, 2.715860e-03, 
	2.088649e-03, 1.604341e-03, 1.231021e-03, 9.436857e-04, 7.228220e-04, 
	5.532479e-04, 4.231846e-04, 3.235150e-04, 2.471965e-04, 1.887986e-04, 
	1.441406e-04, 1.100082e-04, 8.393287e-05, 6.402103e-05, 4.882136e-05, 
	3.722239e-05, 2.837355e-05, 2.162432e-05, 1.647742e-05, 1.255287e-05, 
	9.560445e-06, 7.278492e-06, 5.537725e-06, 4.208806e-06, 3.192824e-06, 
	2.413980e-06, 1.813964e-06, 1.347589e-06, 9.793797e-07, 6.808387e-07, 
	4.281879e-07, 2.003936e-07};

	std::vector<double> refTemp {2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 2.685000e+01, 
	2.685000e+01, 2.685000e+01};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

// Steady-state, water reactor with water reflector, heat-diffusion coupled calculation
// Two neutron energy groups
// Reactor thermal power = 100.0 kW
// M2 with temperature-dependent thermal conductivity and M1 with constant thermal conductivity
// Heat boundary condition: T(L) = T2 (600K)
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest16)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled16.txt";
  const std::string outputPath = "outputs/Out_Coupled16.txt";
  const std::string traceLevel = "CRITICAL"; 

  const double kEffRef = 0.79440838;

	std::vector<double> refFlux {4.967893e-01, 4.963019e-01, 4.953279e-01, 
	4.938686e-01, 4.919264e-01, 4.895040e-01, 4.866053e-01, 4.832344e-01, 
	4.793965e-01, 4.750974e-01, 4.703434e-01, 4.651416e-01, 4.595000e-01, 
	4.534267e-01, 4.469310e-01, 4.400225e-01, 4.327115e-01, 4.250087e-01, 
	4.169255e-01, 4.084740e-01, 3.996666e-01, 3.905162e-01, 3.810362e-01, 
	3.712406e-01, 3.611435e-01, 3.507598e-01, 3.401044e-01, 3.291929e-01, 
	3.180409e-01, 3.066645e-01, 2.950800e-01, 2.833039e-01, 2.713529e-01, 
	2.592438e-01, 2.469937e-01, 2.346195e-01, 2.221381e-01, 2.095660e-01, 
	1.969196e-01, 1.842143e-01, 1.714641e-01, 1.586811e-01, 1.458736e-01, 
	1.330445e-01, 1.201875e-01, 1.072814e-01, 9.428113e-02, 8.110307e-02, 
	6.760084e-02, 5.352659e-02, 3.963024e-02, 3.000638e-02, 2.272940e-02, 
	1.722430e-02, 1.305772e-02, 9.902787e-03, 7.512863e-03, 5.701704e-03, 
	4.328612e-03, 3.287241e-03, 2.497166e-03, 1.897540e-03, 1.442303e-03, 
	1.096578e-03, 8.339402e-04, 6.343634e-04, 4.826640e-04, 3.673253e-04, 
	2.796097e-04, 2.128850e-04, 1.621159e-04, 1.234783e-04, 9.406685e-05, 
	7.167381e-05, 5.462095e-05, 4.163225e-05, 3.173728e-05, 2.419780e-05, 
	1.845211e-05, 1.407270e-05, 1.073414e-05, 8.188670e-06, 6.247588e-06, 
	4.767174e-06, 3.637934e-06, 2.776437e-06, 2.119100e-06, 1.617455e-06, 
	1.234550e-06, 9.422060e-07, 7.189297e-07, 5.483204e-07, 4.178583e-07, 
	3.179798e-07, 2.413723e-07, 1.824352e-07, 1.368684e-07, 1.013570e-07, 
	7.332878e-08, 5.076736e-08, 1.000000e+00, 9.990192e-01, 9.970589e-01, 
	9.941223e-01, 9.902136e-01, 9.853388e-01, 9.795052e-01, 9.727214e-01, 
	9.649978e-01, 9.563458e-01, 9.467784e-01, 9.363099e-01, 9.249559e-01, 
	9.127334e-01, 8.996605e-01, 8.857566e-01, 8.710425e-01, 8.555398e-01, 
	8.392715e-01, 8.222617e-01, 8.045354e-01, 7.861185e-01, 7.670382e-01, 
	7.473223e-01, 7.269996e-01, 7.060996e-01, 6.846529e-01, 6.626903e-01, 
	6.402437e-01, 6.173454e-01, 5.940284e-01, 5.703263e-01, 5.462731e-01, 
	5.219037e-01, 4.972532e-01, 4.723579e-01, 4.472551e-01, 4.219835e-01, 
	3.965842e-01, 3.711022e-01, 3.455881e-01, 3.201020e-01, 2.947194e-01, 
	2.695406e-01, 2.447062e-01, 2.204219e-01, 1.969997e-01, 1.749232e-01, 
	1.549554e-01, 1.383121e-01, 1.269418e-01, 1.122140e-01, 9.664111e-02, 
	8.165080e-02, 6.798405e-02, 5.595690e-02, 4.563211e-02, 3.692984e-02, 
	2.969769e-02, 2.375383e-02, 1.891255e-02, 1.499843e-02, 1.185346e-02, 
	9.339722e-03, 7.339523e-03, 5.754114e-03, 4.501716e-03, 3.515305e-03, 
	2.740417e-03, 2.133102e-03, 1.658104e-03, 1.287278e-03, 9.982599e-04, 
	7.733372e-04, 5.985321e-04, 4.628435e-04, 3.576354e-04, 2.761433e-04, 
	2.130795e-04, 1.643178e-04, 1.266438e-04, 9.755678e-05, 7.511401e-05, 
	5.780793e-05, 4.446990e-05, 3.419492e-05, 2.628274e-05, 2.019193e-05, 
	1.550414e-05, 1.189624e-05, 9.118706e-06, 6.978837e-06, 5.327692e-06, 
	4.049960e-06, 3.056061e-06, 2.275976e-06, 1.654382e-06, 1.146768e-06, 
	7.162658e-07, 3.309654e-07};

	std::vector<double> refTemp {3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 3.268500e+02, 
	3.268500e+02, 3.268500e+02};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getVector("Fundamental Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  // PrintFuncs::createCppVector(flux, "%7.6e");

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}