#ifndef __TRIKE_VIEW_H__
#define __TRIKE_VIEW_H__

#include "../Model/Unit/Trike.h"
#include "../Position.h"
#include "Orientation.h"
#include "UnitView.h"
#include <map>
#include "SdlWindow.h"
#include "SdlTexture.h"
 
class TrikeView: public UnitView{
    public: 
        TrikeView(Trike& trike, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        void comenzar_ataque();
        Trike& trike;
        static std::map<int, SdlTexture*> trike_sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
        bool attacking;
        std::vector<SdlTexture*>::iterator anim_it;
        int update_sprite;
};

#endif  // __TRIKE_VIEW_H__
