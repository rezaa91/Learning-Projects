#include "Bank.h"

Banking::Bank::Bank(double currentAmount)
	:currentAmount(currentAmount)
{}

void Banking::Bank::withdraw(double cashToWithdraw)
{
	if (this->hasFundsToWithdraw(cashToWithdraw))
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

bool Banking::Bank::hasFundsToWithdraw(double cash) const
{
	return this->currentAmount >= cash;
}
