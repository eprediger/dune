#include "Cursor.h"

Cursor::Cursor() :
	initial_x(0),
	initial_y(0),
	current_x(0),
	current_y(0) {}

Cursor::~Cursor() {}

void Cursor::initialPosition() {
	SDL_GetMouseState(&this->initial_x, &this->initial_y);
}

void Cursor::currentPosition() {
	SDL_GetMouseState(&this->current_x, &this->current_y);
}

bool Cursor::notMoving() {
	return ((this->current_x == this->initial_x) && (this->current_y == this->initial_y));
}
