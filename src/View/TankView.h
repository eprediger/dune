#ifndef __TANK_VIEW_H__
#define __TANK_VIEW_H__

#include "UnitView.h"
#include "../Unit/tank.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "Orientation.h"
#include <map>

class TankView: public UnitView{
    public:
        TankView(Tank& tank, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        static std::map<int, SdlTexture*> sprites;
};

#endif