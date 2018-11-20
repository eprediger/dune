#include "UnitView.h"
#include "UnitViewFactory.h"
#include "TrikeView.h"
#include "../Model/Unit/Trike.h"
#include "HarvesterView.h"
#include "../Model/Unit/Harvester.h"
#include "LightInfantryView.h"
#include "../Model/Unit/LightInfantry.h"
#include "HeavyInfantryView.h"
#include "../Model/Unit/HeavyInfantry.h"
#include "RaiderView.h"
#include "../Model/Unit/Raider.h"
#include "TankView.h"
#include "../Model/Unit/Tank.h"
#include <vector>

UnitView* UnitViewFactory::createUnitView(Trike& trike, SdlWindow& window) {
	return new TrikeView(trike, window);
}

UnitView* UnitViewFactory::createUnitView(Tank& tank, SdlWindow& window) {
	return new TankView(tank, window);
}

UnitView* UnitViewFactory::createUnitView(Raider& raider, SdlWindow& window) {
	return new RaiderView(raider, window);
} 

UnitView* UnitViewFactory::createUnitView(Harvester& harvester, SdlWindow& window) {
	return new HarvesterView(harvester, window);
}

UnitView* UnitViewFactory::createUnitView(LightInfantry& lightInfantry, SdlWindow& window) {
	return new LightInfantryView(lightInfantry, window);
}

UnitView* UnitViewFactory::createUnitView(HeavyInfantry& heavyInfantry, std::vector<RocketView*>& rocketViews,
							 				SdlWindow& window) {
	return new HeavyInfantryView(heavyInfantry,rocketViews, window); 
}
