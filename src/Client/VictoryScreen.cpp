#include "VictoryScreen.h"

VictoryScreen::VictoryScreen(VictoryScreenView& view, VictoryScreenHandler& handler) :
    view(view),
    handler(handler) {}

void VictoryScreen::run() {
    do {
        this->view.render();
    } while (this->handler.handleInput() != WindowStatus::CLOSE);
    this->view.closeWindow();
}
