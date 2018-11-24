#include "ButtonView.h"
#include <string>

ButtonView::ButtonView(const std::string &filename, const SdlWindow &window, int number_steps) :
	buttonState(ViewState::HIDDEN),
	buttonImage(filename, window),
    timer(window, number_steps),
	x(0),
	y(0),
	width(buttonImage.width),
	height(buttonImage.height) {}

ButtonView::ButtonView(const std::string &filename, const SdlWindow &window) :
	buttonState(ViewState::HIDDEN),
	buttonImage(filename, window),
	timer(window, 0),
	x(0),
	y(0),
	width(buttonImage.width),
	height(buttonImage.height) {}

ButtonView::~ButtonView() {}

bool ButtonView::isClicked(const int x, const int y) {
	return (((x >= this->x) && (x <= this->x + this->width)) &&
	        (((y >= this->y) && (y <= this->y + this->height))));
}

void ButtonView::setState(const ViewState newState) {
	this->buttonState = newState;
}

void ButtonView::render(const Area& dest) {
	Area enabledSrc(0, 0, this->buttonImage.width / 2,
	                this->buttonImage.height);
	Area disabledSrc(this->buttonImage.width/2, 0,
	                 this->buttonImage.width,
	                 this->buttonImage.height);
	switch (this->buttonState) {
	case ViewState::HIDDEN:
		break;
	case ViewState::ENABLED:
		this->x = dest.getX();
		this->y = dest.getY();
		this->height = dest.getHeight();
		this->width = dest.getWidth();
		this->buttonImage.render(enabledSrc, dest);
		break;
	case ViewState::DISABLED:
		this->buttonImage.render(disabledSrc, dest);
        break;
	case ViewState::BUSY:
		this->buttonImage.render(disabledSrc, dest);
		this->timer.render(dest);
		break;
	case ViewState::READY:
		this->buttonImage.render(enabledSrc, dest);
		this->x = dest.getX();
		this->y = dest.getY();
		this->height = dest.getHeight();
		this->width = dest.getWidth();
	}
}
