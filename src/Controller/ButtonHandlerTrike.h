#ifndef __BUTTON_HANDLER_TRIKE__
#define __BUTTON_HANDLER_TRIKE__

#include "ButtonHandler.h"

class ButtonHandlerTrike : public ButtonHandler {
public:
	ButtonHandlerTrike(Model &model, GameView &view, CommunicationQueue& queue);
	
	~ButtonHandlerTrike();

	virtual void execute() override;

    virtual bool canBeEnabled() override;

	virtual bool finishAction() override;
};

#endif	// __BUTTON_HANDLER_TRIKE__
