#include "SpiceSiloView.h"
#include "BuildingView.h"
#include "Model/Buildings/SpiceSilo.h"
#include <Area.h>
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <Path.h>

std::map<std::string, std::vector<std::unique_ptr<SdlTexture> > > SpiceSiloView::sprites;

SpiceSiloView::SpiceSiloView(SpiceSilo& spiceSilo, SdlWindow& window)
    : BuildingView(spiceSilo, window, Area(0, 0, 36, 30), Area(0, 0, 36, 30))
{
    if (sprites.empty()) {
        std::vector<std::unique_ptr<SdlTexture> > vector;
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00166cde.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0016709c.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00167459.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00167816.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00167bd3.bmp"), window)));
        sprites.emplace(std::make_pair("Atreides", std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001b2661.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001b2a1f.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001b2ddc.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001b3199.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001b3556.bmp"), window)));
        sprites.emplace(std::make_pair("Harkonnen", std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001fc88e.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001fcc4c.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001fd009.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001fd3c6.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001fd783.bmp"), window)));
        sprites.emplace(std::make_pair("Ordos", std::move(vector)));
    }
    anim_it = sprites.at(building.getPlayer()->getHouse()).begin();
}

void SpiceSiloView::draw(Area& camara) {
    if ((!destroyed) && building.getLife() <= 0) {
        destroyed = true;
    }
    BuildingView::draw(camara, *anim_it);
}
