#ifndef __HEAVY_INFANTRY_VIEW_H__
#define __HEAVY_INFANTRY_VIEW_H__

#include "../Unit/HeavyInfantry.h"
#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Orientation.h"
#include "../Position.h"
#include <vector>
#include <map>
#include "Area.h"

class HeavyInfantryView: public UnitView{
    public:
        HeavyInfantryView(HeavyInfantry& heavyInfantry, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        
        void comenzar_ataque();
        HeavyInfantry& heavyInfantry;
        static std::map<int, std::vector<SdlTexture*> > sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
        std::vector<SdlTexture*>::iterator anim_it;
        bool attacking;
        Orientation prev_orient;
        Orientation attack_orient;
        int update_sprite;
};

#endif