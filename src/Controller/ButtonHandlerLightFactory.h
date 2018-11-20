#ifndef __BUTTON_HANDLER_LIGHT_FACTORY_H__
#define __BUTTON_HANDLER_LIGHT_FACTORY_H__

#include "ButtonHandler.h"

class ButtonHandlerLightFactory : public ButtonHandler {
public:
	ButtonHandlerLightFactory(Model &model, GameView &view, BuildingConstructor& constructor);

	~ButtonHandlerLightFactory();

	virtual void execute() override;

	virtual bool canBeEnabled() override;

	virtual bool finishAction() override;

	virtual void executeReady() override;

	virtual bool finishReady() override;

private:
	BuildingConstructor& constructor;
};

#endif  // __BUTTON_HANDLER_LIGHT_FACTORY_H__
