#include "ButtonEnable.h"
#include "ButtonHandler.h"

EnableState::EnableState() : ButtonState() {}

EnableState::~EnableState() {}

void EnableState::handle(ButtonHandler *button, const int x, const int y) {
	if (button->wasClicked(x, y)) {
		button->execute();
	}
	if (!button->canBeEnabled()) {
		button->setState(State::DISABLED);
	}
}
