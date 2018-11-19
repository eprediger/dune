#ifndef __ROCKET_VIEW_H__
#define __ROCKET_VIEW_H__

#include "GameView.h"
#include "SdlTexture.h"
#include "SdlWindow.h"
#include <vector>
#include "Area.h"
#include "../Position.h"
#include "../Model/Weapons/Rocket.h"

class RocketView {
public:
    RocketView(Rocket& rocket, SdlWindow& window);
    void draw(Area& camara);
    bool finished;
private:
    Rocket& rocket;
    static std::vector<SdlTexture*> travel_sprites;
    static std::vector<SdlTexture*> explosion_sprites;
    bool reverse,exploding;
    Position pos;
    int update_sprite;
    std::vector<SdlTexture*>::iterator anim_it;
};

#endif  // __ROCKET_VIEW_H__
