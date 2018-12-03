#include "ButtonEnabled.h"
#include "ButtonHandler.h"

ButtonEnabled::ButtonEnabled() : ButtonState() {}

void ButtonEnabled::handle(ButtonHandler *button, const int x, const int y) {
	if (button->wasClicked(x, y)) {
		button->execute();
		std::cout << "button pressed! " << std::endl;
		button->setState(State::BUSY);
	}
}

void ButtonEnabled::update(ButtonHandler *button) {
	if (!button->canBeEnabled()) {
		button->setState(State::DISABLED);
	}
}
