#include "GameHandler.h"
#include "View/UnitViewFactory.h"
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
#include "ButtonHandlerSellBuilding.h"
#include <vector>

GameHandler::GameHandler(GameView &view, Model &model, CommunicationQueue &queue, Player& player) :
    InputHandler(),
    view(view),
    model(model),
    player(player),
    selector(0, 0),
    dragger(view),
    constructor(model, player, view, queue),
    queue(queue),
    interface(model, view) {
    view.addSelectorView(this->selector);
    this->buttons.push_back(new ButtonHandlerWindTrap(player, this->view, constructor, this->queue));
    this->buttons.push_back(new ButtonHandlerSpiceRefinery(player, this->view, constructor, this->queue));
    this->buttons.push_back(new ButtonHandlerBarracks(player, this->view, constructor, this->queue));
    this->buttons.push_back(new ButtonHandlerLightFactory(player, this->view, constructor, this->queue));
    this->buttons.push_back(new ButtonHandlerHeavyFactory(player, this->view, constructor, this->queue));
    this->buttons.push_back(new ButtonHandlerSpiceSilo(player, this->view, constructor, this->queue));
    this->buttons.push_back(new ButtonHandlerLightInfantry(player, this->view, this->queue));
    this->buttons.push_back(new ButtonHandlerHeavyInfantry(player, this->view, this->queue));
    this->buttons.push_back(new ButtonHandlerTrike(player, this->view, this->queue));
    this->buttons.push_back(new ButtonHandlerRaider(player, this->view, this->queue));
    this->buttons.push_back(new ButtonHandlerTank(player, this->view, this->queue));
    this->buttons.push_back(new ButtonHandlerHarvester(player, this->view, this->queue));
    this->buttons.push_back(new ButtonHandlerSellBuilding(player, this->view, this->selector, this->queue));
    for (auto& button : this->buttons) {
        if (button->canBeEnabled()) {
            button->setState(State::ENABLED);
        }
    }
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
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        keepPlaying = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT) {
            //this->view.grabMouse();
            this->cursor.initialPosition();
            if (constructor.on == false) {
                this->selector.drag = true;
                this->selector.drag_source = selector.pos;
            }
        }
        if (event.button.button == SDL_BUTTON_MIDDLE) {
            this->cursor.currentPosition();
            Position curr_pos(cursor.current_x, cursor.current_y);
            dragger.on(curr_pos);
        }
        break;
    case SDL_MOUSEMOTION:
        this->cursor.currentPosition();
        if (dragger.isOn()){
            dragger.move(Position(cursor.current_x, cursor.current_y));
        }

        if (this->cursor.current_x >= view.getCameraWidth()) {
            this->selector.pos.x = this->view.getCameraX() + this->view.getCameraWidth() - 128;
        } else {
            this->selector.pos.x = this->view.getCameraX() + this->cursor.current_x;
        }
        this->selector.pos.y = this->cursor.current_y + this->view.getCameraY();
        this->constructor.pos.x = this->selector.pos.x;
        this->constructor.pos.y = this->selector.pos.y;
        break;
    case SDL_MOUSEBUTTONUP:
        this->cursor.currentPosition();
        if (event.button.button == SDL_BUTTON_LEFT) {
            this->selector.drag = false;
            Area selectArea(this->selector.drag_source, this->selector.pos);
            std::vector<Unit*> selection = model.selectUnitsInArea(selectArea, player);
            std::vector<Building*> selected_buildings = model.selectBuildingsInArea(selectArea, player);
            this->selector.addSelection(selection);
            this->selector.addSelection(selected_buildings);
            this->view.releaseMouse();
            if (constructor.on) {
                constructor.build();
            }
            for (auto& button : this->buttons) {
                button->handleUserInput(this->cursor.current_x, this->cursor.current_y);
            }
        }
        // TEST
        if (event.button.button == SDL_BUTTON_RIGHT) {
            this->cursor.currentPosition();
            this->constructor.on = false;
            Position pos(this->cursor.current_x + this->view.getCameraX(), this->cursor.current_y + this->view.getCameraY());
            for (auto& unit : this->selector.selection.getSelectedUnits()) {
                nlohmann::json j;
                j["method"] = "actionOnPosition";
                j["args"]["player_id"] = unit->getPlayer().getId();
                j["args"]["unit_id"] = unit->id;
                j["args"]["x"] = pos.x;
                j["args"]["y"] = pos.y;
                queue.enqueue(j);
            }
        }
        if (event.button.button == SDL_BUTTON_MIDDLE) {
            dragger.off();
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

        case SDLK_DELETE:
        case SDLK_BACKSPACE:
        {
            std::vector<Building*>& to_sell = this->selector.selection.getSelectedBuildings();
            for (auto itr = to_sell.begin(); itr != to_sell.end() ; itr++) {
                nlohmann::json msg;
                msg["method"] = "sellBuilding";
                msg["args"]["player_id"] = player.getId();
                msg["args"]["building_id"] = (*itr)->id;
                queue.enqueue(msg);
            }
        }
        break;
        default:
            break;
        }
        break;
    }

    return keepPlaying;
}

void GameHandler::update() {
    for (auto& button : this->buttons) {
        button->update();
    }
    this->selector.selection.eraseDeads();
}
