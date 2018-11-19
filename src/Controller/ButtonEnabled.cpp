#include "ButtonEnabled.h"
#include "ButtonHandler.h"

ButtonEnabled::ButtonEnabled() : ButtonState() {}

ButtonEnabled::~ButtonEnabled() {}

void ButtonEnabled::handle(ButtonHandler *button, const int x, const int y) {
	if (button->wasClicked(x, y)) {
		button->execute();
	}
	if (!button->canBeEnabled()) {
		button->setState(State::DISABLED);
	}
}
