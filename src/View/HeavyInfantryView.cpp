#include "HeavyInfantryView.h"
#include "../Unit/HeavyInfantry.h"
#include "Area.h"
#include "Orientation.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "UnitView.h"
#include <map>
#include <vector>
#include <iostream>

std::map<int, std::vector<SdlTexture*> > HeavyInfantryView::sprites;
std::map<int, std::vector<SdlTexture*> > HeavyInfantryView::attack_sprites;

HeavyInfantryView::HeavyInfantryView(HeavyInfantry& heavyInfantry,
                                    SdlWindow& window)
    :UnitView(heavyInfantry,window) 
    ,heavyInfantry(heavyInfantry)
    ,attacking(false) 
    ,prev_orient() 
    ,attack_orient()
    ,update_sprite(0)
{
    if (sprites.empty()){
        std::vector<SdlTexture*> indef;
        indef.emplace_back(new SdlTexture("../imgs/imgs/00060799.bmp",window));
        sprites.emplace(std::make_pair(Orientation::indefinida(),
                                    std::move(indef)));
        std::vector<SdlTexture*> norte;
        norte.emplace_back(new SdlTexture("../imgs/imgs/00051d33.bmp",window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00052d78.bmp",window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00051d33.bmp",window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00053ce9.bmp",window));
        sprites.emplace(std::make_pair(Orientation::norte(),
                                    std::move(norte)));

        std::vector<SdlTexture*> noroeste;
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00051e30.bmp",window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00052e3a.bmp",window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00053dde.bmp",window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00054e32.bmp",window));
        sprites.emplace(std::make_pair(Orientation::noroeste(),
                                    std::move(noroeste)));
        
        std::vector<SdlTexture*> oeste;
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00051f19.bmp",window));

        oeste.emplace_back(new SdlTexture("../imgs/imgs/00052efc.bmp",window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00053eaf.bmp",window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00054f03.bmp",window));

        sprites.emplace(std::make_pair(Orientation::oeste(),
                                    std::move(oeste)));

        std::vector<SdlTexture*> sudoeste;
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00052fe9.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00053fdc.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00054fd4.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00053fdc.bmp",window));
        sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                    std::move(sudoeste)));

        std::vector<SdlTexture*> sur;
        sur.emplace_back(new SdlTexture("../imgs/imgs/0005f668.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/0005f773.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/0005ff6f.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/0005fe64.bmp",window));
        sprites.emplace(std::make_pair(Orientation::sur(),
                                    std::move(sur)));
       
        std::vector<SdlTexture*> sudeste;
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/000521dc.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00052a41.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00053982.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/000549ed.bmp",window));
        sprites.emplace(std::make_pair(Orientation::sudeste(),
                                    std::move(sudeste)));
        
        std::vector<SdlTexture*> este;
        este.emplace_back(new SdlTexture("../imgs/imgs/00054c28.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/0005441e.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/000549ed.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/000549ed.bmp",window));

        sprites.emplace(std::make_pair(Orientation::este(),
                                    std::move(este)));

        std::vector<SdlTexture*> noreste;
        noreste.emplace_back(new SdlTexture("../imgs/imgs/000523e6.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/000553cf.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/000522c9.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00052c5c.bmp",window));

        sprites.emplace(std::make_pair(Orientation::noreste(),
                                    std::move(noreste)));
        
        
        
        norte.clear();
        norte.emplace_back(new SdlTexture("../imgs/imgs/00055c15.bmp",window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/000564c3.bmp",window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00056f9e.bmp",window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00057966.bmp",window));
        attack_sprites.emplace(std::make_pair(Orientation::norte(),
                                    std::move(norte)));

        noroeste.clear();
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00055d12.bmp",window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/000565c0.bmp",window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/0005708d.bmp",window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00057a63.bmp",window));
        attack_sprites.emplace(std::make_pair(Orientation::noroeste(),
                                    std::move(noroeste)));
        
        oeste.clear();
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00055e3f.bmp",window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00056742.bmp",window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/000571a6.bmp",window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00057b6a.bmp",window));

        attack_sprites.emplace(std::make_pair(Orientation::oeste(),
                                    std::move(oeste)));

        sudoeste.clear();
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/0005578a.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00055f8c.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/000568f7.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00057303.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00057c97.bmp",window));
        attack_sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                    std::move(sudoeste)));

        sur.clear();
        sur.emplace_back(new SdlTexture("../imgs/imgs/00055867.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/000560a5.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00056a34.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/0005742e.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00057da2.bmp",window));
        attack_sprites.emplace(std::make_pair(Orientation::sur(),
                                    std::move(sur)));
       
        sudeste.clear();
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00055934.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/000561b9.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00056b91.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/0005759b.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00057f0f.bmp",window));
        attack_sprites.emplace(std::make_pair(Orientation::sudeste(),
                                    std::move(sudeste)));
        
        este.clear();
        este.emplace_back(new SdlTexture("../imgs/imgs/00055a11.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/000562ae.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/00056cb8.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/000576af.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/00058010.bmp",window));

        attack_sprites.emplace(std::make_pair(Orientation::este(),
                                    std::move(este)));

        noreste.clear();
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00055b4e.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/000563eb.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00056e55.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/0005782c.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00058183.bmp",window));

        attack_sprites.emplace(std::make_pair(Orientation::noreste(),
                                    std::move(noreste)));

        
    }
    anim_it = sprites.at(orientation.getValor()).begin();
}


void HeavyInfantryView::comenzar_ataque(){
    orientation.calcular(prev_pos,heavyInfantry.getVictimPosition());
    anim_it = attack_sprites.at(orientation.getValor()).begin();
}
 
void HeavyInfantryView::draw(Area& camara){ 
    Position pos = unit.getPosition();
	Area dest(pos.getX()- 6 - camara.getX(),pos.getY()-8 - camara.getY() ,25,25);
	orientation.calcular(prev_pos,pos);

    if (heavyInfantry.isAttacking()) {
        if (!attacking) {
            update_sprite = 0;
            attacking = true;
            comenzar_ataque();
        }
    } else {
        attacking = false;
    }

    while (attacking){
        (*anim_it)->render(Area(0,0,25,25),dest);
        if (update_sprite == 60){
            anim_it++;
            update_sprite = 0;
        }
        update_sprite+=1;
        if (anim_it == attack_sprites.at(orientation.getValor()).end()){
            anim_it = sprites.at(orientation.getValor()).begin();
//            heavyInfantry.attacking = false;
            attacking = false;
        }
        return;
    }

    if (orientation.getValor() == prev_orient.getValor()){
        if (!(pos == prev_pos)){
            if (update_sprite == 2){
                anim_it++;
                update_sprite = 0;
            }
            update_sprite+=1;
            if (anim_it == sprites.at(orientation.getValor()).end()){
                anim_it = sprites.at(orientation.getValor()).begin();
            }
        }
        (*anim_it)->render(Area(0,0,12,16),dest);
    }
    else anim_it = sprites.at(orientation.getValor()).begin();
    prev_orient = orientation;
    prev_pos = pos;
    (*anim_it)->render(Area(0,0,12,16),dest);
}