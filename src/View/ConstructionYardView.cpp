#include "ConstructionYardView.h"
#include "BuildingView.h"
#include "../Model/Buildings/ConstructionYard.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

std::map<std::string, std::vector<SdlTexture*> > ConstructionYardView::sprites;
 
ConstructionYardView::ConstructionYardView(ConstructionYard& constructionYard, SdlWindow& window)
    :BuildingView(constructionYard)
{
    if (sprites.empty()){
        std::vector<SdlTexture*> vector;
        vector.emplace_back(new SdlTexture("../imgs/imgs/00159aa0.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/0015b996.bmp",window));
        sprites.emplace(std::make_pair("Atreides",std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001a44ee.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001a64f6.bmp",window));
        sprites.emplace(std::make_pair("Harkonnen",std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001eebc5.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001f09a1.bmp",window));
        sprites.emplace(std::make_pair("Ordos",std::move(vector)));
    }
    anim_it = sprites.at("Ordos").begin();
}


void ConstructionYardView::draw(Area& camara){
    if (!destroyed){
        if (building.getLife()<=0){
            destroyed = true;
            anim_it++;
        }
    }
    Area src(0,0,94,80);
    Area dest(pos.getX() - camara.getX() - 47, pos.getY() - camara.getY() - 40,90,80);
    (*anim_it)->render(src,dest);
}