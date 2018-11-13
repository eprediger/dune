#include "GameHandler.h"
#include "../View/UnitViewFactory.h"
#include <iostream>

GameHandler::GameHandler(OldView &view, Model &model) :
	InputHandler(),
	view(view),
	model(model) {}

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
		break;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_MIDDLE) {
			this->cursor.currentPosition();
			Raider & raider = model.createRaider(this->cursor.current_x, this->cursor.current_y, 0);
			view.addUnitView(UnitViewFactory::createUnitView(raider, view.getWindow()));
			// std::cout << "Suelta en x: " << this->cursor.current_x << " y: " << this->cursor.current_y << std::endl;
		}
		break;
	case SDL_KEYDOWN:
		switch ( event.key.keysym.sym ) {
		case SDLK_LEFT:
		case SDLK_a:
			std::cout << " Izquierda " << std::endl;
			view.moveLeft(MOVE_AMOUNT);
			break;
		case SDLK_RIGHT:
		case SDLK_d:
			std::cout << " Derecha " << std::endl;
			view.moveRight(MOVE_AMOUNT);
			break;
		case SDLK_DOWN:
		case SDLK_s:
			std::cout << " Abajo " << std::endl;
			view.moveDown(MOVE_AMOUNT);
			break;
		case SDLK_UP:
		case SDLK_w:
			std::cout << " Arriba " << std::endl;
			view.moveUp(MOVE_AMOUNT);
			break;
		default:
			break;
		}
		break;
	}
	return true;
}
