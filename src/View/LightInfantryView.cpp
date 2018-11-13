#include "LightInfantryView.h"
#include "../Model/Unit/LightInfantry.h"
#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <map>
#include <vector>
#include "Orientation.h"

std::map<int, std::vector<SdlTexture*> > LightInfantryView::sprites;
std::map<int, std::vector<SdlTexture*> > LightInfantryView::attack_sprites;
std::vector<SdlTexture*> LightInfantryView::dead_sprites;

LightInfantryView::LightInfantryView(LightInfantry& lightInfantry
                                     , SdlWindow& window)
    :OffensiveUnitView(lightInfantry,Area(0,0,20,20)) 
{
    if (sprites.empty()) {
        std::vector<SdlTexture*> indef;
        indef.emplace_back(new SdlTexture("../imgs/imgs/00061b8d.bmp", window));
        sprites.emplace(std::make_pair(Orientation::indefinida(),
                                       std::move(indef)));
        std::vector<SdlTexture*> norte;
        norte.emplace_back(new SdlTexture("../imgs/imgs/00061fa2.bmp", window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00062e44.bmp", window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00063d30.bmp", window));
        sprites.emplace(std::make_pair(Orientation::norte(),
                                       std::move(norte)));

        std::vector<SdlTexture*> noroeste;
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00060dc5.bmp", window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00062f21.bmp", window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00060ef9.bmp", window));
        sprites.emplace(std::make_pair(Orientation::noroeste(),
                                       std::move(noroeste)));

        std::vector<SdlTexture*> oeste;
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00063ebb.bmp", window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00063ebb.bmp", window));

        oeste.emplace_back(new SdlTexture("../imgs/imgs/00062fe3.bmp", window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00062fe3.bmp", window));

        sprites.emplace(std::make_pair(Orientation::oeste(),
                                       std::move(oeste)));
        std::vector<SdlTexture*> sudoeste;
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00061a62.bmp", window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00065ff7.bmp", window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00063f8c.bmp", window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00064f20.bmp", window));
        sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                       std::move(sudoeste)));

        std::vector<SdlTexture*> sur;
        sur.emplace_back(new SdlTexture("../imgs/imgs/00062a2c.bmp", window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00061b8d.bmp", window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00062a2c.bmp", window));

        sur.emplace_back(new SdlTexture("../imgs/imgs/00061b8d.bmp", window));
        sprites.emplace(std::make_pair(Orientation::sur(),
                                       std::move(sur)));
        std::vector<SdlTexture*> sudeste;
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00061c8a.bmp", window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00062b0c.bmp", window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00063a17.bmp", window));
        sprites.emplace(std::make_pair(Orientation::sudeste(),
                                       std::move(sudeste)));

        std::vector<SdlTexture*> este;
        este.emplace_back(new SdlTexture("../imgs/imgs/00062c29.bmp", window));
        este.emplace_back(new SdlTexture("../imgs/imgs/00061d88.bmp", window));
        este.emplace_back(new SdlTexture("../imgs/imgs/00063b15.bmp", window));
        sprites.emplace(std::make_pair(Orientation::este(),
                                       std::move(este)));

        std::vector<SdlTexture*> noreste;
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00063c32.bmp", window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00061e95.bmp", window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00062d46.bmp", window));
        sprites.emplace(std::make_pair(Orientation::noreste(),
                                       std::move(noreste)));


        norte.clear();
        norte.emplace_back(new SdlTexture("../imgs/imgs/00064469.bmp", window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/000654ea.bmp", window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/000665d0.bmp", window));
        attack_sprites.emplace(std::make_pair(Orientation::norte(),
                                              std::move(norte)));

        noroeste.clear();
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/0006457d.bmp", window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/000655f5.bmp", window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/000666db.bmp", window));
        attack_sprites.emplace(std::make_pair(Orientation::noroeste(),
                                              std::move(noroeste)));

        oeste.clear();
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00064691.bmp", window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00065709.bmp", window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/000667fc.bmp", window));
        attack_sprites.emplace(std::make_pair(Orientation::oeste(),
                                              std::move(oeste)));

        sudoeste.clear();
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/0006478f.bmp", window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00065826.bmp", window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00066929.bmp", window));
        attack_sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                              std::move(sudoeste)));

        sur.clear();
        sur.emplace_back(new SdlTexture("../imgs/imgs/00064870.bmp", window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00065924.bmp", window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00066a26.bmp", window));
        attack_sprites.emplace(std::make_pair(Orientation::sur(),
                                              std::move(sur)));

        sudeste.clear();
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/0006497d.bmp", window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00065a61.bmp", window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00066b53.bmp", window));
        attack_sprites.emplace(std::make_pair(Orientation::sudeste(),
                                              std::move(sudeste)));

        este.clear();
        este.emplace_back(new SdlTexture("../imgs/imgs/00064a7a.bmp", window));
        este.emplace_back(new SdlTexture("../imgs/imgs/00065b5e.bmp", window));
        este.emplace_back(new SdlTexture("../imgs/imgs/00066c50.bmp", window));

        attack_sprites.emplace(std::make_pair(Orientation::este(),
                                              std::move(este)));

        noreste.clear();
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00064c37.bmp", window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00065d1b.bmp", window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00066e0d.bmp", window));

        attack_sprites.emplace(std::make_pair(Orientation::noreste(),
                                              std::move(noreste)));

        dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/0006b081.bmp",window));
        dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/0006b1ca.bmp",window));
        dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/0006b9d5.bmp",window));
        dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/0006c2da.bmp",window));
        dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/0006cc5e.bmp",window));
        dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/0006bc17.bmp",window));  
    }
    anim_it = sprites.at(orientation.getValor()).begin();
}

void LightInfantryView::draw(Area& camara){ 
    if (offensiveUnit.isAttacking() || animating_attack){
        drawAttack(camara,attack_sprites);
    }
    else UnitView::draw(camara,sprites,anim_it,update);
}

DeadUnitView* LightInfantryView::getDeadUnitView(){
    return new DeadUnitView(prev_pos,sprite_area,dead_sprites);
}