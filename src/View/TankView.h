#ifndef __TANK_VIEW_H__
#define __TANK_VIEW_H__

#include "UnitView.h"
#include "../Model/Unit/Tank.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "Orientation.h"
#include <map>
#include <vector>

class TankView: public UnitView{
    public:
        TankView(Tank& tank, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        void comenzar_ataque();
        Tank& tank;
        static std::map<int, SdlTexture*> sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
        bool attacking;
        std::vector<SdlTexture*>::iterator anim_it;
        int update_sprite;
};

#endif  // __TANK_VIEW_H__
