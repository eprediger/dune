#ifndef __LIGHT_INFANTRY_VIEW_H__
#define __LIGHT_INFANTRY_VIEW_H__

#include "UnitView.h"
#include "../Unit/LightInfantry.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Orientation.h"
#include <map>
#include <vector>
class LightInfantryView: public UnitView {
    public:
        LightInfantryView(LightInfantry& lightInfantry
                          ,SdlWindow& window);
        
        virtual void draw(Area& camara);
    private:
        static std::map<int, std::vector<SdlTexture*> > sprites;
        std::vector<SdlTexture*>::iterator animation_it;
        Orientation prev_orient; 
};

#endif