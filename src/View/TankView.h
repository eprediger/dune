#ifndef __TANK_VIEW_H__
#define __TANK_VIEW_H__

#include "OffensiveUnitView.h"
#include "../Model/Unit/Tank.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "Orientation.h"
#include <map>
#include <vector>

class TankView: public OffensiveUnitView{
    public:
        TankView(Tank& tank, SdlWindow& window);
        virtual void draw(Area& camara);
        virtual std::vector<SdlTexture*>& getDeadSprites();
        virtual Area getDeadUnitSrcArea();
	    virtual Area getDeadUnitDestArea();
	
    private:
        static std::map<int, SdlTexture*> sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
        static std::vector<SdlTexture*> dead_sprites;
};

#endif  // __TANK_VIEW_H__
