#include "HarvesterView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Position.h"
#include "Orientation.h"
#include "Area.h"
#include "UnitView.h"
#include <map>
#include <vector>

std::map<int, SdlTexture*> HarvesterView::harvester_sprites;
std::vector<SdlTexture*> HarvesterView::dead_sprites;

HarvesterView::HarvesterView(Harvester& harvester, SdlWindow& window) :
	UnitView(harvester, Area(0, 0, 41, 38), window) {
	if (harvester_sprites.empty()) {
		harvester_sprites.emplace(std::make_pair(Orientation::indefinida(), new SdlTexture("../imgs/imgs/000a612e.bmp", window)));
		harvester_sprites.emplace(std::make_pair(Orientation::norte(), new SdlTexture("../imgs/imgs/000a612e.bmp", window)));
		harvester_sprites.emplace(std::make_pair(Orientation::noroeste(), new SdlTexture("../imgs/imgs/000a73a3.bmp", window)));
		harvester_sprites.emplace(std::make_pair(Orientation::oeste(), new SdlTexture("../imgs/imgs/000a910f.bmp", window)));
		harvester_sprites.emplace(std::make_pair(Orientation::sudoeste(), new SdlTexture("../imgs/imgs/000aad94.bmp", window)));
		harvester_sprites.emplace(std::make_pair(Orientation::sur(), new SdlTexture("../imgs/imgs/000ac0d3.bmp", window)));
		harvester_sprites.emplace(std::make_pair(Orientation::sudeste(), new SdlTexture("../imgs/imgs/000ad4b2.bmp", window)));
		harvester_sprites.emplace(std::make_pair(Orientation::este(), new SdlTexture("../imgs/imgs/000af1f9.bmp", window)));
		harvester_sprites.emplace(std::make_pair(Orientation::noreste(), new SdlTexture("../imgs/imgs/000b0a18.bmp", window)));

		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e004b.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e06d5.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e10e6.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e1d2a.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e2729.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e30a6.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e3d02.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e591c.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e6697.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e744d.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e81c8.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e8dcf.bmp", window));
		dead_sprites.emplace_back(new SdlTexture("../imgs/imgs/002e99b9.bmp", window));
	}
}

void HarvesterView::draw(Area& camara) {
	UnitView::draw(camara, harvester_sprites);
}

std::vector<SdlTexture*>& HarvesterView::getDeadSprites() {
	return dead_sprites;
}

Area HarvesterView::getDeadUnitSrcArea() {
	return Area(0, 0, 80, 80);
}

Area HarvesterView::getDeadUnitDestArea() {
	return Area(0, 0, 40, 40);
}
