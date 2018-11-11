#ifndef __BUILDING_VIEW_FACTORY_H__
#define __BUILDING_VIEW_FACTORY_H__

#include "BuildingView.h"
#include "BarracksView.h"
#include "ConstructionYardView.h"
#include "LightFactoryView.h"
#include "HeavyFactoryView.h"
#include "SpiceRefineryView.h"
#include "SpiceSiloView.h"
#include "WindTrapView.h"
#include "../Buildings/Barracks.h"
#include "../Buildings/ConstructionYard.h"
#include "../Buildings/LightFactory.h"
#include "../Buildings/HeavyFactory.h"
#include "../Buildings/SpiceRefinery.h"
#include "../Buildings/SpiceSilo.h"
#include "../Buildings/WindTrap.h"
#include "SdlWindow.h"

class BuildingViewFactory{
    private:
        BuildingViewFactory();
    public:
        static BuildingView* createBuildingView(Barracks& building,SdlWindow& window);
        static BuildingView* createBuildingView(ConstructionYard& building,SdlWindow& window);
        static BuildingView* createBuildingView(LightFactory& building,SdlWindow& window);
        static BuildingView* createBuildingView(HeavyFactory& building,SdlWindow& window);
        static BuildingView* createBuildingView(SpiceRefinery& building,SdlWindow& window);
        static BuildingView* createBuildingView(SpiceSilo& building,SdlWindow& window);
        static BuildingView* createBuildingView(WindTrap& building,SdlWindow& window);
};

#endif