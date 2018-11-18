#include "ButtonView.h"
/*#include "ButtonViewHidden.h"
#include "ButtonViewEnabled.h"
#include "ButtonViewDisabled.h"*/
#include <string>

ButtonView::ButtonView(const std::string& filename, const SdlWindow& window) :
	buttonState(ViewState::HIDDEN),
	/*currentState(new ButtonHidden()),*/
	buttonImage(filename, window),
	x(0),
	y(0),
	width(buttonImage.width),
	height(buttonImage.height) {}

ButtonView::~ButtonView() {
	// delete this->currentState;
}

bool ButtonView::isClicked(const int x, const int y) {
	return (((x >= this->x) && (x <= this->x + this->width)) &&
	        (((y >= this->y) && (y <= this->y + this->height))));
}

void ButtonView::setState(const ViewState newState) {
	// delete this->currentState;

	switch (newState) {
	case ViewState::HIDDEN:
		// this->currentState = new ButtonHidden();
		this->buttonState = ViewState::HIDDEN;
		break;
	case ViewState::ENABLED:
		// this->currentState = new ButtonEnabled();
		this->buttonState = ViewState::ENABLED;
		break;
	case ViewState::DISABLED:
		// this->currentState = new ButtonDisabled();
		this->buttonState = ViewState::DISABLED;
		break;
	}
}

void ButtonView::render(const Area& dest) {

    // Se debera quitar luego el estado DISABLED de aqui
	if (this->buttonState != ViewState::HIDDEN && this->buttonState != ViewState::DISABLED) {
		Area src(0, 0, this->buttonImage.width, this->buttonImage.height);
		this->buttonImage.render(src, dest);
		this->x = dest.getX();
		this->y = dest.getY();
	}
}
