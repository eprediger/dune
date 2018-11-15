#include "BuildingView.h"
#include "PlayerColorMaker.h"
#include <cstdlib>

BuildingView::BuildingView(Building& building,SdlWindow& window, Area src_area, Area dest_area) :
	building(building),
	window(window),
	pos(building.getPosition()),
	destroyed(false),
	src_area(src_area),
	dest_area(dest_area)
{
	PlayerColorMaker::makeColor(*building.getPlayer(),&player_r,&player_g,&player_b);
	playerColorRect.x = dest_area.getX();
	playerColorRect.y = dest_area.getY();
	playerColorRect.w = dest_area.getWidth() + 8;
	playerColorRect.h = dest_area.getHeight() + 8;
}

BuildingView::~BuildingView() {}

Building &BuildingView::getBuilding() {
	return building;
}


void BuildingView::draw(Area& camara, SdlTexture*& sprite){

    dest_area.setX(pos.x - camara.getX() - dest_area.getWidth());
	dest_area.setY(pos.y - camara.getY() - dest_area.getHeight());
	playerColorRect.x = dest_area.getX() -4 ;
	playerColorRect.y = dest_area.getY() - 4 ;
	SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window.getRenderer(),player_r,player_g,player_b,250);
	SDL_RenderDrawRect(window.getRenderer(), &playerColorRect);
	SDL_SetRenderDrawColor(window.getRenderer(),player_r,player_g,player_b,30);
	SDL_RenderFillRect(window.getRenderer(),&playerColorRect);
	
	sprite->render(src_area,dest_area);
}



void BuildingView::draw(Area& camara, SdlTexture*& sprite,SdlTexture*& base,int base_x, int base_y){

    dest_area.setX(pos.x - camara.getX() - dest_area.getWidth());
	dest_area.setY(pos.y - camara.getY() - dest_area.getHeight());
	playerColorRect.x = dest_area.getX() - 8 ;
	playerColorRect.y = dest_area.getY();
	playerColorRect.w = dest_area.getWidth() + abs(base_x) + 8;
	playerColorRect.h = dest_area.getHeight() + abs(base_y) + 8;
	SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window.getRenderer(),player_r,player_g,player_b,250);
	SDL_RenderDrawRect(window.getRenderer(), &playerColorRect);
	SDL_SetRenderDrawColor(window.getRenderer(),player_r,player_g,player_b,30);
	SDL_RenderFillRect(window.getRenderer(),&playerColorRect);
	
	dest_area.setX(dest_area.getX() + base_x);
	dest_area.setY(dest_area.getY() + base_y);
	base->render(src_area,dest_area);
	dest_area.setX(dest_area.getX() - base_x);
	dest_area.setY(dest_area.getY() - base_y);
	sprite->render(src_area,dest_area);

}