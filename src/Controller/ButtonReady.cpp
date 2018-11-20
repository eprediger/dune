#include "ButtonReady.h"
#include "ButtonHandler.h"

ButtonReady::ButtonReady() : ButtonState() {}

ButtonReady::~ButtonReady() {}

void ButtonReady::handle(ButtonHandler* button, const int x, const int y) {}

void ButtonReady::update(ButtonHandler *button) {
    if (button->canBeEnabled()) {
        button->setState(State::ENABLED);
    } else {
        button->setState(State::DISABLED);
    }
}
