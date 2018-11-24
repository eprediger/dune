#ifndef __BUTTON_HANDLER_RAIDER__
#define __BUTTON_HANDLER_RAIDER__

#include "ButtonHandler.h"

class ButtonHandlerRaider : public ButtonHandler {
public:
	ButtonHandlerRaider(Model &model, GameView &view, CommunicationQueue& queue);

	~ButtonHandlerRaider();

	virtual void execute() override;

    virtual bool canBeEnabled() override;

	virtual bool finishAction() override;
};

#endif	// __BUTTON_HANDLER_RAIDER__
