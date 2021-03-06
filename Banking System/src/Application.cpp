#include "Application.h"

#include <iostream>
#include <iomanip> // for setprecision
#include <sstream> // for std::stream

Banking::Application::Application()
	:account(Bank(100)),display(Display())
{
}

void Banking::Application::init()
{
	LOG("App initialised");

	options_t options =
	{
		"View Balance",
		"Deposit",
		"Withdraw",
		"Exit"
	};

	this->display.setOptions(options);

	unsigned int userOption = -1;
	while (userOption != 4)
	{
		this->display.print();
		userOption = this->display.getOption();
		system("cls");
		this->processInput(userOption);
		std::cout << std::endl;
	}

	std::cout << "See you soon." << std::endl;
}

// TODO extract into multiple functions
void Banking::Application::processInput(unsigned int option)
{
	std::string output;

	switch (option)
	{
	case 1:
	{
		std::stringstream stream;
		stream << "Balance: " << std::fixed << std::setprecision(2) << this->account.getBalance();
		return this->display.output(stream.str());
	}
	case 2:
	{
		std::cout << "How much would you like to deposit?" << std::endl;
		double depositAmount;
		std::cin >> depositAmount;

		if (std::cin.fail())
		{
			LOG("Deposit validation failed!");
			std::cin.clear(); // clears the error flag
			std::cin.ignore(1000, '\n'); // clear the buffer on the current line (up to 1000 chars)
			return this->display.output("Invalid input received!");
		}
		this->account.deposit(depositAmount);
		std::stringstream stream;
		stream << "Deposited " << std::fixed << std::setprecision(2) << depositAmount;
		return this->display.output(stream.str());
	}
	case 3:
	{
		std::cout << "How much would you like to withdraw?" << std::endl;
		double withdrawAmount;
		std::cin >> withdrawAmount;

		if (std::cin.fail())
		{
			LOG("Withdraw validation failed!");
			std::cin.clear(); // clears the error flag
			std::cin.ignore(1000, '\n'); // clear the buffer on the current line (up to 1000 chars)
			return this->display.output("Invalid input received!");
		}
		std::numeric_limits<std::streamsize>::max(); // clear the buffer

		if (this->account.hasFundsToWithdraw(withdrawAmount))
		{
			this->account.withdraw(withdrawAmount);
			std::stringstream stream;
			stream << "Withdrawn " << std::fixed << std::setprecision(2) << withdrawAmount;
			return this->display.output(stream.str());
		}
		else {
			return this->display.output("Not enough funds!");
		}
	}
	default:
		return this->display.output("Invalid option!");
	}
}
