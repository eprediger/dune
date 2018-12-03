#include "TrikeView.h"
#include "SdlTexture.h"
#include "Model/Unit/Trike.h"
#include "Position.h"
#include "UnitView.h"
#include "Orientation.h"
#include <map>
#include <vector>
#include <memory>

std::map<int, std::unique_ptr<SdlTexture>> TrikeView::trike_sprites;
std::map<int, std::vector<std::unique_ptr<SdlTexture> > > TrikeView:: attack_sprites;
std::vector<std::unique_ptr<SdlTexture> > TrikeView::dead_sprites;

TrikeView::TrikeView(Trike& trike, SdlWindow& window) :
	OffensiveUnitView(trike, Area(0, 0, 25, 25), window) {
	if (trike_sprites.empty()) {
		trike_sprites.emplace(std::make_pair(Orientation::indefinida(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0009e9ca.bmp", window))));
		trike_sprites.emplace(std::make_pair(Orientation::norte(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0009e6d8.bmp", window))));
		trike_sprites.emplace(std::make_pair(Orientation::noroeste(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0009eb8b.bmp", window))));
		trike_sprites.emplace(std::make_pair(Orientation::oeste(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0009f4f4.bmp", window))));
		trike_sprites.emplace(std::make_pair(Orientation::sudoeste(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0009fe42.bmp", window))));
		trike_sprites.emplace(std::make_pair(Orientation::sur(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/000a038f.bmp", window))));
		trike_sprites.emplace(std::make_pair(Orientation::sudeste(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/00128cdd.bmp", window))));
		trike_sprites.emplace(std::make_pair(Orientation::este(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/000a1090.bmp", window))));
		trike_sprites.emplace(std::make_pair(Orientation::noreste(), std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/0012a366.bmp", window))));

		std::vector<std::unique_ptr<SdlTexture> > norte;
		norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-n1.bmp", window)));
		norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-n2.bmp", window)));
		attack_sprites.emplace(std::make_pair(Orientation::norte(),
		                                      std::move(norte)));

		std::vector<std::unique_ptr<SdlTexture> > noroeste;
		noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-nw1.bmp", window)));
		noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-nw2.bmp", window)));
		attack_sprites.emplace(std::make_pair(Orientation::noroeste(),
		                                      std::move(noroeste)));

		std::vector<std::unique_ptr<SdlTexture> > oeste;
		oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-w1.bmp", window)));
		oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-w2.bmp", window)));
		attack_sprites.emplace(std::make_pair(Orientation::oeste(),
		                                      std::move(oeste)));

		std::vector<std::unique_ptr<SdlTexture> > sudoeste;
		sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-sw1.bmp", window)));
		sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-sw2.bmp", window)));
		attack_sprites.emplace(std::make_pair(Orientation::sudoeste(),
		                                      std::move(sudoeste)));

		std::vector<std::unique_ptr<SdlTexture> > sur;
		sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-s1.bmp", window)));
		sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-s2.bmp", window)));
		attack_sprites.emplace(std::make_pair(Orientation::sur(),
		                                      std::move(sur)));

		std::vector<std::unique_ptr<SdlTexture> > sudeste;
		sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-se1.bmp", window)));
		sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-se2.bmp", window)));
		attack_sprites.emplace(std::make_pair(Orientation::sudeste(),
		                                      std::move(sudeste)));

		std::vector<std::unique_ptr<SdlTexture> > este;
		este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-e1.bmp", window)));
		este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-e2.bmp", window)));
		attack_sprites.emplace(std::make_pair(Orientation::este(),
		                                      std::move(este)));

		std::vector<std::unique_ptr<SdlTexture> > noreste;
		noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-ne1.bmp", window)));
		noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/trike-ne2.bmp", window)));

		attack_sprites.emplace(std::make_pair(Orientation::noreste(),
		                                      std::move(noreste)));

		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e004b.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e06d5.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e10e6.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e1d2a.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e2729.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e30a6.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e3d02.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e591c.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e6697.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e744d.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e81c8.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e8dcf.bmp", window)));
		dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture("../imgs/imgs/002e99b9.bmp", window)));
	}
}

void TrikeView::draw(Area& camara) {
	if (offensiveUnit.isAttacking() && (offensiveUnit.isShooting() || animating_attack)) {
		drawAttack(camara, attack_sprites);
	} else {
		animating_attack = false;
		UnitView::draw(camara, trike_sprites);
	}
}

std::vector<std::unique_ptr<SdlTexture> >& TrikeView::getDeadSprites() {
	return dead_sprites;
}

Area TrikeView::getDeadUnitSrcArea() {
	return Area(0, 0, 80, 80);
}

Area TrikeView::getDeadUnitDestArea() {
	return Area(0, 0, 40, 40);
}
