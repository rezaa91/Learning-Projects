#include <iostream>
#include <cassert>

template<int N>
class MultiplyBy
{
public:
	constexpr int operator() (const int x) const
	{
		return this->multiplier * x;
	}

private:
	const int multiplier = N;
};

int main()
{
	constexpr MultiplyBy<2> multiplyBy2;

	static_assert(multiplyBy2(2) == 4, "Does not equal 4");
	static_assert(multiplyBy2(16) == 32, "Does not equal 32");

	std::cin.get();
}
