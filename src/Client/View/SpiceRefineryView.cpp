#include "SpiceRefineryView.h"
#include "BuildingView.h"
#include "Model/Buildings/SpiceRefinery.h"
#include <Area.h>
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>
#include <memory>

std::map<std::string, std::vector<std::unique_ptr<SdlTexture> > > SpiceRefineryView::sprites;

SpiceRefineryView::SpiceRefineryView(SpiceRefinery& spiceRefinery, SdlWindow& window) :
    BuildingView(spiceRefinery,window,Area(0,0,108,72),Area(0,0,108,72)) {
    if (sprites.empty()) {
        std::vector<std::unique_ptr<SdlTexture> > vector;
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0015d8d3.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0015f087.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/00160d10.bmp",window)));
        sprites.emplace(std::make_pair("Atreides", std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001a8737.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001aa068.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001ac04d.bmp",window)));
        sprites.emplace(std::make_pair("Harkonnen", std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001f29a8.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001f4261.bmp",window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/001f6096.bmp",window)));
        sprites.emplace(std::make_pair("Ordos", std::move(vector)));
    }
    anim_it = sprites.at(building.getPlayer()->getHouse()).begin();
    anim_it++;
}

void SpiceRefineryView::draw(Area& camara) {
    if ((!destroyed) && building.getLife()<=0){
        destroyed = true;
    }
    BuildingView::draw(camara,*anim_it,sprites.at(building.getPlayer()->getHouse())[0],-10,25);   
}
