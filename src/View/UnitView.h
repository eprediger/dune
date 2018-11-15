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
#include "DeadUnitView.h"
#include "PlayerColorMaker.h"

class UnitView {
	public:
		UnitView(Unit& unit, Area sprite_area, SdlWindow& window);
		virtual ~UnitView();
		Unit& getUnit();
		virtual void draw(Area& camara) = 0;
		void draw(Area& camara, std::map<int,SdlTexture*>& sprites);
		void draw(Area& camara, std::map<int, std::vector<SdlTexture*> >& sprites
				  ,std::vector<SdlTexture*>::iterator& anim_it, int& update);
		void drawDamage(Area& camara, std::vector<SdlTexture*>& damage_sprites);
		static bool isDead(const UnitView *unit_view);
		virtual DeadUnitView* getDeadUnitView();
		virtual std::vector<SdlTexture*>& getDeadSprites() = 0;
	protected: 
		SdlWindow& window;
		SDL_Rect playerColorRect;
		Unit& unit;
		int player_r,player_g,player_b;
		Area sprite_area;
		Area dest_area;
		Position prev_pos;
		Orientation orientation;
		int life;
		std::vector<SdlTexture*>::iterator damage_anim_it;
		int damage_update;
	private: 
};  

#endif
