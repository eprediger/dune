#ifndef __WINDTRAP_VIEW_H__
#define __WINDTRAP_VIEW_H__

#include "BuildingView.h"
#include "../Buildings/WindTrap.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <map>
#include <vector>
#include <string>

class WindTrapView: public BuildingView{
    public:
        WindTrapView(WindTrap& windtrap, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        static std::map<std::string, std::vector<SdlTexture*> > sprites;
        std::vector<SdlTexture*>::iterator anim_it;
};

#endif