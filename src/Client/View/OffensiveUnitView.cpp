#include "OffensiveUnitView.h"
#include <map>
#include <vector>

OffensiveUnitView::OffensiveUnitView(OffensiveUnit& unit, Area sprite_area, SdlWindow& window) :
    UnitView(unit, sprite_area, window),
    offensiveUnit(unit),
    anim_it(),
    update(0),
    animating_attack(false) {}

void OffensiveUnitView::drawAttack(Area& camara, std::map<int, std::vector<std::unique_ptr<SdlTexture> > >& sprites) {
   prev_pos = offensiveUnit.getPosition();
    if ((!animating_attack) || (*anim_it == nullptr)) {
        Orientation prev_orient = orientation;
        orientation.calcularEnAtaque(prev_pos, offensiveUnit.getVictimPosition());
        animating_attack = true;
        anim_it = sprites.at(orientation.getValor()).begin();
        update = 0;
    }
    dest_area.setX(prev_pos.x - camara.getX() - sprite_area.getWidth() / 2);
    dest_area.setY(prev_pos.y - camara.getY() - sprite_area.getHeight() / 2);
    playerColorRect.x = dest_area.getX();
    playerColorRect.y = dest_area.getY();
    SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(window.getRenderer(), player_r, player_g, player_b, 250);
    SDL_RenderDrawRect(window.getRenderer(), &playerColorRect);
    SDL_SetRenderDrawColor(window.getRenderer(), player_r, player_g, player_b, 30);
    SDL_RenderFillRect(window.getRenderer(), &playerColorRect);
    (*anim_it)->render(sprite_area, dest_area);
    update++;
    if (update == 10) {
        anim_it++;
        update = 0;
        if (anim_it == sprites.at(orientation.getValor()).end()) {
            animating_attack = false;
        }
    }
}
