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
	int mouse_x, mouse_y;
	bool left_click = false;
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
	   
	   if (left_click){
		if (mouse_x==WIDTH/2 - 1){
			camara.setX(camara.getX()+1);
		}
		if (mouse_y==HEIGHT/2 - 1){
			camara.setY(camara.getY()+1);
		}
		if (mouse_x == 0){
			camara.setX(camara.getX()-1);
		}
		if (mouse_y==0){
			camara.setY(camara.getY()-1);
		}
	    }	

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
			    SDL_GetMouseState(&mouse_x, &mouse_y);
                            map.setDestiny(unidad, mouse_x + camara.getX(), mouse_y + camara.getY());
                        } else if (event.button.button == SDL_BUTTON_LEFT){
				window.grabMouse(false);
				left_click = false;
			}
			break;
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
			break;
		    case SDL_MOUSEBUTTONDOWN:
		    	if (event.button.button == SDL_BUTTON_LEFT){
				window.grabMouse(true);				
				left_click = true;			
			}
			break;
		    case SDL_MOUSEMOTION:
			if (left_click){
				SDL_GetMouseState(&mouse_x,&mouse_y);
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
