#include <algorithm>
#include "OldView.h"
#include "BuildingView.h"

OldView::OldView(SdlWindow &window, Area &camera)
		: window(window)
		, camera(camera)
		, selectorView(nullptr)
{

}

void OldView::addUnitView(UnitView* unitView) {
	unit_views.push_back(std::move(unitView));
}

void OldView::addBuildingView(BuildingView* buildingView) {
	building_views.push_back(std::move(buildingView));
}

void OldView::addSelectorView(SelectorView* selectorView){
	this->selectorView = selectorView;
}

void OldView::draw() {
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

void OldView::cleanDeadUnitViews(){
	bool has_dead_views = false;
	for (auto unit_view : unit_views){
		if (UnitView::isDead(unit_view)){
			has_dead_views = true;
			delete unit_view;
		}
	}
	if (has_dead_views){
		unit_views.erase(std::remove_if(unit_views.begin(), unit_views.end(), UnitView::isDead));
	}
}

OldView::~OldView() {
	for(auto unit_view : unit_views){
		delete unit_view;
	}
	for(auto building_view : building_views){
		delete building_view;
	}

}

SdlWindow &OldView::getWindow() {
	return window;
}
