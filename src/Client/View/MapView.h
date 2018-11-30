#ifndef __MAP_VIEW_H__
#define __MAP_VIEW_H__

#include "Model/Map.h"
#include "SdlTexture.h"
#include "SdlWindow.h"
#include <map>
#include <Area.h>

class MapView {
public:
	MapView(Map &map, SdlWindow &window);
	void draw(Area& camara);
private:
	Map& map;
	SdlTexture terrenos;
	std::map<char, Area> areas;
};

#endif
