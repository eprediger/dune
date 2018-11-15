#ifndef __BUTTON_HANDLER_HARVESTER_H__
#define __BUTTON_HANDLER_HARVESTER_H__

#include "ButtonHandler.h"

class ButtonHandlerHarvester : public ButtonHandler {
public:
	ButtonHandlerHarvester(Model &model, GameView &view);

	~ButtonHandlerHarvester();

	virtual void execute() override;
};

#endif  // __BUTTON_HANDLER_HARVESTER_H__
