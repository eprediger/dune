#include "HouseSelection.h"
#include <string>

HouseSelection::HouseSelection() :
	WindowMenu(),
	selectedHouse(),
	view(WINDOW_WIDTH, WINDOW_HEIGHT),
	handler(view) {}

HouseSelection::~HouseSelection() {}

#include <iostream>

void HouseSelection::run() {
	do {
		this->view.render();
		this->status = this->handler.handleInput();
	} while (this->keepWindowOpen());
	this->view.closeWindow();
	this->selectedHouse = this->handler.getSelectedHouse();
}

std::string HouseSelection::getSelectedHouse() const {
	return this->selectedHouse;
}
