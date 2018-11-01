#include "UnitView.h"
#include "UnitViewFactory.h"
#include "TrikeView.h"
#include "../Unit/trike.h"
#include "HarvesterView.h"
#include "../Unit/harvester.h"

UnitView* UnitViewFactory::createUnitView(Trike& trike, SdlWindow& window){
    return new TrikeView(trike,window);
}

UnitView* UnitViewFactory::createUnitView(Harvester& harvester, SdlWindow& window){
    return new HarvesterView(harvester,window);
}