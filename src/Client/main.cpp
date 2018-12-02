#include <iostream>
#include <string>

#include <nlohmann/json.hpp>
#include <Model/GameConfiguration.h>

#include "Application.h"
#include "Codes.h"
#include "Client.h"

#include <MainMenu.h>
#include <Controller/MainMenuHandler.h>
#include <View/MainMenuView.h>

#include <HouseSelection.h>
#include <Controller/HouseSelectionHandler.h>
#include <View/HouseSelectionView.h>

#include <Controller/GameHandler.h>
#include <View/GameView.h>
#include <GameInterface.h>
#include <HandlerThread.h>

#define MAX_FPS 60
#define SECOND  1000

int main(int argc, const char *argv[]) {
	if (argc != CLT_ARGS) {
		std::cerr << "Uso: " << argv[0] << std::endl;
		return USAGE_ERROR;
	} else {
		MainMenuView menuView(WINDOW_WIDTH, WINDOW_HEIGHT);
		MainMenuHandler menuHandler(menuView);
		MainMenu mainMenu(menuView, menuHandler);
		mainMenu.run();

		/*std::cout << "Host: " << mainMenu.getHost() << std::endl;
		std::cout << "Port: " << mainMenu.getPort() << std::endl;*/

		CommunicationQueue queue;
		Client client(mainMenu.getHost().c_str(), mainMenu.getPort().c_str(), queue);
		try {
			HouseSelectionView houseSelectionView(WINDOW_WIDTH, WINDOW_HEIGHT);
			HouseSelectionHandler houseSelectionHandler(houseSelectionView);
			HouseSelection houseSelection(houseSelectionView, houseSelectionHandler);
			std::string selectedHouse = houseSelection.run();

			/*std::cout << "Casa: " << selectedHouse << std::endl;*/

			client.start();
			nlohmann::json house;
			house["house"] = selectedHouse;//std::string(argv[3]);
			queue.enqueue(house);

			nlohmann::json mapFile = queue.dequeue();
			Model model(mapFile, queue);

			nlohmann::json player = queue.dequeue();
			model.addPlayer(player);

			nlohmann::json gameConfig = queue.dequeue();
			GameConfiguration::init(gameConfig);

			Player& myPlayer = model.getPlayer(player["id"]);

			GameView gameView(WINDOW_WIDTH, WINDOW_HEIGHT, model, myPlayer);
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
						if (j["class"] == "Step") break;
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

			handler.join();
			client.disconnect();
		} catch (const SdlException &e) {
			std::cerr << e.what() << std::endl;
			// client.disconnect();
			return FAILURE;
		} catch (const CustomException& ce) {
			std::cerr << ce.what() << std::endl;
			// client.disconnect();
			return ce.getErrorCode();
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
			// client.disconnect();
			return FAILURE;
		}
	}
	return SUCCESS;
}
