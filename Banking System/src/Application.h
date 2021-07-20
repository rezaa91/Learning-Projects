#pragma once

#include "Display.h"
#include "Bank.h"

#if _DEBUG
#define LOG(x) { std::cout << (x) << std::endl; }
#else
#define LOG
#endif // _DEBUG

namespace Banking
{
	class Application
	{
	public:
		Application();
		void init();
		~Application();
	private:
		void processInput(unsigned int option);
		Display* display;
		Bank* account;
	};
}
