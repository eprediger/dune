#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "SdlException.h"
#include "Area.h"
#include "Map.h"
#include "VistaUnidad.h"

#define SUCCESS 0
#define FAILURE 1

#define WIDTH 800
#define HEIGHT 600

int main(int argc, const char* argv[]) {
    try {
        Map map(WIDTH, HEIGHT);
        Unity unidad(WIDTH/2, HEIGHT/2);
        map.put(unidad);

        SdlWindow window(WIDTH, HEIGHT);
        window.fill();
	VistaUnidad vista(unidad,window);        
	bool running = true;
        int vel = 0;
        while (running) {
            SDL_Event event;
            window.fill(); // Repinto el fondo gris
            vista.dibujar();
	    while (SDL_PollEvent(&event)) {
                switch(event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_RIGHT) {
                            int x,y;
			    SDL_GetMouseState(&x, &y);
                            map.setDestiny(unidad, x, y);
                        }
                    default:
                        break;
                }
            }
            if (vel == 20){
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
