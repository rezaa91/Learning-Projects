#include "Matrix.h"

#include <iostream>

namespace Matrix {
	
	Mat2::Mat2(const std::array<int, 4> matrix)
		:matrix(matrix)
	{
	}

	Mat2& Mat2::operator*(const int scalar)
	{
		for (auto& entry : this->matrix)
		{
			entry *= scalar;
		}
		return *this;
	}

	Mat2& Mat2::operator+(const Mat2& other)
	{
		const size_t cells = 4;
		for (size_t i = 0; i < cells; i++)
		{
			this->matrix.at(i) += other.matrix.at(i);
		}
		return *this;
	}

	Mat2& Mat2::operator*(const Mat2& other)
	{
		const int tmp_0 = this->matrix.at(0);
		const int tmp_1 = this->matrix.at(1);
		const int tmp_2 = this->matrix.at(2);
		const int tmp_3 = this->matrix.at(3);

		this->matrix.at(0) = (tmp_0 * other.matrix.at(0)) + (tmp_1 * other.matrix.at(2));
		this->matrix.at(1) = (tmp_0 * other.matrix.at(1)) + (tmp_1 * other.matrix.at(3));
		this->matrix.at(2) = (tmp_2 * other.matrix.at(0)) + (tmp_3 * other.matrix.at(2));
		this->matrix.at(3) = (tmp_2 * other.matrix.at(1)) + (tmp_3 * other.matrix.at(3));

		return *this;
	}

	void Mat2::print() const
	{
		using Matrix_t = std::array<int, 4>;

		size_t index = 0;
		std::cout << "==========\n";
		for (Matrix_t::const_iterator it = matrix.begin(); it != matrix.end(); it++)
		{
			std::cout << "| " << *it << " |";
			if (index == 1)
			{
				std::cout << "\n==========\n";
			}
			index++;
		}
		std::cout << "\n==========\n";
	}
}
