#include "SpiceRefineryView.h"
#include "BuildingView.h"
#include "../Model/Buildings/SpiceRefinery.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

std::map<std::string, std::vector<SdlTexture*> > SpiceRefineryView::sprites;

SpiceRefineryView::SpiceRefineryView(SpiceRefinery& spiceRefinery, SdlWindow& window) :
    BuildingView(spiceRefinery) {
    if (sprites.empty()) {
        std::vector<SdlTexture*> vector;
        vector.emplace_back(new SdlTexture("../imgs/imgs/0015d8d3.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/0015f087.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/00160d10.bmp", window));
        sprites.emplace(std::make_pair("Atreides", std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001a8737.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001aa068.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001ac04d.bmp", window));
        sprites.emplace(std::make_pair("Harkonnen", std::move(vector)));
        vector.clear();
        vector.emplace_back(new SdlTexture("../imgs/imgs/001f29a8.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001f4261.bmp", window));
        vector.emplace_back(new SdlTexture("../imgs/imgs/001f6096.bmp", window));
        sprites.emplace(std::make_pair("Ordos", std::move(vector)));
    }
    anim_it = sprites.at("Ordos").begin();
    base = (*anim_it);
    anim_it++;
}

void SpiceRefineryView::draw(Area& camara) {
    if (!destroyed) {
        if (building.getLife() <= 0) {
            destroyed = true;
            anim_it++;
        }
    }
    Area src(0, 0, 108, 72);
    Area dest(pos.getX() - camara.getX() - 54, pos.getY() - camara.getY() - 36, 108, 72);
    base->render(src, dest);
    (*anim_it)->render(src, dest);
}
