#include "ButtonView.h"
#include <string>

ButtonView::ButtonView(const std::string& filename, const SdlWindow& window) :
	buttonImage(filename, window),
	x(0),
	y(0),
	width(buttonImage.width),
	height(buttonImage.height)/*,
	currentState(new HiddenState())*/ {}

ButtonView::~ButtonView() {
	/*delete this->currentState;*/
}

void ButtonView::changeState(State newState) {
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

bool ButtonView::isClicked(const int x, const int y) {
	return (((x >= this->x) && (x <= this->x + this->width)) && (((y >= this->y) && (y <= this->y + this->height))));
}

void ButtonView::render(const Area& dest) {
	Area src(0, 0, this->buttonImage.width, this->buttonImage.height);
	this->buttonImage.render(src, dest);
	this->x = dest.getX();
	this->y = dest.getY();
}
