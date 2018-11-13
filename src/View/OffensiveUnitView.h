#ifndef __OFFENSIVE_UNIT_VIEW_H__
#define __OFFENSIVE_UNIT_VIEW_H__


#include "UnitView.h"
#include "../Model/Unit/OffensiveUnit.h"
#include "Area.h"

class OffensiveUnitView: public UnitView{
    public:
        OffensiveUnitView(OffensiveUnit& unit, Area sprite_area);
        virtual void draw(Area& camara) = 0;
        void drawAttack(Area& camara, std::map<int, std::vector<SdlTexture*> >& sprites);
    protected:
        OffensiveUnit& offensiveUnit;
        std::vector<SdlTexture*>::iterator anim_it;
        int update;
        bool animating_attack;
};

#endif