#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include "Orientation.h"
#include <map>
#include "Area.h"


UnitView::UnitView(Unit& unit, Area sprite_area,SdlWindow& window)
	:window(window)
	,playerColorRect()
	,unit(unit)
	,sprite_area(sprite_area)
	,dest_area(sprite_area)
	,prev_pos(unit.getPosition())
	,orientation()
	,life(unit.getLife())
	,damage_anim_it()
	,damage_update(0)
{

	PlayerColorMaker::makeColor(unit.getPlayer(),&player_r,&player_g,&player_b);
	playerColorRect.x = 0;
	playerColorRect.y = 0;
	playerColorRect.w = sprite_area.getWidth();
	playerColorRect.h = sprite_area.getHeight();
}

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
	//sprites.at(orientation.getValor())->setColor(unit.getPlayer().getId());
    playerColorRect.x = dest_area.getX();
    playerColorRect.y = dest_area.getY();
    
	SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window.getRenderer(),player_r,player_g,player_b,250);
	SDL_RenderDrawRect(window.getRenderer(), &playerColorRect);
	SDL_SetRenderDrawColor(window.getRenderer(),player_r,player_g,player_b,30);
	SDL_RenderFillRect(window.getRenderer(),&playerColorRect);
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
	playerColorRect.x = dest_area.getX();
    playerColorRect.y = dest_area.getY();
    
	SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window.getRenderer(),player_r,player_g,player_b,250);
	SDL_RenderDrawRect(window.getRenderer(), &playerColorRect);
	SDL_SetRenderDrawColor(window.getRenderer(),player_r,player_g,player_b,30);
	SDL_RenderFillRect(window.getRenderer(),&playerColorRect);
	
	//(*anim_it)->setColor(unit.getPlayer().getId());
	(*anim_it)->render(sprite_area,dest_area);
}
		
void UnitView::drawDamage(Area& camara, std::vector<SdlTexture*>& damage_sprites){
	if (damage_update == 5){
		damage_anim_it++;
		damage_update = 0;
		if (damage_anim_it == damage_sprites.end()){
			damage_anim_it = damage_sprites.begin();
		}
	}
	else damage_update++;
	(*damage_anim_it)->render(Area(0,0,10,10),dest_area);
}

DeadUnitView* UnitView::getDeadUnitView(){
	return new DeadUnitView(prev_pos,Area(0,0,80,80),this->getDeadSprites(),player_r,player_g,player_b,window);
}  