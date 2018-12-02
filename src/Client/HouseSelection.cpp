#include "HouseSelection.h"

HouseSelection::HouseSelection(HouseSelectionView& view,
                               HouseSelectionHandler& handler) :
	wasHouseSelected(false),
	view(view),
	handler(handler) {}

HouseSelection::~HouseSelection() {}

std::string HouseSelection::run() {
	do {
		this->view.render();
	} while (this->handler.handleInput());
	this->view.closeWindow();
	return this->handler.getSelectedHouse();
}
