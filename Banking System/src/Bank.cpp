#include "Bank.h"

Banking::Bank::Bank(double currentAmount)
	:currentAmount(currentAmount)
{}

void Banking::Bank::withdraw(double cashToWithdraw)
{
	if (cashToWithdraw <= this->currentAmount)
	{
		this->currentAmount -= cashToWithdraw;
	}
}

void Banking::Bank::deposit(double cashToDeposit)
{
	this->currentAmount += cashToDeposit;
}

double Banking::Bank::getBalance() const
{
	return this->currentAmount;
}
