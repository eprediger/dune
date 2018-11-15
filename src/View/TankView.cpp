#include "TankView.h"
#include "../Model/Unit/Tank.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "Orientation.h"


std::map<int,SdlTexture*> TankView::sprites;
std::map<int, std::vector<SdlTexture*> > TankView::attack_sprites;
std::vector<SdlTexture*> TankView::dead_sprites;

TankView::TankView(Tank& tank, SdlWindow& window) :
	OffensiveUnitView(tank,Area(0,0,30,30),window)
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
    
    std::vector<SdlTexture*> norte;
    norte.emplace_back(new SdlTexture("../imgs/imgs/tank-n1.bmp",window));
    norte.emplace_back(new SdlTexture("../imgs/imgs/tank-n2.bmp",window));
    attack_sprites.emplace(std::make_pair(Orientation::norte(),
                                std::move(norte)));

    std::vector<SdlTexture*> noroeste;
    noroeste.emplace_back(new SdlTexture("../imgs/imgs/tank-nw1.bmp",window));
    noroeste.emplace_back(new SdlTexture("../imgs/imgs/tank-nw2.bmp",window));
    noroeste.emplace_back(new SdlTexture("../imgs/imgs/tank-nw3.bmp",window));
    attack_sprites.emplace(std::make_pair(Orientation::noroeste(),
                                std::move(noroeste)));
    
    std::vector<SdlTexture*> oeste;
    oeste.emplace_back(new SdlTexture("../imgs/imgs/tank-w1.bmp",window));
    oeste.emplace_back(new SdlTexture("../imgs/imgs/tank-w2.bmp",window));
    attack_sprites.emplace(std::make_pair(Orientation::oeste(),
                                std::move(oeste)));

    std::vector<SdlTexture*> sudoeste;
    sudoeste.emplace_back(new SdlTexture("../imgs/imgs/tank-sw1.bmp",window));
    sudoeste.emplace_back(new SdlTexture("../imgs/imgs/tank-sw2.bmp",window));
    attack_sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                std::move(sudoeste)));

    std::vector<SdlTexture*> sur;
    sur.emplace_back(new SdlTexture("../imgs/imgs/tank-s1.bmp",window));
    sur.emplace_back(new SdlTexture("../imgs/imgs/tank-s2.bmp",window));
    attack_sprites.emplace(std::make_pair(Orientation::sur(),
                                std::move(sur)));
    
    std::vector<SdlTexture*> sudeste;
    sudeste.emplace_back(new SdlTexture("../imgs/imgs/tank-se1.bmp",window));
    sudeste.emplace_back(new SdlTexture("../imgs/imgs/tank-se2.bmp",window));
    attack_sprites.emplace(std::make_pair(Orientation::sudeste(),
                                std::move(sudeste)));
    
    std::vector<SdlTexture*> este;
    este.emplace_back(new SdlTexture("../imgs/imgs/tank-e1.bmp",window));
    este.emplace_back(new SdlTexture("../imgs/imgs/tank-e2.bmp",window));
    attack_sprites.emplace(std::make_pair(Orientation::este(),
                                std::move(este)));

    std::vector<SdlTexture*> noreste;
    noreste.emplace_back(new SdlTexture("../imgs/imgs/tank-ne1.bmp",window));
    noreste.emplace_back(new SdlTexture("../imgs/imgs/tank-ne2.bmp",window));
    
    attack_sprites.emplace(std::make_pair(Orientation::noreste(),
                            std::move(noreste)));
        
        
        dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e004b.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e06d5.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e10e6.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e1d2a.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e2729.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e30a6.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e3d02.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e591c.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e6697.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e744d.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e81c8.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e8dcf.bmp",window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e99b9.bmp",window));
    
    }  
}  


void TankView::draw(Area& camara){ 
    if (offensiveUnit.isAttacking() || animating_attack){
        drawAttack(camara,attack_sprites);
    }
    else UnitView::draw(camara,sprites);
}

std::vector<SdlTexture*>& TankView::getDeadSprites(){
    return dead_sprites;
}