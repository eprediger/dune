#include "BuildingView.h"
#include "BarracksView.h"
#include "ConstructionYardView.h"
#include "LightFactoryView.h"
#include "HeavyFactoryView.h"
#include "SpiceRefineryView.h"
#include "SpiceSiloView.h"
#include "WindTrapView.h"
#include "../Model/Buildings/Barracks.h"
#include "../Model/Buildings/ConstructionYard.h"
#include "../Model/Buildings/LightFactory.h"
#include "../Model/Buildings/HeavyFactory.h"
#include "../Model/Buildings/SpiceRefinery.h"
#include "../Model/Buildings/SpiceSilo.h"
#include "../Model/Buildings/WindTrap.h"
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
