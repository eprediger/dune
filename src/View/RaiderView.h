#ifndef __RAIDER_VIEW_H__
#define __RAIDER_VIEW_H__

#include "OffensiveUnitView.h"
#include "../Model/Unit/Raider.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "../Position.h"
#include "Orientation.h"
#include <map>

class RaiderView: public OffensiveUnitView{
    public:
        RaiderView(Raider& raider, SdlWindow& window);
        virtual void draw(Area& area);
    private:
        static std::map<int, SdlTexture*> raider_sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
};


#endif  // __RAIDER_VIEW_H__
