#include <algorithm>
#include "View.h"
#include "BuildingView.h"

View::View(SdlWindow &window, Area &camera) : window(window) ,camera(camera){

}

void View::addUnitView(UnitView* unitView) {
    unit_views.push_back(std::unique_ptr<UnitView>(unitView));
}

void View::addBuildingView(BuildingView* buildingView) {
    building_views.push_back(std::unique_ptr<BuildingView>(buildingView));
}

void View::draw() {
//    for (auto unit_view : unit_views){
    for (auto itr = unit_views.begin(); itr != unit_views.end(); ++itr){
        if (!Unit::isDead(&(*itr)->getUnit())){
            (*itr)->draw(camera);
        }
    }

    for (auto itr = building_views.begin(); itr != building_views.end(); ++itr){
        (*itr)->draw(camera);
    }
}

void View::cleanDeadUnitViews(){
    if (std::find_if(unit_views.begin(), unit_views.end(), UnitView::isDead) != unit_views.end()){
        unit_views.erase(std::remove_if(unit_views.begin(), unit_views.end(), UnitView::isDead));
    }
}