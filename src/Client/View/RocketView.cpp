#include "RocketView.h"
#include "Model/Weapons/Rocket.h"
#include <vector>
#include "SdlTexture.h"
#include "SdlWindow.h"
#include <memory>

std::vector<std::unique_ptr<SdlTexture> > RocketView::travel_sprites;
std::vector<std::unique_ptr<SdlTexture> > RocketView::explosion_sprites;

RocketView::RocketView(Rocket& rocket, SdlWindow& window) :
    finished(false),
    rocket(rocket),
    reverse(false),
    exploding(false),
    pos(rocket.getPosition()),
    update_sprite(0) {
    if (travel_sprites.empty()) {
        travel_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebc36.bmp", window)));
        travel_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebc00.bmp", window)));
        travel_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebbb2.bmp", window)));
        travel_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ebb55.bmp", window)));


        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002dc3d4.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002db5e5.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002da77e.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002d9a03.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002d8756.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002d7389.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002d5fbc.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002d4bef.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002d393a.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002d24dd.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002d1080.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002cfc23.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002ce7c6.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002cd3b1.bmp", window)));
        explosion_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002cbf9c.bmp", window)));
    }
    anim_it = travel_sprites.begin();
}

void RocketView::draw(Area& camara) {
    if (!exploding) {
        pos = rocket.getPosition();
        if (rocket.arrived) {
            exploding = true;
            anim_it = explosion_sprites.begin();
        } else {
            Area dest_area(pos.x - camara.getX() - 5 , pos.y - camara.getY() - 5, 10, 10);
            if (camara.anyInteract(dest_area)) {
                (*anim_it)->render(Area(0, 0, 20, 20), dest_area);
            }
            anim_it++;
            if (anim_it == travel_sprites.end()) {
                anim_it = travel_sprites.begin();
            }
            return;
        }
    }

    Area dest_area(pos.x - camara.getX(), pos.y - camara.getY(), 40, 40);
    if (camara.anyInteract(dest_area)) {
        (*anim_it)->render(Area(0, 0, 72, 72), dest_area);
    }

    if (update_sprite == 5) {
        if (reverse)
            anim_it--;
        else
            anim_it++;
        update_sprite = 0;
        if (anim_it == explosion_sprites.end()) {
            reverse = true;
            anim_it--;
        }
        if (anim_it == explosion_sprites.begin()) {
            finished = true;
        }
    } else {
        update_sprite += 1;
    }
}
