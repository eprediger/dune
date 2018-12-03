#ifndef __BUTTON_DISABLE_H__
#define __BUTTON_DISABLE_H__

#include "ButtonState.h"

class ButtonDisabled : public ButtonState {
public:
	ButtonDisabled();

	virtual ~ButtonDisabled() = default;

	virtual void handle(ButtonHandler *button, const int x, const int y) override;

	virtual void update(ButtonHandler *button) override;
};

#endif	// __BUTTON_DISABLE_H__
