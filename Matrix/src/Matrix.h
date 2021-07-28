#pragma once

#include <array>

namespace Matrix {

	template<typename Mat2>
	class Mat2Iterator
	{
	public:
		using ValueType = typename Mat2::ValueType;
		using PointerType = ValueType*;
		using ReferenceType = ValueType&;

	public:
		Mat2Iterator(PointerType ptr)
			: m_Ptr(ptr) {}

	public:
		Mat2Iterator& operator++()
		{
			m_Ptr++;
			return *this;
		}

		Mat2Iterator operator++(int)
		{
			Mat2Iterator iterator = *this;
			++(*this);
			return iterator;
		}

		Mat2Iterator& operator--()
		{
			m_Ptr--;
			return *this;
		}

		Mat2Iterator operator--(int)
		{
			Mat2Iterator iterator = *this;
			--(*this);
			return iterator;
		}

		ReferenceType operator[](int index)
		{
			return *(m_Ptr + index);
		}

		PointerType operator->()
		{
			return m_Ptr;
		}

		ReferenceType operator*()
		{
			return *m_Ptr;
		}

		bool operator==(const Mat2Iterator& other) const
		{
			return m_Ptr == other.m_Ptr;
		}

		bool operator!=(const Mat2Iterator& other) const
		{
			return !(*this == other);
		}

	private:
		PointerType m_Ptr;
	};

	template<typename T>
	class Mat2
	{
	public:
		using Mat2_t = T[4];
		using ValueType = T;
		using Iterator = Mat2Iterator<Mat2<T>>; // TODO - look in to this syntax

	public:
		Mat2(const Mat2_t matrix)
		{
			memcpy(this->matrix, matrix, sizeof(T) * 4);
		}

		void print() const
		{
			size_t i = 0;
			std::cout << "==========\n";
			for (auto entry : this->matrix)
			{
				std::cout << "| " << entry << " |";
				if (i == 1)
					std::cout << "\n==========\n";
				i++;
			}
			std::cout << "\n==========\n";
		}

		Mat2_t* getMatrix()
		{
			return &this->matrix;
		}
	public:
		Mat2& operator*(const int scalar)
		{
			for (auto& entry : this->matrix)
			{
				entry *= scalar;
			}
			return *this;
		}

		Mat2& operator*(const Mat2& other)
		{
			const int tmp_0 = this->matrix[0];
			const int tmp_1 = this->matrix[1];
			const int tmp_2 = this->matrix[2];
			const int tmp_3 = this->matrix[3];

			this->matrix[0] = (tmp_0 * other.matrix[0]) + (tmp_1 * other.matrix[2]);
			this->matrix[1] = (tmp_0 * other.matrix[1]) + (tmp_1 * other.matrix[3]);
			this->matrix[2] = (tmp_2 * other.matrix[0]) + (tmp_3 * other.matrix[2]);
			this->matrix[3] = (tmp_2 * other.matrix[1]) + (tmp_3 * other.matrix[3]);

			return *this;
		}

		Mat2& operator+(const Mat2& other)
		{
			const size_t cells = 4;
			for (size_t i = 0; i < cells; i++)
			{
				this->matrix[i] += other.matrix[i];
			}
			return *this;
		}

	public:
		Iterator begin()
		{
			return Iterator(matrix);
		}

		Iterator end()
		{
			return Iterator(matrix + 4);
		}
		
	private:
		Mat2_t matrix;
	};
}
