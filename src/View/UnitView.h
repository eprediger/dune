#ifndef __UNIT_VIEW_H__
#define __UNIT_VIEW_H__


#include "../Model/Unit/Unit.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include <map>
#include "Orientation.h" 
#include "Area.h"
#include <memory>

class UnitView{
	public:
		UnitView(Unit& unit, SdlWindow& window);
		virtual ~UnitView();
		Unit& getUnit();
		virtual void draw(Area& camara) = 0;
		static bool isDead(const UnitView *unit_view);
	protected: 
		Unit& unit;
		Position prev_pos;
		Orientation orientation;
	private: 
};  

#endif
