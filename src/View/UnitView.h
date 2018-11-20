#ifndef __UNIT_VIEW_H__
#define __UNIT_VIEW_H__

#include "../Model/Unit/Unit.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include "Orientation.h"
#include "Area.h"
#include "DeadUnitView.h"
#include "PlayerColorMaker.h"
#include <map>
#include <memory>
#include <vector>
#include <memory>
class UnitView {
public:
	UnitView(Unit& unit, Area sprite_area, SdlWindow& window);
	virtual ~UnitView();
	Unit& getUnit();
	virtual void draw(Area& camara) = 0;
	void draw(Area& camara, std::map<int, std::unique_ptr<SdlTexture>>& sprites);
	void draw(Area& camara, std::map<int, std::vector<std::unique_ptr<SdlTexture> > >& sprites,
	          std::vector<std::unique_ptr<SdlTexture> >::iterator& anim_it, int& update);
	void drawDamage(Area& camara);
	static bool isDead(const UnitView *unit_view);
	virtual DeadUnitView* getDeadUnitView();
	virtual Area getDeadUnitSrcArea() = 0;
	virtual Area getDeadUnitDestArea() = 0;
	virtual std::vector<std::unique_ptr<SdlTexture> >& getDeadSprites() = 0;

protected:
	SdlWindow& window;
	SDL_Rect playerColorRect;
	Unit& unit;
	int player_r, player_g, player_b;
	Area damage_sprite_area, sprite_area;
	Area damage_dest_area, dest_area;
	Position prev_pos;
	Orientation orientation;
	int life;
	static std::vector<std::unique_ptr<SdlTexture> > damage_sprites;
	std::vector<std::unique_ptr<SdlTexture> >::iterator damage_anim_it;
	int damage_update;
	bool animating_damage;
};

#endif	// __UNIT_VIEW_H__
