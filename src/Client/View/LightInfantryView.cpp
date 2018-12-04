#include "LightInfantryView.h"
#include "Model/Unit/LightInfantry.h"
#include "UnitView.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include <map>
#include <vector>
#include "Orientation.h"
#include <memory>
#include <Path.h>
#include "Sound.h"

std::map<int, std::vector<std::unique_ptr<SdlTexture> > > LightInfantryView::sprites;
std::map<int, std::vector<std::unique_ptr<SdlTexture> > > LightInfantryView::attack_sprites;
std::vector<std::unique_ptr<SdlTexture> > LightInfantryView::dead_sprites;
std::unique_ptr<Mix_Chunk> LightInfantryView::deathFx;

LightInfantryView::LightInfantryView(LightInfantry& lightInfantry,
                                     SdlWindow& window) :
    OffensiveUnitView(lightInfantry, Area(0, 0, 20, 20), window)
{
    if (!deathFx) {
        deathFx = std::move(std::unique_ptr<Mix_Chunk>(Mix_LoadWAV(Path::rootVar("assets/sound/fx/infantry death.wav").c_str())));
    }

    if (sprites.empty()) {
        std::vector<std::unique_ptr<SdlTexture> > indef;
        indef.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00061b8d.bmp"), window)));
        sprites.emplace(std::make_pair(Orientation::indefinida(),
                                       std::move(indef)));
        std::vector<std::unique_ptr<SdlTexture> > norte;
        norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00061fa2.bmp"), window)));
        norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062e44.bmp"), window)));
        norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00063d30.bmp"), window)));
        sprites.emplace(std::make_pair(Orientation::norte(),
                                       std::move(norte)));

        std::vector<std::unique_ptr<SdlTexture> > noroeste;
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00060dc5.bmp"), window)));
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062f21.bmp"), window)));
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00060ef9.bmp"), window)));
        sprites.emplace(std::make_pair(Orientation::noroeste(),
                                       std::move(noroeste)));

        std::vector<std::unique_ptr<SdlTexture> > oeste;
        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00063ebb.bmp"), window)));
        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00063ebb.bmp"), window)));

        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062fe3.bmp"), window)));
        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062fe3.bmp"), window)));

        sprites.emplace(std::make_pair(Orientation::oeste(),
                                       std::move(oeste)));
        std::vector<std::unique_ptr<SdlTexture> > sudoeste;
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00061a62.bmp"), window)));
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00065ff7.bmp"), window)));
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00063f8c.bmp"), window)));
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00064f20.bmp"), window)));
        sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                       std::move(sudoeste)));

        std::vector<std::unique_ptr<SdlTexture> > sur;
        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062a2c.bmp"), window)));
        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00061b8d.bmp"), window)));
        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062a2c.bmp"), window)));

        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00061b8d.bmp"), window)));
        sprites.emplace(std::make_pair(Orientation::sur(),
                                       std::move(sur)));
        std::vector<std::unique_ptr<SdlTexture> > sudeste;
        sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00061c8a.bmp"), window)));
        sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062b0c.bmp"), window)));
        sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00063a17.bmp"), window)));
        sprites.emplace(std::make_pair(Orientation::sudeste(),
                                       std::move(sudeste)));

        std::vector<std::unique_ptr<SdlTexture> > este;
        este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062c29.bmp"), window)));
        este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00061d88.bmp"), window)));
        este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00063b15.bmp"), window)));
        sprites.emplace(std::make_pair(Orientation::este(),
                                       std::move(este)));

        std::vector<std::unique_ptr<SdlTexture> > noreste;
        noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00063c32.bmp"), window)));
        noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00061e95.bmp"), window)));
        noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00062d46.bmp"), window)));
        sprites.emplace(std::make_pair(Orientation::noreste(),
                                       std::move(noreste)));

        norte.clear();
        norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00064469.bmp"), window)));
        norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000654ea.bmp"), window)));
        norte.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000665d0.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::norte(),
                                              std::move(norte)));

        noroeste.clear();
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006457d.bmp"), window)));
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000655f5.bmp"), window)));
        noroeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000666db.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::noroeste(),
                                              std::move(noroeste)));

        oeste.clear();
        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00064691.bmp"), window)));
        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00065709.bmp"), window)));
        oeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/000667fc.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::oeste(),
                                              std::move(oeste)));

        sudoeste.clear();
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006478f.bmp"), window)));
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00065826.bmp"), window)));
        sudoeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00066929.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::sudoeste(),
                                              std::move(sudoeste)));

        sur.clear();
        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00064870.bmp"), window)));
        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00065924.bmp"), window)));
        sur.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00066a26.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::sur(),
                                              std::move(sur)));

        sudeste.clear();
        sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006497d.bmp"), window)));
        sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00065a61.bmp"), window)));
        sudeste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00066b53.bmp"), window)));
        attack_sprites.emplace(std::make_pair(Orientation::sudeste(),
                                              std::move(sudeste)));

        este.clear();
        este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00064a7a.bmp"), window)));
        este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00065b5e.bmp"), window)));
        este.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00066c50.bmp"), window)));

        attack_sprites.emplace(std::make_pair(Orientation::este(),
                                              std::move(este)));

        noreste.clear();
        noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00064c37.bmp"), window)));
        noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00065d1b.bmp"), window)));
        noreste.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/00066e0d.bmp"), window)));

        attack_sprites.emplace(std::make_pair(Orientation::noreste(),
                                              std::move(noreste)));

        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006b081.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006b1ca.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006b9d5.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006c2da.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006cc5e.bmp"), window)));
        dead_sprites.emplace_back(std::unique_ptr<SdlTexture>(new SdlTexture(Path::rootVar("assets/img/sprites/0006bc17.bmp"), window)));
    }
    anim_it = sprites.at(orientation.getValor()).begin();
}

void LightInfantryView::draw(Area& camara) {
    if (offensiveUnit.isAttacking() && (offensiveUnit.isShooting() || animating_attack)) {
        drawAttack(camara, attack_sprites);
        if (!animating_attack) {
            anim_it = sprites.at(orientation.getValor()).begin();
        }
    } else {
        if (animating_attack) {
            anim_it = sprites.at(orientation.getValor()).begin();
            animating_attack = false;
        }
        UnitView::draw(camara, sprites, anim_it, update);
    }
}

std::vector<std::unique_ptr<SdlTexture> >& LightInfantryView::getDeadSprites() {
    Sound::getSound()->playDeathFx(deathFx.get());
    return dead_sprites;
}

Area LightInfantryView::getDeadUnitSrcArea() {
    return Area(0, 0, 20, 20);
}

Area LightInfantryView::getDeadUnitDestArea() {
    return Area(0, 0, 20, 20);
}
