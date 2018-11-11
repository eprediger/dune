#ifndef __VIEW_H__
#define __VIEW_H__

#include "SdlWindow.h"
#include "MapView.h" 
#include "UnitView.h"
#include "BuildingView.h"
#include <memory>
#include "SelectorView.h"
class View {
private:
    std::vector<UnitView*> unit_views;
    std::vector<BuildingView*> building_views;
    SelectorView* selectorView;
//    std::vector<MapView> map_view;
    SdlWindow& window;
    Area& camera;

public:
    View(SdlWindow &window, Area &camera);
    ~View();

    SdlWindow& getWindow();
    void addUnitView(UnitView* unitView);

    void addBuildingView(BuildingView* buildingView);

    void addSelectorView(SelectorView* selectorView);

    void draw();

    void cleanDeadUnitViews();

};
#endif //__VIEW_H__
