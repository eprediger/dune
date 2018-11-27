#ifndef __OFFENSIVE_UNIT_VIEW_H__
#define __OFFENSIVE_UNIT_VIEW_H__

#include "UnitView.h"
#include "Model/Unit/OffensiveUnit.h"
#include "../../Common/Area.h"
#include <map>
#include <vector>
#include "RocketView.h"
#include <memory> 
class OffensiveUnitView: public UnitView {
public:
    OffensiveUnitView(OffensiveUnit& unit, Area sprite_area, SdlWindow& window);
    virtual void draw(Area& camara) = 0;
    void drawAttack(Area& camara, std::map<int, std::vector<std::unique_ptr<SdlTexture> > >& sprites);
    virtual std::vector<std::unique_ptr<SdlTexture> >& getDeadSprites() = 0;
    virtual Area getDeadUnitSrcArea() = 0;
    virtual Area getDeadUnitDestArea() = 0;

protected:
    OffensiveUnit& offensiveUnit;
    std::vector<std::unique_ptr<SdlTexture> >::iterator anim_it;
    int update;
    bool animating_attack;
};

#endif  // __OFFENSIVE_UNIT_VIEW_H__
