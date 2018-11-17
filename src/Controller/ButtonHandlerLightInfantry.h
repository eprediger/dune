#ifndef __BUTTON_HANDLER_LIGHT_INFANTRY__
#define __BUTTON_HANDLER_LIGHT_INFANTRY__

#include "ButtonHandler.h"

class ButtonHandlerLightInfantry : public ButtonHandler {
public:
	ButtonHandlerLightInfantry(Model &model, GameView &view);

	~ButtonHandlerLightInfantry();

	virtual void execute() override;

    virtual bool canBeEnabled() override;
};

#endif	// __BUTTON_HANDLER_LIGHT_INFANTRY__
