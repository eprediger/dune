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
		UnitView(Unit& unit, Area sprite_area);
		virtual ~UnitView();
		Unit& getUnit();
		virtual void draw(Area& camara) = 0;
		void draw(Area& camara, std::map<int,SdlTexture*>& sprites);
		void draw(Area& camara, std::map<int, std::vector<SdlTexture*> >& sprites
				  ,std::vector<SdlTexture*>::iterator& anim_it, int& update);
		static bool isDead(const UnitView *unit_view);
	protected: 
		Unit& unit;
		Area sprite_area;
		Area dest_area;
		Position prev_pos;
		Orientation orientation;
	private: 
};  

#endif
