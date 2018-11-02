#ifndef __UNIT_VIEW_FACTORY_H__
#define __UNIT_VIEW_FACTORY_H__

#include "UnitView.h"
#include "SdlWindow.h"
#include "../Unit/trike.h"
#include "../Unit/harvester.h"
#include "../Unit/light-infantry.h"
 
class UnitViewFactory{
    public:
        static UnitView* createUnitView(Trike& trike
                                        ,SdlWindow& window);
        static UnitView* createUnitView(Harvester& harvester
                                        ,SdlWindow& window);
        static UnitView* createUnitView(LightInfantry& lightInfantry
                                        ,SdlWindow& window);
    private:
        UnitViewFactory();
};

#endif