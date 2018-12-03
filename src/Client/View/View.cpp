#include "View.h"

View::View(const int width, const int height) :
	windowWidth(width),
	windowHeight(height),
	window(width, height) {
	this->window.fill();
}

View::~View() {}

void View::closeWindow() {
	this->window.destroyWindow();
}
