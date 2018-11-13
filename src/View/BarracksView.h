#ifndef __BARRACKS_VIEW_H__
#define __BARRACKS_VIEW_H__


#include "BuildingView.h"
#include "Area.h"
#include "../Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Model/Buildings/Barracks.h"
#include <vector>
#include <map>
#include <string> 

class BarracksView: public BuildingView{
    public:
        BarracksView(Barracks& barracks, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        static std::map<std::string,std::vector<SdlTexture*> > sprites;
        std::vector<SdlTexture*>::iterator anim_it;
        SdlTexture* base;
};

#endif	// __BARRACKS_VIEW_H__
