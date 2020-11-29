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

  const double kEffRef = 7.920189e-01;

  std::vector<double> refFlux = {3.216386e-02,
                                 3.212784e-02,
                                 3.205587e-02,
                                 3.194807e-02,
                                 3.180462e-02,
                                 3.162576e-02,
                                 3.141181e-02,
                                 3.116311e-02,
                                 3.088010e-02,
                                 3.056326e-02,
                                 3.021312e-02,
                                 2.983026e-02,
                                 2.941535e-02,
                                 2.896909e-02,
                                 2.849221e-02,
                                 2.798554e-02,
                                 2.744991e-02,
                                 2.688623e-02,
                                 2.629544e-02,
                                 2.567854e-02,
                                 2.503654e-02,
                                 2.437053e-02,
                                 2.368161e-02,
                                 2.297092e-02,
                                 2.223963e-02,
                                 2.148896e-02,
                                 2.072015e-02,
                                 1.993444e-02,
                                 1.913314e-02,
                                 1.831755e-02,
                                 1.748900e-02,
                                 1.664883e-02,
                                 1.579840e-02,
                                 1.493908e-02,
                                 1.407226e-02,
                                 1.319932e-02,
                                 1.232166e-02,
                                 1.144066e-02,
                                 1.055772e-02,
                                 9.674232e-03,
                                 8.791579e-03,
                                 7.911138e-03,
                                 7.034276e-03,
                                 6.162345e-03,
                                 5.296685e-03,
                                 4.438618e-03,
                                 3.589444e-03,
                                 2.750444e-03,
                                 1.922873e-03,
                                 1.107961e-03};

  std::vector<double> refTemp = {3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02,
                                 3.237500e+02};

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

  const double kEffRef = 7.821075e-01;

  std::vector<double> refFlux = {3.339932e-02,
                                 3.335320e-02,
                                 3.326115e-02,
                                 3.312352e-02,
                                 3.294086e-02,
                                 3.271388e-02,
                                 3.244343e-02,
                                 3.213056e-02,
                                 3.177642e-02,
                                 3.138232e-02,
                                 3.094967e-02,
                                 3.047999e-02,
                                 2.997489e-02,
                                 2.943606e-02,
                                 2.886524e-02,
                                 2.826422e-02,
                                 2.763482e-02,
                                 2.697886e-02,
                                 2.629818e-02,
                                 2.559460e-02,
                                 2.486993e-02,
                                 2.412592e-02,
                                 2.336431e-02,
                                 2.258677e-02,
                                 2.179491e-02,
                                 2.099030e-02,
                                 2.017443e-02,
                                 1.934873e-02,
                                 1.851457e-02,
                                 1.767326e-02,
                                 1.682603e-02,
                                 1.597407e-02,
                                 1.511852e-02,
                                 1.426047e-02,
                                 1.340097e-02,
                                 1.254105e-02,
                                 1.168170e-02,
                                 1.082391e-02,
                                 9.968664e-03,
                                 9.116942e-03,
                                 8.269736e-03,
                                 7.428057e-03,
                                 6.592940e-03,
                                 5.765453e-03,
                                 4.946700e-03,
                                 4.137824e-03,
                                 3.340015e-03,
                                 2.554507e-03,
                                 1.782581e-03,
                                 1.025565e-03};

  std::vector<double> refTemp = {8.929907e+02,
                                 8.923163e+02,
                                 8.909691e+02,
                                 8.889520e+02,
                                 8.862697e+02,
                                 8.829280e+02,
                                 8.789344e+02,
                                 8.742977e+02,
                                 8.690279e+02,
                                 8.631365e+02,
                                 8.566360e+02,
                                 8.495400e+02,
                                 8.418633e+02,
                                 8.336214e+02,
                                 8.248309e+02,
                                 8.155093e+02,
                                 8.056744e+02,
                                 7.953450e+02,
                                 7.845404e+02,
                                 7.732804e+02,
                                 7.615851e+02,
                                 7.494750e+02,
                                 7.369712e+02,
                                 7.240946e+02,
                                 7.108667e+02,
                                 6.973091e+02,
                                 6.834434e+02,
                                 6.692914e+02,
                                 6.548751e+02,
                                 6.402166e+02,
                                 6.253378e+02,
                                 6.102612e+02,
                                 5.950088e+02,
                                 5.796031e+02,
                                 5.640666e+02,
                                 5.484217e+02,
                                 5.326913e+02,
                                 5.168981e+02,
                                 5.010651e+02,
                                 4.852153e+02,
                                 4.693720e+02,
                                 4.535586e+02,
                                 4.377986e+02,
                                 4.221158e+02,
                                 4.065340e+02,
                                 3.910773e+02,
                                 3.757698e+02,
                                 3.606356e+02,
                                 3.456990e+02,
                                 3.309843e+02};


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

  const double kEffRef = 7.816337e-01;

  std::vector<double> refFlux = {3.326493e-02,
                                 3.321991e-02,
                                 3.313002e-02,
                                 3.299561e-02,
                                 3.281718e-02,
                                 3.259539e-02,
                                 3.233104e-02,
                                 3.202510e-02,
                                 3.167864e-02,
                                 3.129288e-02,
                                 3.086914e-02,
                                 3.040885e-02,
                                 2.991350e-02,
                                 2.938469e-02,
                                 2.882405e-02,
                                 2.823326e-02,
                                 2.761404e-02,
                                 2.696811e-02,
                                 2.629723e-02,
                                 2.560312e-02,
                                 2.488750e-02,
                                 2.415206e-02,
                                 2.339846e-02,
                                 2.262832e-02,
                                 2.184320e-02,
                                 2.104462e-02,
                                 2.023404e-02,
                                 1.941288e-02,
                                 1.858249e-02,
                                 1.774416e-02,
                                 1.689913e-02,
                                 1.604861e-02,
                                 1.519375e-02,
                                 1.433565e-02,
                                 1.347541e-02,
                                 1.261408e-02,
                                 1.175268e-02,
                                 1.089226e-02,
                                 1.003384e-02,
                                 9.178441e-03,
                                 8.327107e-03,
                                 7.480899e-03,
                                 6.640903e-03,
                                 5.808237e-03,
                                 4.984054e-03,
                                 4.169549e-03,
                                 3.365960e-03,
                                 2.574570e-03,
                                 1.796705e-03,
                                 1.033740e-03};

  std::vector<double> refTemp = {8.760830e+02,
                                 8.754409e+02,
                                 8.741581e+02,
                                 8.722373e+02,
                                 8.696825e+02,
                                 8.664989e+02,
                                 8.626931e+02,
                                 8.582729e+02,
                                 8.532474e+02,
                                 8.476265e+02,
                                 8.414214e+02,
                                 8.346444e+02,
                                 8.273086e+02,
                                 8.194280e+02,
                                 8.110175e+02,
                                 8.020926e+02,
                                 7.926697e+02,
                                 7.827658e+02,
                                 7.723982e+02,
                                 7.615851e+02,
                                 7.503448e+02,
                                 7.386962e+02,
                                 7.266587e+02,
                                 7.142516e+02,
                                 7.014948e+02,
                                 6.884083e+02,
                                 6.750125e+02,
                                 6.613278e+02,
                                 6.473749e+02,
                                 6.331747e+02,
                                 6.187480e+02,
                                 6.041161e+02,
                                 5.893003e+02,
                                 5.743221e+02,
                                 5.592031e+02,
                                 5.439653e+02,
                                 5.286306e+02,
                                 5.132214e+02,
                                 4.977599e+02,
                                 4.822690e+02,
                                 4.667715e+02,
                                 4.512905e+02,
                                 4.358493e+02,
                                 4.204717e+02,
                                 4.051812e+02,
                                 3.900020e+02,
                                 3.749581e+02,
                                 3.600738e+02,
                                 3.453736e+02,
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