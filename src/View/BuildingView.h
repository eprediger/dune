#ifndef __BUILDINGVIEW_H__
#define __BUILDINGVIEW_H__


#include "../Buildings/Building.h"
#include "SdlWindow.h"
#include "Area.h"
#include "SdlTexture.h"

class BuildingView {
public:
    BuildingView(Building& building, SdlWindow& window);
    virtual ~BuildingView();
    Building& getBuilding();
    virtual void draw(Area& camara);
protected:
    Building& building;
    Position prev_pos;
    SdlTexture building_sprite;

private:

};


#endif //__BUILDINGVIEW_H__
