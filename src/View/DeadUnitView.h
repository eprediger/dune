#ifndef __DEAD_UNIT_VIEW_H__
#define __DEAD_UNIT_VIEW_H__

#include "SdlTexture.h"
#include "../Position.h"
#include "Area.h"

class DeadUnitView{
    public:
        DeadUnitView(Position pos,Area area, std::vector<SdlTexture*>& sprites);
        void draw(Area& camara);
    private:
        int update;
        std::vector<SdlTexture*>& dead_sprites; 
        std::vector<SdlTexture*>::iterator anim_it;
};

#endif