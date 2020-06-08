#pragma once
#include <vector>

enum class Status
{
	NONE,
	BORN,
	LIVE,
	DIED
};


class Cell
{
public:
	Cell() {}

	Cell(int x, int y) {
		this->x = x;
		this->y = y;
		status = Status::NONE;
	}


	Status status;
	int x;
	int y;
	std::vector<Cell*> nearCells;

	static COLORREF getColor(Status status);

	void step1();
	void step2();
	bool isLivedCell();
	int countNearLivedCell();
	void turn();
};
