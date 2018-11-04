#ifndef __UNIT_VIEW_FACTORY_H__
#define __UNIT_VIEW_FACTORY_H__

#include "UnitView.h"
#include "SdlWindow.h"
#include "../Unit/Trike.h"
#include "../Unit/Harvester.h"
#include "../Unit/LightInfantry.h"
#include "../Unit/HeavyInfantry.h"
#include "../Unit/Raider.h"
#include "../Unit/Tank.h"

class UnitViewFactory{
    public:
        static UnitView* createUnitView(Trike& trike
                                        ,SdlWindow& window);
        static UnitView* createUnitView(Tank& tank
                                        ,SdlWindow& window);
        static UnitView* createUnitView(Raider& raider
                                        ,SdlWindow& window);
        static UnitView* createUnitView(Harvester& harvester
                                        ,SdlWindow& window);
        static UnitView* createUnitView(LightInfantry& lightInfantry
                                        ,SdlWindow& window);
        static UnitView* createUnitView(HeavyInfantry& heavyInfantry
                                        ,SdlWindow& window);
    private:
        UnitViewFactory();
};

#endif