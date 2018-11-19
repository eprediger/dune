#include "ButtonBusy.h"
#include "ButtonHandler.h"

ButtonBusy::ButtonBusy() :ButtonState() {}

ButtonBusy::~ButtonBusy() {}

void ButtonBusy::handle(ButtonHandler* button, const int x, const int y) {
    if (button->finishAction()) {
        button->setState(State::READY);
    }
}
