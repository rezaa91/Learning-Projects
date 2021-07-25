#pragma once

class Grid
{
public:
	Grid(const uint32_t rows, const uint32_t cols);
	void draw() const;
	void setState(const int index, const char symbol);
	std::vector<int> getFreeStates() const;
	bool isGameOver(bool playersTurn, const int lastChoice);
	bool isFinished() const;
private:
	const uint32_t rows;
	const uint32_t cols;
	std::array<uint8_t, 9> states;
	bool finished;
};

