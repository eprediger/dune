#include "BuildingView.h"

BuildingView::BuildingView(Building& building) :
	building(building),
	pos(building.getPosition()),
	destroyed(false) {}

BuildingView::~BuildingView() {}

Building &BuildingView::getBuilding() {
	return building;
}
