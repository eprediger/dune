#ifndef __GAME_HANDLER_H__
#define __GAME_HANDLER_H__

#include "InputHandler.h"
#include "../View/GameView.h"
// #include "../Model/Model.h"

class GameHandler : public InputHandler {
public:
	// Handler para eventos del juego
	// explicit GameHandler(Model& model);
	explicit GameHandler(View& view);
	
	// Libera recursos asociados a la instancia
	~GameHandler();
	
	bool handleInput() override;

private:
	View& view;
	// Model& model;
};

#endif	// __GAME_HANDLER_H__
