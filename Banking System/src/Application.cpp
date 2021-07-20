#include "Application.h"

#include <iostream>
#include <string>

Banking::Application::Application()
{
	this->account = nullptr;
	this->display = nullptr;
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

	this->display = new Display(options);
	this->account = new Bank(100);

	unsigned int userOption = -1;
	while (userOption != 4)
	{
		this->display->print();
		userOption = this->display->getOption();
		system("cls");
		this->processInput(userOption);
		std::cout << std::endl;
	}

	std::cout << "See you soon." << std::endl;
}

void Banking::Application::processInput(unsigned int option)
{
	std::string output;

	switch (option)
	{
	case 1:
		return this->display->output(std::to_string(this->account->getBalance()));
	case 2:
	{
		std::cout << "How much would you like to deposit?" << std::endl;
		double depositAmount;
		std::cin >> depositAmount;
		this->account->deposit(depositAmount);
		output = "deposited " + std::to_string(depositAmount);
		return this->display->output(output);
	}
	case 3:
	{
		std::cout << "How much would you like to withdraw?" << std::endl;
		double withdrawAmount;
		std::cin >> withdrawAmount;
		this->account->withdraw(withdrawAmount);
		output = "Withdrawn " + std::to_string(withdrawAmount);
		return this->display->output(output);
	}
	}
}

Banking::Application::~Application()
{
	delete this->display;
	delete this->account;
	LOG("Application cleaned up.");
}
