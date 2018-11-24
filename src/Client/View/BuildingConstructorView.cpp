#include "BuildingConstructorView.h"
#include "PlayerColorMaker.h"

BuildingConstructorView::BuildingConstructorView(BuildingConstructor& constructor,
        SdlWindow& window) :
    constructor(constructor),
    window(window),
    rect() {
    PlayerColorMaker::makeColor(constructor.getPlayer(), &r, &g, &b);
}

void BuildingConstructorView::draw(Area& camara) {
    PlayerColorMaker::makeColor(constructor.getPlayer(), &r, &g, &b);
    if (constructor.on) {
        SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
        if (constructor.canWeBuild()) {
            SDL_SetRenderDrawColor(window.getRenderer(), r, g, b, 60);
        } else {
            SDL_SetRenderDrawColor(window.getRenderer(), 64, 64, 64, 60);
        }
        rect.x = constructor.pos.x - camara.getX();
        rect.y = constructor.pos.y - camara.getY();
        rect.w = constructor.width * 32;
        rect.h = constructor.height * 32;

        SDL_RenderFillRect(window.getRenderer(), &rect);
    }
}
