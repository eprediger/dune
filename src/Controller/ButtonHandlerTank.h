#ifndef __BUTTON_HANDLER_TANK__
#define __BUTTON_HANDLER_TANK__

#include "ButtonHandler.h"

class ButtonHandlerTank : public ButtonHandler {
public:
	ButtonHandlerTank(Model &model, GameView &view);

	~ButtonHandlerTank();

	virtual void execute() override;

    virtual bool canBeEnabled() override;
};

#endif	// __BUTTON_HANDLER_TANK__
