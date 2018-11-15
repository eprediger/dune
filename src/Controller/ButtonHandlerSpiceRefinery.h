#ifndef __BUTTON_HANDLER_SPICE_REFINERY_H__
#define __BUTTON_HANDLER_SPICE_REFINERY_H__

#include "ButtonHandler.h"

class ButtonHandlerSpiceRefinery : public ButtonHandler {
public:
	ButtonHandlerSpiceRefinery(Model &model, GameView &view);

	~ButtonHandlerSpiceRefinery();

	virtual void execute() override;
};

#endif  // __BUTTON_HANDLER_SPICE_REFINERY_H__
