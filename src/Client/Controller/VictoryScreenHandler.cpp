
#include "VictoryScreenHandler.h"

VictoryScreenHandler::VictoryScreenHandler(VictoryScreenView &view) :
    view(view){

}

VictoryScreenHandler::~VictoryScreenHandler() {}

#include <iostream>
WindowStatus VictoryScreenHandler::handleInput() {
    SDL_Event event;
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT){
        return WindowStatus::CLOSE;
    }
    return WindowStatus::OPEN;
}
