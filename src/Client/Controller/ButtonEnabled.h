#ifndef __BUTTON_ENABLE_H__
#define __BUTTON_ENABLE_H__

#include "ButtonState.h"

class ButtonEnabled : public ButtonState {
public:
	ButtonEnabled();
	
	virtual ~ButtonEnabled() = default;
	
	virtual void handle(ButtonHandler *button, const int x, const int y) override;
	
	virtual void update(ButtonHandler *button) override;
};

#endif	// __BUTTON_ENABLE_H__
