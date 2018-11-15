#ifndef __BUTTON_HANDLER_HEAVY_INFANTRY__
#define __BUTTON_HANDLER_HEAVY_INFANTRY__

#include "ButtonHandler.h"

class ButtonHandlerHeavyInfantry : public ButtonHandler {
public:
	ButtonHandlerHeavyInfantry(Model &model, GameView &view);

	~ButtonHandlerHeavyInfantry();

	virtual void execute() override;
};

#endif	// __BUTTON_HANDLER_HEAVY_INFANTRY__
