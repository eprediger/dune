#ifndef __LIGHT_INFANTRY_VIEW_H__
#define __LIGHT_INFANTRY_VIEW_H__

#include "UnitView.h"
#include "../Model/Unit/LightInfantry.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Orientation.h"
#include <map>
#include <vector>
class LightInfantryView: public UnitView {
    public:
        LightInfantryView(LightInfantry& lightInfantry
                          ,SdlWindow& window);
        
        virtual void draw(Area& camara);
    private:
        void comenzar_ataque();
        LightInfantry& lightInfantry;
        static std::map<int, std::vector<SdlTexture*> > sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
        std::vector<SdlTexture*>::iterator anim_it;
        bool attacking;
        Orientation prev_orient; 
        Orientation attack_orient;
        int update_sprite;
};

#endif