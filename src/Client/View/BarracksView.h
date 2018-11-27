#ifndef __BARRACKS_VIEW_H__
#define __BARRACKS_VIEW_H__

#include "BuildingView.h"
#include "../../Common/Area.h"
#include "Position.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Model/Buildings/Barracks.h"
#include <vector>
#include <map>
#include <string> 

class BarracksView: public BuildingView{
    public:
        BarracksView(Barracks& barracks, SdlWindow& window);
        virtual void draw(Area& camara);
    private:
        static std::map<std::string,std::vector<std::unique_ptr<SdlTexture> > > sprites;
        std::vector<std::unique_ptr<SdlTexture> >::iterator anim_it;
        std::unique_ptr<SdlTexture> base;
};

#endif	// __BARRACKS_VIEW_H__
