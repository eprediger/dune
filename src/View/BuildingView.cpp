#include "BuildingView.h"

BuildingView::BuildingView(Building& building
						,SdlWindow& window)
	:building(building)
	,prev_pos(building.getPosition())
	,building_sprite("../imgs/imgs/001a44ee.bmp",window)
{
}

Building &BuildingView::getBuilding() {
	return building;
}


void BuildingView::draw(Area& camara){
    Position pos = building.getPosition();
    Area dest(pos.getX()- 20 - camara.getX(),pos.getY()-19 - camara.getY() ,41,38);
    prev_pos = pos;
    building_sprite.render(Area(0, 0, 41, 38),dest);
}


