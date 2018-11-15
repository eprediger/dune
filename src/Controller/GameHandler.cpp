#include "GameHandler.h"
#include "ButtonHandlerHarvester.h"
#include "ButtonHandlerTank.h"
#include "ButtonHandlerTrike.h"
#include "ButtonHandlerRaider.h"
#include "ButtonHandlerHeavyInfantry.h"
#include "ButtonHandlerLightInfantry.h"
#include "../View/UnitViewFactory.h"

GameHandler::GameHandler(GameView &view, Model &model) :
        InputHandler(),
        view(view),
        model(model),
        selector(0,0) {
    view.addSelectorView(this->selector);
}

GameHandler::~GameHandler() {
    while (!this->buttons.empty()) {
        delete this->buttons.back();
        this->buttons.pop_back();
    }
}

bool GameHandler::handleInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            return false;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                //this->view.grabMouse();
                this->cursor.initialPosition();
                this->selector.drag = true;
                this->selector.drag_source = selector.pos;
            }
            break;
        case SDL_MOUSEMOTION:
            this->cursor.currentPosition();
            this->selector.pos.x = this->cursor.current_x + this->view.getCameraX();
            this->selector.pos.y = this->cursor.current_y + this->view.getCameraY();
            break;
        case SDL_MOUSEBUTTONUP:
            this->cursor.currentPosition();
            if (event.button.button == SDL_BUTTON_LEFT) {
                    this->selector.drag = false;
                    Area selectArea(this->selector.drag_source, this->selector.pos);
                    std::vector<Unit*> selection = model.selectUnitsInArea(selectArea, model.getPlayer(0));
                    this->selector.addSelection(selection);
                this->view.releaseMouse();

                for (auto button : buttons){
                    button->onClicked(this->cursor.current_x, this->cursor.current_y);
                }

            }
            // TEST
            if (event.button.button == SDL_BUTTON_MIDDLE) {
                Raider& raider = model.createRaider(this->cursor.current_x, this->cursor.current_y, 0);
                view.addUnitView(UnitViewFactory::createUnitView(raider, view.getWindow()));

                Raider& raider2 = model.createRaider(this->cursor.current_x+150, this->cursor.current_y+150, 1);
                view.addUnitView(UnitViewFactory::createUnitView(raider2, view.getWindow()));
            
                HeavyInfantry& li = model.createHeavyInfantry(this->cursor.current_x+150, this->cursor.current_y+0, 0);
                view.addUnitView(UnitViewFactory::createUnitView(li, view.getWindow()));
            
                Harvester& harv = model.createHarvester(this->cursor.current_x+150, this->cursor.current_y+100, 0);
                view.addUnitView(UnitViewFactory::createUnitView(harv, view.getWindow()));
            }
            if (event.button.button == SDL_BUTTON_RIGHT) {
                this->cursor.currentPosition();

                //this->model.getMap().setDestiny(unit, this->cursor.current_x + this->view.getCameraX(), this->cursor.current_y + this->view.getCameraY());
                Position pos(this->cursor.current_x + this->view.getCameraX(), this->cursor.current_y + this->view.getCameraY());
                for (auto& unit : this->selector.selection.getSelectedUnits()) {
                    this->model.actionOnPosition(pos, *unit);
                }
            }
            break;
        case SDL_KEYDOWN:
            switch ( event.key.keysym.sym ) {
                case SDLK_LEFT:
                case SDLK_a:
                    view.moveLeft(MOVE_AMOUNT);
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
                    view.moveRight(MOVE_AMOUNT);
                    break;
                case SDLK_DOWN:
                case SDLK_s:
                    view.moveDown(MOVE_AMOUNT);
                    break;
                case SDLK_UP:
                case SDLK_w:
                    view.moveUp(MOVE_AMOUNT);
                    break;
                default:
                    break;
            }
            break;
    }
    this->view.cleanDeadUnitViews();
    this->selector.selection.eraseDeads();
    return true;
}
