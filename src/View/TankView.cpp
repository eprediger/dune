#include "TankView.h"
#include "../Unit/tank.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "Orientation.h"


std::map<int,SdlTexture*> TankView::sprites;

TankView::TankView(Tank& tank, SdlWindow& window)
	:UnitView(tank,window)   
{ 	
    if (sprites.empty()){  
    sprites.emplace(std::make_pair(Orientation::indefinida(),new SdlTexture("../imgs/imgs/000ba250.bmp",window)));		
    sprites.emplace(std::make_pair(Orientation::norte(),new SdlTexture("../imgs/imgs/000b748d.bmp",window)));
    sprites.emplace(std::make_pair(Orientation::noroeste(),new SdlTexture("../imgs/imgs/000b7bae.bmp",window)));	
    sprites.emplace(std::make_pair(Orientation::oeste(),new SdlTexture("../imgs/imgs/000b8ae8.bmp",window)));
    sprites.emplace(std::make_pair(Orientation::sudoeste(),new SdlTexture("../imgs/imgs/000b996e.bmp",window)));
    sprites.emplace(std::make_pair(Orientation::sur(),new SdlTexture("../imgs/imgs/000ba250.bmp",window)));
    sprites.emplace(std::make_pair(Orientation::sudeste(),new SdlTexture("../imgs/imgs/000baa5f.bmp",window)));
    sprites.emplace(std::make_pair(Orientation::este(),new SdlTexture("../imgs/imgs/000bba76.bmp",window)));
    sprites.emplace(std::make_pair(Orientation::noreste(),new SdlTexture("../imgs/imgs/000bc58e.bmp",window)));
  
    }  
}  

 
void TankView::draw(Area& camara){
	Position pos = unit.getPosition();
	Area dest(pos.getX()- 13 - camara.getX(),pos.getY()-13 - camara.getY() ,30,30);
	orientation.calcular(prev_pos,pos);
	prev_pos = pos;
	sprites.at(orientation.getValor())->render(Area(0, 0, 30, 30),dest);
} 