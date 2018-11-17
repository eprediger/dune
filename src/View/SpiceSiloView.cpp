#include "SpiceSiloView.h"
#include "BuildingView.h"
#include "../Model/Buildings/SpiceSilo.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

std::map<std::string, std::vector<SdlTexture*> > SpiceSiloView::sprites;

SpiceSiloView::SpiceSiloView(SpiceSilo& spiceSilo, SdlWindow& window)
    : BuildingView(spiceSilo,window,Area(0,0,36,30),Area(0,0,36,30))
{
    if (sprites.empty()) {
        std::vector<SdlTexture*> vector;
        vector.emplace_back(new SdlTexture("../imgs/imgs/00166cde.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/0016709c.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/00167459.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/00167816.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/00167bd3.bmp", window));
        sprites.emplace(std::make_pair("Atreides", std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001b2661.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001b2a1f.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001b2ddc.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001b3199.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001b3556.bmp", window));
        sprites.emplace(std::make_pair("Harkonnen", std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001fc88e.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001fcc4c.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001fd009.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001fd3c6.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001fd783.bmp", window));
        sprites.emplace(std::make_pair("Ordos", std::move(vector)));
    }
    anim_it = sprites.at("Ordos").begin();
}

void SpiceSiloView::draw(Area& camara) {
    if ((!destroyed) && building.getLife()<=0){
        destroyed = true;
    }
    BuildingView::draw(camara,*anim_it);    
}
