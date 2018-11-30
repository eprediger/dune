#ifndef __HEAVY_INFANTRY_VIEW_H__
#define __HEAVY_INFANTRY_VIEW_H__

#include "Model/Unit/HeavyInfantry.h"
#include "OffensiveUnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Orientation.h"
#include "Position.h"
#include <vector>
#include <map>
#include <Area.h>

class HeavyInfantryView: public OffensiveUnitView{
    public:
        HeavyInfantryView(HeavyInfantry& heavyInfantry, SdlWindow& window);
        virtual void draw(Area& camara);
        virtual std::vector<std::unique_ptr<SdlTexture> >& getDeadSprites();
        virtual Area getDeadUnitSrcArea();
	    virtual Area getDeadUnitDestArea();
	
    private:
        HeavyInfantry& heavyInf;
        static std::map<int, std::vector<std::unique_ptr<SdlTexture> > > sprites;
        static std::map<int, std::vector<std::unique_ptr<SdlTexture> > > attack_sprites;
        static std::vector<std::unique_ptr<SdlTexture> > dead_sprites;
};

#endif  // __HEAVY_INFANTRY_VIEW_H__
