#include "GameHandler.h"
#include "ButtonHandlerHarvester.h"
#include "ButtonHandlerTank.h"
#include "ButtonHandlerTrike.h"
#include "ButtonHandlerRaider.h"
#include "ButtonHandlerHeavyInfantry.h"
#include "ButtonHandlerLightInfantry.h"
#include "ButtonHandlerBarracks.h"
#include "ButtonHandlerHeavyFactory.h"
#include "ButtonHandlerLightFactory.h"
#include "ButtonHandlerSpiceRefinery.h"
#include "ButtonHandlerSpiceSilo.h"
#include "ButtonHandlerWindTrap.h"
#include "../View/UnitViewFactory.h"
#include <vector>

GameHandler::GameHandler(GameView &view, Model &model) :
    InputHandler(),
    view(view),
    model(model),
    selector(0, 0),
    constructor(model,model.getPlayer(0),view) {
    view.addSelectorView(this->selector);
    this->buttons.push_back(new ButtonHandlerWindTrap(this->model, this->view, constructor));
    this->buttons.push_back(new ButtonHandlerSpiceRefinery(this->model, this->view, constructor));
    this->buttons.push_back(new ButtonHandlerBarracks(this->model, this->view, constructor));
    this->buttons.push_back(new ButtonHandlerHeavyFactory(this->model, this->view, constructor));
    this->buttons.push_back(new ButtonHandlerLightFactory(this->model, this->view, constructor));
    this->buttons.push_back(new ButtonHandlerSpiceSilo(this->model, this->view, constructor));
    this->buttons.push_back(new ButtonHandlerLightInfantry(this->model, this->view));
    this->buttons.push_back(new ButtonHandlerHeavyInfantry(this->model, this->view));
    this->buttons.push_back(new ButtonHandlerTrike(this->model, this->view));
    this->buttons.push_back(new ButtonHandlerRaider(this->model, this->view));
    this->buttons.push_back(new ButtonHandlerTank(this->model, this->view));
    this->buttons.push_back(new ButtonHandlerHarvester(this->model, this->view));
}

GameHandler::~GameHandler() {
    while (!this->buttons.empty()) {
        delete this->buttons.back();
        this->buttons.pop_back();
    }
}

bool GameHandler::handleInput() {
    bool keepPlaying = true;
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        keepPlaying = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) {
            //this->view.grabMouse();
            this->cursor.initialPosition();
            if (constructor.on == false){ 
                this->selector.drag = true;
                this->selector.drag_source = selector.pos;
            }
        }
        break;
    case SDL_MOUSEMOTION:
        this->cursor.currentPosition();
        this->selector.pos.x = this->cursor.current_x + this->view.getCameraX();
        this->selector.pos.y = this->cursor.current_y + this->view.getCameraY();
        this->constructor.pos.x = this->selector.pos.x;
        this->constructor.pos.y = this->selector.pos.y;
        break;
    case SDL_MOUSEBUTTONUP:
        this->cursor.currentPosition();
        if (event.button.button == SDL_BUTTON_LEFT) {
            this->selector.drag = false;
            Area selectArea(this->selector.drag_source, this->selector.pos);
            std::vector<Unit*> selection = model.selectUnitsInArea(selectArea, model.getPlayer(0));
            this->selector.addSelection(selection);
            this->view.releaseMouse();
            if (constructor.on){
                constructor.build();
            }
            for (auto& button : this->buttons) {
                button->update(this->cursor.current_x, this->cursor.current_y);
            }

        }
        // TEST
        if (event.button.button == SDL_BUTTON_MIDDLE) {
            Raider& raider = model.createRaider(this->cursor.current_x, this->cursor.current_y, 0);
            view.addUnitView(UnitViewFactory::createUnitView(raider, view.getWindow()));

            Harvester& harvester = model.createHarvester(this->cursor.current_x, this->cursor.current_y, 0);
            view.addUnitView(UnitViewFactory::createUnitView(harvester, view.getWindow()));
        }
        if (event.button.button == SDL_BUTTON_RIGHT) {
            this->cursor.currentPosition();
            this->constructor.on = false;
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
    return keepPlaying;
}
