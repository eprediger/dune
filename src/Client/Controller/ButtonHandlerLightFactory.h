#ifndef __BUTTON_HANDLER_LIGHT_FACTORY_H__
#define __BUTTON_HANDLER_LIGHT_FACTORY_H__

#include "ButtonHandler.h"

class ButtonHandlerLightFactory : public ButtonHandler {
public:
	ButtonHandlerLightFactory(Player& player, GameView &view,
			BuildingConstructor& constructor, CommunicationQueue& queue);

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
