#include "LightInfantryView.h"
#include "../Unit/light-infantry.h"
#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <map>
#include <vector>
#include "Orientation.h"

std::map<int,std::vector<SdlTexture*> > LightInfantryView::sprites;
 
LightInfantryView::LightInfantryView(LightInfantry& lightInfantry
                                    ,SdlWindow& window)
    :UnitView(lightInfantry,window)
    ,prev_orient()
{
    if (sprites.empty()){
        std::vector<SdlTexture*> indef;
        indef.emplace_back(new SdlTexture("../imgs/imgs/00061b8d.bmp",window));
        indef.emplace_back(new SdlTexture("../imgs/imgs/00062a2c.bmp",window));
        sprites.emplace(std::make_pair(Orientation::indefinida(),
                                    std::move(indef)));
        std::vector<SdlTexture*> norte;
        norte.emplace_back(new SdlTexture("../imgs/imgs/00061fa2.bmp",window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00062e44.bmp",window));
        norte.emplace_back(new SdlTexture("../imgs/imgs/00063d30.bmp",window));
        sprites.emplace(std::make_pair(Orientation::norte(),
                                    std::move(norte)));

        std::vector<SdlTexture*> noroeste;
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00060dc5.bmp",window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00062f21.bmp",window));
        noroeste.emplace_back(new SdlTexture("../imgs/imgs/00060ef9.bmp",window));
        sprites.emplace(std::make_pair(Orientation::noroeste(),
                                    std::move(noroeste)));
        
        std::vector<SdlTexture*> oeste;
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00063ebb.bmp",window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00064e5e.bmp",window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00062fe3.bmp",window));
        oeste.emplace_back(new SdlTexture("../imgs/imgs/00065f35.bmp",window));
        sprites.emplace(std::make_pair(Orientation::oeste(),
                                    std::move(oeste)));
        std::vector<SdlTexture*> sudoeste;
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00061a62.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00065ff7.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00063f8c.bmp",window));
        sudoeste.emplace_back(new SdlTexture("../imgs/imgs/00064f20.bmp",window));
        sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                    std::move(sudoeste)));

        std::vector<SdlTexture*> sur;
        sur.emplace_back(new SdlTexture("../imgs/imgs/00062a2c.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00062a2c.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00061b8d.bmp",window));
        sur.emplace_back(new SdlTexture("../imgs/imgs/00061b8d.bmp",window));
        sprites.emplace(std::make_pair(Orientation::sur(),
                                    std::move(sur)));
        std::vector<SdlTexture*> sudeste;
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00061c8a.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00062b0c.bmp",window));
        sudeste.emplace_back(new SdlTexture("../imgs/imgs/00063a17.bmp",window));
        sprites.emplace(std::make_pair(Orientation::sudeste(),
                                    std::move(sudeste)));
        
        std::vector<SdlTexture*> este;
        este.emplace_back(new SdlTexture("../imgs/imgs/00062c29.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/00061d88.bmp",window));
        este.emplace_back(new SdlTexture("../imgs/imgs/00063b15.bmp",window));
        sprites.emplace(std::make_pair(Orientation::este(),
                                    std::move(este)));

        std::vector<SdlTexture*> noreste;
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00063c32.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00061e95.bmp",window));
        noreste.emplace_back(new SdlTexture("../imgs/imgs/00062d46.bmp",window));
        sprites.emplace(std::make_pair(Orientation::noreste(),
                                    std::move(noreste)));
    }
    animation_it = sprites.at(orientation.getValor()).begin();
}


void LightInfantryView::draw(Area& camara){
    Position pos = unit.getPosition();
	Area dest(pos.getX()- 6 - camara.getX(),pos.getY()-8 - camara.getY() ,12,16);
	orientation.calcular(prev_pos,pos);
    if (orientation.getValor() == prev_orient.getValor()){
        if (pos == prev_pos){
            animation_it++;
            if (animation_it == sprites.at(orientation.getValor()).end()){
                animation_it = sprites.at(orientation.getValor()).begin();
            }
        }
        (*animation_it)->render(Area(0,0,12,16),dest);
    }
    else animation_it = sprites.at(orientation.getValor()).begin();
    prev_orient = orientation;
    prev_pos = pos;
    (*animation_it)->render(Area(0,0,12,16),dest);
}