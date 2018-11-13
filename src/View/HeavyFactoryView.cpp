#include "HeavyFactoryView.h"
#include "BuildingView.h"
#include "../Model/Buildings/HeavyFactory.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

std::map<std::string, std::vector<SdlTexture*> > HeavyFactoryView::sprites;
 
HeavyFactoryView::HeavyFactoryView(HeavyFactory& heavyFactory, SdlWindow& window)
    :BuildingView(heavyFactory)
{
    if (sprites.empty()){
        std::vector<SdlTexture*> vector;
        vector.emplace_back(new SdlTexture("../imgs/imgs/00146e44.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/00147d65.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/00149a9e.bmp",window));
        sprites.emplace(std::make_pair("Atreides",std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/00190d63.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/0019203a.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/00193dc4.bmp",window));
        sprites.emplace(std::make_pair("Harkonnen",std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001dc086.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001dd390.bmp",window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001dedc0.bmp",window));
        sprites.emplace(std::make_pair("Ordos",std::move(vector)));
    }
    anim_it = sprites.at("Ordos").begin();
    base = (*anim_it);
    anim_it++;
}


void HeavyFactoryView::draw(Area& camara){
    if (!destroyed){
        if (building.getLife()<=0){
            destroyed = true;
            anim_it++;
        }
    }
    Area src(0,0,89,75);
    Area dest(pos.getX() - camara.getX() - 45, pos.getY() - camara.getY() - 38,90,75);
    base->render(src,dest);
    (*anim_it)->render(src,dest);
}
