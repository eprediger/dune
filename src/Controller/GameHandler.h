#ifndef __GAME_HANDLER_H__
#define __GAME_HANDLER_H__

#define MOVE_AMOUNT 16
#define PLAYER 1

#include "InputHandler.h"
#include "../View/GameView.h"
#include "../Model/Model.h"
#include "../View/GameView.h"
#include "ButtonHandler.h"
#include <vector>

class GameHandler : public InputHandler {
public:
	// Handler para eventos del juego
	// explicit GameHandler(Model& model);
	explicit GameHandler(GameView &view, Model &model);

	// Libera recursos asociados a la instancia
	~GameHandler();

	bool handleInput() override;

	static int actual_player;

private:
	GameView& view;
	Model& model;
	Selector selector;
	BuildingConstructor constructor;
	std::vector<ButtonHandler*> buttons;
};

#endif	// __GAME_HANDLER_H__
