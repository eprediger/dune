#include "RocketView.h"
#include "../Model/Weapons/Rocket.h"
#include <vector>
#include "SdlTexture.h"
#include "SdlWindow.h"

std::vector<SdlTexture*> RocketView::sprites;

RocketView::RocketView(Rocket& rocket, SdlWindow& window) :
    rocket(rocket),
    exploding(false),
    pos(rocket.getPosition()),
    update_sprite(0),
    finished(false) {
    if (sprites.empty()) {
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002cbf9c.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002cd3b1.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002ce7c6.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002cfc23.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002d1080.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002d24dd.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002d393a.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002d4bef.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002d5fbc.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002d7389.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002d8756.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002d9a03.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002da77e.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002db5e5.bmp", window));
        sprites.emplace_back(new SdlTexture("../imgs/imgs/002dc3d4.bmp", window));
    }
}

void RocketView::draw(Area& camara) {
    if (!exploding) {
        pos = rocket.getPosition();
        if (rocket.arrived()) {
            exploding = true;
            anim_it++;
        } else {
            (*anim_it)->render(Area(0, 0, 72, 72),
                               Area(pos.x - camara.getX() - 36, pos.y - camara.getY() - 36, 72, 72));
            return;
        }
        (*anim_it)->render(Area(0, 0, 72, 72),
                           Area(pos.x - camara.getX() - 36, pos.y - camara.getY() - 36, 72, 72));
        if (update_sprite == 5) {
            anim_it++;
            update_sprite = 0;
            if (anim_it == sprites.end()) {
                finished = true;
            }
        } else {
            update_sprite += 1;
        }
    }
}
