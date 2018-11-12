#ifndef __ROCKET_VIEW_H__
#define __ROCKET_VIEW_H__

#include "../Weapons/Rocket.h"
#include "OldView.h"
#include "SdlTexture.h"
#include "SdlWindow.h"
#include <vector>
#include "Area.h"
#include "../Position.h"

class RocketView{
    public:
        RocketView(Rocket& rocket, SdlWindow& window);
        void draw(Area& camara);
    private: 
        Rocket& rocket;
        static std::vector<SdlTexture*> sprites;
        bool exploding;
        Position pos;
        int update_sprite;
        bool finished;
        std::vector<SdlTexture*>::iterator anim_it;
};

#endif