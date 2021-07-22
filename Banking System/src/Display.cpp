#include "Display.h"

void Banking::Display::setOptions(const options_t& options)
{
	this->options = options;
}

void Banking::Display::print() const
{
	unsigned int optionNumber = 1;
	for (auto option : this->options)
	{
		std::cout << optionNumber++ << ".\t" << option << std::endl;
	}
}

int Banking::Display::getOption() const
{
	int optionSelected;
	std::cin >> optionSelected;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return -1;
	}

	return optionSelected;
}

void Banking::Display::output(const std::string& output) const
{
	std::cout << "\t>> " << output << std::endl;
}
