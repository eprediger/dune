#ifndef __BUTTON_HANDLER_SPICE_REFINERY_H__
#define __BUTTON_HANDLER_SPICE_REFINERY_H__

#include "ButtonHandler.h"

class ButtonHandlerSpiceRefinery : public ButtonHandler {
public:
	ButtonHandlerSpiceRefinery(Model &model, GameView &view,
			BuildingConstructor& constructor, CommunicationQueue& queue);

	~ButtonHandlerSpiceRefinery();

	virtual void execute() override;

    virtual bool canBeEnabled() override;

   virtual bool finishAction() override;

	virtual void executeReady() override;

	virtual bool finishReady() override;

private:
	BuildingConstructor& constructor;
};

#endif  // __BUTTON_HANDLER_SPICE_REFINERY_H__
