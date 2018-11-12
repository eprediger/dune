#include "GameHandler.h"
#include <iostream>

GameHandler::GameHandler(View& view) :
	InputHandler(),
	view(view) {}
	// model(model) {}

GameHandler::~GameHandler() {}

bool GameHandler::handleInput() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			return false;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT) {
				this->cursor.initialPosition();
				// std::cout << "Click en x: " << this->cursor.initial_x << " y: " << this->cursor.initial_y << std::endl;
			}
			break;
		case SDL_MOUSEMOTION:
			if (event.button.button == SDL_BUTTON_LEFT) {
				this->cursor.currentPosition();
				// std::cout << "Moviendo en x: " << this->cursor.current_x << " y: " << this->cursor.current_y << std::endl;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT) {
				this->cursor.currentPosition();
				// std::cout << "Suelta en x: " << this->cursor.current_x << " y: " << this->cursor.current_y << std::endl;
			}
			break;
	}
	return true;
}
