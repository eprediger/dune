#include <iostream>

#include <nlohmann/json.hpp>
#include <Model/GameConfiguration.h>

#include "Application.h"
#include "Codes.h"
#include "Client.h"
#include "View/VictoryScreenView.h"
#include "VictoryScreen.h"

#include <MainMenu.h>

#include <HouseSelection.h>

#include <Controller/GameHandler.h>
#include <HandlerThread.h>

int main(int argc, const char *argv[]) {
    if (argc != CLT_ARGS) {
        std::cerr << "Uso: " << argv[0] << std::endl;
        return USAGE_ERROR;
    } else {
        MainMenu mainMenu;
        mainMenu.run();
        if (mainMenu.windowStatus() != WindowStatus::CLOSE) {
            HouseSelection houseSelection;
            houseSelection.run();
            if (houseSelection.windowStatus() != WindowStatus::CLOSE) {
                CommunicationQueue queue;
                Client client(mainMenu.getHost().c_str(), mainMenu.getPort().c_str(), queue);
                try {
                    client.start();
                    nlohmann::json house;
                    house["house"] = houseSelection.getSelectedHouse();
                    queue.enqueue(house);

                    nlohmann::json playerName;
                    playerName["playerName"] = mainMenu.getPlayerName();
                    queue.enqueue(playerName);

                    nlohmann::json mapFile = queue.dequeue();
                    Model model(mapFile, queue);

                    nlohmann::json player = queue.dequeue();
                    model.addPlayer(player);

                    nlohmann::json gameConfig = queue.dequeue();
                    GameConfiguration::init(gameConfig);

                    Player &myPlayer = model.getPlayer(player["id"]);

                    GameView gameView(mainMenu.getWindowWidth(), mainMenu.getWindowHeight(), model, myPlayer);
                    GameInterface interface(model, gameView);
                    GameHandler gameHandler(gameView, model, queue, myPlayer);

                    Application app(gameView, gameHandler, model);

                    HandlerThread handler(app);

                    handler.start();
                    const int time_step = SECOND / MAX_FPS;
                    int sleep_extra = 0;

                    while (app.running() && !model.isGameFinished()) {
                        unsigned int loop_init = SDL_GetTicks();

                        ////// Inicia el LOOP //////////
                        app.render();
                        app.update();

                        if (!queue.recvEmpty()) {
                            while (true) {
                                nlohmann::json j(queue.dequeue());
                                interface.execute(j);
                                if ((j["class"] == "Step") || (j["class"] == "finishGame")) break;
                            }
                        }

                        unsigned int loop_end = SDL_GetTicks();

                        int step_duration = (loop_end - loop_init);
                        int sleep_delay = time_step - step_duration - sleep_extra;
                        sleep_delay = (sleep_delay < 0) ? 0 : sleep_delay;

                        SDL_Delay(sleep_delay);
                        unsigned int delay_end = SDL_GetTicks();

                        sleep_extra = (delay_end - loop_end) - sleep_delay;
                    }

                    handler.stop();
                    handler.join();
                    gameView.closeWindow();
                    client.disconnect();

                    if (model.isGameFinished()) {
                        std::string winner_name = model.getPlayer(model.getWinnerId()).getName();
                        VictoryScreenView victoryScreenView(WINDOW_WIDTH, WINDOW_HEIGHT,
                                                            winner_name);
                        VictoryScreenHandler victoryScreenHandler(victoryScreenView);
                        VictoryScreen victoryScreen(victoryScreenView, victoryScreenHandler);
                        victoryScreen.run();
                    }


                } catch (const SdlException &e) {
                    std::cerr << e.what() << std::endl;
                    client.disconnect();
                    return FAILURE;
                } catch (const CustomException &ce) {
                    std::cerr << ce.what() << std::endl;
                    client.disconnect();
                    return ce.getErrorCode();
                } catch (std::exception &e) {
                    std::cerr << e.what() << std::endl;
                    client.disconnect();
                    return FAILURE;
                }
            }
        }
    }
    return SUCCESS;
}
