#ifndef __DEAD_BUILDING_VIEW_H__
#define __DEAD_BUILDING_VIEW_H__

#include "DeadUnitView.h"
#include <vector>

class DeadBuildingView: public DeadUnitView {
public:
	DeadBuildingView(Position pos, Area src_area, Area dest_area,
	                 std::vector<SdlTexture*>& sprites, int r, int g, int b, SdlWindow& window);
	virtual void draw(Area& camara) override;
};

#endif
