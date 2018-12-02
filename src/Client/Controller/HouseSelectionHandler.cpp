#include "HouseSelectionHandler.h"
#include <CustomException.h>
#include <Codes.h>

HouseSelectionHandler::HouseSelectionHandler(HouseSelectionView& view) :
	InputHandler(),
	view(view),
	selectedHouse() {}

HouseSelectionHandler::~HouseSelectionHandler() {}

bool HouseSelectionHandler::handleInput() {
	bool handleResult = true;
	SDL_Event event;
	SDL_WaitEvent(&(event));
	switch (event.type) {
	case SDL_QUIT:
		handleResult = false;
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT) {
			this->cursor.currentPosition();
			handleResult = !(this->view.setFocusOn(this->cursor.current_x,
			                                       this->cursor.current_y));
		}
		break;
	}
	return handleResult;
}

std::string HouseSelectionHandler::getSelectedHouse() const {
	return this->view.getHouse();
}

