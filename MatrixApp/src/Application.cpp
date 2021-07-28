#include <iostream>
#include <array>

#include "Matrix.h"

int main()
{
	int arr1[4] = { 1, 3, 2, 2 };
	Matrix::Mat2<int> matrix1(arr1);
	int arr2[4] = { 0, 2, 1, 1 };
	Matrix::Mat2<int> matrix2(arr2);

	std::cout << "Matrix multiplication by scalar\n";
	matrix1 * 2;
	std::cout << "Expected: 2, 6, 4, 4\n";
	matrix1.print();

	std::cout << "\n\nMatrix addition\n";
	std::cout << "Expected: 2, 8, 5, 5\n";
	matrix1 + matrix2;
	matrix1.print();


	std::cout << "\n\nMatrix multiplication by matrix\n";
	int arr3[4] = { 1, 2, 3, 4 };
	int arr4[4] = { 0, 2, 2, 1 };
	Matrix::Mat2<int> matrix3(arr3);
	Matrix::Mat2<int> matrix4(arr4);

	//1 2    0 2        4 4
    //3 4    2 1        8 10

	//0 2  1 2          6 8
	//2 1  3 4          5 8

	matrix3 * matrix4;
	std::cout << "Expected: 4, 4, 8, 10\n";
	matrix3.print();

	auto a = matrix1.getMatrix();

	std::cin.get();
}