#ifndef __BUTTON_HANDLER_HEAVY_INFANTRY__
#define __BUTTON_HANDLER_HEAVY_INFANTRY__

#include "ButtonHandler.h"

class ButtonHandlerHeavyInfantry : public ButtonHandler {
public:
	ButtonHandlerHeavyInfantry(Player& player, GameView &view, CommunicationQueue& queue);

	~ButtonHandlerHeavyInfantry();

	virtual void execute() override;

    virtual bool canBeEnabled() override;

	virtual bool finishAction() override;
};

#endif	// __BUTTON_HANDLER_HEAVY_INFANTRY__
