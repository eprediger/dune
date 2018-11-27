#include "ButtonHandlerSellBuilding.h"
#include "GameHandler.h"
#include <vector>
#include "../Model/Buildings/Building.h"

ButtonHandlerSellBuilding::ButtonHandlerSellBuilding(Player& player, GameView &view,
			Selector &selector, CommunicationQueue& queue) :
        ButtonHandler(view.createSellBuildingButton("../assets/img/btns/sellBuilding.png"),player, view,
                      queue),
	selector(selector) {}

ButtonHandlerSellBuilding::~ButtonHandlerSellBuilding() {}

void ButtonHandlerSellBuilding::execute() {
	std::vector<Building *> &to_sell = this->selector.selection.getSelectedBuildings();
	for (auto itr = to_sell.begin(); itr != to_sell.end(); itr++) {
		nlohmann::json j;
		j["method"] = "sellBuilding";
		j["args"]["player"] = player.getId();
		j["args"]["building_id"] = (*itr)->id;
	}
}

bool ButtonHandlerSellBuilding::canBeEnabled() {
	return !(this->selector.selection.getSelectedBuildings().empty());
}
