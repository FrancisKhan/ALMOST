#include "gtest/gtest.h"
#include "TestHelper.h"

class IntegrationTests : public ::testing::Test 
{
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};

// CYLINDER TESTS //

TEST_F(IntegrationTests, Problem1CY)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem1CY.txt";
  const std::string outputPath = "outputs/Out_Problem1CY.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.6129;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(IntegrationTests, Problem5CY)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem5CY.txt";
  const std::string outputPath = "outputs/Out_Problem5CY.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.29032;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_DOUBLE_EQ(test.getKEff(), kEffRef);
}

TEST_F(IntegrationTests, Problem7)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem7.txt";
  const std::string outputPath = "outputs/Out_Problem7.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.996731;
  std::vector<double> refFlux = {0.1315, 0.1294, 0.1253,
                                 0.1192, 0.1113, 0.1017,
                                 0.0906, 0.0781, 0.0643, 0.0487};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem9)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem9.txt";
  const std::string outputPath = "outputs/Out_Problem9.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.995209;
  std::vector<double> refFlux = {0.1437, 0.1396, 0.1317, 0.1201,
                                 0.1051, 0.0865, 0.0664, 0.0538,
                                 0.0443, 0.0365, 0.0299, 0.0239, 0.0183};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem10)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem10.txt";
  const std::string outputPath = "outputs/Out_Problem10.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.980285;
  std::vector<double> refFlux = {0.1026, 0.1017, 0.0999, 0.0971,
                                 0.0936, 0.0891, 0.0839, 0.0778,
                                 0.0707, 0.0623, 0.0411, 0.0252, 
                                 0.0166, 0.0113, 0.0078, 0.0055,
                                 0.0039, 0.0028, 0.0020, 0.0015,
                                 0.0011, 0.0008, 0.0006, 0.0004,
                                 0.0003, 0.0002, 0.0002, 0.0001, 
                                 0.0001, 0.0000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem44CY)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem44CY.txt";
  const std::string outputPath = "outputs/Out_Problem44CY.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 2.68377;
  std::vector<double> refFlux = {0.0403, 0.0403, 0.0403, 0.0403,
                                 0.0403, 0.0403, 0.0403, 0.0403,
                                 0.0403, 0.0403, 0.0597, 0.0597,
                                 0.0597, 0.0597, 0.0597, 0.0597,
                                 0.0597, 0.0597, 0.0597, 0.0597};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem74)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem74.txt";
  const std::string outputPath = "outputs/Out_Problem74.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 1.60;
  std::vector<double> refFlux = {0.0613, 0.0613, 0.0613, 0.0613,
                                 0.0613, 0.0613, 0.0613, 0.0613,
                                 0.0613, 0.0613, 0.0294, 0.0294,
                                 0.0294, 0.0294, 0.0294, 0.0294,
                                 0.0294, 0.0294, 0.0294, 0.0294,
                                 0.0092, 0.0092, 0.0092, 0.0092,
                                 0.0092, 0.0092, 0.0092, 0.0092,
                                 0.0092, 0.0092};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem75)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem75.txt";
  const std::string outputPath = "outputs/Out_Problem75.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 1.60;
  std::vector<double> refFlux = {0.0307, 0.0307, 0.0307, 0.0307,
                                 0.0307, 0.0307, 0.0307, 0.0307,
                                 0.0307, 0.0307, 0.0147, 0.0147,
                                 0.0147, 0.0147, 0.0147, 0.0147,
                                 0.0147, 0.0147, 0.0147, 0.0147,
                                 0.0046, 0.0046, 0.0046, 0.0046,
                                 0.0046, 0.0046, 0.0046, 0.0046,
                                 0.0046, 0.0046, 0.0046, 0.0046,
                                 0.0046, 0.0046, 0.0046, 0.0046,
                                 0.0046, 0.0046, 0.0046, 0.0046,
                                 0.0147, 0.0147, 0.0147, 0.0147,
                                 0.0147, 0.0147, 0.0147, 0.0147,
                                 0.0147, 0.0147, 0.0307, 0.0307, 
                                 0.0307, 0.0307, 0.0307, 0.0307,
                                 0.0307, 0.0307, 0.0307, 0.0307};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

// SPHERE TESTS //

TEST_F(IntegrationTests, Problem1SP)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem1SP.txt";
  const std::string outputPath = "outputs/Out_Problem1SP.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.6129;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(IntegrationTests, Problem5SP)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem5SP.txt";
  const std::string outputPath = "outputs/Out_Problem5SP.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.29032;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_DOUBLE_EQ(test.getKEff(), kEffRef);
}

TEST_F(IntegrationTests, Problem8)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem8.txt";
  const std::string outputPath = "outputs/Out_Problem8.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.995072999999999999;
  std::vector<double> refFlux = {0.1180, 0.1162, 0.1128, 0.1078,
                                 0.1014, 0.0937, 0.0848, 0.0750,
                                 0.0645, 0.0535, 0.0421, 0.0301};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem16)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem16.txt";
  const std::string outputPath = "outputs/Out_Problem16.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99623200000000001;
  std::vector<double> refFlux = {0.0918, 0.0907, 0.0887, 0.0857,
                                 0.0817, 0.0770, 0.0715, 0.0653,
                                 0.0586, 0.0515, 0.0439, 0.0358, 
                                 0.0286, 0.0244, 0.0210, 0.0182,
                                 0.0157, 0.0136, 0.0116, 0.0099,
                                 0.0082, 0.0066};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem44SP)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem44SP.txt";
  const std::string outputPath = "outputs/Out_Problem44SP.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 2.68377;
  std::vector<double> refFlux = {0.0403, 0.0403, 0.0403, 0.0403,
                                 0.0403, 0.0403, 0.0403, 0.0403,
                                 0.0403, 0.0403, 0.0597, 0.0597,
                                 0.0597, 0.0597, 0.0597, 0.0597,
                                 0.0597, 0.0597, 0.0597, 0.0597};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem49)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem49.txt";
  const std::string outputPath = "outputs/Out_Problem49.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99142300000000005;
  std::vector<double> refFlux = {0.0567, 0.0555, 0.0531, 0.0497,
                                 0.0454, 0.0402, 0.0345, 0.0283,
                                 0.0219, 0.0152, 0.0860, 0.0841,
                                 0.0804, 0.0751, 0.0683, 0.0603,
                                 0.0513, 0.0416, 0.0315, 0.0209};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem69)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem69.txt";
  const std::string outputPath = "outputs/Out_Problem69.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99737500000000001;
  std::vector<double> refFlux = {0.0534, 0.0534, 0.0534, 0.0534,
                                 0.0534, 0.0534, 0.0534, 0.0534,
                                 0.0534, 0.0534, 0.0533, 0.0532,
                                 0.0529, 0.0522, 0.0508, 0.0482,
                                 0.0436, 0.0364, 0.0261, 0.0135,
                                 0.0020, 0.0020, 0.0020, 0.0020,
                                 0.0020, 0.0020, 0.0020, 0.0020,
                                 0.0020, 0.0020, 0.0020, 0.0020,
                                 0.0020, 0.0019, 0.0019, 0.0018,
                                 0.0016, 0.0014, 0.0010, 0.0005};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

// SLAB TESTS //

TEST_F(IntegrationTests, Problem1SL)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem1SL.txt";
  const std::string outputPath = "outputs/Out_Problem1SL.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.6129;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_FLOAT_EQ(test.getKEff(), kEffRef);
}

TEST_F(IntegrationTests, Problem5SL)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem5SL.txt";
  const std::string outputPath = "outputs/Out_Problem5SL.txt";
  const std::string traceLevel = "DEBUG";
  const double kEffRef = 2.29032;
  std::vector<double> refFlux = {0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000,
                                 0.1000, 0.1000, 0.1000, 0.1000};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
	EXPECT_DOUBLE_EQ(test.getKEff(), kEffRef);
}

TEST_F(IntegrationTests, Problem2)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem2.txt";
  const std::string outputPath = "outputs/Out_Problem2.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99758899999999995;
  std::vector<double> refFlux = {0.0745, 0.0920, 0.1044, 0.1125,
                                 0.1166, 0.1166, 0.1125, 0.1044, 
                                 0.0920, 0.0745};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem3)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem3.txt";
  const std::string outputPath = "outputs/Out_Problem3.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.998938;
  std::vector<double> refFlux = {0.0346, 0.0410, 0.0461, 0.0501,
                                 0.0531, 0.0553, 0.0566, 0.0569,
                                 0.0563, 0.0548, 0.0522, 0.0482, 
                                 0.0429, 0.0393, 0.0364, 0.0338,
                                 0.0315, 0.0294, 0.0274, 0.0254, 
                                 0.0236, 0.0218, 0.0201, 0.0184,
                                 0.0167, 0.0150, 0.0131};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem4)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem4.txt";
  const std::string outputPath = "outputs/Out_Problem4.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.999304;
  std::vector<double> refFlux = {0.0157, 0.0176, 0.0193, 0.0210, 
                                 0.0228, 0.0246, 0.0265, 0.0285,
                                 0.0307, 0.0334, 0.0374, 0.0408,
                                 0.0433, 0.0452, 0.0464, 0.0470,
                                 0.0470, 0.0464, 0.0452, 0.0433, 
                                 0.0408, 0.0374, 0.0334, 0.0307,
                                 0.0285, 0.0265, 0.0246, 0.0228,
                                 0.0210, 0.0193, 0.0176, 0.0157};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem6)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem6.txt";
  const std::string outputPath = "outputs/Out_Problem6.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.996382;
  std::vector<double> refFlux = {0.0817, 0.1041, 0.1195, 0.1288,
                                 0.1318, 0.1288, 0.1195, 0.1041,
                                 0.0817};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem44SL)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem44SL.txt";
  const std::string outputPath = "outputs/Out_Problem44SL.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 2.68377;
  std::vector<double> refFlux = {0.0403, 0.0403, 0.0403, 0.0403,
                                 0.0403, 0.0403, 0.0403, 0.0403,
                                 0.0403, 0.0403, 0.0597, 0.0597,
                                 0.0597, 0.0597, 0.0597, 0.0597,
                                 0.0597, 0.0597, 0.0597, 0.0597};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem48)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem48.txt";
  const std::string outputPath = "outputs/Out_Problem48.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99607999999999997;
  std::vector<double> refFlux = {0.0302, 0.0378, 0.0433, 0.0470,
                                 0.0489, 0.0489, 0.0470, 0.0433,
                                 0.0378, 0.0302, 0.0402, 0.0527,
                                 0.0617, 0.0676, 0.0706, 0.0706,
                                 0.0676, 0.0617, 0.0527, 0.0402};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem68)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem68.txt";
  const std::string outputPath = "outputs/Out_Problem68.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.994753;
  std::vector<double> refFlux = {0.0168, 0.0314, 0.0424, 0.0497,
                                 0.0540, 0.0563, 0.0574, 0.0579,
                                 0.0581, 0.0582, 0.0582, 0.0581,
                                 0.0579, 0.0574, 0.0563, 0.0540,
                                 0.0497, 0.0424, 0.0314, 0.0168,
                                 0.0006, 0.0012, 0.0016, 0.0018,
                                 0.0020, 0.0021, 0.0021, 0.0022,
                                 0.0022, 0.0022, 0.0022, 0.0022,
                                 0.0022, 0.0021, 0.0021, 0.0020,
                                 0.0018, 0.0016, 0.0012, 0.0006};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Problem58)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/Problem58.txt";
  const std::string outputPath = "outputs/Out_Problem58.txt";
  const std::string traceLevel = "DEBUG";

  const double kEffRef = 0.99239500000000003;
  std::vector<double> refFlux = {0.0010, 0.0010, 0.0011, 0.0011,
                                 0.0012, 0.0012, 0.0012, 0.0013, 
                                 0.0013, 0.0014, 0.0014, 0.0014, 
                                 0.0015, 0.0015, 0.0015, 0.0016, 
                                 0.0016, 0.0017, 0.0017, 0.0017, 
                                 0.0018, 0.0018, 0.0018, 0.0019, 
                                 0.0019, 0.0019, 0.0020, 0.0020, 
                                 0.0021, 0.0021, 0.0021, 0.0022, 
                                 0.0022, 0.0022, 0.0023, 0.0023, 
                                 0.0024, 0.0024, 0.0024, 0.0025,
                                 0.0025, 0.0026, 0.0026, 0.0026, 
                                 0.0027, 0.0027, 0.0028, 0.0028, 
                                 0.0029, 0.0029, 0.0032, 0.0037, 
                                 0.0041, 0.0045, 0.0050, 0.0054, 
                                 0.0058, 0.0061, 0.0065, 0.0068, 
                                 0.0072, 0.0075, 0.0078, 0.0080,
                                 0.0083, 0.0085, 0.0087, 0.0089, 
                                 0.0091, 0.0092, 0.0093, 0.0094, 
                                 0.0095, 0.0096, 0.0096, 0.0096, 
                                 0.0096, 0.0095, 0.0094, 0.0093, 
                                 0.0092, 0.0091, 0.0089, 0.0087, 
                                 0.0085, 0.0083, 0.0080, 0.0078, 
                                 0.0075, 0.0072, 0.0068, 0.0065, 
                                 0.0061, 0.0058, 0.0054, 0.0050, 
                                 0.0045, 0.0041, 0.0037, 0.0032, 
                                 0.0029, 0.0029, 0.0028, 0.0028, 
                                 0.0027, 0.0027, 0.0026, 0.0026, 
                                 0.0026, 0.0025, 0.0025, 0.0024,
                                 0.0024, 0.0024, 0.0023, 0.0023,
                                 0.0022, 0.0022, 0.0022, 0.0021,
                                 0.0021, 0.0021, 0.0020, 0.0020,
                                 0.0019, 0.0019, 0.0019, 0.0018,
                                 0.0018, 0.0018, 0.0017, 0.0017,
                                 0.0017, 0.0016, 0.0016, 0.0015,
                                 0.0015, 0.0015, 0.0014, 0.0014,
                                 0.0014, 0.0013, 0.0013, 0.0012,
                                 0.0012, 0.0012, 0.0011, 0.0011,
                                 0.0010, 0.0010, 0.0004, 0.0005,
                                 0.0006, 0.0006, 0.0007, 0.0007,
                                 0.0008, 0.0008, 0.0009, 0.0009,
                                 0.0010, 0.0010, 0.0011, 0.0011,
                                 0.0011, 0.0012, 0.0012, 0.0013,
                                 0.0013, 0.0014, 0.0014, 0.0014,
                                 0.0015, 0.0015, 0.0016, 0.0016,
                                 0.0017, 0.0017, 0.0017, 0.0018,
                                 0.0018, 0.0019, 0.0019, 0.0019,
                                 0.0020, 0.0020, 0.0020, 0.0021,
                                 0.0021, 0.0022, 0.0022, 0.0022,
                                 0.0023, 0.0023, 0.0023, 0.0024,
                                 0.0024, 0.0024, 0.0025, 0.0025, 
                                 0.0027, 0.0030, 0.0033, 0.0036,
                                 0.0040, 0.0043, 0.0046, 0.0049,
                                 0.0051, 0.0054, 0.0057, 0.0059,
                                 0.0061, 0.0063, 0.0065, 0.0067,
                                 0.0069, 0.0070, 0.0072, 0.0073,
                                 0.0074, 0.0074, 0.0075, 0.0075,
                                 0.0076, 0.0076, 0.0075, 0.0075,
                                 0.0074, 0.0074, 0.0073, 0.0072,
                                 0.0070, 0.0069, 0.0067, 0.0065,
                                 0.0063, 0.0061, 0.0059, 0.0057,
                                 0.0054, 0.0051, 0.0049, 0.0046,
                                 0.0043, 0.0040, 0.0036, 0.0033,
                                 0.0030, 0.0027, 0.0025, 0.0025,
                                 0.0024, 0.0024, 0.0024, 0.0023,
                                 0.0023, 0.0023, 0.0022, 0.0022,
                                 0.0022, 0.0021, 0.0021, 0.0020,
                                 0.0020, 0.0020, 0.0019, 0.0019,
                                 0.0019, 0.0018, 0.0018, 0.0017,
                                 0.0017, 0.0017, 0.0016, 0.0016,
                                 0.0015, 0.0015, 0.0014, 0.0014,
                                 0.0014, 0.0013, 0.0013, 0.0012,
                                 0.0012, 0.0011, 0.0011, 0.0011,
                                 0.0010, 0.0010, 0.0009, 0.0009,
                                 0.0008, 0.0008, 0.0007, 0.0007,
                                 0.0006, 0.0006, 0.0005, 0.0004};

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();

  std::vector<double> flux = test.getNeutronFlux();
  bool areEqual = std::equal(refFlux.begin(), refFlux.end(), flux.begin());

  EXPECT_TRUE(areEqual);
  EXPECT_DOUBLE_EQ(test.getKEff(),  kEffRef);
}

TEST_F(IntegrationTests, Kinetics1)
{	
  const std::string codePath   = "./app/app";
  const std::string inputPath  = "inputs/kinetics1.txt";
  const std::string outputPath = "outputs/Out_kinetics1.txt";
  const std::string traceLevel = "DEBUG";

  const double powerRef = 1.339142691;

  TestHelper test(codePath, inputPath, outputPath, traceLevel);
  test.runCode();
  
  EXPECT_DOUBLE_EQ(test.getVector("Output power").back(),  powerRef);
}
