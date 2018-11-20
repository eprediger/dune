#include "DeadBuildingView.h"

DeadBuildingView::DeadBuildingView(Position pos, Area src_area, Area dest_area,
	             std::vector<std::unique_ptr<SdlTexture> >& sprites, int r, int g, int b, SdlWindow& window)
    
    :DeadUnitView(pos,src_area,dest_area,sprites,r,g,b,window){}


void DeadBuildingView::draw(Area& camara){
    dest_area.setX(pos.x - camara.getX());
	dest_area.setY(pos.y - camara.getY());
	(*anim_it)->render(src_area, dest_area);
	update++;
	if (update == 10) {
		anim_it++;
		update = 0;
	}
}