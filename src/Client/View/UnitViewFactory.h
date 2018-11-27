#ifndef __UNIT_VIEW_FACTORY_H__
#define __UNIT_VIEW_FACTORY_H__

#include "UnitView.h"
#include "SdlWindow.h"
#include "RocketView.h"
#include <vector>
#include "Model/Unit/Trike.h"
#include "Model/Unit/Harvester.h"
#include "Model/Unit/LightInfantry.h"
#include "Model/Unit/HeavyInfantry.h"
#include "Model/Unit/Raider.h"
#include "Model/Unit/Tank.h"

class UnitViewFactory {
public:
    static UnitView* createUnitView(Trike& trike
                                    , SdlWindow& window);
    static UnitView* createUnitView(Tank& tank
                                    , SdlWindow& window);
    static UnitView* createUnitView(Raider& raider
                                    , SdlWindow& window);
    static UnitView* createUnitView(Harvester& harvester
                                    , SdlWindow& window);
    static UnitView* createUnitView(LightInfantry& lightInfantry
                                    , SdlWindow& window);
    static UnitView* createUnitView(HeavyInfantry& heavyInfantry
                                    , SdlWindow& window);
private:
    UnitViewFactory();
};

#endif  // __UNIT_VIEW_FACTORY_H__
