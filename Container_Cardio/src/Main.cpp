#include <iostream>
#include <algorithm>

// CONTAINERS
#include <vector>

template<typename T>
void printItem(T item)
{
	std::cout << item << std::endl;
}

int main()
{
	/*
	* VECTORS
	*/
	std::vector<int> v_Cont = { 8, 6, 2, 1, 3, 7, 10, 4, 0 };

	// sort desc
	std::sort(v_Cont.begin(), v_Cont.end(), std::greater<int>());
	std::for_each(v_Cont.begin(), v_Cont.end(), printItem<int>);
	std::cout << "================================================\n";

	// filter
	std::vector<int> v_CopyTo;
	std::copy_if(v_Cont.begin(), v_Cont.end(), std::back_inserter(v_CopyTo), [](int item) {
		return item % 2 == 0;
		});
	std::for_each(v_CopyTo.begin(), v_CopyTo.end(), printItem<int>);
	std::cout << "================================================\n";

	// mutate filter
	v_CopyTo.erase(std::remove_if(v_CopyTo.begin(), v_CopyTo.end(), [](int item) {
		return item < 5;
		}), v_CopyTo.end());
	std::for_each(v_CopyTo.begin(), v_CopyTo.end(), printItem<int>);
	std::cout << "================================================\n";

	// find
	int needle = 6;
	auto itemFound = std::find(v_Cont.begin(), v_Cont.end(), needle);
	(itemFound != std::end(v_Cont))
		? std::cout << "v_Cont contains " << needle << std::endl
		: std::cout << "v_Cont does not contain " << needle << std::endl;
	std::cout << "================================================\n";

	// merge 2 vectors
	std::vector<float> v1 = { 1.1f, 2.2f, 3.3f };
	std::vector<float> v2 = { 4.4f, 5.5f };
	v1.insert(v1.end(), v2.begin(), v2.end());
	std::for_each(v1.begin(), v1.end(), printItem<float>);
	std::cout << "================================================\n";

	// every
	std::vector<int> v_Int = { 2, 4, 6, 8 , 10 };
	bool every = std::all_of(v_Int.begin(), v_Int.end(), [](int item) {
		return item % 2 == 0;
		});
	std::cout << "All numbers are " << (every ? "even" : "not even") << std::endl;
	std::cout << "================================================\n";

	// some
	bool some = std::any_of(v_Int.begin(), v_Int.end(), [](int item) {
		return item == 8;
		});
	std::cout << "v_Int " << (some ? "includes " : "does not include ") << 8 << std::endl;
	std::cout << "================================================\n";

	std::cin.get();
}
