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
			if (event.button.button == SDL_BUTTON_LEFT) {
				this->cursor.currentPosition();
				// std::cout << "Moviendo en x: " << this->cursor.current_x << " y: " << this->cursor.current_y << std::endl;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				this->cursor.currentPosition();
				Raider & raider = model.createRaider(this->cursor.current_x, this->cursor.current_y, 0);
				view.addUnitView(UnitViewFactory::createUnitView(raider,view.getWindow()));
				// std::cout << "Suelta en x: " << this->cursor.current_x << " y: " << this->cursor.current_y << std::endl;
			}
			break;
		case SDL_KEYDOWN:
			switch( event.key.keysym.sym ){
				case SDLK_LEFT:
					std::cout << " Izquierda " << std::endl;
					view.moveLeft(4);
					break;
				case SDLK_RIGHT:
					std::cout << " Derecha " << std::endl;
					view.moveRight(4);
					break;
				case SDLK_DOWN:
					std::cout << " Abajo " << std::endl;
					view.moveDown(4);
					break;
				case SDLK_UP:
					std::cout << " Arriba " << std::endl;
					view.moveUp(4);
					break;
				default:
					break;
			}
			break;
	}
	return true;
}
