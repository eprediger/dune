#ifndef __BUTTON_HANDLER_BARRACKS_H__
#define __BUTTON_HANDLER_BARRACKS_H__

#include "ButtonHandler.h"
#include "BuildingConstructor.h"

class ButtonHandlerBarracks : public ButtonHandler {
public:
	ButtonHandlerBarracks(Player& player, GameView &view,
			BuildingConstructor& constructor, CommunicationQueue& queue);

	~ButtonHandlerBarracks();

	virtual void execute() override;

	virtual bool canBeEnabled() override;

	virtual bool finishAction() override;

	virtual void executeReady() override;

	virtual bool finishReady() override;

private:
	BuildingConstructor& constructor;
};

#endif  // __BUTTON_HANDLER_BARRACKS_H__
