#include "ButtonHandlerSellBuilding.h"
#include "GameHandler.h"
#include <vector>
#include <Path.h>
#include "../Model/Buildings/Building.h"

ButtonHandlerSellBuilding::ButtonHandlerSellBuilding(Player& player, GameView &view,
			Selector &selector, CommunicationQueue& queue) :
        ButtonHandler(view.createSellBuildingButton(Path::rootVar("assets/img/btns/sellBuilding.png")),player, view,
                      queue, 0),
	selector(selector) {}

ButtonHandlerSellBuilding::~ButtonHandlerSellBuilding() {}

void ButtonHandlerSellBuilding::execute() {
	std::vector<Building *> &to_sell = this->selector.selection.getSelectedBuildings();
	for (auto itr = to_sell.begin(); itr != to_sell.end(); itr++) {
		nlohmann::json j;
		j["method"] = "sellBuilding";
		j["args"]["player_id"] = player.getId();
		j["args"]["building_id"] = (*itr)->id;
		queue.enqueue(j);
	}
}

bool ButtonHandlerSellBuilding::canBeEnabled() {
	return !(this->selector.selection.getSelectedBuildings().empty());
}
