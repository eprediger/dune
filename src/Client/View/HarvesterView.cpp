#include "HarvesterView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Position.h"
#include "Orientation.h"
#include <Area.h>
#include "UnitView.h"
#include <map>
#include <vector>
#include <memory>
#include <Path.h>

std::map<int, std::unique_ptr<SdlTexture>> HarvesterView::harvester_sprites;
std::vector<std::unique_ptr<SdlTexture> > HarvesterView::dead_sprites;

HarvesterView::HarvesterView(Harvester& harvester, SdlWindow& window) :
	UnitView(harvester, Area(0, 0, 41, 38), window) {
	if (harvester_sprites.empty()) {
		harvester_sprites.emplace(std::make_pair(Orientation::indefinida(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000a612e.bmp"),window))));
		harvester_sprites.emplace(std::make_pair(Orientation::norte(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000a612e.bmp"),window))));
		harvester_sprites.emplace(std::make_pair(Orientation::noroeste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000a73a3.bmp"),window))));
		harvester_sprites.emplace(std::make_pair(Orientation::oeste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000a910f.bmp"),window))));
		harvester_sprites.emplace(std::make_pair(Orientation::sudoeste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000aad94.bmp"),window))));
		harvester_sprites.emplace(std::make_pair(Orientation::sur(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000ac0d3.bmp"),window))));
		harvester_sprites.emplace(std::make_pair(Orientation::sudeste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000ad4b2.bmp"),window))));
		harvester_sprites.emplace(std::make_pair(Orientation::este(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000af1f9.bmp"),window))));
		harvester_sprites.emplace(std::make_pair(Orientation::noreste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000b0a18.bmp"),window))));

		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e004b.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e06d5.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e10e6.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e1d2a.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e2729.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e30a6.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e3d02.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e591c.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e6697.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e744d.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e81c8.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e8dcf.bmp"),window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e99b9.bmp"),window)));
	}
}

void HarvesterView::draw(Area& camara) {
	UnitView::draw(camara, harvester_sprites);
}

std::vector<std::unique_ptr<SdlTexture> >& HarvesterView::getDeadSprites() {
	return dead_sprites;
}

Area HarvesterView::getDeadUnitSrcArea() {
	return Area(0, 0, 80, 80);
}

Area HarvesterView::getDeadUnitDestArea() {
	return Area(0, 0, 40, 40);
}
