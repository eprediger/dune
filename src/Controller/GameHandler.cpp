#include "GameHandler.h"
#include "../View/UnitViewFactory.h"
#include <iostream>

GameHandler::GameHandler(GameView &view, Model &model) :
		InputHandler(),
		view(view),
		model(model),
		selector(0,0) {
	view.addSelectorView(this->selector);
}

GameHandler::~GameHandler() {}

bool GameHandler::handleInput() {

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			return false;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT) {
				this->view.grabMouse();
				this->cursor.initialPosition();
				selector.drag = true;
				selector.drag_source = selector.pos;
			}
			break;
		case SDL_MOUSEMOTION:
			this->cursor.currentPosition();
			selector.pos.x = this->cursor.current_x + this->view.getCameraX();
			selector.pos.y = this->cursor.current_y + this->view.getCameraY();
			break;
		case SDL_MOUSEBUTTONUP:
			this->cursor.currentPosition();
			if (event.button.button == SDL_BUTTON_LEFT) {
				selector.drag = false;
				Area selectArea(selector.drag_source, selector.pos);
				std::vector<Unit*> selection = model.selectUnitsInArea(selectArea, model.getPlayer(0));
				selector.addSelection(selection);
				this->view.releaseMouse();
			}
			// TEST
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				Raider& raider = model.createRaider(this->cursor.current_x, this->cursor.current_y, 0);
				view.addUnitView(UnitViewFactory::createUnitView(raider, view.getWindow()));

				Raider& raider2 = model.createRaider(this->cursor.current_x+150, this->cursor.current_y+150, 1);
				view.addUnitView(UnitViewFactory::createUnitView(raider2, view.getWindow()));
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				this->cursor.currentPosition();

				//this->model.getMap().setDestiny(unit, this->cursor.current_x + this->view.getCameraX(), this->cursor.current_y + this->view.getCameraY());

                Position pos(this->cursor.current_x + this->view.getCameraX(), this->cursor.current_y + this->view.getCameraY());
                for (auto& unit : selector.selection.getSelectedUnits()) {
                    this->model.actionOnPosition(pos, *unit);
				}
			}
			break;
		case SDL_KEYDOWN:
			switch ( event.key.keysym.sym ) {
				case SDLK_LEFT:
				case SDLK_a:
					view.moveLeft(MOVE_AMOUNT);
					break;
				case SDLK_RIGHT:
				case SDLK_d:
					view.moveRight(MOVE_AMOUNT);
					break;
				case SDLK_DOWN:
				case SDLK_s:
					view.moveDown(MOVE_AMOUNT);
					break;
				case SDLK_UP:
				case SDLK_w:
					view.moveUp(MOVE_AMOUNT);
					break;
				default:
					break;
			}
			break;
	}
	return true;
}
