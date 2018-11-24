#include "ConstructionYardView.h"
#include "BuildingView.h"
#include "Model/Buildings/ConstructionYard.h"
#include "Area.h"
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>
#include <memory>


std::map<std::string, std::vector<std::unique_ptr<SdlTexture> > > ConstructionYardView::sprites;
 
ConstructionYardView::ConstructionYardView(ConstructionYard& constructionYard, SdlWindow& window)
    :BuildingView(constructionYard,window,Area(0,0,94,80),Area(0,0,94,80))
{
    if (sprites.empty()){
        std::vector<std::unique_ptr<SdlTexture> > vector;
        vector.emplace_back(std::unique_ptr<SdlTexture>( new SdlTexture("../imgs/imgs/00159aa0.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>( new SdlTexture("../imgs/imgs/0015b996.bmp",window)));
        sprites.emplace(std::make_pair("Atreides",std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>( new SdlTexture("../imgs/imgs/001a44ee.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>( new SdlTexture("../imgs/imgs/001a64f6.bmp",window)));
        sprites.emplace(std::make_pair("Harkonnen",std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>( new SdlTexture("../imgs/imgs/001eebc5.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>( new SdlTexture("../imgs/imgs/001f09a1.bmp",window)));
        sprites.emplace(std::make_pair("Ordos",std::move(vector)));
    }
    anim_it = sprites.at(building.getPlayer()->getHouse()).begin();
}

void ConstructionYardView::draw(Area& camara){
    if ((!destroyed) && building.getLife()<=0){
        destroyed = true;
    }
    BuildingView::draw(camara,*anim_it);    
}
