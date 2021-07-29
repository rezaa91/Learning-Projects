#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<typename T>
void printItem(T item)
{
	std::cout << item << std::endl;
}

class Item;

using items_t = std::vector<Item>;

class Item
{
public:
	Item(const std::string& name)
		:name(name), complete(false) {}

	void markAsComplete()
	{
		this->complete = true;
	}

	bool isComplete() const
	{
		return this->complete;
	}

	const std::string getName() const
	{
		return this->name;
	}

	void printInfo() const
	{
		std::cout << "\"" << this->name << "\" is " << (this->complete ? " " : "not ") << "complete" << std::endl;
	}

	bool operator< (const Item& other) const
	{
		return this->name < other.name;
	}

	bool operator> (const Item& other) const
	{
		return this->name > other.name;
	}

	bool operator==(const Item& other) const
	{
		return this->isComplete() == other.isComplete();
	}

private:
	std::string name;
	bool complete;
};

void printItems(const items_t& items)
{
	std::cout << "========================================\n";
	std::for_each(items.begin(), items.end(), [](Item item) {
		item.printInfo();
		});
	std::cout << "========================================\n";
};

int main()
{

	// VECTORS
	Item itemOne("A item one");
	Item itemTwo("B item two");
	Item itemThree("C item three");
	Item itemFour("D item four");
	Item itemFive("E item five");

	itemTwo.markAsComplete();
	itemFive.markAsComplete();

	items_t items;
	items.push_back(itemTwo);
	items.push_back(itemOne);
	items.push_back(itemFive);
	items.push_back(itemThree);
	items.push_back(itemFour);

	printItems(items);

	// sort alphabetically - asc
	std::sort(items.begin(), items.end());
	printItems(items);

	// show incomplete
	items.erase(std::remove_if(items.begin(), items.end(), [](Item item) {
		return item.isComplete();
		}), items.end());
	printItems(items);

	bool allIncomplete = std::all_of(items.begin(), items.end(), [](Item item) {
		return !item.isComplete();
		});
	std::cout << 1 << " == " << allIncomplete << std::endl;

	bool someComplete = std::any_of(items.begin(), items.end(), [](Item item) {
		return item.isComplete();
		});
	std::cout << 0 << " == " << someComplete << std::endl;



	// SCALAR VECTORS
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

