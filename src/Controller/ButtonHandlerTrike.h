#ifndef __BUTTON_HANDLER_TRIKE__
#define __BUTTON_HANDLER_TRIKE__

#include "ButtonHandler.h"

class ButtonHandlerTrike : public ButtonHandler {
public:
	ButtonHandlerTrike(Model &model, GameView &view);
	
	~ButtonHandlerTrike();

	virtual void execute() override;
};

#endif	// __BUTTON_HANDLER_TRIKE__
