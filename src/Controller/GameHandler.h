#ifndef __GAME_HANDLER_H__
#define __GAME_HANDLER_H__

#define MOVE_AMOUNT 4

#include "InputHandler.h"
#include "../View/GameView.h"
#include "../Model/Model.h"
#include "../View/GameView.h"

class GameHandler : public InputHandler {
public:
	// Handler para eventos del juego
	// explicit GameHandler(Model& model);
	explicit GameHandler(GameView &view, Model &model);

	// Libera recursos asociados a la instancia
	~GameHandler();

	bool handleInput() override;

private:
	GameView& view;
	Model& model;
	Selector selector;
};

#endif	// __GAME_HANDLER_H__
