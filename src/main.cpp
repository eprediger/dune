#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "SdlException.h"
#include "Area.h"
#include "Map.h"
#include "VistaUnidad.h"
#include "VistaMap.h"

#define SUCCESS 0
#define FAILURE 1

#define WIDTH 1600
#define HEIGHT 1280

int main(int argc, const char* argv[]) {
    try {
        Map map(WIDTH, HEIGHT);
        Unity unidad(WIDTH/2, HEIGHT/2);
        map.put(unidad);
	SdlWindow window(WIDTH/2, HEIGHT/2);
	Area camara(0,0,WIDTH/2,HEIGHT/2);        
	window.fill();
	VistaMap vistaMap(map,window);
	VistaUnidad vistaUnidad(unidad,window);        
	bool running = true;
        int vel = 0;
        while (running) {
	    if (camara.getX() < 0){
		camara.setX(0);
	    }
	    if (camara.getY() < 0){
		camara.setY(0);
	    }
	    if (camara.getX() + camara.getWidth() > map.getWidth()){
		camara.setX(map.getWidth() - camara.getWidth());
	    }
	    if (camara.getY() + camara.getHeight() > map.getHeight()){
		camara.setY(map.getHeight() - camara.getHeight());
	    }
            SDL_Event event;
	    vistaMap.dibujar(camara);
            vistaUnidad.dibujar(camara);
	    while (SDL_PollEvent(&event)) {
                switch(event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_RIGHT) {
                            int x,y;
			    SDL_GetMouseState(&x, &y);
                            map.setDestiny(unidad, x + camara.getX(), y + camara.getY());
                        }
		    case SDL_KEYDOWN:
			switch( event.key.keysym.sym ){
				case SDLK_LEFT:
					camara.setX(camara.getX()-4);
					break;
				case SDLK_RIGHT:
					camara.setX(camara.getX()+4);	
					break;
				case SDLK_DOWN:
					camara.setY(camara.getY()+4);
                    			break;
				case SDLK_UP:
					camara.setY(camara.getY()-4);
					break;
				default:
					break;
			}
		    default:
                        break;
                }
            }
            if (vel == 10){
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
