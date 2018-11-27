#ifndef __WINDTRAP_VIEW_H__
#define __WINDTRAP_VIEW_H__

#include "BuildingView.h"
#include "Model/Buildings/WindTrap.h"
#include "../../Common/Area.h"
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <map>
#include <vector>
#include <string>

class WindTrapView: public BuildingView {
    public:
        WindTrapView(WindTrap& windtrap, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        static std::map<std::string, std::vector<std::unique_ptr<SdlTexture> > > sprites;
        std::vector<std::unique_ptr<SdlTexture> >::iterator anim_it;
};

#endif	// __WINDTRAP_VIEW_H__
