#include "TrikeView.h"
#include <map>
#include "SdlTexture.h"
#include "../Unit/Trike.h"
#include "../Position.h"
#include "UnitView.h"
#include "Orientation.h"

std::map<int,SdlTexture*> TrikeView::trike_sprites;

TrikeView::TrikeView(Trike& unit, SdlWindow& window)
	:UnitView(unit,window) 
{
    if (trike_sprites.empty()){  
        trike_sprites.emplace(std::make_pair(Orientation::indefinida(),new SdlTexture("../imgs/imgs/0009e9ca.bmp",window)));		
		trike_sprites.emplace(std::make_pair(Orientation::norte(),new SdlTexture("../imgs/imgs/0009e6d8.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::noroeste(),new SdlTexture("../imgs/imgs/0009eb8b.bmp",window)));	
		trike_sprites.emplace(std::make_pair(Orientation::oeste(),new SdlTexture("../imgs/imgs/0009f4f4.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::sudoeste(),new SdlTexture("../imgs/imgs/0009fe42.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::sur(),new SdlTexture("../imgs/imgs/000a038f.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::sudeste(),new SdlTexture("../imgs/imgs/00128cdd.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::este(),new SdlTexture("../imgs/imgs/000a1090.bmp",window)));
		trike_sprites.emplace(std::make_pair(Orientation::noreste(),new SdlTexture("../imgs/imgs/0012a366.bmp",window)));
    }  
}  

 
void TrikeView::draw(Area& camara){
	Position pos = unit.getPosition();
	Area dest(pos.getX()- 13 - camara.getX(),pos.getY()-13 - camara.getY() ,25,25);
	orientation.calcular(prev_pos,pos);
	prev_pos = pos;
	trike_sprites.at(orientation.getValor())->render(Area(0, 0, 32, 32),dest);
}