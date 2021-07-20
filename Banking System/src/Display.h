#pragma once

#include <iostream>
#include <vector>

using options_t = std::vector<std::string>;

namespace Banking {
	class Display
	{
	public:
		explicit Display(const options_t& options);
		void print() const;
		unsigned int getOption() const;
		void output(const std::string& output) const;
	private:
		const options_t& options;
	};
}

