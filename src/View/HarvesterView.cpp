#include "HarvesterView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Position.h"
#include "Orientation.h"
#include <map>
#include "Area.h"
#include "UnitView.h"

std::map<int,SdlTexture*> HarvesterView::harvester_sprites;

HarvesterView::HarvesterView(Harvester& harvester, SdlWindow& window)
	:UnitView(harvester,harvester_sprites,window)
{ 
	if (harvester_sprites.empty()){
		harvester_sprites.emplace(std::make_pair(Orientation::indefinida(),new SdlTexture("../imgs/imgs/000a612e.bmp",window)));		
		harvester_sprites.emplace(std::make_pair(Orientation::norte(),new SdlTexture("../imgs/imgs/000a612e.bmp",window)));
		harvester_sprites.emplace(std::make_pair(Orientation::noroeste(),new SdlTexture("../imgs/imgs/000a73a3.bmp",window)));	
		harvester_sprites.emplace(std::make_pair(Orientation::oeste(),new SdlTexture("../imgs/imgs/000a910f.bmp",window)));
		harvester_sprites.emplace(std::make_pair(Orientation::sudoeste(),new SdlTexture("../imgs/imgs/000aad94.bmp",window)));
		harvester_sprites.emplace(std::make_pair(Orientation::sur(),new SdlTexture("../imgs/imgs/000ac0d3.bmp",window)));
		harvester_sprites.emplace(std::make_pair(Orientation::sudeste(),new SdlTexture("../imgs/imgs/000ad4b2.bmp",window)));
		harvester_sprites.emplace(std::make_pair(Orientation::este(),new SdlTexture("../imgs/imgs/000af1f9.bmp",window)));
		harvester_sprites.emplace(std::make_pair(Orientation::noreste(),new SdlTexture("../imgs/imgs/000b0a18.bmp",window)));
	}
}

void HarvesterView::draw(Area camara){
	Position pos = unit.getPosition();
	Area dest(pos.getX()- 16 - camara.getX(),pos.getY()-16 - camara.getY() ,32,32);
	orientation.calcular(prev_pos,pos);
	prev_pos = pos;
	harvester_sprites.at(orientation.getValor())->render(Area(0, 0, 41, 38),dest);
}