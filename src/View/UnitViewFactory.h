#ifndef __UNIT_VIEW_FACTORY_H__
#define __UNIT_VIEW_FACTORY_H__

#include "UnitView.h"
#include "SdlWindow.h"
#include "TrikeView.h"
#include "../Unit/trike.h"
#include "HarvesterView.h"
#include "../Unit/harvester.h"

class UnitViewFactory{
    public:
        static UnitView* createUnitView(Trike& trike
                                        ,SdlWindow& window);
        static UnitView* createUnitView(Harvester& harvester
                                        ,SdlWindow& window);
    private:
        UnitViewFactory();
};

#endif