#ifndef __BUTTON_HANDLER_H__
#define __BUTTON_HANDLER_H__

#include "../View/ButtonView.h"
#include "../Model/Model.h"
#include "../View/GameView.h"

class ButtonHandler {
public:
	ButtonHandler(ButtonView& button_view, Model& model, GameView& view);

	virtual ~ButtonHandler();

	void onClicked(int x, int y);

	virtual void execute() = 0;

protected:
	ButtonView& button_view;
	Model& model;
	GameView& view;
};


#endif //__BUTTON_HANDLER_H__
