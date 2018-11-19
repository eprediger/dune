#include "ButtonHandler.h"
#include "ButtonDisabled.h"
#include "ButtonEnabled.h"
#include "../View/View.h"
#include "../Model/GlobalConfig.h"
#include "ButtonBusy.h"
#include "ButtonReady.h"

ButtonHandler::ButtonHandler(ButtonView& buttonView, Model& model, GameView& view) :
	buttonState(new ButtonDisabled()),
	buttonView(buttonView),
	model(model),
	view(view) {}

ButtonHandler::~ButtonHandler() {
	delete this->buttonState;
}

void ButtonHandler::handleUserInput(const int x, const int y) {
	this->buttonState->handle(this, x, y);
}

void ButtonHandler::update() {
	this->buttonState->update(this);
}

bool ButtonHandler::wasClicked(const int x, const int y) {
	return this->buttonView.isClicked(x, y);
}

void ButtonHandler::setState(const State state) {
	delete this->buttonState;

	switch (state) {
	case State::DISABLED:
		this->buttonState = new ButtonDisabled();
		this->buttonView.setState(ViewState::DISABLED);
		break;
	case State::ENABLED:
		this->buttonState = new ButtonEnabled();
		this->buttonView.setState(ViewState::ENABLED);
		break;
	case State::BUSY:
		this->buttonState = new ButtonBusy();
		this->buttonView.setState(ViewState::BUSY);
		break;
	case State::READY:
		this->buttonState = new ButtonReady();
		break;
	}
}
