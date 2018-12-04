#ifndef __TANK_VIEW_H__
#define __TANK_VIEW_H__

#include "OffensiveUnitView.h"
#include "Model/Unit/Tank.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <Area.h>
#include "Orientation.h"
#include <map>
#include <vector>
#include "Sound.h"

class TankView: public OffensiveUnitView {
public:
    TankView(Tank& tank, SdlWindow& window);
    virtual void draw(Area& camara);
    virtual std::vector<std::unique_ptr<SdlTexture> >& getDeadSprites();
    virtual Area getDeadUnitSrcArea();
    virtual Area getDeadUnitDestArea();

private:
    static std::map<int, std::unique_ptr<SdlTexture>> sprites;
    static std::map<int, std::vector<std::unique_ptr<SdlTexture> > > attack_sprites;
    static std::vector<std::unique_ptr<SdlTexture> > dead_sprites;
    static std::unique_ptr<Mix_Chunk> deathFx;
 
};

#endif  // __TANK_VIEW_H__
