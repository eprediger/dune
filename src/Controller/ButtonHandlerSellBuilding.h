#ifndef __BUTTON_HANDLER_SELL_BUILDING_H__
#define __BUTTON_HANDLER_SELL_BUILDING_H__

#include "ButtonHandler.h"

class ButtonHandlerSellBuilding : public ButtonHandler {
public:
	ButtonHandlerSellBuilding(Model &model, GameView &view, Selector &selector);

	virtual ~ButtonHandlerSellBuilding();

	// Cuando se hace click sobre el boton se vende el edificio seleccionado
	virtual void execute() override;

	// El boton se habilita cuando hay edificios seleccionados
	virtual bool canBeEnabled() override;

private:
	Selector& selector;
};

#endif //__BUTTON_HANDLER_SELL_BUILDING_H__
