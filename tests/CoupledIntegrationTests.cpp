#include "gtest/gtest.h"
#include "TestHelper.h"

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

  const double kEffRef = 8.225162e-01;

  std::vector<double> refFlux = {3.207819e-02,
                                 3.204246e-02,
                                 3.197105e-02,
                                 3.186409e-02,
                                 3.172176e-02,
                                 3.154430e-02,
                                 3.133201e-02,
                                 3.108525e-02,
                                 3.080444e-02,
                                 3.049005e-02,
                                 3.014262e-02,
                                 2.976272e-02,
                                 2.935101e-02,
                                 2.890817e-02,
                                 2.843494e-02,
                                 2.793213e-02,
                                 2.740057e-02,
                                 2.684116e-02,
                                 2.625482e-02,
                                 2.564254e-02,
                                 2.500534e-02,
                                 2.434426e-02,
                                 2.366041e-02,
                                 2.295491e-02,
                                 2.222893e-02,
                                 2.148366e-02,
                                 2.072033e-02,
                                 1.994017e-02,
                                 1.914447e-02,
                                 1.833452e-02,
                                 1.751162e-02,
                                 1.667710e-02,
                                 1.583232e-02,
                                 1.497862e-02,
                                 1.411737e-02,
                                 1.324993e-02,
                                 1.237769e-02,
                                 1.150202e-02,
                                 1.062429e-02,
                                 9.745892e-03,
                                 8.868179e-03,
                                 7.992515e-03,
                                 7.120252e-03,
                                 6.252727e-03,
                                 5.391265e-03,
                                 4.537172e-03,
                                 3.691736e-03,
                                 2.856223e-03,
                                 2.031875e-03,
                                 1.219910e-03};

  std::vector<double> refTemp = {2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01};

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

  const double kEffRef = 7.937634e-01;

  std::vector<double> refFlux = {3.215889e-02,
                                 3.212289e-02,
                                 3.205095e-02,
                                 3.194319e-02,
                                 3.179980e-02,
                                 3.162102e-02,
                                 3.140716e-02,
                                 3.115857e-02,
                                 3.087568e-02,
                                 3.055897e-02,
                                 3.020897e-02,
                                 2.982628e-02,
                                 2.941155e-02,
                                 2.896547e-02,
                                 2.848880e-02,
                                 2.798234e-02,
                                 2.744694e-02,
                                 2.688350e-02,
                                 2.629296e-02,
                                 2.567632e-02,
                                 2.503460e-02,
                                 2.436887e-02,
                                 2.368024e-02,
                                 2.296985e-02,
                                 2.223887e-02,
                                 2.148852e-02,
                                 2.072002e-02,
                                 1.993465e-02,
                                 1.913368e-02,
                                 1.831843e-02,
                                 1.749021e-02,
                                 1.665039e-02,
                                 1.580030e-02,
                                 1.494133e-02,
                                 1.407485e-02,
                                 1.320225e-02,
                                 1.232493e-02,
                                 1.144426e-02,
                                 1.056165e-02,
                                 9.678484e-03,
                                 8.796145e-03,
                                 7.916009e-03,
                                 7.039442e-03,
                                 6.167797e-03,
                                 5.302410e-03,
                                 4.444602e-03,
                                 3.595673e-03,
                                 2.756904e-03,
                                 1.929547e-03,
                                 1.114832e-03};

  std::vector<double> refTemp = {3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02};

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

  const double kEffRef = 7.872892e-01;

  std::vector<double> refFlux = {3.079064e-02,
                                 3.076246e-02,
                                 3.070613e-02,
                                 3.062168e-02,
                                 3.050918e-02,
                                 3.036871e-02,
                                 3.020035e-02,
                                 3.000422e-02,
                                 2.978046e-02,
                                 2.952921e-02,
                                 2.925062e-02,
                                 2.894486e-02,
                                 2.861211e-02,
                                 2.825256e-02,
                                 2.786641e-02,
                                 2.745387e-02,
                                 2.701515e-02,
                                 2.655049e-02,
                                 2.606010e-02,
                                 2.554424e-02,
                                 2.500318e-02,
                                 2.443718e-02,
                                 2.384655e-02,
                                 2.323161e-02,
                                 2.259270e-02,
                                 2.193021e-02,
                                 2.124457e-02,
                                 2.053625e-02,
                                 1.980579e-02,
                                 1.905377e-02,
                                 1.828088e-02,
                                 1.748785e-02,
                                 1.667553e-02,
                                 1.584487e-02,
                                 1.499692e-02,
                                 1.413284e-02,
                                 1.325393e-02,
                                 1.236164e-02,
                                 1.145752e-02,
                                 1.054331e-02,
                                 9.620862e-03,
                                 8.692210e-03,
                                 7.759524e-03,
                                 6.825133e-03,
                                 5.891509e-03,
                                 4.961267e-03,
                                 4.037157e-03,
                                 3.122048e-03,
                                 2.218918e-03,
                                 1.330840e-03};

  std::vector<double> refTemp = {5.454762e+02,
                                 5.449450e+02,
                                 5.438832e+02,
                                 5.422918e+02,
                                 5.401725e+02,
                                 5.375274e+02,
                                 5.343591e+02,
                                 5.306709e+02,
                                 5.264666e+02,
                                 5.217503e+02,
                                 5.165269e+02,
                                 5.108017e+02,
                                 5.045806e+02,
                                 4.978699e+02,
                                 4.906765e+02,
                                 4.830078e+02,
                                 4.748718e+02,
                                 4.662770e+02,
                                 4.572325e+02,
                                 4.477477e+02,
                                 4.378330e+02,
                                 4.274990e+02,
                                 4.167571e+02,
                                 4.056192e+02,
                                 3.940979e+02,
                                 3.822064e+02,
                                 3.699586e+02,
                                 3.573693e+02,
                                 3.444536e+02,
                                 3.312277e+02,
                                 3.177086e+02,
                                 3.039138e+02,
                                 2.898621e+02,
                                 2.755727e+02,
                                 2.610661e+02,
                                 2.463635e+02,
                                 2.314871e+02,
                                 2.164600e+02,
                                 2.013064e+02,
                                 1.860514e+02,
                                 1.707209e+02,
                                 1.553421e+02,
                                 1.399427e+02,
                                 1.245516e+02,
                                 1.091984e+02,
                                 9.391339e+01,
                                 7.872765e+01,
                                 6.367279e+01,
                                 4.878088e+01,
                                 3.408432e+01};


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

  const double kEffRef = 7.813016e-01;

  std::vector<double> refFlux = {3.317713e-02,
                                 3.313257e-02,
                                 3.304362e-02,
                                 3.291061e-02,
                                 3.273403e-02,
                                 3.251453e-02,
                                 3.225292e-02,
                                 3.195014e-02,
                                 3.160727e-02,
                                 3.122549e-02,
                                 3.080611e-02,
                                 3.035054e-02,
                                 2.986025e-02,
                                 2.933679e-02,
                                 2.878179e-02,
                                 2.819687e-02,
                                 2.758373e-02,
                                 2.694406e-02,
                                 2.627955e-02,
                                 2.559189e-02,
                                 2.488276e-02,
                                 2.415378e-02,
                                 2.340658e-02,
                                 2.264271e-02,
                                 2.186368e-02,
                                 2.107097e-02,
                                 2.026599e-02,
                                 1.945007e-02,
                                 1.862454e-02,
                                 1.779063e-02,
                                 1.694955e-02,
                                 1.610245e-02,
                                 1.525043e-02,
                                 1.439459e-02,
                                 1.353598e-02,
                                 1.267562e-02,
                                 1.181455e-02,
                                 1.095378e-02,
                                 1.009434e-02,
                                 9.237262e-03,
                                 8.383615e-03,
                                 7.534485e-03,
                                 6.690997e-03,
                                 5.854318e-03,
                                 5.025662e-03,
                                 4.206293e-03,
                                 3.397526e-03,
                                 2.600735e-03,
                                 1.817345e-03,
                                 1.048836e-03};

  std::vector<double> refTemp = {8.727453e+02,
                                 8.721124e+02,
                                 8.708479e+02,
                                 8.689544e+02,
                                 8.664357e+02,
                                 8.632969e+02,
                                 8.595441e+02,
                                 8.551850e+02,
                                 8.502280e+02,
                                 8.446828e+02,
                                 8.385601e+02,
                                 8.318716e+02,
                                 8.246298e+02,
                                 8.168483e+02,
                                 8.085413e+02,
                                 7.997237e+02,
                                 7.904113e+02,
                                 7.806203e+02,
                                 7.703676e+02,
                                 7.596705e+02,
                                 7.485468e+02,
                                 7.370148e+02,
                                 7.250931e+02,
                                 7.128006e+02,
                                 7.001565e+02,
                                 6.871804e+02,
                                 6.738920e+02,
                                 6.603113e+02,
                                 6.464584e+02,
                                 6.323540e+02,
                                 6.180184e+02,
                                 6.034727e+02,
                                 5.887378e+02,
                                 5.738350e+02,
                                 5.587858e+02,
                                 5.436119e+02,
                                 5.283354e+02,
                                 5.129784e+02,
                                 4.975634e+02,
                                 4.821133e+02,
                                 4.666510e+02,
                                 4.511999e+02,
                                 4.357836e+02,
                                 4.204260e+02,
                                 4.051513e+02,
                                 3.899839e+02,
                                 3.749484e+02,
                                 3.600695e+02,
                                 3.453723e+02,
                                 3.308771e+02};

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

  const double kEffRef = 8.205513e-01;

  std::vector<double> refFlux = {1.341489e-02,
                                 1.340017e-02,
                                 1.337076e-02,
                                 1.332670e-02,
                                 1.326806e-02,
                                 1.319495e-02,
                                 1.310749e-02,
                                 1.300583e-02,
                                 1.289012e-02,
                                 1.276057e-02,
                                 1.261739e-02,
                                 1.246081e-02,
                                 1.229111e-02,
                                 1.210855e-02,
                                 1.191344e-02,
                                 1.170611e-02,
                                 1.148689e-02,
                                 1.125614e-02,
                                 1.101426e-02,
                                 1.076162e-02,
                                 1.049865e-02,
                                 1.022578e-02,
                                 9.943442e-03,
                                 9.652109e-03,
                                 9.352250e-03,
                                 9.044349e-03,
                                 8.728904e-03,
                                 8.406423e-03,
                                 8.077425e-03,
                                 7.742437e-03,
                                 7.401993e-03,
                                 7.056636e-03,
                                 6.706914e-03,
                                 6.353381e-03,
                                 5.996596e-03,
                                 5.637120e-03,
                                 5.275521e-03,
                                 4.912368e-03,
                                 4.548236e-03,
                                 4.183708e-03,
                                 3.819380e-03,
                                 3.455870e-03,
                                 3.093834e-03,
                                 2.733997e-03,
                                 2.377208e-03,
                                 2.024525e-03,
                                 1.677374e-03,
                                 1.337819e-03,
                                 1.009023e-03,
                                 6.960527e-04,
                                 1.845191e-02,
                                 1.843167e-02,
                                 1.839122e-02,
                                 1.833062e-02,
                                 1.824998e-02,
                                 1.814943e-02,
                                 1.802915e-02,
                                 1.788932e-02,
                                 1.773019e-02,
                                 1.755201e-02,
                                 1.735509e-02,
                                 1.713975e-02,
                                 1.690634e-02,
                                 1.665526e-02,
                                 1.638692e-02,
                                 1.610176e-02,
                                 1.580025e-02,
                                 1.548290e-02,
                                 1.515021e-02,
                                 1.480273e-02,
                                 1.444105e-02,
                                 1.406573e-02,
                                 1.367741e-02,
                                 1.327670e-02,
                                 1.286427e-02,
                                 1.244077e-02,
                                 1.200689e-02,
                                 1.156334e-02,
                                 1.111081e-02,
                                 1.065004e-02,
                                 1.018176e-02,
                                 9.706720e-03,
                                 9.225664e-03,
                                 8.739353e-03,
                                 8.248546e-03,
                                 7.754003e-03,
                                 7.256481e-03,
                                 6.756724e-03,
                                 6.255454e-03,
                                 5.753355e-03,
                                 5.251047e-03,
                                 4.749031e-03,
                                 4.247616e-03,
                                 3.746779e-03,
                                 3.245928e-03,
                                 2.743500e-03,
                                 2.236263e-03,
                                 1.718127e-03,
                                 1.178084e-03,
                                 5.966787e-04};

  std::vector<double> refTemp = {2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01,
                                 2.685000e+01};

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

  const double kEffRef = 7.920029e-01;

  std::vector<double> refFlux = {1.088173e-02,
                                 1.086975e-02,
                                 1.084580e-02,
                                 1.080993e-02,
                                 1.076220e-02,
                                 1.070268e-02,
                                 1.063148e-02,
                                 1.054871e-02,
                                 1.045452e-02,
                                 1.034906e-02,
                                 1.023250e-02,
                                 1.010504e-02,
                                 9.966892e-03,
                                 9.818286e-03,
                                 9.659467e-03,
                                 9.490698e-03,
                                 9.312258e-03,
                                 9.124442e-03,
                                 8.927560e-03,
                                 8.721935e-03,
                                 8.507906e-03,
                                 8.285822e-03,
                                 8.056048e-03,
                                 7.818959e-03,
                                 7.574939e-03,
                                 7.324387e-03,
                                 7.067707e-03,
                                 6.805316e-03,
                                 6.537636e-03,
                                 6.265097e-03,
                                 5.988137e-03,
                                 5.707198e-03,
                                 5.422730e-03,
                                 5.135186e-03,
                                 4.845023e-03,
                                 4.552703e-03,
                                 4.258692e-03,
                                 3.963461e-03,
                                 3.667491e-03,
                                 3.371270e-03,
                                 3.075305e-03,
                                 2.780131e-03,
                                 2.486330e-03,
                                 2.194556e-03,
                                 1.905591e-03,
                                 1.620417e-03,
                                 1.340344e-03,
                                 1.067223e-03,
                                 8.037733e-04,
                                 5.541337e-04,
                                 2.104655e-02,
                                 2.102338e-02,
                                 2.097707e-02,
                                 2.090770e-02,
                                 2.081539e-02,
                                 2.070030e-02,
                                 2.056260e-02,
                                 2.040255e-02,
                                 2.022039e-02,
                                 2.001644e-02,
                                 1.979103e-02,
                                 1.954454e-02,
                                 1.927738e-02,
                                 1.898999e-02,
                                 1.868285e-02,
                                 1.835646e-02,
                                 1.801138e-02,
                                 1.764815e-02,
                                 1.726739e-02,
                                 1.686972e-02,
                                 1.645579e-02,
                                 1.602629e-02,
                                 1.558190e-02,
                                 1.512337e-02,
                                 1.465142e-02,
                                 1.416684e-02,
                                 1.367041e-02,
                                 1.316292e-02,
                                 1.264519e-02,
                                 1.211807e-02,
                                 1.158237e-02,
                                 1.103897e-02,
                                 1.048872e-02,
                                 9.932492e-03,
                                 9.371144e-03,
                                 8.805543e-03,
                                 8.236546e-03,
                                 7.664988e-03,
                                 7.091675e-03,
                                 6.517356e-03,
                                 5.942695e-03,
                                 5.368212e-03,
                                 4.794200e-03,
                                 4.220586e-03,
                                 3.646705e-03,
                                 3.070945e-03,
                                 2.490160e-03,
                                 1.898731e-03,
                                 1.287040e-03,
                                 6.390045e-04};

  std::vector<double> refTemp = {3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02,
                                 3.268500e+02};

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

  const double kEffRef = 7.875591e-01;

  std::vector<double> refFlux = {9.309510e-03,
                                 9.303000e-03,
                                 9.289985e-03,
                                 9.270470e-03,
                                 9.244466e-03,
                                 9.211984e-03,
                                 9.173037e-03,
                                 9.127638e-03,
                                 9.075797e-03,
                                 9.017523e-03,
                                 8.952821e-03,
                                 8.881686e-03,
                                 8.804108e-03,
                                 8.720067e-03,
                                 8.629531e-03,
                                 8.532453e-03,
                                 8.428773e-03,
                                 8.318414e-03,
                                 8.201283e-03,
                                 8.077268e-03,
                                 7.946240e-03,
                                 7.808051e-03,
                                 7.662539e-03,
                                 7.509524e-03,
                                 7.348814e-03,
                                 7.180208e-03,
                                 7.003498e-03,
                                 6.818472e-03,
                                 6.624925e-03,
                                 6.422658e-03,
                                 6.211489e-03,
                                 5.991259e-03,
                                 5.761839e-03,
                                 5.523139e-03,
                                 5.275116e-03,
                                 5.017785e-03,
                                 4.751222e-03,
                                 4.475581e-03,
                                 4.191097e-03,
                                 3.898102e-03,
                                 3.597033e-03,
                                 3.288451e-03,
                                 2.973063e-03,
                                 2.651756e-03,
                                 2.325657e-03,
                                 1.996227e-03,
                                 1.665430e-03,
                                 1.336023e-03,
                                 1.012071e-03,
                                 6.998517e-04,
                                 2.167824e-02,
                                 2.165637e-02,
                                 2.161265e-02,
                                 2.154705e-02,
                                 2.145956e-02,
                                 2.135019e-02,
                                 2.121891e-02,
                                 2.106572e-02,
                                 2.089063e-02,
                                 2.069363e-02,
                                 2.047475e-02,
                                 2.023404e-02,
                                 1.997155e-02,
                                 1.968737e-02,
                                 1.938163e-02,
                                 1.905451e-02,
                                 1.870620e-02,
                                 1.833698e-02,
                                 1.794717e-02,
                                 1.753718e-02,
                                 1.710747e-02,
                                 1.665859e-02,
                                 1.619118e-02,
                                 1.570596e-02,
                                 1.520374e-02,
                                 1.468545e-02,
                                 1.415209e-02,
                                 1.360475e-02,
                                 1.304462e-02,
                                 1.247298e-02,
                                 1.189117e-02,
                                 1.130062e-02,
                                 1.070281e-02,
                                 1.009924e-02,
                                 9.491492e-03,
                                 8.881129e-03,
                                 8.269729e-03,
                                 7.658851e-03,
                                 7.050015e-03,
                                 6.444674e-03,
                                 5.844175e-03,
                                 5.249703e-03,
                                 4.662191e-03,
                                 4.082181e-03,
                                 3.509573e-03,
                                 2.943213e-03,
                                 2.380175e-03,
                                 1.814502e-03,
                                 1.235018e-03,
                                 6.214672e-04};

  std::vector<double> refTemp = {5.476914e+02,
                                 5.471554e+02,
                                 5.460839e+02,
                                 5.444782e+02,
                                 5.423397e+02,
                                 5.396708e+02,
                                 5.364741e+02,
                                 5.327531e+02,
                                 5.285114e+02,
                                 5.237537e+02,
                                 5.184846e+02,
                                 5.127099e+02,
                                 5.064354e+02,
                                 4.996677e+02,
                                 4.924140e+02,
                                 4.846820e+02,
                                 4.764797e+02,
                                 4.678161e+02,
                                 4.587004e+02,
                                 4.491425e+02,
                                 4.391531e+02,
                                 4.287432e+02,
                                 4.179245e+02,
                                 4.067095e+02,
                                 3.951111e+02,
                                 3.831431e+02,
                                 3.708198e+02,
                                 3.581564e+02,
                                 3.451688e+02,
                                 3.318734e+02,
                                 3.182878e+02,
                                 3.044300e+02,
                                 2.903191e+02,
                                 2.759748e+02,
                                 2.614177e+02,
                                 2.466693e+02,
                                 2.317520e+02,
                                 2.166888e+02,
                                 2.015036e+02,
                                 1.862214e+02,
                                 1.708676e+02,
                                 1.554686e+02,
                                 1.400516e+02,
                                 1.246444e+02,
                                 1.092758e+02,
                                 9.397529e+01,
                                 7.877326e+01,
                                 6.370139e+01,
                                 4.879306e+01,
                                 3.408432e+01};

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

  const double kEffRef = 7.875591e-01;

  std::vector<double> refFlux = {9.309510e-03,
                                 9.303000e-03,
                                 9.289985e-03,
                                 9.270470e-03,
                                 9.244466e-03,
                                 9.211984e-03,
                                 9.173037e-03,
                                 9.127638e-03,
                                 9.075797e-03,
                                 9.017523e-03,
                                 8.952821e-03,
                                 8.881686e-03,
                                 8.804108e-03,
                                 8.720067e-03,
                                 8.629531e-03,
                                 8.532453e-03,
                                 8.428773e-03,
                                 8.318414e-03,
                                 8.201283e-03,
                                 8.077268e-03,
                                 7.946240e-03,
                                 7.808051e-03,
                                 7.662539e-03,
                                 7.509524e-03,
                                 7.348814e-03,
                                 7.180208e-03,
                                 7.003498e-03,
                                 6.818472e-03,
                                 6.624925e-03,
                                 6.422658e-03,
                                 6.211489e-03,
                                 5.991259e-03,
                                 5.761839e-03,
                                 5.523139e-03,
                                 5.275116e-03,
                                 5.017785e-03,
                                 4.751222e-03,
                                 4.475581e-03,
                                 4.191097e-03,
                                 3.898102e-03,
                                 3.597033e-03,
                                 3.288451e-03,
                                 2.973063e-03,
                                 2.651756e-03,
                                 2.325657e-03,
                                 1.996227e-03,
                                 1.665430e-03,
                                 1.336023e-03,
                                 1.012071e-03,
                                 6.998517e-04,
                                 2.167824e-02,
                                 2.165637e-02,
                                 2.161265e-02,
                                 2.154705e-02,
                                 2.145956e-02,
                                 2.135019e-02,
                                 2.121891e-02,
                                 2.106572e-02,
                                 2.089063e-02,
                                 2.069363e-02,
                                 2.047475e-02,
                                 2.023404e-02,
                                 1.997155e-02,
                                 1.968737e-02,
                                 1.938163e-02,
                                 1.905451e-02,
                                 1.870620e-02,
                                 1.833698e-02,
                                 1.794717e-02,
                                 1.753718e-02,
                                 1.710747e-02,
                                 1.665859e-02,
                                 1.619118e-02,
                                 1.570596e-02,
                                 1.520374e-02,
                                 1.468545e-02,
                                 1.415209e-02,
                                 1.360475e-02,
                                 1.304462e-02,
                                 1.247298e-02,
                                 1.189117e-02,
                                 1.130062e-02,
                                 1.070281e-02,
                                 1.009924e-02,
                                 9.491492e-03,
                                 8.881129e-03,
                                 8.269729e-03,
                                 7.658851e-03,
                                 7.050015e-03,
                                 6.444674e-03,
                                 5.844175e-03,
                                 5.249703e-03,
                                 4.662191e-03,
                                 4.082181e-03,
                                 3.509573e-03,
                                 2.943213e-03,
                                 2.380175e-03,
                                 1.814502e-03,
                                 1.235018e-03,
                                 6.214672e-04};

  std::vector<double> refTemp = {5.476914e+02,
                                 5.471554e+02,
                                 5.460839e+02,
                                 5.444782e+02,
                                 5.423397e+02,
                                 5.396708e+02,
                                 5.364741e+02,
                                 5.327531e+02,
                                 5.285114e+02,
                                 5.237537e+02,
                                 5.184846e+02,
                                 5.127099e+02,
                                 5.064354e+02,
                                 4.996677e+02,
                                 4.924140e+02,
                                 4.846820e+02,
                                 4.764797e+02,
                                 4.678161e+02,
                                 4.587004e+02,
                                 4.491425e+02,
                                 4.391531e+02,
                                 4.287432e+02,
                                 4.179245e+02,
                                 4.067095e+02,
                                 3.951111e+02,
                                 3.831431e+02,
                                 3.708198e+02,
                                 3.581564e+02,
                                 3.451688e+02,
                                 3.318734e+02,
                                 3.182878e+02,
                                 3.044300e+02,
                                 2.903191e+02,
                                 2.759748e+02,
                                 2.614177e+02,
                                 2.466693e+02,
                                 2.317520e+02,
                                 2.166888e+02,
                                 2.015036e+02,
                                 1.862214e+02,
                                 1.708676e+02,
                                 1.554686e+02,
                                 1.400516e+02,
                                 1.246444e+02,
                                 1.092758e+02,
                                 9.397529e+01,
                                 7.877326e+01,
                                 6.370139e+01,
                                 4.879306e+01,
                                 3.408432e+01};

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