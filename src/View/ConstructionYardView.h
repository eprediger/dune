#ifndef __CONSTRUCTION_YARD_VIEW_H__
#define __CONSTRUCTION_YARD_VIEW_H__


#include "BuildingView.h"
#include "../Buildings/ConstructionYard.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <vector>
#include <map>
#include <string>

class ConstructionYardView: public BuildingView{
    public:
        ConstructionYardView(ConstructionYard& constructionYard, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        static std::map<std::string, std::vector<SdlTexture*> > sprites;
        std::vector<SdlTexture*>::iterator anim_it;
};



#endif