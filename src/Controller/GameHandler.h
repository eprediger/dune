#ifndef __GAME_HANDLER_H__
#define __GAME_HANDLER_H__

#define MOVE_AMOUNT 4

#include "InputHandler.h"
#include "../View/GameView.h"
#include "../Model/Model.h"
#include "../View/OldView.h"

class GameHandler : public InputHandler {
public:
	// Handler para eventos del juego
	// explicit GameHandler(Model& model);
	explicit GameHandler(OldView &view, Model &model);

	// Libera recursos asociados a la instancia
	~GameHandler();

	bool handleInput() override;

private:
	OldView& view;
	Model& model;
};

#endif	// __GAME_HANDLER_H__
