#include "RaiderView.h"
#include "../Model/Unit/Raider.h"
#include "SdlTexture.h"
#include "SdlWindow.h"
#include "Orientation.h"
#include "Area.h"
#include <map>
#include <iostream>
#include <vector>

std::map<int, SdlTexture*> RaiderView::raider_sprites;
std::map<int, std::vector<SdlTexture*> > RaiderView::attack_sprites;
std::vector<SdlTexture*> RaiderView::dead_sprites;

RaiderView::RaiderView(Raider& raider, SdlWindow& window) :
	OffensiveUnitView(raider, Area(0, 0, 30, 30), window) {
	if (raider_sprites.empty()) {
		raider_sprites.emplace(std::make_pair(Orientation::indefinida(), new SdlTexture("../imgs/imgs/000a08e6.bmp", window)));
		raider_sprites.emplace(std::make_pair(Orientation::norte(), new SdlTexture("../imgs/imgs/0009e6d8.bmp", window)));
		raider_sprites.emplace(std::make_pair(Orientation::noroeste(), new SdlTexture("../imgs/imgs/0009eb8b.bmp", window)));
		raider_sprites.emplace(std::make_pair(Orientation::oeste(), new SdlTexture("../imgs/imgs/0009f4f4.bmp", window)));
		raider_sprites.emplace(std::make_pair(Orientation::sudoeste(), new SdlTexture("../imgs/imgs/0009fe42.bmp", window)));
		raider_sprites.emplace(std::make_pair(Orientation::sur(), new SdlTexture("../imgs/imgs/000a038f.bmp", window)));
		raider_sprites.emplace(std::make_pair(Orientation::sudeste(), new SdlTexture("../imgs/imgs/000a08e6.bmp", window)));
		raider_sprites.emplace(std::make_pair(Orientation::este(), new SdlTexture("../imgs/imgs/000a1090.bmp", window)));
		raider_sprites.emplace(std::make_pair(Orientation::noreste(), new SdlTexture("../imgs/imgs/000a1992.bmp", window)));

		std::vector<SdlTexture*> norte;
		norte.emplace_back(new SdlTexture("../imgs/imgs/trike-n1.bmp", window));
		norte.emplace_back(new SdlTexture("../imgs/imgs/trike-n2.bmp", window));
		attack_sprites.emplace(std::make_pair(Orientation::norte(),
		                                      std::move(norte)));

		std::vector<SdlTexture*> noroeste;
		noroeste.emplace_back(new SdlTexture("../imgs/imgs/trike-nw1.bmp", window));
		noroeste.emplace_back(new SdlTexture("../imgs/imgs/trike-nw2.bmp", window));
		attack_sprites.emplace(std::make_pair(Orientation::noroeste(),
		                                      std::move(noroeste)));

		std::vector<SdlTexture*> oeste;
		oeste.emplace_back(new SdlTexture("../imgs/imgs/trike-w1.bmp", window));
		oeste.emplace_back(new SdlTexture("../imgs/imgs/trike-w2.bmp", window));
		attack_sprites.emplace(std::make_pair(Orientation::oeste(),
		                                      std::move(oeste)));

		std::vector<SdlTexture*> sudoeste;
		sudoeste.emplace_back(new SdlTexture("../imgs/imgs/trike-sw1.bmp", window));
		sudoeste.emplace_back(new SdlTexture("../imgs/imgs/trike-sw2.bmp", window));
		attack_sprites.emplace(std::make_pair(Orientation::sudoeste(),
		                                      std::move(sudoeste)));

		std::vector<SdlTexture*> sur;
		sur.emplace_back(new SdlTexture("../imgs/imgs/trike-s1.bmp", window));
		sur.emplace_back(new SdlTexture("../imgs/imgs/trike-s2.bmp", window));
		attack_sprites.emplace(std::make_pair(Orientation::sur(),
		                                      std::move(sur)));

		std::vector<SdlTexture*> sudeste;
		sudeste.emplace_back(new SdlTexture("../imgs/imgs/trike-se1.bmp", window));
		sudeste.emplace_back(new SdlTexture("../imgs/imgs/trike-se2.bmp", window));
		attack_sprites.emplace(std::make_pair(Orientation::sudeste(),
		                                      std::move(sudeste)));

		std::vector<SdlTexture*> este;
		este.emplace_back(new SdlTexture("../imgs/imgs/trike-e1.bmp", window));
		este.emplace_back(new SdlTexture("../imgs/imgs/trike-e2.bmp", window));
		attack_sprites.emplace(std::make_pair(Orientation::este(),
		                                      std::move(este)));

		std::vector<SdlTexture*> noreste;
		noreste.emplace_back(new SdlTexture("../imgs/imgs/trike-ne1.bmp", window));
		noreste.emplace_back(new SdlTexture("../imgs/imgs/trike-ne2.bmp", window));

		attack_sprites.emplace(std::make_pair(Orientation::noreste(),
		                                      std::move(noreste)));

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

void RaiderView::draw(Area& camara) {
	if (offensiveUnit.isAttacking() || animating_attack) {
		drawAttack(camara, attack_sprites);
	} else {
		UnitView::draw(camara, raider_sprites);
	}
}

std::vector<SdlTexture*>& RaiderView::getDeadSprites() {
	return dead_sprites;
}

Area RaiderView::getDeadUnitSrcArea() {
	return Area(0, 0, 80, 80);
}

Area RaiderView::getDeadUnitDestArea() {
	return Area(0, 0, 40, 40);
}
