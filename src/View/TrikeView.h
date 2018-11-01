#ifndef __TRIKE_VIEW_H__
#define __TRIKE_VIEW_H__

#include "../Unit/trike.h"
#include "../Position.h"
#include "Orientation.h"
#include "UnitView.h"
#include <map>
#include "SdlWindow.h"
#include "SdlTexture.h"
 
class TrikeView: public UnitView{
    public: 
        TrikeView(Trike& unit, SdlWindow& window);
        virtual void draw(Area camara);
    private:
       static std::map<int,SdlTexture*> trike_sprites;
        
};

#endif