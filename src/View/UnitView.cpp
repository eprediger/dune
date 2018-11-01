#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include "Orientation.h"
#include <map>
#include "Area.h"

UnitView::UnitView(Unit& unit
						,std::map<int,SdlTexture*>& sprites
						,SdlWindow& window)
	:unit(unit)
	,prev_pos(unit.getPosition())
	,orientation()
	,sprites(sprites) 
{}

Unit &UnitView::getUnit() {
	return unit;
}


