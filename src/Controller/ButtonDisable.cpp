#include "ButtonDisable.h"
#include "ButtonHandler.h"

DisableState::DisableState() : ButtonState() {}

DisableState::~DisableState() {}

void DisableState::handle(ButtonHandler *button, const int x, const int y) {
	if (button->canBeEnabled()) {
		button->setState(State::ENABLED);
	}
}
