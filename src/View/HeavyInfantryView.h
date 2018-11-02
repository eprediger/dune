#ifndef __HEAVY_INFANTRY_VIEW_H__
#define __HEAVY_INFANTRY_VIEW_H__

#include "../Unit/heavy-infantry.h"
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
        static std::map<int, std::vector<SdlTexture*> > sprites;
        std::vector<SdlTexture*>::iterator anim_it;
        Orientation prev_orient;
};

#endif