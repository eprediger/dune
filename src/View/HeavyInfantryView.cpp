#include "HeavyInfantryView.h"
#include "../Unit/heavy-infantry.h"
#include "Area.h"
#include "Orientation.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "UnitView.h"
#include <map>
#include <vector>

std::map<int, std::vector<SdlTexture*> > HeavyInfantryView::sprites;

HeavyInfantryView::HeavyInfantryView(HeavyInfantry& heavyInfantry,
                                    SdlWindow& window)
    :UnitView(heavyInfantry,window)
    ,prev_orient() 
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
    }
    anim_it = sprites.at(orientation.getValor()).begin();
}


void HeavyInfantryView::draw(Area& camara){ 
    Position pos = unit.getPosition();
	Area dest(pos.getX()- 6 - camara.getX(),pos.getY()-8 - camara.getY() ,15,20);
	orientation.calcular(prev_pos,pos);
    if (orientation.getValor() == prev_orient.getValor()){
        if (!(pos == prev_pos)){
            anim_it++;
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