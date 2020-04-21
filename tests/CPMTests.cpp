#include "Mesh.h"
#include "Input.h"
#include "Output.h"
#include "Library.h"
#include "gtest/gtest.h"
#include "numeric_tools.h"
#include "BaseSpectrumCode.h"
#include "SpectrumCodeFactory.h"

#include <iostream>

using namespace Eigen;

class MMatrixTest : public ::testing::Test 
{
 protected:
  virtual void SetUp() 
  {
	  out.setOutputPath("tests/testLog.txt");
	  out.createLogger("TEST");
	  out.setLevel("DEBUG");
  }
  virtual void TearDown() 
  {
	  spdlog::drop("TEST");
  }
};

TEST_F(MMatrixTest, calcMMatrixTestC3E4)
{	
	double cellSide = 1.0;
	int cells       = 3;
	int energies    = 4;
	
	Tensor3d scattMatrix = Tensor3d(energies, energies, cells);
	scattMatrix.setZero();
	
	// self scattering 0 <-> 0
	
	scattMatrix(0, 0, 0) = -8.9;
	scattMatrix(0, 0, 1) = -8.9;
	scattMatrix(0, 0, 2) = -8.9;
	
	// self scattering 1 <-> 1
	
	scattMatrix(1, 1, 0) = -0.1;
	scattMatrix(1, 1, 1) = -0.1;
	scattMatrix(1, 1, 2) = -0.1;
	
	// self scattering 2 <-> 2
	
	scattMatrix(2, 2, 0) = -1.2;
	scattMatrix(2, 2, 1) = -1.2;
	scattMatrix(2, 2, 2) = -1.2;
	
	// self scattering 3 <-> 3
	
	scattMatrix(3, 3, 0) = -2.3;
	scattMatrix(3, 3, 1) = -2.3;
	scattMatrix(3, 3, 2) = -2.3;
	
	// down scattering 0 -> 1
	
	scattMatrix(0, 1, 0) = -0.1;
	scattMatrix(0, 1, 1) = -0.1;
	scattMatrix(0, 1, 2) = -0.1;
	
	// down scattering 1 -> 2
	
	scattMatrix(1, 2, 0) = -1.2;
	scattMatrix(1, 2, 1) = -1.2;
	scattMatrix(1, 2, 2) = -1.2;
	
	// down scattering 2 -> 3
	
	scattMatrix(2, 3, 0) = -2.3;
	scattMatrix(2, 3, 1) = -2.3;
	scattMatrix(2, 3, 2) = -2.3;
	
	// down scattering 0 -> 2
	
	scattMatrix(0, 2, 0) = -0.2;
	scattMatrix(0, 2, 1) = -0.2;
	scattMatrix(0, 2, 2) = -0.2;
	
	// down scattering 1 -> 3
	
	scattMatrix(1, 3, 0) = -1.3;
	scattMatrix(1, 3, 1) = -1.3;
	scattMatrix(1, 3, 2) = -1.3;
	
	// down scattering 0 -> 3
	
	scattMatrix(0, 3, 0) = -0.3;
	scattMatrix(0, 3, 1) = -0.3;
	scattMatrix(0, 3, 2) = -0.3;
	
	// up scattering 1 -> 0
	
	scattMatrix(1, 0, 0) = -1.0;
	scattMatrix(1, 0, 1) = -1.0;
	scattMatrix(1, 0, 2) = -1.0;
	
	// up scattering 2 -> 1
	
	scattMatrix(2, 1, 0) = -2.1;
	scattMatrix(2, 1, 1) = -2.1;
	scattMatrix(2, 1, 2) = -2.1;
	
	// up scattering 3 -> 2
	
	scattMatrix(3, 2, 0) = -3.2;
	scattMatrix(3, 2, 1) = -3.2;
	scattMatrix(3, 2, 2) = -3.2;
	
	// up scattering 2 -> 0
	
	scattMatrix(2, 0, 0) = -2.0;
	scattMatrix(2, 0, 1) = -2.0;
	scattMatrix(2, 0, 2) = -2.0;
	
	// up scattering 3 -> 1
	
	scattMatrix(3, 1, 0) = -3.1;
	scattMatrix(3, 1, 1) = -3.1;
	scattMatrix(3, 1, 2) = -3.1;
	
	// up scattering 3 -> 0
	
	scattMatrix(3, 0, 0) = -3.0;
	scattMatrix(3, 0, 1) = -3.0;
	scattMatrix(3, 0, 2) = -3.0;
	
	Mesh problem;
	Library library;
	Input input(problem, library);
	
	CrossSectionSet XSSet;
	XSSet.setScattMatrix(scattMatrix);
	library.setCrossSectionSet(XSSet);
	
	MatrixXd cpm = MatrixXd::Identity(cells * energies, cells * energies);
	
	problem.setMeshKind(GeomKind::CYLINDER);
	problem.setBoundaries(cellSide, cells); 
	problem.setEnergyGroupsNumber(energies);
	
	std::shared_ptr<BaseSpectrumCode> spectrumCode = SpectrumCodeFactory::setSpectrumCode(problem, library);
	MatrixXd MMatrix = spectrumCode->calcMMatrix(cpm);
	
  EXPECT_DOUBLE_EQ(MMatrix(0,  0), 9.9);
	EXPECT_DOUBLE_EQ(MMatrix(0,  1), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(0,  2), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(0,  3), 1.0);
	EXPECT_DOUBLE_EQ(MMatrix(0,  4), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(0,  5), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(0,  6), 2.0);
	EXPECT_DOUBLE_EQ(MMatrix(0,  7), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(0,  8), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(0,  9), 3.0);
	EXPECT_DOUBLE_EQ(MMatrix(0, 10), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(0, 11), 0.0);
	
	EXPECT_DOUBLE_EQ(MMatrix(1,  0), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(1,  1), 9.9);
	EXPECT_DOUBLE_EQ(MMatrix(1,  2), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(1,  3), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(1,  4), 1.0);
	EXPECT_DOUBLE_EQ(MMatrix(1,  5), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(1,  6), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(1,  7), 2.0);
	EXPECT_DOUBLE_EQ(MMatrix(1,  8), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(1,  9), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(1, 10), 3.0);
	EXPECT_DOUBLE_EQ(MMatrix(1, 11), 0.0);
	
	EXPECT_DOUBLE_EQ(MMatrix(2,  0), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(2,  1), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(2,  2), 9.9);
	EXPECT_DOUBLE_EQ(MMatrix(2,  3), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(2,  4), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(2,  5), 1.0);
	EXPECT_DOUBLE_EQ(MMatrix(2,  6), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(2,  7), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(2,  8), 2.0);
	EXPECT_DOUBLE_EQ(MMatrix(2,  9), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(2, 10), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(2, 11), 3.0);
	
	EXPECT_DOUBLE_EQ(MMatrix(3,  0), 0.1);
	EXPECT_DOUBLE_EQ(MMatrix(3,  1), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(3,  2), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(3,  3), 1.1);
	EXPECT_DOUBLE_EQ(MMatrix(3,  4), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(3,  5), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(3,  6), 2.1);
	EXPECT_DOUBLE_EQ(MMatrix(3,  7), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(3,  8), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(3,  9), 3.1);
	EXPECT_DOUBLE_EQ(MMatrix(3, 10), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(3, 11), 0.0);
	
    EXPECT_DOUBLE_EQ(MMatrix(4,  0), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(4,  1), 0.1);
	EXPECT_DOUBLE_EQ(MMatrix(4,  2), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(4,  3), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(4,  4), 1.1);
	EXPECT_DOUBLE_EQ(MMatrix(4,  5), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(4,  6), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(4,  7), 2.1);
	EXPECT_DOUBLE_EQ(MMatrix(4,  8), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(4,  9), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(4, 10), 3.1);
	EXPECT_DOUBLE_EQ(MMatrix(4, 11), 0.0);
	
	EXPECT_DOUBLE_EQ(MMatrix(5,  0), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(5,  1), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(5,  2), 0.1);
	EXPECT_DOUBLE_EQ(MMatrix(5,  3), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(5,  4), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(5,  5), 1.1);
	EXPECT_DOUBLE_EQ(MMatrix(5,  6), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(5,  7), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(5,  8), 2.1);
	EXPECT_DOUBLE_EQ(MMatrix(5,  9), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(5, 10), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(5, 11), 3.1);
	
	EXPECT_DOUBLE_EQ(MMatrix(6,  0), 0.2);
	EXPECT_DOUBLE_EQ(MMatrix(6,  1), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(6,  2), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(6,  3), 1.2);
	EXPECT_DOUBLE_EQ(MMatrix(6,  4), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(6,  5), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(6,  6), 2.2);
	EXPECT_DOUBLE_EQ(MMatrix(6,  7), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(6,  8), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(6,  9), 3.2);
	EXPECT_DOUBLE_EQ(MMatrix(6, 10), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(6, 11), 0.0);
	
	EXPECT_DOUBLE_EQ(MMatrix(7,  0), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(7,  1), 0.2);
	EXPECT_DOUBLE_EQ(MMatrix(7,  2), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(7,  3), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(7,  4), 1.2);
	EXPECT_DOUBLE_EQ(MMatrix(7,  5), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(7,  6), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(7,  7), 2.2);
	EXPECT_DOUBLE_EQ(MMatrix(7,  8), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(7,  9), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(7, 10), 3.2);
	EXPECT_DOUBLE_EQ(MMatrix(7, 11), 0.0);
	
    EXPECT_DOUBLE_EQ(MMatrix(8,  0), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(8,  1), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(8,  2), 0.2);
	EXPECT_DOUBLE_EQ(MMatrix(8,  3), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(8,  4), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(8,  5), 1.2);
	EXPECT_DOUBLE_EQ(MMatrix(8,  6), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(8,  7), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(8,  8), 2.2);
	EXPECT_DOUBLE_EQ(MMatrix(8,  9), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(8, 10), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(8, 11), 3.2);
	
	EXPECT_DOUBLE_EQ(MMatrix(9,  0), 0.3);
	EXPECT_DOUBLE_EQ(MMatrix(9,  1), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(9,  2), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(9,  3), 1.3);
	EXPECT_DOUBLE_EQ(MMatrix(9,  4), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(9,  5), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(9,  6), 2.3);
	EXPECT_DOUBLE_EQ(MMatrix(9,  7), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(9,  8), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(9,  9), 3.3);
	EXPECT_DOUBLE_EQ(MMatrix(9, 10), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(9, 11), 0.0);
	
	EXPECT_DOUBLE_EQ(MMatrix(10,  0), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(10,  1), 0.3);
	EXPECT_DOUBLE_EQ(MMatrix(10,  2), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(10,  3), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(10,  4), 1.3);
	EXPECT_DOUBLE_EQ(MMatrix(10,  5), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(10,  6), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(10,  7), 2.3);
	EXPECT_DOUBLE_EQ(MMatrix(10,  8), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(10,  9), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(10, 10), 3.3);
	EXPECT_DOUBLE_EQ(MMatrix(10, 11), 0.0);
	
    EXPECT_DOUBLE_EQ(MMatrix(11,  0), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(11,  1), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(11,  2), 0.3);
	EXPECT_DOUBLE_EQ(MMatrix(11,  3), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(11,  4), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(11,  5), 1.3);
	EXPECT_DOUBLE_EQ(MMatrix(11,  6), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(11,  7), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(11,  8), 2.3);
	EXPECT_DOUBLE_EQ(MMatrix(11,  9), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(11, 10), 0.0);
	EXPECT_DOUBLE_EQ(MMatrix(11, 11), 3.3);
}

TEST_F(MMatrixTest, calcMMatrixTestC4E1)
{
	double cellSide = 1.0;
	int cells       = 5;
	int energies    = 1;
	
	Tensor3d scattMatrix = Tensor3d(energies, energies, cells);
	scattMatrix.setZero();
	
	// self scattering 0 <-> 0
	
	scattMatrix(0, 0, 0) = -8.9;
	scattMatrix(0, 0, 1) = -8.9;
	scattMatrix(0, 0, 2) = -8.9;
	scattMatrix(0, 0, 3) = -8.9;
	scattMatrix(0, 0, 4) = -8.9;
	
	Mesh problem;
	Library library;
	Input input(problem, library);
	
	CrossSectionSet XSSet;
	XSSet.setScattMatrix(scattMatrix);
	library.setCrossSectionSet(XSSet);
	
	MatrixXd cpm = MatrixXd::Identity(cells * energies, cells * energies);
	
	problem.setMeshKind(GeomKind::CYLINDER);
	problem.setBoundaries(cellSide, cells); 
	problem.setEnergyGroupsNumber(energies);
	
	std::shared_ptr<BaseSpectrumCode> spectrumCode = SpectrumCodeFactory::setSpectrumCode(problem, library);
	MatrixXd MMatrix =spectrumCode->calcMMatrix(cpm);

	out.getLogger()->debug("MMatrix2"); //
    printMatrix(MMatrix, out, TraceLevel::DEBUG);
}