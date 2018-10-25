#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "SdlException.h"
#include "Area.h"
#include "Map.h"

#define SUCCESS 0
#define FAILURE 1

#define WIDTH 800
#define HEIGTH 600

int main(int argc, const char* argv[]) {
    try {
        Map::create(WIDTH, HEIGTH);
        Unity unidad(WIDTH/2, HEIGTH/2);
        Map::getInstance()->put(unidad);

        SdlWindow window(WIDTH, HEIGTH);
        window.fill();
        SdlTexture im("../imgs/imgs/000a6d70.bmp", window);
        Area srcArea(0, 0, 41, 38); // estos numeros?
        bool running = true;
        int vel = 0;
        while (running) {
            SDL_Event event;
            int x = unidad.getPosition().getX();
            int y = unidad.getPosition().getY();
            Area destArea(x, y, 41, 38);
            window.fill(); // Repinto el fondo gris
            im.render(srcArea, destArea);
            while (SDL_PollEvent(&event)) {
//            SDL_WaitEvent(&event);
                switch(event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_RIGHT) {
                            SDL_GetMouseState(&x, &y);
                            Map::getInstance()->setDestiny(unidad, x, y);
                        }
                    default:
                        break;
                }
            }
            if (vel == 100){
                unidad.move();
                vel = 0;
            }
            vel++;
            window.render();
        }
    } catch (const SdlException& e) {
        std::cerr << e.what() << std::endl;
        return FAILURE;
    }
    return SUCCESS;
}
