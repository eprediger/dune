#include "UnitView.h"
#include "UnitViewFactory.h"
#include "TrikeView.h"
#include "../Unit/trike.h"
#include "HarvesterView.h"
#include "../Unit/harvester.h"
#include "LightInfantryView.h"
#include "../Unit/light-infantry.h"

UnitView* UnitViewFactory::createUnitView(Trike& trike, SdlWindow& window){
    return new TrikeView(trike,window);
}

UnitView* UnitViewFactory::createUnitView(Harvester& harvester, SdlWindow& window){
    return new HarvesterView(harvester,window);
}

UnitView* UnitViewFactory::createUnitView(LightInfantry& lightInfantry
            ,SdlWindow& window)
{
    return new LightInfantryView(lightInfantry,window);
}