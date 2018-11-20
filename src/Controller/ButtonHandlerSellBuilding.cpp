#include "ButtonHandlerSellBuilding.h"
#include "GameHandler.h"
#include <vector>

ButtonHandlerSellBuilding::ButtonHandlerSellBuilding(Model &model, GameView &view, Selector &selector) :
	ButtonHandler(view.createSellBuildingButton("../assets/img/btns/sellBuilding.png"), model, view),
	selector(selector) {}

ButtonHandlerSellBuilding::~ButtonHandlerSellBuilding() {}

void ButtonHandlerSellBuilding::execute() {
	std::vector<Building *> &to_sell = this->selector.selection.getSelectedBuildings();
	for (auto itr = to_sell.begin(); itr != to_sell.end(); itr++) {
		model.getPlayer(GameHandler::actual_player).sellBuilding(*itr);
	}
}

bool ButtonHandlerSellBuilding::canBeEnabled() {
	return !(this->selector.selection.getSelectedBuildings().empty());
}
