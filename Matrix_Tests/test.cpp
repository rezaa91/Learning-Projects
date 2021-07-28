#include "pch.h"

#include "Matrix.h"

using Mat2_t = std::array<int, 4>;
using Mat2_float_t = std::array<float, 4>;

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
	int arr[4] = { 1, 2, 2, 3 };
	Matrix::Mat2<int> mat(arr);
	Mat2_t expected = { 2, 4, 4, 6 };
	mat * 2;


	auto* result = mat.getMatrix()[0];
	for (size_t i = 0; i < 4; i++)
	{
		EXPECT_EQ(result[i] , expected[i]);
	}
}

TEST_F(MatrixTest, multipliesFloatMatrixByScalar)
{
	float arr[4] = { 1.1f, 2.2f, 2.2f, 3.3f };
	Matrix::Mat2<float> mat(arr);
	Mat2_float_t expected = { 2.2f, 4.4f, 4.4f, 6.6f };
	mat * 2;

	for (size_t i = 0; i < 4; i++)
	{
		EXPECT_EQ(mat.getMatrix()[i], expected[i]);
	}
}

TEST_F(MatrixTest, multipliesMatrices)
{
	int arr1[4] = { 0, 2, 2, 1 };
	Matrix::Mat2<int> mat1(arr1);
	int arr2[4] = { 1, 2, 3, 2 };
	Matrix::Mat2<int> mat2(arr2);
	Mat2_t expected = {6, 4, 5, 6};
	mat1 * mat2;

	for (size_t i = 0; i < 4; i++)
	{
		EXPECT_EQ(mat1.getMatrix()[i], expected[i]);
	}
}

TEST_F(MatrixTest, matrixAddition)
{
	int arr1[4] = { 1, 1, 2, 4 };
	Matrix::Mat2<int> mat1(arr1);
	int arr2[4] = { 2, 0, 1, 4 };
	Matrix::Mat2<int> mat2(arr2);
	Mat2_t expected({ 3, 1, 3, 8 });
	mat1 + mat2;

	for (size_t i = 0; i < 4; i++)
	{
		EXPECT_EQ(mat1.getMatrix()[i], expected[i]);
	}
}

TEST_F(MatrixTest, matrixFloatAddition)
{
	float arr1[4] = { 1.0f, 1.0f, 2.0f, 4.0f };
	Matrix::Mat2<float> mat1(arr1);
	float arr2[4] = { 2.1f, 1.1f, 4.4f, 0.0f };
	Matrix::Mat2<float> mat2(arr2);
	Mat2_float_t expected({ 3.1f, 2.1f, 6.4f, 4.0f });
	mat1 + mat2;

	for (size_t i = 0; i < 4; i++)
	{
		EXPECT_EQ(mat1.getMatrix()[i], expected[i]);
	}
}
