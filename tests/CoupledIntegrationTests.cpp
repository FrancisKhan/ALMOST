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

	std::vector<double> refFlux {3.209796e-02, 3.206212e-02, 3.199050e-02, 
	3.188322e-02, 3.174047e-02, 3.156249e-02, 3.134959e-02, 3.110212e-02, 
	3.082052e-02, 3.050526e-02, 3.015689e-02, 2.977598e-02, 2.936319e-02, 
	2.891923e-02, 2.844483e-02, 2.794082e-02, 2.740802e-02, 2.684735e-02, 
	2.625975e-02, 2.564619e-02, 2.500771e-02, 2.434537e-02, 2.366028e-02, 
	2.295357e-02, 2.222641e-02, 2.148000e-02, 2.071557e-02, 1.993437e-02, 
	1.913768e-02, 1.832680e-02, 1.750304e-02, 1.666773e-02, 1.582222e-02, 
	1.496787e-02, 1.410603e-02, 1.323809e-02, 1.236542e-02, 1.148939e-02, 
	1.061138e-02, 9.732759e-03, 8.854896e-03, 7.979148e-03, 7.106862e-03, 
	6.239372e-03, 5.378000e-03, 4.524046e-03, 3.678795e-03, 2.843507e-03, 
	2.019421e-03, 1.207749e-03};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {3.217491e-02, 3.213882e-02, 3.206670e-02, 
	3.195867e-02, 3.181491e-02, 3.163568e-02, 3.142129e-02, 3.117209e-02, 
	3.088852e-02, 3.057106e-02, 3.022025e-02, 2.983670e-02, 2.942104e-02, 
	2.897401e-02, 2.849634e-02, 2.798885e-02, 2.745241e-02, 2.688791e-02, 
	2.629631e-02, 2.567861e-02, 2.503583e-02, 2.436906e-02, 2.367942e-02, 
	2.296804e-02, 2.223611e-02, 2.148485e-02, 2.071549e-02, 1.992931e-02, 
	1.912758e-02, 1.831163e-02, 1.748278e-02, 1.664239e-02, 1.579180e-02, 
	1.493239e-02, 1.406554e-02, 1.319264e-02, 1.231508e-02, 1.143425e-02, 
	1.055154e-02, 9.668329e-03, 8.786010e-03, 7.905950e-03, 7.029512e-03, 
	6.158043e-03, 5.292878e-03, 4.435332e-03, 3.586700e-03, 2.748257e-03, 
	1.921253e-03, 1.106911e-03};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {3.095426e-02, 3.092499e-02, 3.086648e-02, 
	3.077879e-02, 3.066201e-02, 3.051624e-02, 3.034164e-02, 3.013837e-02, 
	2.990662e-02, 2.964660e-02, 2.935854e-02, 2.904270e-02, 2.869932e-02, 
	2.832870e-02, 2.793113e-02, 2.750690e-02, 2.705633e-02, 2.657974e-02, 
	2.607747e-02, 2.554986e-02, 2.499727e-02, 2.442006e-02, 2.381863e-02, 
	2.319338e-02, 2.254474e-02, 2.187318e-02, 2.117918e-02, 2.046329e-02, 
	1.972609e-02, 1.896822e-02, 1.819040e-02, 1.739340e-02, 1.657809e-02, 
	1.574542e-02, 1.489643e-02, 1.403231e-02, 1.315432e-02, 1.226387e-02, 
	1.136250e-02, 1.045188e-02, 9.533827e-03, 8.610294e-03, 7.683388e-03, 
	6.755355e-03, 5.828586e-03, 4.905603e-03, 3.989060e-03, 3.081727e-03, 
	2.186481e-03, 1.306289e-03};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {3.346375e-02, 3.341713e-02, 3.332408e-02, 
	3.318498e-02, 3.300037e-02, 3.277100e-02, 3.249774e-02, 3.218166e-02, 
	3.182396e-02, 3.142597e-02, 3.098915e-02, 3.051507e-02, 3.000537e-02, 
	2.946180e-02, 2.888613e-02, 2.828021e-02, 2.764589e-02, 2.698507e-02, 
	2.629960e-02, 2.559137e-02, 2.486221e-02, 2.411392e-02, 2.334827e-02, 
	2.256697e-02, 2.177166e-02, 2.096393e-02, 2.014530e-02, 1.931721e-02, 
	1.848104e-02, 1.763811e-02, 1.678967e-02, 1.593691e-02, 1.508095e-02, 
	1.422288e-02, 1.336374e-02, 1.250455e-02, 1.164627e-02, 1.078988e-02, 
	9.936328e-03, 9.086569e-03, 8.241565e-03, 7.402295e-03, 6.569759e-03, 
	5.744991e-03, 4.929057e-03, 4.123067e-03, 3.328173e-03, 2.545576e-03, 
	1.776525e-03, 1.022317e-03};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {1.319308e-02, 1.317858e-02, 1.314959e-02, 
	1.310618e-02, 1.304840e-02, 1.297637e-02, 1.289020e-02, 1.279003e-02, 
	1.267603e-02, 1.254840e-02, 1.240734e-02, 1.225310e-02, 1.208594e-02, 
	1.190612e-02, 1.171395e-02, 1.150976e-02, 1.129387e-02, 1.106665e-02, 
	1.082847e-02, 1.057973e-02, 1.032083e-02, 1.005220e-02, 9.774282e-03, 
	9.487529e-03, 9.192407e-03, 8.889396e-03, 8.578988e-03, 8.261683e-03, 
	7.937992e-03, 7.608435e-03, 7.273540e-03, 6.933839e-03, 6.589873e-03, 
	6.242187e-03, 5.891330e-03, 5.537856e-03, 5.182321e-03, 4.825285e-03, 
	4.467315e-03, 4.108984e-03, 3.750878e-03, 3.393607e-03, 3.037820e-03, 
	2.684237e-03, 2.333698e-03, 1.987256e-03, 1.646328e-03, 1.312956e-03, 
	9.902569e-04, 6.831885e-04, 1.868820e-02, 1.866766e-02, 1.862661e-02, 
	1.856513e-02, 1.848330e-02, 1.838129e-02, 1.825924e-02, 1.811737e-02, 
	1.795592e-02, 1.777516e-02, 1.757539e-02, 1.735694e-02, 1.712018e-02, 
	1.686551e-02, 1.659334e-02, 1.630413e-02, 1.599836e-02, 1.567654e-02, 
	1.533919e-02, 1.498688e-02, 1.462018e-02, 1.423970e-02, 1.384605e-02, 
	1.343989e-02, 1.302187e-02, 1.259267e-02, 1.215299e-02, 1.170353e-02, 
	1.124503e-02, 1.077821e-02, 1.030382e-02, 9.822614e-03, 9.335356e-03, 
	8.842812e-03, 8.345750e-03, 7.844941e-03, 7.341146e-03, 6.835118e-03, 
	6.327585e-03, 5.819233e-03, 5.310681e-03, 4.802429e-03, 4.294778e-03, 
	3.787690e-03, 3.280555e-03, 2.771789e-03, 2.258154e-03, 1.733590e-03, 
	1.187227e-03, 5.999912e-04};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {1.068559e-02, 1.067381e-02, 1.065026e-02, 
	1.061499e-02, 1.056805e-02, 1.050953e-02, 1.043952e-02, 1.035813e-02, 
	1.026552e-02, 1.016182e-02, 1.004722e-02, 9.921906e-03, 9.786088e-03, 
	9.639992e-03, 9.483862e-03, 9.317958e-03, 9.142554e-03, 8.957943e-03, 
	8.764429e-03, 8.562331e-03, 8.351984e-03, 8.133732e-03, 7.907934e-03, 
	7.674960e-03, 7.435189e-03, 7.189013e-03, 6.936830e-03, 6.679050e-03, 
	6.416089e-03, 6.148370e-03, 5.876324e-03, 5.600385e-03, 5.320994e-03, 
	5.038598e-03, 4.753646e-03, 4.466591e-03, 4.177891e-03, 3.888010e-03, 
	3.597418e-03, 3.306597e-03, 3.016045e-03, 2.726289e-03, 2.437901e-03, 
	2.151530e-03, 1.867947e-03, 1.588123e-03, 1.313359e-03, 1.045484e-03, 
	7.871886e-04, 5.425569e-04, 2.125450e-02, 2.123107e-02, 2.118424e-02, 
	2.111409e-02, 2.102075e-02, 2.090436e-02, 2.076513e-02, 2.060328e-02, 
	2.041910e-02, 2.021288e-02, 1.998497e-02, 1.973575e-02, 1.946564e-02, 
	1.917509e-02, 1.886458e-02, 1.853463e-02, 1.818579e-02, 1.781863e-02, 
	1.743376e-02, 1.703182e-02, 1.661346e-02, 1.617938e-02, 1.573029e-02, 
	1.526691e-02, 1.479002e-02, 1.430038e-02, 1.379879e-02, 1.328605e-02, 
	1.276301e-02, 1.223049e-02, 1.168934e-02, 1.114044e-02, 1.058466e-02, 
	1.002285e-02, 9.455908e-03, 8.884699e-03, 8.310085e-03, 7.732912e-03, 
	7.153990e-03, 6.574076e-03, 5.993838e-03, 5.413800e-03, 4.834257e-03, 
	4.255140e-03, 3.675788e-03, 3.094595e-03, 2.508433e-03, 1.911724e-03, 
	1.294937e-03, 6.421714e-04};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {9.242953e-03, 9.236041e-03, 9.222225e-03, 
	9.201521e-03, 9.173950e-03, 9.139541e-03, 9.098326e-03, 9.050342e-03, 
	8.995628e-03, 8.934224e-03, 8.866167e-03, 8.791491e-03, 8.710226e-03, 
	8.622392e-03, 8.528002e-03, 8.427054e-03, 8.319535e-03, 8.205415e-03, 
	8.084650e-03, 7.957174e-03, 7.822906e-03, 7.681746e-03, 7.533576e-03, 
	7.378258e-03, 7.215643e-03, 7.045566e-03, 6.867854e-03, 6.682328e-03, 
	6.488807e-03, 6.287117e-03, 6.077091e-03, 5.858585e-03, 5.631476e-03, 
	5.395676e-03, 5.151140e-03, 4.897871e-03, 4.635935e-03, 4.365465e-03, 
	4.086672e-03, 3.799860e-03, 3.505433e-03, 3.203916e-03, 2.895976e-03, 
	2.582459e-03, 2.264444e-03, 1.943343e-03, 1.621062e-03, 1.300282e-03, 
	9.849567e-04, 6.811721e-04, 2.184401e-02, 2.182188e-02, 2.177761e-02, 
	2.171122e-02, 2.162268e-02, 2.151201e-02, 2.137921e-02, 2.122428e-02, 
	2.104724e-02, 2.084812e-02, 2.062695e-02, 2.038380e-02, 2.011873e-02, 
	1.983185e-02, 1.952331e-02, 1.919328e-02, 1.884198e-02, 1.846968e-02, 
	1.807671e-02, 1.766348e-02, 1.723045e-02, 1.677816e-02, 1.630724e-02, 
	1.581841e-02, 1.531248e-02, 1.479034e-02, 1.425301e-02, 1.370156e-02, 
	1.313718e-02, 1.256115e-02, 1.197481e-02, 1.137959e-02, 1.077698e-02, 
	1.016852e-02, 9.555787e-03, 8.940378e-03, 8.323899e-03, 7.707942e-03, 
	7.094059e-03, 6.483737e-03, 5.878354e-03, 5.279126e-03, 4.687010e-03, 
	4.102563e-03, 3.525697e-03, 2.955269e-03, 2.388371e-03, 1.819116e-03, 
	1.236518e-03, 6.208038e-04};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {9.282989e-03, 9.276087e-03, 9.262290e-03, 
	9.241609e-03, 9.214062e-03, 9.179670e-03, 9.138460e-03, 9.090461e-03, 
	9.035700e-03, 8.974209e-03, 8.906014e-03, 8.831140e-03, 8.749604e-03, 
	8.661419e-03, 8.566586e-03, 8.465097e-03, 8.356932e-03, 8.242056e-03, 
	8.120418e-03, 7.991956e-03, 7.856585e-03, 7.714210e-03, 7.564716e-03, 
	7.407974e-03, 7.243843e-03, 7.072172e-03, 6.892798e-03, 6.705560e-03, 
	6.510291e-03, 6.306835e-03, 6.095045e-03, 5.874793e-03, 5.645974e-03, 
	5.408519e-03, 5.162396e-03, 4.907626e-03, 4.644285e-03, 4.372517e-03, 
	4.092542e-03, 3.804668e-03, 3.509303e-03, 3.206972e-03, 2.898338e-03, 
	2.584242e-03, 2.265757e-03, 1.944285e-03, 1.621718e-03, 1.300728e-03, 
	9.852523e-04, 6.813618e-04, 2.180483e-02, 2.178267e-02, 2.173836e-02, 
	2.167188e-02, 2.158326e-02, 2.147249e-02, 2.133959e-02, 2.118456e-02, 
	2.100744e-02, 2.080826e-02, 2.058707e-02, 2.034395e-02, 2.007898e-02, 
	1.979228e-02, 1.948400e-02, 1.915434e-02, 1.880352e-02, 1.843184e-02, 
	1.803963e-02, 1.762728e-02, 1.719529e-02, 1.674418e-02, 1.627459e-02, 
	1.578723e-02, 1.528289e-02, 1.476247e-02, 1.422695e-02, 1.367740e-02, 
	1.311497e-02, 1.254093e-02, 1.195659e-02, 1.136336e-02, 1.076269e-02, 
	1.015611e-02, 9.545156e-03, 8.931419e-03, 8.316485e-03, 7.701930e-03, 
	7.089298e-03, 6.480071e-03, 5.875626e-03, 5.277181e-03, 4.685701e-03, 
	4.101753e-03, 3.525263e-03, 2.955098e-03, 2.388369e-03, 1.819201e-03, 
	1.236624e-03, 6.208750e-04};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {2.942393e-02, 2.939593e-02, 2.933997e-02, 
	2.925615e-02, 2.914457e-02, 2.900541e-02, 2.883887e-02, 2.864519e-02, 
	2.842466e-02, 2.817760e-02, 2.790438e-02, 2.760539e-02, 2.728107e-02, 
	2.693190e-02, 2.655838e-02, 2.616106e-02, 2.574051e-02, 2.529734e-02, 
	2.483220e-02, 2.434575e-02, 2.383869e-02, 2.331175e-02, 2.276569e-02, 
	2.220128e-02, 2.161932e-02, 2.102065e-02, 2.040610e-02, 1.977654e-02, 
	1.913286e-02, 1.847595e-02, 1.780674e-02, 1.712615e-02, 1.643512e-02, 
	1.573461e-02, 1.502557e-02, 1.430898e-02, 1.358582e-02, 1.285706e-02, 
	1.212369e-02, 1.138669e-02, 1.064705e-02, 9.905752e-03, 9.163785e-03, 
	8.422124e-03, 7.681743e-03, 6.943609e-03, 6.208680e-03, 5.477906e-03, 
	4.752225e-03, 4.032564e-03, 3.245366e-03, 2.564961e-03, 2.027573e-03, 
	1.603053e-03, 1.267630e-03, 1.002553e-03, 7.930313e-04, 6.273917e-04, 
	4.964215e-04, 3.928472e-04, 3.109252e-04, 2.461193e-04, 1.948457e-04, 
	1.542729e-04, 1.221633e-04, 9.674807e-05, 7.662896e-05, 6.070035e-05, 
	4.808789e-05, 3.810002e-05, 3.018967e-05, 2.392401e-05, 1.896057e-05, 
	1.502827e-05, 1.191260e-05, 9.443714e-06, 7.487171e-06, 5.936509e-06, 
	4.707424e-06, 3.733151e-06, 2.960809e-06, 2.348507e-06, 1.863063e-06, 
	1.478187e-06, 1.173050e-06, 9.311487e-07, 7.394107e-07, 5.874790e-07, 
	4.671518e-07, 3.719364e-07, 2.966973e-07, 2.373772e-07, 1.907775e-07, 
	1.543843e-07, 1.262328e-07, 1.048003e-07, 8.892354e-08, 7.773529e-08, 
	7.061697e-08, 6.716427e-08};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {2.920430e-02, 2.917690e-02, 2.912215e-02, 
	2.904013e-02, 2.893095e-02, 2.879477e-02, 2.863179e-02, 2.844224e-02, 
	2.822641e-02, 2.798459e-02, 2.771714e-02, 2.742445e-02, 2.710693e-02, 
	2.676505e-02, 2.639928e-02, 2.601016e-02, 2.559825e-02, 2.516412e-02, 
	2.470840e-02, 2.423173e-02, 2.373479e-02, 2.321828e-02, 2.268293e-02, 
	2.212949e-02, 2.155874e-02, 2.097147e-02, 2.036850e-02, 1.975067e-02, 
	1.911884e-02, 1.847387e-02, 1.781666e-02, 1.714810e-02, 1.646910e-02, 
	1.578060e-02, 1.508352e-02, 1.437881e-02, 1.366740e-02, 1.295026e-02, 
	1.222835e-02, 1.150261e-02, 1.077401e-02, 1.004351e-02, 9.312066e-03, 
	8.580630e-03, 7.850151e-03, 7.121574e-03, 6.395833e-03, 5.673857e-03, 
	4.956562e-03, 4.244855e-03, 3.459237e-03, 2.767142e-03, 2.213915e-03, 
	1.771602e-03, 1.417896e-03, 1.134992e-03, 9.086755e-04, 7.275962e-04, 
	5.826870e-04, 4.667038e-04, 3.738579e-04, 2.995221e-04, 2.399975e-04, 
	1.923261e-04, 1.541423e-04, 1.235537e-04, 9.904644e-05, 7.940895e-05, 
	6.367167e-05, 5.105849e-05, 4.094807e-05, 3.284290e-05, 2.634458e-05, 
	2.113400e-05, 1.695556e-05, 1.360449e-05, 1.091671e-05, 8.760743e-06, 
	7.031223e-06, 5.643698e-06, 4.530471e-06, 3.637273e-06, 2.920595e-06, 
	2.345555e-06, 1.884185e-06, 1.514059e-06, 1.217202e-06, 9.792036e-07, 
	7.885176e-07, 6.358977e-07, 5.139458e-07, 4.167514e-07, 3.396034e-07, 
	2.787605e-07, 2.312686e-07, 1.948165e-07, 1.676234e-07, 1.483507e-07, 
	1.360368e-07, 1.300485e-07};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {3.265778e-02, 3.260732e-02, 3.250666e-02, 
	3.235633e-02, 3.215712e-02, 3.191005e-02, 3.161639e-02, 3.127764e-02, 
	3.089548e-02, 3.047179e-02, 3.000863e-02, 2.950819e-02, 2.897279e-02, 
	2.840483e-02, 2.780681e-02, 2.718128e-02, 2.653081e-02, 2.585798e-02, 
	2.516536e-02, 2.445548e-02, 2.373081e-02, 2.299377e-02, 2.224666e-02, 
	2.149172e-02, 2.073105e-02, 1.996665e-02, 1.920036e-02, 1.843391e-02, 
	1.766890e-02, 1.690678e-02, 1.614885e-02, 1.539629e-02, 1.465015e-02, 
	1.391132e-02, 1.318061e-02, 1.245869e-02, 1.174611e-02, 1.104334e-02, 
	1.035074e-02, 9.668610e-03, 8.997153e-03, 8.336517e-03, 7.686795e-03, 
	7.048031e-03, 6.420234e-03, 5.803384e-03, 5.197442e-03, 4.602353e-03, 
	4.018062e-03, 3.444511e-03, 2.816009e-03, 2.258527e-03, 1.811043e-03, 
	1.451910e-03, 1.163737e-03, 9.325455e-04, 7.471062e-04, 5.983962e-04, 
	4.791671e-04, 3.835964e-04, 3.070078e-04, 2.456461e-04, 1.964963e-04, 
	1.571382e-04, 1.256292e-04, 1.004107e-04, 8.023229e-05, 6.409107e-05, 
	5.118285e-05, 4.086295e-05, 3.261467e-05, 2.602401e-05, 2.075933e-05, 
	1.655506e-05, 1.319856e-05, 1.051965e-05, 8.382163e-06, 6.677165e-06, 
	5.317545e-06, 4.233660e-06, 3.369850e-06, 2.681644e-06, 2.133520e-06, 
	1.697116e-06, 1.349793e-06, 1.073487e-06, 8.537919e-07, 6.792243e-07, 
	5.406355e-07, 4.307433e-07, 3.437578e-07, 2.750832e-07, 2.210797e-07, 
	1.788754e-07, 1.462167e-07, 1.213509e-07, 1.029343e-07, 8.996172e-08, 
	8.171305e-08, 7.771492e-08};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {3.235261e-02, 3.230433e-02, 3.220801e-02, 
	3.206414e-02, 3.187341e-02, 3.163678e-02, 3.135539e-02, 3.103061e-02, 
	3.066397e-02, 3.025719e-02, 2.981215e-02, 2.933085e-02, 2.881541e-02, 
	2.826806e-02, 2.769109e-02, 2.708685e-02, 2.645771e-02, 2.580606e-02, 
	2.513430e-02, 2.444479e-02, 2.373983e-02, 2.302170e-02, 2.229257e-02, 
	2.155456e-02, 2.080966e-02, 2.005979e-02, 1.930672e-02, 1.855212e-02, 
	1.779756e-02, 1.704444e-02, 1.629407e-02, 1.554763e-02, 1.480617e-02, 
	1.407063e-02, 1.334182e-02, 1.262048e-02, 1.190720e-02, 1.120251e-02, 
	1.050684e-02, 9.820552e-03, 9.143923e-03, 8.477176e-03, 7.820481e-03, 
	7.173963e-03, 6.537710e-03, 5.911781e-03, 5.296216e-03, 4.691041e-03, 
	4.096275e-03, 3.511941e-03, 2.871144e-03, 2.302747e-03, 1.846502e-03, 
	1.480338e-03, 1.186522e-03, 9.508040e-04, 7.617339e-04, 6.101123e-04, 
	4.885488e-04, 3.911069e-04, 3.130188e-04, 2.504557e-04, 2.003436e-04, 
	1.602148e-04, 1.280889e-04, 1.023767e-04, 8.180317e-05, 6.534592e-05, 
	5.218497e-05, 4.166302e-05, 3.325324e-05, 2.653354e-05, 2.116578e-05, 
	1.687919e-05, 1.345697e-05, 1.072562e-05, 8.546279e-06, 6.807899e-06, 
	5.421658e-06, 4.316552e-06, 3.435829e-06, 2.734149e-06, 2.175293e-06, 
	1.730344e-06, 1.376220e-06, 1.094505e-06, 8.705085e-07, 6.925230e-07, 
	5.512207e-07, 4.391769e-07, 3.504884e-07, 2.804691e-07, 2.254083e-07, 
	1.823777e-07, 1.490795e-07, 1.237268e-07, 1.049497e-07, 9.172310e-08, 
	8.331293e-08, 7.923652e-08};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {3.273398e-02, 3.268302e-02, 3.258137e-02, 
	3.242957e-02, 3.222842e-02, 3.197897e-02, 3.168250e-02, 3.134053e-02, 
	3.095478e-02, 3.052717e-02, 3.005978e-02, 2.955485e-02, 2.901472e-02, 
	2.844186e-02, 2.783880e-02, 2.720812e-02, 2.655244e-02, 2.587439e-02, 
	2.517658e-02, 2.446156e-02, 2.373187e-02, 2.298993e-02, 2.223812e-02, 
	2.147867e-02, 2.071373e-02, 1.994531e-02, 1.917530e-02, 1.840544e-02, 
	1.763734e-02, 1.687247e-02, 1.611214e-02, 1.535754e-02, 1.460972e-02, 
	1.386960e-02, 1.313796e-02, 1.241548e-02, 1.170271e-02, 1.100010e-02, 
	1.030802e-02, 9.626742e-03, 8.956464e-03, 8.297318e-03, 7.649379e-03, 
	7.012673e-03, 6.387189e-03, 5.772884e-03, 5.169696e-03, 4.577546e-03, 
	3.996351e-03, 3.426028e-03, 2.801238e-03, 2.246949e-03, 1.801966e-03, 
	1.444794e-03, 1.158156e-03, 9.281670e-04, 7.436701e-04, 5.956986e-04, 
	4.770484e-04, 3.819316e-04, 3.056990e-04, 2.446167e-04, 1.956861e-04, 
	1.565002e-04, 1.251265e-04, 1.000144e-04, 7.991970e-05, 6.384436e-05, 
	5.098802e-05, 4.070900e-05, 3.249296e-05, 2.592773e-05, 2.068314e-05, 
	1.649472e-05, 1.315076e-05, 1.048177e-05, 8.352133e-06, 6.653347e-06, 
	5.298648e-06, 4.218663e-06, 3.357945e-06, 2.672190e-06, 2.126011e-06, 
	1.691151e-06, 1.345053e-06, 1.069719e-06, 8.507963e-07, 6.768414e-07, 
	5.387384e-07, 4.292313e-07, 3.425507e-07, 2.741167e-07, 2.203025e-07, 
	1.782462e-07, 1.457021e-07, 1.209236e-07, 1.025718e-07, 8.964483e-08, 
	8.142520e-08, 7.744115e-08};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {3.242309e-02, 3.237436e-02, 3.227714e-02, 
	3.213192e-02, 3.193943e-02, 3.170062e-02, 3.141666e-02, 3.108893e-02, 
	3.071901e-02, 3.030864e-02, 2.985972e-02, 2.937430e-02, 2.885453e-02, 
	2.830268e-02, 2.772106e-02, 2.711208e-02, 2.647814e-02, 2.582167e-02, 
	2.514511e-02, 2.445084e-02, 2.374122e-02, 2.301854e-02, 2.228503e-02, 
	2.154281e-02, 2.079393e-02, 2.004029e-02, 1.928373e-02, 1.852592e-02, 
	1.776843e-02, 1.701271e-02, 1.626006e-02, 1.551167e-02, 1.476861e-02, 
	1.403180e-02, 1.330209e-02, 1.258017e-02, 1.186667e-02, 1.116210e-02, 
	1.046688e-02, 9.781357e-03, 9.105805e-03, 8.440432e-03, 7.785391e-03, 
	7.140791e-03, 6.506699e-03, 5.883156e-03, 5.270178e-03, 4.667768e-03, 
	4.075921e-03, 3.494631e-03, 2.857339e-03, 2.291949e-03, 1.838055e-03, 
	1.473729e-03, 1.181350e-03, 9.467556e-04, 7.585637e-04, 6.076288e-04, 
	4.866023e-04, 3.895806e-04, 3.118213e-04, 2.495156e-04, 1.996052e-04, 
	1.596345e-04, 1.276325e-04, 1.020174e-04, 8.152027e-05, 6.512298e-05, 
	5.200917e-05, 4.152429e-05, 3.314370e-05, 2.644699e-05, 2.109736e-05, 
	1.682507e-05, 1.341414e-05, 1.069169e-05, 8.519403e-06, 6.786595e-06, 
	5.404765e-06, 4.303151e-06, 3.425195e-06, 2.725707e-06, 2.168589e-06, 
	1.725020e-06, 1.371990e-06, 1.091143e-06, 8.678354e-07, 6.903966e-07, 
	5.495278e-07, 4.378276e-07, 3.494110e-07, 2.796065e-07, 2.247146e-07, 
	1.818160e-07, 1.486201e-07, 1.233454e-07, 1.046260e-07, 9.144017e-08, 
	8.305592e-08, 7.899208e-08};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {1.229447e-02, 1.228227e-02, 1.225790e-02, 
	1.222138e-02, 1.217278e-02, 1.211218e-02, 1.203965e-02, 1.195531e-02, 
	1.185930e-02, 1.175176e-02, 1.163284e-02, 1.150274e-02, 1.136164e-02, 
	1.120977e-02, 1.104735e-02, 1.087463e-02, 1.069186e-02, 1.049932e-02, 
	1.029731e-02, 1.008612e-02, 9.866062e-03, 9.637473e-03, 9.400690e-03, 
	9.156063e-03, 8.903954e-03, 8.644734e-03, 8.378784e-03, 8.106494e-03, 
	7.828260e-03, 7.544489e-03, 7.255590e-03, 6.961982e-03, 6.664085e-03, 
	6.362328e-03, 6.057138e-03, 5.748947e-03, 5.438187e-03, 5.125286e-03, 
	4.810669e-03, 4.494748e-03, 4.177914e-03, 3.860525e-03, 3.542879e-03, 
	3.225168e-03, 2.907414e-03, 2.589338e-03, 2.270153e-03, 1.948200e-03, 
	1.620328e-03, 1.280834e-03, 9.482600e-04, 7.182526e-04, 5.441515e-04, 
	4.123358e-04, 3.125122e-04, 2.368994e-04, 1.796133e-04, 1.362032e-04, 
	1.033017e-04, 7.836026e-05, 5.944977e-05, 4.510947e-05, 3.423309e-05, 
	2.598263e-05, 1.972317e-05, 1.497355e-05, 1.136909e-05, 8.633313e-06, 
	6.556596e-06, 4.979974e-06, 3.782873e-06, 2.873830e-06, 2.183453e-06, 
	1.659085e-06, 1.260764e-06, 9.581620e-07, 7.282531e-07, 5.535579e-07, 
	4.208040e-07, 3.199129e-07, 2.432302e-07, 1.849422e-07, 1.406324e-07, 
	1.069458e-07, 8.133338e-08, 6.185801e-08, 4.704775e-08, 3.578386e-08, 
	2.721596e-08, 2.069756e-08, 1.573709e-08, 1.196069e-08, 9.083882e-09, 
	6.890095e-09, 5.214289e-09, 3.930493e-09, 2.942304e-09, 2.175617e-09, 
	1.573058e-09, 1.089668e-09, 1.760442e-02, 1.758696e-02, 1.755206e-02, 
	1.749979e-02, 1.743022e-02, 1.734345e-02, 1.723962e-02, 1.711889e-02, 
	1.698144e-02, 1.682747e-02, 1.665723e-02, 1.647097e-02, 1.626898e-02, 
	1.605155e-02, 1.581902e-02, 1.557173e-02, 1.531007e-02, 1.503442e-02, 
	1.474519e-02, 1.444282e-02, 1.412776e-02, 1.380048e-02, 1.346147e-02, 
	1.311122e-02, 1.275025e-02, 1.237910e-02, 1.199832e-02, 1.160844e-02, 
	1.121006e-02, 1.080375e-02, 1.039009e-02, 9.969687e-03, 9.543152e-03, 
	9.111099e-03, 8.674155e-03, 8.232955e-03, 7.788150e-03, 7.340410e-03, 
	6.890437e-03, 6.438983e-03, 5.986890e-03, 5.535146e-03, 5.084992e-03, 
	4.638106e-03, 4.196915e-03, 3.765130e-03, 3.348665e-03, 2.957224e-03, 
	2.607008e-03, 2.325371e-03, 2.157433e-03, 1.905486e-03, 1.629837e-03, 
	1.362853e-03, 1.120671e-03, 9.097746e-04, 7.311506e-04, 5.828564e-04, 
	4.615777e-04, 3.635407e-04, 2.850197e-04, 2.225975e-04, 1.732764e-04, 
	1.345047e-04, 1.041560e-04, 8.048624e-05, 6.208253e-05, 4.781112e-05, 
	3.676944e-05, 2.824348e-05, 2.167140e-05, 1.661303e-05, 1.272486e-05, 
	9.739605e-06, 7.449918e-06, 5.695292e-06, 4.351749e-06, 3.323689e-06, 
	2.537512e-06, 1.936630e-06, 1.477589e-06, 1.127053e-06, 8.594714e-07, 
	6.552784e-07, 4.994998e-07, 3.806836e-07, 2.900753e-07, 2.209859e-07, 
	1.683060e-07, 1.281336e-07, 9.748840e-08, 7.409357e-08, 5.620779e-08, 
	4.249671e-08, 3.193377e-08, 2.372352e-08, 1.724141e-08, 1.198577e-08, 
	7.537998e-09, 3.527812e-09};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
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

	std::vector<double> refFlux {9.857513e-03, 9.847842e-03, 9.828514e-03, 
	9.799559e-03, 9.761020e-03, 9.712955e-03, 9.655436e-03, 9.588550e-03, 
	9.512397e-03, 9.427091e-03, 9.332760e-03, 9.229546e-03, 9.117601e-03, 
	8.997094e-03, 8.868203e-03, 8.731121e-03, 8.586052e-03, 8.433210e-03, 
	8.272821e-03, 8.105122e-03, 7.930361e-03, 7.748795e-03, 7.560689e-03, 
	7.366319e-03, 7.165969e-03, 6.959930e-03, 6.748502e-03, 6.531991e-03, 
	6.310708e-03, 6.084973e-03, 5.855107e-03, 5.621440e-03, 5.384303e-03, 
	5.144031e-03, 4.900959e-03, 4.655424e-03, 4.407761e-03, 4.158302e-03, 
	3.907366e-03, 3.655262e-03, 3.402267e-03, 3.148620e-03, 2.894489e-03, 
	2.639928e-03, 2.384813e-03, 2.128724e-03, 1.870768e-03, 1.609283e-03, 
	1.341366e-03, 1.062098e-03, 7.863607e-04, 5.953999e-04, 4.510067e-04, 
	3.417722e-04, 2.590970e-04, 1.964955e-04, 1.490735e-04, 1.131357e-04, 
	8.589023e-05, 6.522688e-05, 4.954987e-05, 3.765182e-05, 2.861882e-05, 
	2.175878e-05, 1.654741e-05, 1.258732e-05, 9.577231e-06, 7.288631e-06, 
	5.548139e-06, 4.224157e-06, 3.216775e-06, 2.450111e-06, 1.866516e-06, 
	1.422183e-06, 1.083813e-06, 8.260855e-07, 6.297451e-07, 4.801435e-07, 
	3.661349e-07, 2.792367e-07, 2.129916e-07, 1.624832e-07, 1.239674e-07, 
	9.459236e-08, 7.218549e-08, 5.509129e-08, 4.204812e-08, 3.209425e-08, 
	2.449648e-08, 1.869567e-08, 1.426532e-08, 1.088002e-08, 8.291328e-09, 
	6.309496e-09, 4.789417e-09, 3.619960e-09, 2.715804e-09, 2.011170e-09, 
	1.455022e-09, 1.007348e-09, 1.984244e-02, 1.982298e-02, 1.978408e-02, 
	1.972581e-02, 1.964826e-02, 1.955153e-02, 1.943577e-02, 1.930117e-02, 
	1.914791e-02, 1.897624e-02, 1.878640e-02, 1.857867e-02, 1.835338e-02, 
	1.811086e-02, 1.785146e-02, 1.757557e-02, 1.728361e-02, 1.697600e-02, 
	1.665320e-02, 1.631568e-02, 1.596395e-02, 1.559851e-02, 1.521991e-02, 
	1.482870e-02, 1.442545e-02, 1.401074e-02, 1.358518e-02, 1.314939e-02, 
	1.270400e-02, 1.224964e-02, 1.178697e-02, 1.131667e-02, 1.083939e-02, 
	1.035584e-02, 9.866717e-03, 9.372735e-03, 8.874633e-03, 8.373183e-03, 
	7.869200e-03, 7.363574e-03, 6.857311e-03, 6.351604e-03, 5.847952e-03, 
	5.348344e-03, 4.855569e-03, 4.373709e-03, 3.908954e-03, 3.470903e-03, 
	3.074693e-03, 2.744449e-03, 2.518835e-03, 2.226601e-03, 1.917596e-03, 
	1.620151e-03, 1.348970e-03, 1.110322e-03, 9.054525e-04, 7.327781e-04, 
	5.892746e-04, 4.713340e-04, 3.752712e-04, 2.976055e-04, 2.352016e-04, 
	1.853229e-04, 1.456341e-04, 1.141757e-04, 8.932503e-05, 6.975223e-05, 
	5.437656e-05, 4.232596e-05, 3.290082e-05, 2.554275e-05, 1.980791e-05, 
	1.534490e-05, 1.187634e-05, 9.183946e-06, 7.096360e-06, 5.479358e-06, 
	4.228018e-06, 3.260467e-06, 2.512922e-06, 1.935765e-06, 1.490445e-06, 
	1.147050e-06, 8.823913e-07, 6.785107e-07, 5.215137e-07, 4.006573e-07, 
	3.076401e-07, 2.360505e-07, 1.809374e-07, 1.384772e-07, 1.057144e-07, 
	8.036109e-08, 6.063972e-08, 4.516093e-08, 3.282698e-08, 2.275468e-08, 
	1.421246e-08, 6.567161e-09};

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

  std::vector<double> flux = test.getVector("Neutron Flux");
  bool areEqual1 = std::equal(refFlux.begin(), refFlux.end(), flux.begin());
  EXPECT_TRUE(areEqual1);

  std::vector<double> temp = test.getVector("Final temperatures");
  bool areEqual2 = std::equal(refTemp.begin(), refTemp.end(), temp.begin());
  EXPECT_TRUE(areEqual2);

  EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}