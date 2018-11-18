#include "ButtonReady.h"
#include "ButtonHandler.h"

ButtonReady::ButtonReady() : ButtonState() {}

ButtonReady::~ButtonReady() {}

void ButtonReady::handle(ButtonHandler* button, const int x, const int y) {
    if (button->canBeEnabled()) {
        button->setState(State::ENABLED);
    } else {
        button->setState(State::DISABLED);
    }
}
