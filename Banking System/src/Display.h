#pragma once

#include <iostream>
#include <vector>

using options_t = std::vector<std::string>;

namespace Banking {
	class Display
	{
	public:
		Display() = default;
		void setOptions(const options_t& options);
		void print() const;
		int getOption() const;
		void output(const std::string& output) const;
	private:
		options_t options;
	};
}

