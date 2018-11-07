#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include "Orientation.h"
#include <map>
#include "Area.h"

UnitView::UnitView(Unit& unit
						,SdlWindow& window)
	:unit(unit)
	,prev_pos(unit.getPosition())
	,orientation()
{}

Unit &UnitView::getUnit() {
	return unit;
}

bool UnitView::isDead(const UnitView *unit_view) {
    return Unit::isDead(&unit_view->unit);
}


 