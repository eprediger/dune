#include "DeadUnitView.h"
#include "../Position.h"
#include "Area.h"
#include <vector>

DeadUnitView::DeadUnitView(Position pos, Area src_area, Area dest_area,
                           std::vector<std::unique_ptr<SdlTexture> >& sprites,
                           int r, int g, int b, SdlWindow& window) :
	dead_sprites(sprites),
	anim_it(sprites.begin()),
	src_area(src_area),
	dest_area(dest_area),
	pos(pos),
	update(0),
	player_r(r),
	player_g(g),
	player_b(b),
	window(window) {}

bool DeadUnitView::finished() {
	return (anim_it == dead_sprites.end());
}

void DeadUnitView::draw(Area& camara) {
	dest_area.setX(pos.x - camara.getX() - dest_area.getWidth() / 2);
	dest_area.setY(pos.y - camara.getY() - dest_area.getHeight() / 2);
	(*anim_it)->render(src_area, dest_area);
	update++;
	if (update == 15) {
		anim_it++;
		update = 0;
	}
}

DeadUnitView::~DeadUnitView() {

}
