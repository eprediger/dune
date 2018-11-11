#include <iostream>
#include "View/SdlWindow.h"
#include "View/SdlTexture.h"
#include "View/SdlException.h"
#include "View/Area.h"
#include "Map.h"
#include "View/UnitView.h"
#include "View/UnitViewFactory.h"
#include "View/MapView.h"
#include "Model.h"
#include "View/View.h"
#include "GlobalConfig.h"
#include "Unit/LightInfantry.h"
#include "Unit/Raider.h"
#include "Unit/HeavyInfantry.h"
#include "Unit/Harvester.h"
#include "View/Widget.h"
#include "Buildings/Barracks.h"
#include "Selector.h" 
#include "View/SelectorView.h"
#define SUCCESS 0
#define FAILURE 1

#define WIDTH 1600
#define HEIGHT 1280

config_t GlobalConfig;

int main(int argc, const char* argv[]) {
    try {
        Player player(0);
        int mouse_x, mouse_y;
        bool left_click = false;
//        Map map(WIDTH, HEIGHT);
//        Unit unidad(WIDTH/2, HEIGHT/2);
//		Unit unidad2(20, 20);
//        map.put(unidad);
//        map.put(unidad2);
        SdlWindow window(WIDTH/2, HEIGHT/2);
        Area camara(0,0,WIDTH/2,HEIGHT/2);
        Selector selector(WIDTH/2, HEIGHT/2);
        View vista(window, camara);
        vista.addSelectorView(new SelectorView(selector,window));
        Model model(WIDTH, HEIGHT, 2, vista);
        Map& map = model.getMap();

        window.fill();
        MapView mapView(map,window);
//	UnitView unitView(model.createUnit(WIDTH/2, HEIGHT/2),window);
//	UnitView unitView2(model.createUnit(0,0),window);
//  vista.addUnitView(model.createUnit(WIDTH/2, HEIGHT/2));
        Widget lightInfantryCreator(window, "../imgs/units-btns/linfantry.gif");

        model.createHarvester(300,200, 0);
        model.createTrike(100,200, 0);
        model.createLightInfantry(100,100, 0);
        model.createHeavyInfantry(200,200, 0);
        model.createRaider(100,150, 0);
        model.createRaider(400,150, 0);
        model.createRaider(180,150, 0);
        model.createTank(250,200, 0);

        model.createBarracks(50, 600, 0);

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

            selector.pos.x = mouse_x+camara.getX();
            selector.pos.y = mouse_y+camara.getY();
            SDL_Event event;
            mapView.draw(camara);
//            unitView.draw(camara);
//            unitView2.draw(camara);
            vista.draw();
            lightInfantryCreator.draw();
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
                            // Descomentando esto y comentando lo de abajo, se permite atacar entre todos
//                            Unit* objetiveUnit = map.getClosestUnit(pos, 50 * 50);


                            for (auto& unit:selector.selection.getSelectedUnits()){
                                model.actionOnPosition(pos, *unit);
                            }

                        } else if (event.button.button == SDL_BUTTON_LEFT){
                            selector.drag = false;
                            Area selectArea(selector.drag_source,selector.pos);
                            std::vector<Unit*> selection = model.selectUnitsInArea(selectArea,player);
                            selector.addSelection(selection); 
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
                            SDL_GetMouseState(&mouse_x, &mouse_y);
                            std::cout << "x: " << mouse_x << " y: " << mouse_y << std::endl;
                            if (((mouse_x >= 650) && (mouse_x <= 716)) && ((mouse_y >= 500) && (mouse_y <= 566))) {
                                model.createHeavyInfantry(500,500, 1);
                            }
                            selector.drag = true;
                            selector.drag_source = selector.pos;
                        }
                        break;
                    case SDL_MOUSEMOTION:
                        
                            SDL_GetMouseState(&mouse_x,&mouse_y);
                            break;
                        
                    default:
                        break;
                }
            }
			vista.cleanDeadUnitViews();
			selector.selection.eraseDeads();
            model.step();
            window.render();
        }
    } catch (const SdlException& e) {
        std::cerr << e.what() << std::endl;
        return FAILURE;
    }

    return SUCCESS;
}
