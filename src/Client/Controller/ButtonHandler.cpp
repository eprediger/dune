#include "ButtonHandler.h"
#include "ButtonDisabled.h"
#include "ButtonEnabled.h"
#include "ButtonBusy.h"
#include "ButtonReady.h"
#include "View/View.h"
#include "Model/GlobalConfig.h"

ButtonHandler::ButtonHandler(ButtonView &buttonView, Player& player, GameView &view, CommunicationQueue &queue) :
	buttonState(new ButtonDisabled()),
	buttonView(buttonView),
	player(player),
	view(view),
	queue(queue) {}

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
		this->buttonView.setState(ViewState::READY);
		break;
	}
}

void ButtonHandler::executeReady() {}

bool ButtonHandler::finishReady() {
    return true;
}

bool ButtonHandler::finishAction() {
	return true;
}
