#ifndef __LIGHT_INFANTRY_VIEW_H__
#define __LIGHT_INFANTRY_VIEW_H__

#include "OffensiveUnitView.h"
#include "../Model/Unit/LightInfantry.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Orientation.h"
#include <map>
#include <vector>

class LightInfantryView: public OffensiveUnitView {
    public:
        LightInfantryView(LightInfantry& lightInfantry
                          ,SdlWindow& window);
        
        virtual void draw(Area& camara);
        virtual std::vector<SdlTexture*>& getDeadSprites();
        virtual Area getDeadUnitSrcArea();
	    virtual Area getDeadUnitDestArea();
	
    private:
        static std::map<int, std::vector<SdlTexture*> > sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
        static std::vector<SdlTexture*> dead_sprites;
};

#endif  // __LIGHT_INFANTRY_VIEW_H__
