#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include "Orientation.h"
#include <map>
#include "Area.h"


UnitView::UnitView(Unit& unit, Area sprite_area)
	:unit(unit)
	,sprite_area(sprite_area)
	,dest_area(sprite_area)
	,prev_pos(unit.getPosition())
	,orientation(){}

UnitView::~UnitView() {}

Unit &UnitView::getUnit() {
	return unit;
}

bool UnitView::isDead(const UnitView *unit_view) {
    return Unit::isDead(&unit_view->unit);
}

void UnitView::draw(Area& camara, std::map<int, SdlTexture*>& sprites){
	Position pos = unit.getPosition();
	dest_area.setX(pos.x - camara.getX() - sprite_area.getWidth()/2);
	dest_area.setY(pos.y - camara.getY() - sprite_area.getHeight()/2);
	orientation.calcular(prev_pos,pos);
	prev_pos = pos;
    sprites.at(orientation.getValor())->render(sprite_area,dest_area);
}

void UnitView::draw(Area& camara, std::map<int, std::vector<SdlTexture*> >& sprites
				  ,std::vector<SdlTexture*>::iterator& anim_it, int& update)
{
	Position pos = unit.getPosition();
	dest_area.setX(pos.x - camara.getX() - sprite_area.getWidth()/2);
	dest_area.setY(pos.y - camara.getY() - sprite_area.getHeight()/2);
	if (!(prev_pos==pos)){
		Orientation prev_orient = orientation;
		orientation.calcular(prev_pos,pos);
		if(!(orientation==prev_orient)){
			anim_it = sprites.at(orientation.getValor()).begin();
			update = 0;
		}
		if (update == 0){
			anim_it++;
			update = 0;
			if (anim_it == sprites.at(orientation.getValor()).end()){
				anim_it = sprites.at(orientation.getValor()).begin();
			}
		}
		else update++;
		prev_pos = pos;	
	}
	(*anim_it)->render(sprite_area,dest_area);
}
		