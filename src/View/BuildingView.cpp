#include "BuildingView.h"

BuildingView::BuildingView(Building& building)
	:building(building)
	,pos(building.getPosition())
	,destroyed(false)
{
}

Building &BuildingView::getBuilding() {
	return building;
}



