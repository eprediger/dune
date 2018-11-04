#ifndef __RAIDER_VIEW_H__
#define __RAIDER_VIEW_H__

#include "UnitView.h"
#include "../Unit/Raider.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "../Position.h"
#include "Orientation.h"
#include <map>

class RaiderView: public UnitView{
    public:
        RaiderView(Raider& raider, SdlWindow& window);
        virtual void draw(Area& area);
    private:
        static std::map<int, SdlTexture*> raider_sprites;
};

#endif