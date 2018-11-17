#ifndef __BUTTON_HANDLER_SPICE_SILO_H__
#define __BUTTON_HANDLER_SPICE_SILO_H__

#include "ButtonHandler.h"

class ButtonHandlerSpiceSilo : public ButtonHandler {
public:
	ButtonHandlerSpiceSilo(Model& model, GameView& view);

	~ButtonHandlerSpiceSilo();

	virtual void execute() override;

    virtual bool canBeEnabled() override;
};

#endif  // __BUTTON_HANDLER_SPICE_SILO_H__
