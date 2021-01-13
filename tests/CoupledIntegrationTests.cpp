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
// Heat boundary condition: T(L) = T2
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
// Reactor thermal power = 100.0 kW
// Constant thermal conductivity
// Heat boundary condition: T(L) = T2
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest2)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled2.txt";
  const std::string outputPath = "outputs/Out_Coupled2.txt";
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
// temperature-dependent thermal conductivity
// Heat boundary condition: T(L) = T2
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest3)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled3.txt";
  const std::string outputPath = "outputs/Out_Coupled3.txt";
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
// Reactor thermal power = 100.0 kW
// temperature-dependent thermal conductivity
// Heat boundary condition: T(L) = T2
// Diffusion boundary condition: zero incoming flux at the boundary

TEST_F(CoupledIntegrationTests, coupledTest4)
{	
  const std::string codePath   = "app/almost";
  const std::string inputPath  = "inputs/Coupled4.txt";
  const std::string outputPath = "outputs/Out_Coupled4.txt";
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