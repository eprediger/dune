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
	explicit GameHandler(GameView &view, Model &model);
	static int actual_player;

	// Libera recursos asociados a la instancia
	~GameHandler();
  
	bool handleInput() override;


	// Metodo temporal
	virtual void step();

	std::deque<nlohmann::json> send_queue;
private:
	GameView& view;
	Model& model;
	Selector selector;
	BuildingConstructor constructor;
	std::vector<ButtonHandler*> buttons;
};

#endif	// __GAME_HANDLER_H__
