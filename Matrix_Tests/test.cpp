#include "pch.h"

#include "Matrix.h"

class MatrixTest : public ::testing::Test
{
protected:
	MatrixTest() {
		// set up
	};

	~MatrixTest() override {
		// clean up
	};

	void SetUp() override {
		// called after constructor and before each test
	};
	
	void TearDown() override {
		// called immeadiately after each test (right before destructor)
	};
};

TEST_F(MatrixTest, multipliesByScalar)
{
	Matrix::Mat2 mat({ 1, 2, 2, 3 });
	Matrix::Mat2_t expected = { 2, 4, 4, 6 };
	mat * 2;

	EXPECT_EQ(mat.matrix.size(), expected.size());

	for (size_t i = 0; i < 4; i++)
	{
		EXPECT_EQ(mat.matrix[i], expected[i]);
	}
}

TEST_F(MatrixTest, multipliesMatrices)
{
	Matrix::Mat2 mat1({ 0, 2, 2, 1 });
	Matrix::Mat2 mat2({ 1, 2, 3, 2 });
	Matrix::Mat2_t expected = {6, 4, 5, 6};
	mat1 * mat2;

	EXPECT_EQ(mat1.matrix.size(), expected.size()) << "matrix is an unexpected size.";

	for (size_t i = 0; i < 4; i++)
	{
		EXPECT_EQ(mat1.matrix[i], expected[i]) << "value " << mat1.matrix[i] << " at position [" << i << "] does not match expected " << expected[i];
	}
}

TEST_F(MatrixTest, matrixAddition)
{
	Matrix::Mat2 mat1({ 1, 1, 2, 4 });
	Matrix::Mat2 mat2({ 2, 0, 1, 4 });
	Matrix::Mat2_t expected({ 3, 1, 3, 8 });
	mat1 + mat2;

	EXPECT_EQ(mat1.matrix.size(), expected.size()) << "Matrix is unexpected size.";

	for (size_t i = 0; i < 4; i++)
	{
		EXPECT_EQ(mat1.matrix[i], expected[i]) << "Unexpected value " << mat1.matrix[i] << " at position [" << i << "]";
	}
}
