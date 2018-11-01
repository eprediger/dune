#include "View.h"

View::View(SdlWindow &window, Area &camera) : window(window) ,camera(camera){

}

void View::addUnitView(Unit &unit) {
    unit_views.push_back(std::unique_ptr<UnitView>( new UnitView(unit, window)));
}

void View::draw() {
//    for (auto unit_view : unit_views){
    for (auto itr = unit_views.begin(); itr != unit_views.end(); ++itr){
        if (!Unit::isDead(&(*itr)->getUnit())){
            (*itr)->draw(camera);
        }
    }
}