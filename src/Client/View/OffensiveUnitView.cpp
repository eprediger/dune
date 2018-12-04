#include "OffensiveUnitView.h"
#include <map>
#include <vector>
#include "Sound.h"
#include <memory>
#include <Path.h>

std::unique_ptr<Mix_Chunk> OffensiveUnitView::machineGunFx;

OffensiveUnitView::OffensiveUnitView(OffensiveUnit& unit, Area sprite_area, SdlWindow& window) :
    UnitView(unit, sprite_area, window),
    offensiveUnit(unit),
    anim_it(),
    update(0),
    animating_attack(false)
{
    if (!machineGunFx)
        machineGunFx = std::move(std::unique_ptr<Mix_Chunk>(Mix_LoadWAV(Path::rootVar("assets/sound/fx/machine gun.wav").c_str())));
}

void OffensiveUnitView::drawAttack(Area& camara, std::map<int, std::vector<std::unique_ptr<SdlTexture> > >& sprites) {
    prev_pos = offensiveUnit.getPosition();
    if ((!animating_attack) || (*anim_it == nullptr)) {
        orientation.calcularEnAtaque(prev_pos, offensiveUnit.getVictimPosition());
        animating_attack = true;
        anim_it = sprites.at(orientation.getValor()).begin();
        update = 0;
        if (offensiveUnit.getUnitType()!=Unit::HEAVY_INFANTRY)
            Sound::getSound()->playShootingFx(machineGunFx.get());
    }
    dest_area.setX(prev_pos.x - camara.getX() - sprite_area.getWidth() / 2);
    dest_area.setY(prev_pos.y - camara.getY() - sprite_area.getHeight() / 2);
    playerColorRect.x = dest_area.getX();
    playerColorRect.y = dest_area.getY();
    if (camara.anyInteract(dest_area)) {
        SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(window.getRenderer(), player_r, player_g, player_b, 250);
        SDL_RenderDrawRect(window.getRenderer(), &playerColorRect);
        SDL_SetRenderDrawColor(window.getRenderer(), player_r, player_g, player_b, 30);
        SDL_RenderFillRect(window.getRenderer(), &playerColorRect);
        (*anim_it)->render(sprite_area, dest_area);
    }
    update++;
    if (update == 10) {
        anim_it++;
        update = 0;
        if (anim_it == sprites.at(orientation.getValor()).end()) {
            animating_attack = false;
        }
    }
}
