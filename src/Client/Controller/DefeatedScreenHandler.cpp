
#include "DefeatedScreenHandler.h"

DefeatedScreenHandler::DefeatedScreenHandler(DefeatedScreenView &view) :
    view(view){

}

DefeatedScreenHandler::~DefeatedScreenHandler() {}

#include <iostream>
WindowStatus DefeatedScreenHandler::handleInput() {
    SDL_Event event;
    SDL_WaitEvent(&event);
    if (event.type == SDL_QUIT){
        return WindowStatus::CLOSE;
    }
    return WindowStatus::OPEN;
}
