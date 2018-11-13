#ifndef __BUILDINGVIEW_H__
#define __BUILDINGVIEW_H__

#include "../Model/Buildings/Building.h"
#include "SdlWindow.h"
#include "Area.h"
#include "SdlTexture.h"

class BuildingView {
public:
	explicit BuildingView(Building& building);
	virtual ~BuildingView();
	Building& getBuilding();
	virtual void draw(Area& camara) = 0;
protected:
	Building& building;
	Position pos;
	bool destroyed;
};

#endif //__BUILDINGVIEW_H__
