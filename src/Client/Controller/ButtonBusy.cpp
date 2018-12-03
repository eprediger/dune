#include "ButtonBusy.h"
#include "ButtonHandler.h"

ButtonBusy::ButtonBusy() : ButtonState() {}

void ButtonBusy::handle(ButtonHandler* button, const int x, const int y) {}

void ButtonBusy::update(ButtonHandler *button) {
	if (button->finishAction()) {
		button->setState(State::READY);
	}
}
