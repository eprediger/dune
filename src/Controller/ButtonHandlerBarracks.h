#ifndef __BUTTON_HANDLER_BARRACKS_H__
#define __BUTTON_HANDLER_BARRACKS_H__

#include "ButtonHandler.h"

class ButtonHandlerBarracks : public ButtonHandler {
public:
	ButtonHandlerBarracks(Model &model, GameView &view);

	~ButtonHandlerBarracks();

	virtual void execute() override;
};

#endif  // __BUTTON_HANDLER_BARRACKS_H__
