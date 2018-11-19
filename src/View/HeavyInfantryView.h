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
        HeavyInfantryView(HeavyInfantry& heavyInfantry, std::vector<RocketView*>& rocketViews, SdlWindow& window);
        virtual void draw(Area& camara);
        virtual std::vector<SdlTexture*>& getDeadSprites();
        virtual Area getDeadUnitSrcArea();
	    virtual Area getDeadUnitDestArea();
	
    private:
        HeavyInfantry& heavyInf;
        static std::map<int, std::vector<SdlTexture*> > sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
        static std::vector<SdlTexture*> dead_sprites;
        std::vector<RocketView*>& rocketViews;
};


#endif  // __HEAVY_INFANTRY_VIEW_H__
