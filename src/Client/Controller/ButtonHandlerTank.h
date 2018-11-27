#ifndef __BUTTON_HANDLER_TANK__
#define __BUTTON_HANDLER_TANK__

#include "ButtonHandler.h"

class ButtonHandlerTank : public ButtonHandler {
public:
	ButtonHandlerTank(Player& player, GameView &view, CommunicationQueue& queue);

	~ButtonHandlerTank();

	virtual void execute() override;

    virtual bool canBeEnabled() override;

	virtual bool finishAction() override;
};

#endif	// __BUTTON_HANDLER_TANK__
