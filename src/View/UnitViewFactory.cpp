#include "UnitView.h"
#include "UnitViewFactory.h"
#include "TrikeView.h"
#include "../Unit/Trike.h"
#include "HarvesterView.h"
#include "../Unit/Harvester.h"
#include "LightInfantryView.h"
#include "../Unit/LightInfantry.h"
#include "HeavyInfantryView.h"
#include "../Unit/HeavyInfantry.h"
#include "RaiderView.h"
#include <iostream>
#include "../Unit/Raider.h"
#include "TankView.h"
#include "../Unit/Tank.h"

UnitView* UnitViewFactory::createUnitView(Trike& trike, SdlWindow& window){
    return new TrikeView(trike,window);
}

UnitView* UnitViewFactory::createUnitView(Tank& tank, SdlWindow& window){
    return new TankView(tank,window);
}

UnitView* UnitViewFactory::createUnitView(Raider& raider, SdlWindow& window){
    return new RaiderView(raider,window);
}

UnitView* UnitViewFactory::createUnitView(Harvester& harvester, SdlWindow& window){
    return new HarvesterView(harvester,window);
}

UnitView* UnitViewFactory::createUnitView(LightInfantry& lightInfantry
            ,SdlWindow& window)
{
    return new LightInfantryView(lightInfantry,window);
}

UnitView* UnitViewFactory::createUnitView(HeavyInfantry& heavyInfantry
                                        ,SdlWindow& window)
{
    return new HeavyInfantryView(heavyInfantry,window);
}