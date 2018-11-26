#include <iostream>
#include <string>

#include <nlohmann/json.hpp>
#include "Model/GlobalConfig.h"

#include "Application.h"
#include "Model/GlobalConfig.h"
#include "Codes.h"
#include "Client.h"

#include "View/GameView.h"
#include "Controller/GameHandler.h"
#include "View/GameView.h"

#include <iostream>

// ./client 127.0.0.1 10001 ORDOS

#define MAX_FPS	60
#define SECOND	1000

config_t GlobalConfig;

int main(int argc, const char *argv[]) {
//    if (argc != CLT_ARGS) {
    if (argc != 5) {
        std::cerr << "Uso: " << argv[0]
                  << " <ip-servidor> <puerto-servidor> <casa> [<mapa> (Temporal)]" << std::endl;
        return USAGE_ERROR;
    } else {
        CommunicationQueue queue;
        Client client(argv[1], argv[2], queue);
        try {
            /*MainMenuView menuView(WINDOW_WIDTH, WINDOW_HEIGHT);
            MainMenuHandler menuHandler(menuView);
            Application app(menuView, menuHandler);*/

            /*HouseSelectionView houseSelectionView(WINDOW_WIDTH, WINDOW_HEIGHT);
            HouseSelectionHandler houseSelectionHandler(houseSelectionView);
            Application app(houseSelectionView, houseSelectionHandler);*/

            Model model(argv[4], 3, queue);
            GameView gameView(WINDOW_WIDTH, WINDOW_HEIGHT, model);
            GameHandler gameHandler(gameView, model, queue);
            Application app(gameView, gameHandler, model);
            client.start();
            while (app.running() && !model.isGameFinished()) {
                app.handleEvent();        // Input de usuario
                app.update();            // Actualizar Modelo
                app.render();            // Dibujar Vista
            }
            client.disconnect();
        } catch (const SdlException &e) {
            std::cerr << e.what() << std::endl;
            client.disconnect();
            return FAILURE;
        } catch (const CustomException& ce) {
            std::cerr << ce.what() << std::endl;
            client.disconnect();
            return ce.getErrorCode();
        } catch (std::exception& e){
            std::cerr << e.what() << std::endl;
            client.disconnect();
            return FAILURE;
        }
    }
    return SUCCESS;
}