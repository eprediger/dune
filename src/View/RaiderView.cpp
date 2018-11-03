#include "RaiderView.h"
#include "../Unit/raider.h"
#include "SdlTexture.h"
#include "SdlWindow.h"
#include <map>
#include <iostream>
#include "Orientation.h"
#include "Area.h"


std::map<int,SdlTexture*> RaiderView::raider_sprites;

RaiderView::RaiderView(Raider& raider, SdlWindow& window)
	:UnitView(raider,window)   
{ 	
    if (raider_sprites.empty()){  
		raider_sprites.emplace(std::make_pair(Orientation::indefinida(),new SdlTexture("../imgs/imgs/000a08e6.bmp",window)));		
		raider_sprites.emplace(std::make_pair(Orientation::norte(),new SdlTexture("../imgs/imgs/0009e6d8.bmp",window)));
		raider_sprites.emplace(std::make_pair(Orientation::noroeste(),new SdlTexture("../imgs/imgs/0009eb8b.bmp",window)));	
		raider_sprites.emplace(std::make_pair(Orientation::oeste(),new SdlTexture("../imgs/imgs/0009f4f4.bmp",window)));
		raider_sprites.emplace(std::make_pair(Orientation::sudoeste(),new SdlTexture("../imgs/imgs/0009fe42.bmp",window)));
		raider_sprites.emplace(std::make_pair(Orientation::sur(),new SdlTexture("../imgs/imgs/000a038f.bmp",window)));
		raider_sprites.emplace(std::make_pair(Orientation::sudeste(),new SdlTexture("../imgs/imgs/000a08e6.bmp",window)));
		raider_sprites.emplace(std::make_pair(Orientation::este(),new SdlTexture("../imgs/imgs/000a1090.bmp",window)));
		raider_sprites.emplace(std::make_pair(Orientation::noreste(),new SdlTexture("../imgs/imgs/000a1992.bmp",window)));
	
	}  
}  

 
void RaiderView::draw(Area& camara){
	Position pos = unit.getPosition();
	Area dest(pos.getX()- 15 - camara.getX(),pos.getY()-15 - camara.getY() ,30,30);
	orientation.calcular(prev_pos,pos);
	prev_pos = pos;
	raider_sprites.at(orientation.getValor())->render(Area(0, 0, 35, 35),dest);
} 