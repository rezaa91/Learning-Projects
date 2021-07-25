#include "pch.h"
#include "Application.h"
#include "Grid.h"

int getRandomNumber(const int min, const int max)
{
	std::random_device rd; // used as the seed for the mt19937 random number generator
	std::mt19937 engine(rd()); // randomg number generator
	std::uniform_int_distribution<int> distrib(min, max); // set min and max values for random number

	return distrib(engine);
}

void Application::run() const
{
	AppDetails_t details = this->details();
	std::cout << details.at("displayName") << "\n";
	std::cout << details.at("rules") << "\n\n";

	// Decide who goes first - player or computer
	bool playersTurn = true;
	std::cout << "Do you wish to go first? [Y/n] ";
	if (std::cin.get() != '\n')
	{
		uint8_t input = std::cin.get();
		playersTurn = input == 'n';
	}
	std::cout << (playersTurn ? "Player" : "Computer") << " goes first" << std::endl;


	// Draw grid and begin game
	Grid grid(3, 3);

	while (!grid.isFinished())
	{
		system("cls");
		grid.draw();
		std::vector<int> freeCells = grid.getFreeStates();
		int choice;

		if (playersTurn)
		{
			std::cout << "Your Turn\n\n";
			bool invalidChoice = true;

			while (invalidChoice)
			{
				std::cout << "Where would you like to go? [1-9] ";
				std::cin >> choice;

				if (std::cin.fail())
				{
					std::cerr << "Invalid input received\n";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}
				else if (choice < 1 || choice > 9) {
					std::cerr << "Invalid input received: " << choice << std::endl;
				}
				else if (std::find(freeCells.begin(), freeCells.end(), choice) == freeCells.end()) { // check if choice has already been selected
					std::cerr << "That option has already been chosen. Try again.." << std::endl;
				}
				else {
					invalidChoice = false;
					grid.setState(choice - 1, 'X'); // -1 to account for 0 indexing
				}
			}
		}
		else {
			std::cout << "Computer is thinking...\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
			int randomIndex = getRandomNumber(0, freeCells.size() - 1);
			choice = freeCells.at(randomIndex);
			grid.setState(choice- 1, '0');
		}

		grid.isGameOver(playersTurn, choice - 1);
		playersTurn = !playersTurn;
	}

	grid.draw();
	std::cout << "\n\nThank you for playing." << std::endl;

}

AppDetails_t Application::details() const {
	return {
		{"name", "Tic Tac Toe"},
		{"displayName", "TIC TAC TOE"},
		{"rules", "Get 3 in a row to win. Each cell has a numerical representation from 1-9.\nPlayer(X)\t Computer(0)"}
	};
}
