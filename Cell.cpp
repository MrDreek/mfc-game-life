#include "pch.h"
#include "Cell.h"


void Cell::step1() {
	int arround = this->countNearLivedCell();

	switch (this->status) {
		case Status::NONE: (arround == 3) ? this->status = Status::BORN : this->status = Status::NONE; break;
		case Status::LIVE: (arround < 2 || arround > 3) ? this->status = Status::DIED : this->status = Status::LIVE; break;
	}
}

void Cell::step2() {
	switch (this->status) {
		case Status::BORN: this->status = Status::LIVE; break;
		case Status::DIED: this->status = Status::NONE; break;
	}
}

COLORREF Cell::getColor(Status status)
{
	switch (status) {
		case Status::NONE: return Config::BLACK;
		case Status::LIVE: return Config::WHITE;
		case Status::BORN: return Config::WHITE;
		case Status::DIED: return Config::BLACK;
	}
	return RGB(139, 69, 19); // BROWN
}

bool Cell::isLivedCell()
{
	return this->status == Status::LIVE || this->status == Status::DIED;
}

int Cell::countNearLivedCell()
{
	int count = 0;

	int size = nearCells.size();
	for (int i = 0; i < size; i++) {
		if ((*nearCells[i]).isLivedCell()) {
			count++;
		}
	}
	return count;
}

void Cell::turn() {
	auto size = nearCells.size();
	for (int i = 0; i < size; i++) {
		nearCells[i]->status = nearCells[i]->isLivedCell() ? Status::NONE : Status::LIVE;
	}
}

void Cell::flip() {
	this->status = this->isLivedCell() ? Status::NONE : Status::LIVE;
}