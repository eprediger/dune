#include "WindTrapView.h"
#include "BuildingView.h"
#include "Model/Buildings/WindTrap.h"
#include <Area.h>
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <Path.h>

std::map<std::string, std::vector<std::unique_ptr<SdlTexture> > > WindTrapView::sprites;

WindTrapView::WindTrapView(WindTrap& windtrap, SdlWindow& window) :
    BuildingView(windtrap, window, Area(0, 0, 64, 72), Area(0, 0, 64, 72)) {
    if (sprites.empty()) {
        std::vector<std::unique_ptr<SdlTexture> > vector;
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0014efd8.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001500d6.bmp"), window)));
        sprites.emplace(std::make_pair("Atreides", std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001998e7.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0019a9f0.bmp"), window)));
        sprites.emplace(std::make_pair("Harkonnen", std::move(vector)));
        vector.clear();
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001e41eb.bmp"), window)));
        vector.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/001e52f4.bmp"), window)));
        sprites.emplace(std::make_pair("Ordos", std::move(vector)));
    }
    anim_it = sprites.at(building.getPlayer()->getHouse()).begin();
}

void WindTrapView::draw(Area& camara) {
    if ((!destroyed) && building.getLife() <= 0) {
        destroyed = true;
    }
    BuildingView::draw(camara, *anim_it);
}
