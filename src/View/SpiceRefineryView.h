#ifndef __SPICE_REFINERY_VIEW_H__
#define __SPICE_REFINERY_VIEW_H__


#include "BuildingView.h"
#include "../Buildings/SpiceRefinery.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

class SpiceRefineryView: public BuildingView{
    public:
        SpiceRefineryView(SpiceRefinery& spiceRefinery, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        static std::map<std::string, std::vector<SdlTexture*> > sprites;
        std::vector<SdlTexture*>::iterator anim_it;
        SdlTexture* base;
};


#endif