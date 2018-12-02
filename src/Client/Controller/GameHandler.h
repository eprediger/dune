#ifndef __GAME_HANDLER_H__
#define __GAME_HANDLER_H__

#define MOVE_AMOUNT 16

#include "InputHandler.h"
#include "View/GameView.h"
#include "Model/Model.h"
#include "View/GameView.h"
#include "ButtonHandler.h"
#include "CommunicationQueue.h"
#include "GameInterface.h"
#include "CameraDragger.h"
#include <vector>

class GameHandler : public InputHandler {
public:
	// Handler para eventos del juego
	explicit GameHandler(GameView &view, Model &model, CommunicationQueue &queue, Player& player);
	static int actual_player;

	// Libera recursos asociados a la instancia
	~GameHandler();

	bool handleInput() override;

	virtual void update() override;

private:
	GameView& view;
	Model& model;
	Player& player;
	Selector selector;
	CameraDragger dragger;
	BuildingConstructor constructor;
	std::vector<ButtonHandler*> buttons;
	CommunicationQueue& queue;
	GameInterface interface;
};

#endif	// __GAME_HANDLER_H__
