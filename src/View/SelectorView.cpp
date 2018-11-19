#include "SelectorView.h"
#include "../Selector.h"
#include "../Model/Attackable.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

SelectorView::SelectorView(Selector& selector, SdlWindow& window) :
    window(window),
    selector(selector),
    drag_rect(),
    max_life(),
    current_life() {
    max_life.h = 4;
    current_life.h = 4;
}

void SelectorView::drawLife(Building* building, Area& camara) {
    max_life.w = building->getInitialLife() / 4;
    if (max_life.w > 80)
        max_life.w = 80;
    max_life.x = building->getPosition().x - 20 - camara.getX();
    max_life.y = building->getPosition().y + 10 - camara.getY();
    SDL_SetRenderDrawColor(window.getRenderer(), 0, 0, 0, 0xFF);
    SDL_RenderFillRect(window.getRenderer(), &max_life);
    float factor = float(building->getLife()) / float(building->getInitialLife());
    current_life.w = max_life.w * factor;
    current_life.x = max_life.x;
    current_life.y = max_life.y;
    int r, g;
    if (factor < 0.65) {
        if (factor < 0.3) {
            r = 128;
            g = 0;
        } else {
            r = 160;
            g = 160;
        }
    } else {
        r = 0;
        g = 128;
    }
    SDL_SetRenderDrawColor(window.getRenderer(), r, g, 0, 0xFF);
    SDL_RenderFillRect(window.getRenderer(), &current_life);
}

void SelectorView::drawLife(Unit* unit, Area& camara) {
    max_life.w = unit->getInitialLife() / 2;
    max_life.x = unit->getPosition().x - 20 - camara.getX();
    max_life.y = unit->getPosition().y + 10 - camara.getY();
    if (max_life.w > 80)
        max_life.w = 80;
    SDL_SetRenderDrawColor(window.getRenderer(), 0, 0, 0, 0xFF);
    SDL_RenderFillRect(window.getRenderer(), &max_life);
    float factor = float(unit->getLife()) / float(unit->getInitialLife());
    current_life.w = max_life.w * factor;
    current_life.x = max_life.x;
    current_life.y = max_life.y;
    int r, g;
    if (factor < 0.65) {
        if (factor < 0.3) {
            r = 128;
            g = 0;
        } else {
            r = 160;
            g = 160;
        }
    } else {
        r = 0;
        g = 128;
    }
    SDL_SetRenderDrawColor(window.getRenderer(), r, g, 0, 0xFF);
    SDL_RenderFillRect(window.getRenderer(), &current_life);
}

void SelectorView::drawSelection(Area& camara) {
    SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_NONE);
    std::vector<Unit*>& units = selector.selection.getSelectedUnits();
    std::vector<Unit*>::iterator units_it = units.begin();
    while (units_it != units.end()) {
        drawLife((*units_it), camara);
        units_it++;
    }
    std::vector<Building*>& buildings = selector.selection.getSelectedBuildings();
    std::vector<Building*>::iterator building_it = buildings.begin();
    while (building_it != buildings.end()) {
        drawLife((*building_it), camara);
        building_it++;
    }
}

void SelectorView::draw(Area& camara) {
    if (selector.drag) {
        drag_rect.x = selector.drag_source.x - camara.getX();
        drag_rect.y = selector.drag_source.y - camara.getY();
        drag_rect.w = selector.pos.x - selector.drag_source.x;
        drag_rect.h = selector.pos.y - selector.drag_source.y;
        SDL_SetRenderDrawBlendMode(window.getRenderer(), SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(window.getRenderer(), 0, 128, 0, 0xFF);
        SDL_RenderDrawRect(window.getRenderer(), &drag_rect);
        SDL_SetRenderDrawColor(window.getRenderer(), 0, 128, 64, 80);
        SDL_RenderFillRect(window.getRenderer(), &drag_rect);
    } else {
        drawSelection(camara);
    }
}
