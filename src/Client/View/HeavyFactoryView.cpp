#include "HeavyFactoryView.h"
#include "BuildingView.h"
#include "Model/Buildings/HeavyFactory.h"
#include "../../Common/Area.h"
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>
#include <memory>

std::map<std::string, std::vector<std::unique_ptr<SdlTexture> > > HeavyFactoryView::sprites;
 
HeavyFactoryView::HeavyFactoryView(HeavyFactory& heavyFactory, SdlWindow& window)
    :BuildingView(heavyFactory,window,Area(0,0,90,75),Area(0,0,90,75))

{
    if (sprites.empty()){
        std::vector<std::unique_ptr<SdlTexture> > vector;
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/00146e44.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/00147d65.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/00149a9e.bmp",window)));
        sprites.emplace(std::make_pair("Atreides",std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/00190d63.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0019203a.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/00193dc4.bmp",window)));
        sprites.emplace(std::make_pair("Harkonnen",std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001dc086.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001dd390.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001dedc0.bmp",window)));
        sprites.emplace(std::make_pair("Ordos",std::move(vector)));
    }
    anim_it = sprites.at(building.getPlayer()->getHouse()).begin(); 
    anim_it++;
}

void HeavyFactoryView::draw(Area& camara){
    if ((!destroyed) && building.getLife()<=0){
        destroyed = true;
    }
    BuildingView::draw(camara,*anim_it,sprites.at(building.getPlayer()->getHouse())[0],-5,18);    
}

