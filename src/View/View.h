#ifndef __VIEW_H__
#define __VIEW_H__

#include "SdlWindow.h"
#include "MapView.h" 
#include "UnitView.h"
#include <memory>

class View {
private:
    std::vector<std::unique_ptr<UnitView>> unit_views;
//    std::vector<MapView> map_view;
    SdlWindow& window;
    Area& camera;

public:
    View(SdlWindow &window, Area &camera);

    void addUnitView(Unit& unit);

    void draw();

};
#endif //__VIEW_H__