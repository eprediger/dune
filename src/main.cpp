#include "Application.h"

/*#include "Controller/MainMenuHandler.h"
#include "View/MainMenuView.h"*/

/*#include "View/HouseSelectionView.h"
#include "Controller/HouseSelectionHandler.h"*/

#include "View/GameView.h"
#include "Controller/GameHandler.h"
#include "GlobalConfig.h"

#include <iostream>

#define SUCCESS 0
#define FAILURE 1

#define MAX_FPS	60
#define SECOND	1000

config_t GlobalConfig;

int main(int argc, const char *argv[]) {
	try {
		/*MainMenuView menuView(WINDOW_WIDTH, WINDOW_HEIGHT);
		MainMenuHandler menuHandler(menuView);
		Application app(menuView, menuHandler);*/

		/*HouseSelectionView houseSelectionView(WINDOW_WIDTH, WINDOW_HEIGHT);
		HouseSelectionHandler houseSelectionHandler(houseSelectionView);
		Application app(houseSelectionView, houseSelectionHandler);*/

		GameView gameView(WINDOW_WIDTH, WINDOW_HEIGHT);
		GameHandler gameHandler(gameView);
		Application app(gameView, gameHandler);

		while (app.running()) {
			app.handleEvent();	 	// Input de usuario
			app.update();			// Actualizar Modelo
			app.render();			// Dibujar Vista
		}
	} catch (const SdlException& e) {
		std::cerr << e.what() << std::endl;
		return FAILURE;
	}

	return SUCCESS;
}
