#include <algorithm>
#include "View.h"
#include "BuildingView.h"

View::View(SdlWindow &window, Area &camera)
    : selectorView(nullptr)
    ,window(window) 
    , camera(camera)
{

}

void View::addUnitView(UnitView* unitView) {
    unit_views.push_back(std::move(unitView));
}

void View::addBuildingView(BuildingView* buildingView) {
    building_views.push_back(std::move(buildingView));
}

void View::addSelectorView(SelectorView* selectorView){
    this->selectorView = selectorView;
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

    if (selectorView!=nullptr){
        selectorView->draw(camera);
    }
}

void View::cleanDeadUnitViews(){
    bool has_dead_views = false;
    for (auto unit_view : unit_views){
        if (UnitView::isDead(unit_view)){
            has_dead_views = true;
        }
    }
    if (has_dead_views){
        std::vector<UnitView*>::iterator it = unit_views.begin();
        while (it!=unit_views.end()){
            if (UnitView::isDead(*it)){
                delete(*it);
                it = unit_views.erase(it);
            }
            else it++;
        }
    }
}

View::~View() {
    for(auto unit_view : unit_views){
        delete unit_view;
    }
    for(auto building_view : building_views){
        delete building_view;
    }

}

SdlWindow &View::getWindow() {
    return window;
}
