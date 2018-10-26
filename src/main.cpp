//
// Created by emiliano on 24/10/18.
//

#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "SdlException.h"
#include "Area.h"
#include "Map.h"
#include "Unity.h"
#include "Building.h"

#define SUCCESS 0
#define FAILURE 1

int main(int argc, const char* argv[]) {

    Map mapa;
    Unity soldado1(0,0);
    Unity soldado2(0,20);
    Unity soldado3(0,10);
    Unity soldado4(1,30);
    Unity soldado5;
    Unity soldado6;
    Building edificio;

    mapa.put(soldado1);
    mapa.put(soldado2);
    mapa.put(soldado3);
    mapa.put(soldado4);

    std::cout << "Vida Soldado 1 [Esp: 50]: " << soldado1.getLife() << std::endl;
    std::cout << "Vida Soldado 2 [Esp: 50]: " << soldado2.getLife() << std::endl;

    std::cout << "Soldado 1 ataca a Soldado 2" << std::endl;
    soldado1.attack(soldado2);

    std::cout << "Vida Soldado 1 [Esp: 50]: " << soldado1.getLife() << std::endl;
    std::cout << "Vida Soldado 2 [Esp: 48]: " << soldado2.getLife() << std::endl;

    std::cout << "Soldado 2 ataca a Soldado 1" << std::endl;
    soldado2.attack(soldado1);
    std::cout << "Vida Soldado 1 [Esp: 48]: " << soldado1.getLife() << std::endl;
    std::cout << "Vida Soldado 2 [Esp: 48]: " << soldado2.getLife() << std::endl;

    std::cout << "Soldado 1 ataca automaticamente" << std::endl;
    soldado1.automaticAttack(mapa);
    mapa.cleanDeadUnitys();
    std::cout << "Vida Soldado 1 [Esp: 50]: " << soldado1.getLife() << std::endl;
    std::cout << "Vida Soldado 2 [Esp: 46]: " << soldado2.getLife() << std::endl;
    std::cout << "Vida Soldado 3 [Esp: ?]: " << soldado3.getLife() << std::endl;
    std::cout << "Vida Soldado 4 [Esp: ?]: " << soldado4.getLife() << std::endl;

    while (soldado2.getLife() > 0){
        soldado1.attack(soldado2);
        std::cout << "Vida Soldado 2: " << soldado2.getLife() << std::endl;
    }

    mapa.cleanDeadUnitys();
    std::cout << "Se limpio el mapa" << std::endl;


    std::cout << "Soldado 1 ataca al edificio" << std::endl;
    soldado1.attack(edificio);
    std::cout << "Vida Soldado 1: " << soldado1.getLife() << std::endl;
    std::cout << "Vida edificio: " << edificio.getLife() << std::endl;





//    try {
//        Map map(640, 480);
//        Unity unity(0,0);
//        SdlWindow window(640, 480);
//        window.fill();
//        SdlTexture im("../imgs/imgs/000a6d70.bmp", window);
//        Area srcArea(0, 0, 41, 38); // estos numeros?
//        int i = 0;
//        int vel = 1;
//        bool running = true;
//        while (running) {
//            int x = unity.getPosition().getX();
//            int y = unity.getPosition().getY();
//            SDL_Event event;
//            Area destArea(x, y, 41, 38);
//            window.fill(); // Repinto el fondo gris
//            im.render(srcArea, destArea);
//            SDL_PollEvent(&event);
//            switch(event.type) {
//                case SDL_QUIT:
//                    running = false;
//                    break;
//                case SDL_KEYDOWN:
//                    if (event.key.keysym.sym == SDLK_UP){
//                        vel++;
//                        std::cout << "Vel: " << vel << std::endl;
//                    } else if (event.key.keysym.sym == SDLK_DOWN){
//                        if (vel != 1) {
//                            vel--;
//                            i = 0;
//                            std::cout << "Vel: " << vel << std::endl;
//                        }
//                    }
//                    break;
//                case SDL_MOUSEBUTTONUP:
//                    if (event.button.button == SDL_BUTTON_RIGHT){
//                        SDL_GetMouseState(&x,&y);
//                        map.setDestiny(unity, x, y);
//                    }
//                default:
//                    break;
//            }
//
//            if (i == vel){
//                unity.move();
//                i = 0;
//            }
//            window.render();
//            i++;
//        }
//    } catch (const SdlException& e) {
//        std::cerr << e.what() << std::endl;
//        return FAILURE;
//    }
    return SUCCESS;
}
