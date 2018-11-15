#include "ButtonHandler.h"
#include "../View/View.h"

ButtonHandler::ButtonHandler(ButtonView& button_view, Model& model, GameView& view) :
	button_view(button_view),
	model(model),
	view(view) {}

ButtonHandler::~ButtonHandler() {}

void ButtonHandler::onClicked(int x, int y) {
	if (button_view.isClicked(x, y)) {
		this->execute();
	}
}
