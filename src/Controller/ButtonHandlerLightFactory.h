#ifndef __BUTTON_HANDLER_LIGHT_FACTORY_H__
#define __BUTTON_HANDLER_LIGHT_FACTORY_H__

#include "ButtonHandler.h"

class ButtonHandlerLightFactory : public ButtonHandler {
public:
	ButtonHandlerLightFactory(Model &model, GameView &view, BuildingConstructor& constructor);

	~ButtonHandlerLightFactory();

	virtual void execute() override;

    virtual bool canBeEnabled() override;
private:
	BuildingConstructor& constructor;
};

#endif  // __BUTTON_HANDLER_LIGHT_FACTORY_H__
