#ifndef __BUILDING_CONSTRUCTOR_VIEW_H__
#define __BUILDING_CONSTRUCTOR_VIEW_H__

class BuildingConstructor;
class BuildingConstructorView;
#include "Controller/BuildingConstructor.h"
#include <Area.h>

class BuildingConstructorView {
private:
	BuildingConstructor& constructor;
	SdlWindow& window;
	int r, g, b;
	SDL_Rect rect;
public:
	BuildingConstructorView(BuildingConstructor& constructor, SdlWindow& window);
	void draw(Area& camara);
};

#endif
