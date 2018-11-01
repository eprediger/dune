#ifndef __HARVESTER_VIEW_H__
#define __HARVESTER_VIEW_H__

#include "../Unit/Harvester.h"
#include "UnitView.h"

class HarvesterView: public UnitView{
    public:
        HarvesterView(Harvester& harvester, SdlWindow& window);
        virtual void draw(Area camara);
    private:
        static std::map<int,SdlTexture*> harvester_sprites;

};

#endif