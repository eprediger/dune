//
// Created by emiliano on 24/10/18.
//

#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "SdlException.h"
#include "Area.h"

#define SUCCESS 0
#define FAILURE 1

int main(int argc, const char* argv[]) {
    try {
        SdlWindow window(640, 480);
        window.fill();
        SdlTexture im("../imgs/imgs/000a6d70.bmp", window);
        Area srcArea(0, 0, 41, 38); // estos numeros?
        int x = 0;
        int y = 0;
        bool running = true;
        while (running) {
            SDL_Event event;
            Area destArea(x, y, 41, 38);
            window.fill(); // Repinto el fondo gris
            im.render(srcArea, destArea);
            SDL_WaitEvent(&event);
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
            window.render();
        }
    } catch (const SdlException& e) {
        std::cerr << e.what() << std::endl;
        return FAILURE;
    }
    return SUCCESS;
}
