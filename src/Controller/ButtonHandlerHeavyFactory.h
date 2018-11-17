#ifndef __BUTTON_HANDLER_HEAVY_FACTORY_H__
#define __BUTTON_HANDLER_HEAVY_FACTORY_H__

#include "ButtonHandler.h"

class ButtonHandlerHeavyFactory : public ButtonHandler {
public:
	ButtonHandlerHeavyFactory(Model &model, GameView &view);

	~ButtonHandlerHeavyFactory();

	virtual void execute() override;

    virtual bool canBeEnabled() override;
};

#endif  // __BUTTON_HANDLER_HEAVY_FACTORY_H__
