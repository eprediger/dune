#include "LightFactoryView.h"
#include "BuildingView.h"
#include "../Model/Buildings/LightFactory.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

std::map<std::string, std::vector<SdlTexture*> > LightFactoryView::sprites;

LightFactoryView::LightFactoryView(LightFactory& lightFactory, SdlWindow& window) :
    BuildingView(lightFactory) {
    if (sprites.empty()) {
        std::vector<SdlTexture*> vector;
        vector.emplace_back(new SdlTexture("../imgs/imgs/00188131.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001898ce.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/0018aadb.bmp", window));
        sprites.emplace(std::make_pair("Atreides", std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001d399f.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001d46ab.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001d5af2.bmp", window));
        sprites.emplace(std::make_pair("Harkonnen", std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/0021dce1.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/0021eedd.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/00220276.bmp", window));
        sprites.emplace(std::make_pair("Ordos", std::move(vector)));
    }
    anim_it = sprites.at("Ordos").begin();
    base = (*anim_it);
    anim_it++;
}

void LightFactoryView::draw(Area& camara) {
    if (!destroyed) {
        if (building.getLife() <= 0) {
            destroyed = true;
            anim_it++;
        }
    }
    Area src(0, 0, 89, 58);
    Area dest(pos.getX() - camara.getX() - 45, pos.getY() - camara.getY() - 30, 90, 60);
    base->render(src, dest);
    (*anim_it)->render(src, dest);
}
