#ifndef __VIEW_H__
#define __VIEW_H__

#include "SdlWindow.h"
#include "MapView.h" 
#include "UnitView.h"
#include "BuildingView.h"
#include <memory>

class View {
private:
    std::vector<std::unique_ptr<UnitView>> unit_views;
    std::vector<std::unique_ptr<BuildingView>> building_views;

//    std::vector<MapView> map_view;
    SdlWindow& window;
    Area& camera;

public:
    View(SdlWindow &window, Area &camera);

    void addUnitView(UnitView* unitView);

    void addBuildingView(BuildingView* buildingView);

    void draw();

    void cleanDeadUnitViews();

};
#endif //__VIEW_H__
