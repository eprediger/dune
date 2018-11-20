#ifndef __BUTTON_HANDLER_WIND_TRAP_H__
#define __BUTTON_HANDLER_WIND_TRAP_H__

#include "ButtonHandler.h"

class ButtonHandlerWindTrap : public ButtonHandler {
public:
	ButtonHandlerWindTrap(Model &model, GameView &view, BuildingConstructor& constructor);

	~ButtonHandlerWindTrap();

	virtual void execute() override;

    virtual bool canBeEnabled() override;

    virtual bool finishAction() override;

	virtual void executeReady() override;

	virtual bool finishReady() override;

private:
	BuildingConstructor& constructor;
};

#endif  // __BUTTON_HANDLER_WIND_TRAP_H__
