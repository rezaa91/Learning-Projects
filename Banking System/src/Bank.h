#pragma once

namespace Banking
{
	class Bank
	{
	public:
		explicit Bank(double currentAmount);
		double getBalance() const;
		void withdraw(double cash);
		void deposit(double cash);
		bool hasFundsToWithdraw(double cash) const;
	private:
		double currentAmount;
	};
}

