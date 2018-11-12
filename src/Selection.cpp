#include "Selection.h"
#include <vector> 

Selection::Selection()
    :units()
    ,buildings(){}


void Selection::addSelection(std::vector<Unit*>& new_units){
    units.clear();
    units = std::move(new_units);
}

void Selection::addSelection(std::vector<Building*>& new_buildings){
    buildings.clear();
    buildings = std::move(new_buildings);
}

std::vector<Unit*>& Selection::getSelectedUnits(){
    return this->units;
}
std::vector<Building*>& Selection::getSelectedBuildings(){
    return this->buildings;
}

void Selection::eraseDeads(){
    std::vector<Unit*>::iterator units_it = units.begin();
    while (units_it!=units.end()){
        if (Unit::isDead(*units_it)){
            units_it = units.erase(units_it);
        }
        else units_it++;
    }
    std::vector<Building*>::iterator buildings_it = buildings.begin();
    while (buildings_it!=buildings.end()){
        if ((*buildings_it)->getLife()<=0){
            buildings_it = buildings.erase(buildings_it);
        }
        else buildings_it++;
    }
}