#ifndef __DEAD_UNIT_VIEW_H__
#define __DEAD_UNIT_VIEW_H__

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include "Area.h"
#include <vector>

class DeadUnitView {
public:
	DeadUnitView(Position pos, Area src_area, Area dest_area,
	             std::vector<SdlTexture*>& sprites, int r, int g, int b, SdlWindow& window);
	virtual ~DeadUnitView();
	virtual void draw(Area& camara);
	bool finished();
protected:
	std::vector<SdlTexture*>& dead_sprites;
	std::vector<SdlTexture*>::iterator anim_it;
	Area src_area, dest_area;
	Position pos;
	int update;
	int player_r, player_g, player_b;
	SdlWindow& window;
};

#endif
