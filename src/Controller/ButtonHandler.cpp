#include "ButtonHandler.h"
#include "ButtonDisable.h"
#include "ButtonEnable.h"
#include "../View/View.h"
#include "../Model/GlobalConfig.h"

ButtonHandler::ButtonHandler(ButtonView& buttonView, Model& model, GameView& view) :
	buttonState(new DisableState()),
	buttonView(buttonView),
	model(model),
	view(view) {}

ButtonHandler::~ButtonHandler() {
	delete this->buttonState;
}

void ButtonHandler::update(const int x, const int y) {
	this->buttonState->handle(this, x, y);
}

bool ButtonHandler::wasClicked(const int x, const int y) {
	return this->buttonView.isClicked(x, y);
}

void ButtonHandler::setState(const State state) {
	delete this->buttonState;

	switch (state) {
	case State::DISABLED:
		this->buttonState = new DisableState();
		break;
	case State::ENABLED:
		this->buttonState = new EnableState();
		break;
/*	case BUSY:
		this->buttonState = new BusyState();
		break;
	case READY:
		this->buttonState = new ReadyState();
		break;*/
	}
}
