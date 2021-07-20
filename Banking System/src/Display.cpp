#include "Display.h"

Banking::Display::Display(const options_t& options)
	:options(options)
{}

void Banking::Display::print() const
{
	unsigned int optionNumber = 1;
	for (auto option : this->options)
	{
		std::cout << optionNumber++ << ".\t" << option << std::endl;
	}
}

unsigned int Banking::Display::getOption() const
{
	char optionSelected;
	std::cin >> optionSelected;
	return optionSelected - '0';
}

void Banking::Display::output(const std::string& output) const
{
	std::cout << "\t>> " << output << std::endl;
}
