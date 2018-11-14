#include "Button.h"

Button::Button(const std::string& filename, const SdlWindow& window) :
	buttonImage(filename, window)/*,
	currentState(new HiddenState())*/ {}

Button::~Button() {
	/*delete this->currentState;*/
}

void Button::changeState(State newState) {
	/*delete this->currentState;
	switch (newState) {
		case State::HIDDEN:
			this->currentState = new HiddenState();
			break;
		case State::ENABLE:
			this->currentState = new EnabledState();
			break;
		case State::DISABLE:
			this->currentState = new DisabledState();
			break;
	}*/
}

void Button::render(const Area& dest) {
	Area src(0, 0, this->buttonImage.width, this->buttonImage.height);
	this->buttonImage.render(src, dest);
}
