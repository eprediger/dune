#ifndef __BUTTON_HANDLER_H__
#define __BUTTON_HANDLER_H__

#include "ButtonState.h"
#include "View/ButtonView.h"
#include "Model/Model.h"
#include "View/GameView.h"
#include <Model/GameConfiguration.h>

class ButtonHandler {
public:
	ButtonHandler(ButtonView &buttonView, Player& player, GameView &view, CommunicationQueue &queue, int time);

	virtual ~ButtonHandler();

	void handleUserInput(const int x, const int y);

	void update();

	bool wasClicked(const int x, const int y);

	virtual void execute() = 0;

	virtual bool canBeEnabled() = 0;

	virtual bool finishAction();

	void setState(const State state);

	virtual void executeReady();

    virtual bool finishReady();

protected:
	ButtonState* buttonState;
	ButtonView& buttonView;
	Player& player;
	GameView& view;
	CommunicationQueue& queue;
	int time;
};

#endif	// __BUTTON_HANDLER_H__
