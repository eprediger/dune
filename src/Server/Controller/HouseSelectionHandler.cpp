#include "HouseSelectionHandler.h"

HouseSelectionHandler::HouseSelectionHandler(HouseSelectionView& view) :
	InputHandler(),
	view(view) {}

HouseSelectionHandler::~HouseSelectionHandler() {}

bool HouseSelectionHandler::handleInput() {
	SDL_Event event;
	SDL_PollEvent(&(event));
	switch (event.type) {
	case SDL_QUIT:
		return false;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT) {
			this->cursor.currentPosition();
			// SDL_GetMouseState(&mouse_x_a, &mouse_y_a);
			// std::cout << "Suelta en x: " << this->cursor.current_x << " y: " << this->cursor.current_y	 << std::endl;
			return !(this->view.setFocusOn(this->cursor.current_x, this->cursor.current_y));
		}
		break;
	}
	return true;
}
