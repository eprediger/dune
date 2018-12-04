#include "DefeatedScreen.h"

DefeatedScreen::DefeatedScreen(DefeatedScreenView& view, DefeatedScreenHandler& handler) :
    view(view),
    handler(handler) {}

void DefeatedScreen::run() {
    do {
        this->view.render();
    } while (this->handler.handleInput() != WindowStatus::CLOSE);
    this->view.closeWindow();
}
