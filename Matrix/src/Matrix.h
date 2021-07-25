#pragma once

#include <array>

namespace Matrix {
	
	using Mat2_t = std::array<int, 4>;

	class Mat2
	{
	public:
		Mat2(const std::array<int, 4> matrix);
		Mat2& operator*(const int scalar);
		Mat2& operator*(const Mat2& other);
		Mat2& operator+(const Mat2& other);
		void print() const;

		std::array<int, 4> matrix;
	};
}
