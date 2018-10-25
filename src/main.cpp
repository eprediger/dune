//
// Created by emiliano on 24/10/18.
//

#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "SdlException.h"
#include "Area.h"
#include "Map.h"

#define SUCCESS 0
#define FAILURE 1

int main(int argc, const char* argv[]) {



    Unity soldado1;
    Unity soldado2;

    std::cout << "Vida Soldado 1 [Esp: 50]: " << soldado1.getLife() << std::endl;
    std::cout << "Vida Soldado 2 [Esp: 50]: " << soldado2.getLife() << std::endl;

    soldado1.attack(soldado2);

    std::cout << "Vida Soldado 1 [Esp: 50]: " << soldado1.getLife() << std::endl;
    std::cout << "Vida Soldado 2 [Esp: 48]: " << soldado2.getLife() << std::endl;








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
