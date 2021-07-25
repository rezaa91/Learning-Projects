#include "pch.h"
#include "Grid.h"

Grid::Grid(const uint32_t rows, const uint32_t cols)
	:rows(rows), cols(cols), finished(false)
{
	this->states = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
}

void Grid::draw() const
{
	std::cout << "====================================\n";
	uint8_t index = 1;
	for (auto& state : this->states)
	{
		std::cout << "|    " << state << "     |";

		if (index++ % 3 == 0)
		{
			std::cout << std::endl;
			std::cout << "====================================\n";
		}
	}
}

bool Grid::isFinished() const
{
	return this->finished;
}

void Grid::setState(const int index, const char symbol)
{
	this->states.at(index) = symbol;
}

std::vector<int> Grid::getFreeStates() const
{
	using State_t = std::array<uint8_t, 9>;
	std::vector<int> freeStates;

	for (State_t::const_iterator it = this->states.begin(); it != this->states.end(); it++)
	{
		if (*it == ' ')
		{
			int index = std::distance(this->states.begin(), it);
			freeStates.push_back(index + 1); // +1 to account for 0 indexing
		}
	}

	// DEBUG PURPOSES
	std::cout << "Available moves: ";
	for (auto cell : freeStates)
	{
		std::cout << cell << " ";
	}
	std::cout << std::endl;

	return freeStates;
}

bool Grid::isGameOver(bool playersTurn, const int lastChoice)
{
	if (this->getFreeStates().size() == 0)
	{
		this->finished = true;
	}

	char symbol = playersTurn ? 'X' : '0';

	// Logic
	// Check most recent move
	// That most recent move must be included in the win (to narrow search)
	// check for row, column and diag win
	// a row will be either: +1 +2, -1 -2, -1 +1
	// a column will either be: +3 +6, -3 -6, -3 +3
	// a diag will either be: indexes 1 3 5

	return false;
}
