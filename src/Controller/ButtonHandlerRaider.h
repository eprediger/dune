#ifndef __BUTTON_HANDLER_RAIDER__
#define __BUTTON_HANDLER_RAIDER__

#include "ButtonHandler.h"

class ButtonHandlerRaider : public ButtonHandler {
public:
	ButtonHandlerRaider(Model &model, GameView &view);

	~ButtonHandlerRaider();

	virtual void execute() override;
};

#endif	// __BUTTON_HANDLER_RAIDER__
