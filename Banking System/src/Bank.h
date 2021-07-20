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
	private:
		double currentAmount;
	};
}

