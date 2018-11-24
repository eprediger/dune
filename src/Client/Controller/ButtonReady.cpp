#include "ButtonReady.h"
#include "ButtonHandler.h"

ButtonReady::ButtonReady() : ButtonState() {}

ButtonReady::~ButtonReady() {}

void ButtonReady::handle(ButtonHandler* button, const int x, const int y) {
    if (button->wasClicked(x, y)) {
        button->executeReady();
    }
}

void ButtonReady::update(ButtonHandler *button) {
    if (button->finishReady()){
        if (button->canBeEnabled()) {
            button->setState(State::ENABLED);
        } else {
            button->setState(State::DISABLED);
        }
    }
}
