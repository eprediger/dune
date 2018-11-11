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
#include "BuildingViewFactory.h"

BuildingView* BuildingViewFactory::createBuildingView(Barracks& building,SdlWindow& window){
    return new BarracksView(building,window);
}
BuildingView* BuildingViewFactory::createBuildingView(ConstructionYard& building,SdlWindow& window){
    return new ConstructionYardView(building,window);
}
BuildingView* BuildingViewFactory::createBuildingView(LightFactory& building,SdlWindow& window){
    return new LightFactoryView(building,window);
}
BuildingView* BuildingViewFactory::createBuildingView(HeavyFactory& building,SdlWindow& window){
    return new HeavyFactoryView(building,window);
}
BuildingView* BuildingViewFactory::createBuildingView(SpiceRefinery& building,SdlWindow& window){
    return new SpiceRefineryView(building, window);
}
BuildingView* BuildingViewFactory::createBuildingView(SpiceSilo& building,SdlWindow& window){
    return new SpiceSiloView(building,window);
}
BuildingView* BuildingViewFactory::createBuildingView(WindTrap& building,SdlWindow& window){
    return new WindTrapView(building,window);
}
