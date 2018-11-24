#include "ButtonDisabled.h"
#include "ButtonHandler.h"

ButtonDisabled::ButtonDisabled() : ButtonState() {}

ButtonDisabled::~ButtonDisabled() {}

void ButtonDisabled::handle(ButtonHandler *button, const int x, const int y) {}

void ButtonDisabled::update(ButtonHandler *button) {
	if (button->canBeEnabled()) {
		button->setState(State::ENABLED);
	}
}
