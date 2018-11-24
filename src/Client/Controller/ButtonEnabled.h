#ifndef __BUTTON_ENABLE_H__
#define __BUTTON_ENABLE_H__

#include "ButtonState.h"

class ButtonEnabled : public ButtonState {
public:
	ButtonEnabled();
	~ButtonEnabled();
	virtual void handle(ButtonHandler *button, const int x, const int y) override;
	virtual void update(ButtonHandler *button) override;
};

#endif	// __BUTTON_ENABLE_H__
