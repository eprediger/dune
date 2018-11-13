#include "WindTrapView.h"
#include "BuildingView.h"
#include "../Model/Buildings/WindTrap.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

std::map<std::string, std::vector<SdlTexture*> > WindTrapView::sprites;

WindTrapView::WindTrapView(WindTrap& windtrap, SdlWindow& window) :
    BuildingView(windtrap) {
    if (sprites.empty()) {
        std::vector<SdlTexture*> vector;
        vector.emplace_back(new SdlTexture("../imgs/imgs/0014efd8.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001500d6.bmp", window));
        sprites.emplace(std::make_pair("Atreides", std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001998e7.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/0019a9f0.bmp", window));
        sprites.emplace(std::make_pair("Harkonnen", std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001e41eb.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001e52f4.bmp", window));
        sprites.emplace(std::make_pair("Ordos", std::move(vector)));
    }
    anim_it = sprites.at("Ordos").begin();
}

void WindTrapView::draw(Area& camara) {
    if (!destroyed) {
        if (building.getLife() <= 0) {
            destroyed = true;
            anim_it++;
        }
    }
    Area src(0, 0, 64, 72);
    Area dest(pos.getX() - camara.getX() - 32, pos.getY() - camara.getY() - 36, 64, 72);
    (*anim_it)->render(src, dest);
}
