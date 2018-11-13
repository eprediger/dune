#ifndef __HEAVY_INFANTRY_VIEW_H__
#define __HEAVY_INFANTRY_VIEW_H__

#include "../Model/Unit/HeavyInfantry.h"
#include "OffensiveUnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Orientation.h"
#include "../Position.h"
#include <vector>
#include <map>
#include "Area.h"


class HeavyInfantryView: public OffensiveUnitView{
    public:
        HeavyInfantryView(HeavyInfantry& heavyInfantry, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        
        static std::map<int, std::vector<SdlTexture*> > sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
};


#endif  // __HEAVY_INFANTRY_VIEW_H__
