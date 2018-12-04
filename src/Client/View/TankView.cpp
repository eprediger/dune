#include "TankView.h"
#include "Model/Unit/Tank.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <Area.h>
#include "Orientation.h"
#include <map>
#include <vector>
#include <memory>
#include <Path.h>

std::map<int, std::unique_ptr<SdlTexture>> TankView::sprites;
std::map<int, std::vector<std::unique_ptr<SdlTexture> > > TankView::attack_sprites;
std::vector<std::unique_ptr<SdlTexture> > TankView::dead_sprites;

TankView::TankView(Tank& tank, SdlWindow& window) :
    OffensiveUnitView(tank, Area(0, 0, 30, 30), window) {
    if (sprites.empty()) {
        sprites.emplace(std::make_pair(Orientation::indefinida(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000ba250.bmp"), window))));
        sprites.emplace(std::make_pair(Orientation::norte(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000b748d.bmp"), window))));
        sprites.emplace(std::make_pair(Orientation::noroeste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000b7bae.bmp"), window))));
        sprites.emplace(std::make_pair(Orientation::oeste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000b8ae8.bmp"), window))));
        sprites.emplace(std::make_pair(Orientation::sudoeste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000b996e.bmp"), window))));
        sprites.emplace(std::make_pair(Orientation::sur(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000ba250.bmp"), window))));
        sprites.emplace(std::make_pair(Orientation::sudeste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000baa5f.bmp"), window))));
        sprites.emplace(std::make_pair(Orientation::este(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000bba76.bmp"), window))));
        sprites.emplace(std::make_pair(Orientation::noreste(), std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000bc58e.bmp"), window))));

        std::vector<std::unique_ptr<SdlTexture> > norte;
        norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-n1.bmp"), window)));
        norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-n2.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::norte(),
                                              std::move(norte)));

        std::vector<std::unique_ptr<SdlTexture> > noroeste;
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-nw1.bmp"), window)));
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-nw2.bmp"), window)));
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-nw3.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::noroeste(),
                                              std::move(noroeste)));

        std::vector<std::unique_ptr<SdlTexture> > oeste;
        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-w1.bmp"), window)));
        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-w2.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::oeste(),
                                              std::move(oeste)));

        std::vector<std::unique_ptr<SdlTexture> > sudoeste;
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-sw1.bmp"), window)));
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-sw2.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                              std::move(sudoeste)));

        std::vector<std::unique_ptr<SdlTexture> > sur;
        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-s1.bmp"), window)));
        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-s2.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::sur(),
                                              std::move(sur)));

        std::vector<std::unique_ptr<SdlTexture> > sudeste;
        sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-se1.bmp"), window)));
        sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-se2.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::sudeste(),
                                              std::move(sudeste)));

        std::vector<std::unique_ptr<SdlTexture> > este;
        este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-e1.bmp"), window)));
        este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-e2.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::este(),
                                              std::move(este)));

        std::vector<std::unique_ptr<SdlTexture> > noreste;
        noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-ne1.bmp"), window)));
        noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/tank-ne2.bmp"), window)));

        attack_sprites.emplace(std::make_pair(Orientation::noreste(),
                                              std::move(noreste)));

        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e004b.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e06d5.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e10e6.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e1d2a.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e2729.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e30a6.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e3d02.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e591c.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e6697.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e744d.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e81c8.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e8dcf.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/002e99b9.bmp"), window)));
    }
}

void TankView::draw(Area& camara) {
    if (offensiveUnit.isAttacking() && (offensiveUnit.isShooting() || animating_attack)) {
        drawAttack(camara, attack_sprites);
    } else {
        animating_attack = false;
        UnitView::draw(camara, sprites);
    }
}

std::vector<std::unique_ptr<SdlTexture> >& TankView::getDeadSprites() {
    return dead_sprites;
}

Area TankView::getDeadUnitSrcArea() {
    return Area(0, 0, 80, 80);
}

Area TankView::getDeadUnitDestArea() {
    return Area(0, 0, 40, 40);
}
