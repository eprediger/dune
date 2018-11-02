#ifndef __UNIT_VIEW_H__
#define __UNIT_VIEW_H__


#include "../Unit/Unit.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include <map>
#include "Orientation.h" 
#include "Area.h"

class UnitView{
	public:
		UnitView(Unit& unit, SdlWindow& window);
		Unit& getUnit();
		virtual void draw(Area& camara) = 0;
	protected: 
		Unit& unit;
		Position prev_pos;
		Orientation orientation;
		
	private:
};  

#endif
