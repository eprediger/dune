#ifndef __RAIDER_VIEW_H__
#define __RAIDER_VIEW_H__

#include "OffensiveUnitView.h"
#include "../Model/Unit/Raider.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Area.h"
#include "../Position.h"
#include "Orientation.h"
#include <map>
#include <vector>

class RaiderView: public OffensiveUnitView {
public:
    RaiderView(Raider& raider, SdlWindow& window);
    virtual void draw(Area& area);
    virtual std::vector<std::unique_ptr<SdlTexture> >& getDeadSprites();
    virtual Area getDeadUnitSrcArea();
    virtual Area getDeadUnitDestArea();

private:
    static std::map<int, std::unique_ptr<SdlTexture>> raider_sprites;
    static std::map<int, std::vector<std::unique_ptr<SdlTexture> > > attack_sprites;
    static std::vector<std::unique_ptr<SdlTexture> > dead_sprites;
};

#endif  // __RAIDER_VIEW_H__
