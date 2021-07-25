#include <iostream>
#include <array>

#include "Matrix.h"

int main()
{
	Matrix::Mat2 matrix1({1, 3, 2, 2});
	Matrix::Mat2 matrix2({ 0, 2, 1, 1 });

	std::cout << "Matrix multiplication by scalar\n";
	matrix1 * 2;
	matrix1.print();

	std::cout << "\n\nMatrix addition\n";
	matrix1 + matrix2;
	matrix1.print();

	std::cout << "\n\nMatrix multiplication by matrix";
	Matrix::Mat2 mat1({ 1, 2, 3, 4 });
	Matrix::Mat2 mat2({ 0, 2, 2, 1 });

	//1 2    0 2        4 4
    //3 4    2 1        8 10

	//0 2  1 2          6 8
	//2 1  3 4          5 8

	mat1 * mat2;
	std::cout << "Expected: 4, 4, 8, 10\n";
	mat1.print();

	std::cin.get();
}