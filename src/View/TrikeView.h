#ifndef __TRIKE_VIEW_H__
#define __TRIKE_VIEW_H__

#include "../Model/Unit/Trike.h"
#include "../Position.h"
#include "Orientation.h"
#include "OffensiveUnitView.h"
#include <map>
#include "SdlWindow.h"
#include "SdlTexture.h"
 
class TrikeView: public OffensiveUnitView{
    public: 
        TrikeView(Trike& trike, SdlWindow& window);
        virtual void draw(Area& camara);
        virtual DeadUnitView* getDeadUnitView();
    private:
        static std::map<int, SdlTexture*> trike_sprites;
        static std::map<int, std::vector<SdlTexture*> > attack_sprites;
        static std::vector<SdlTexture*> dead_sprites;
};


#endif  // __TRIKE_VIEW_H__
