#include <iostream>
#include "View/SdlWindow.h"
#include "View/SdlTexture.h"
#include "View/SdlException.h"
#include "View/Area.h"
#include "Map.h"
#include "View/VistaUnidad.h"
#include "View/VistaMap.h"
#include "Model.h"
#include "View/View.h"
#include "GlobalConfig.h"
#include "Unit/light-infantry.h"
#include "Unit/raider.h"
#include "Unit/heavy-infantry.h"

#define SUCCESS 0
#define FAILURE 1

#define WIDTH 1600
#define HEIGHT 1280

config_t GlobalConfig;

int main(int argc, const char* argv[]) {
    try {
	int mouse_x, mouse_y;
	bool left_click = false;
//        Map map(WIDTH, HEIGHT);
//        Unit unidad(WIDTH/2, HEIGHT/2);
//		Unit unidad2(20, 20);
//        map.put(unidad);
//        map.put(unidad2);
    Model model(WIDTH, HEIGHT);
    Map& map = model.getMap();
	SdlWindow window(WIDTH/2, HEIGHT/2);
	Area camara(0,0,WIDTH/2,HEIGHT/2);

	View vista(window, camara);
	window.fill();
	VistaMap vistaMap(map,window);
//	VistaUnidad vistaUnidad(model.createUnit(WIDTH/2, HEIGHT/2),window);
//	VistaUnidad vistaUnidad2(model.createUnit(0,0),window);
//    vista.addUnitView(model.createUnit(WIDTH/2, HEIGHT/2));
    vista.addUnitView(model.createUnit(std::move(new LightInfantry(0, 0))));
    vista.addUnitView(model.createUnit(std::move(new Raider(89, 0))));

    vista.addUnitView(model.createUnit(std::move(new LightInfantry(0, 100))));
    vista.addUnitView(model.createUnit(std::move(new Raider(89, 100))));

    vista.addUnitView(model.createUnit(std::move(new LightInfantry(0, 200))));
    vista.addUnitView(model.createUnit(std::move(new HeavyInfantry(89, 200))));

    vista.addUnitView(model.createUnit(std::move(new LightInfantry(0, 300))));
    vista.addUnitView(model.createUnit(std::move(new HeavyInfantry(89, 300))));

	bool running = true;
	Unit* selectedUnit;
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
//            vistaUnidad.dibujar(camara);
//            vistaUnidad2.dibujar(camara);
		vista.draw();
	    while (SDL_PollEvent(&event)) {
                switch(event.type) {
                    case SDL_QUIT:
                        running = false;
                        break;
                    case SDL_MOUSEBUTTONUP:
                        if (event.button.button == SDL_BUTTON_RIGHT) {
			    			SDL_GetMouseState(&mouse_x, &mouse_y);
//                            map.setDestiny(unidad, mouse_x + camara.getX(), mouse_y + camara.getY());
							Position pos(mouse_x + camara.getX(), mouse_y + camara.getY());
							Unit* objetiveUnit = map.getClosestUnit(pos, 50 * 50);

							if (objetiveUnit != nullptr && selectedUnit != nullptr && objetiveUnit != selectedUnit) {
//								selectedUnit->attack(*objetiveUnit);
								// Descomentar y comentar el ataque para que la unidad siga a otra hasta alcanzarla y matarla
								// No funciona si la unidad a seguir se encuentra en movimiento
								selectedUnit->follow(objetiveUnit, map);
							} else if (selectedUnit != nullptr) {
								map.setDestiny(*selectedUnit, mouse_x + camara.getX(), mouse_y + camara.getY());
							}
                        } else if (event.button.button == SDL_BUTTON_LEFT){
							window.grabMouse(false);
							left_click = false;
							// TMP //
							int x, y;
							SDL_GetMouseState(&x, &y);
							Position pos(x + camara.getX(), y + camara.getY());
							selectedUnit = map.getClosestUnit(pos, 32 * 32);
							// END_TMP //
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

			model.step();
            window.render();
        }
    } catch (const SdlException& e) {
        std::cerr << e.what() << std::endl;
        return FAILURE;
    }

    return SUCCESS;
}
