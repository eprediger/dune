#ifndef __BUTTON_ENABLE_H__
#define __BUTTON_ENABLE_H__

#include "ButtonState.h"

class EnableState : public ButtonState {
public:
	EnableState();
	~EnableState();
	virtual void handle(ButtonHandler *button, const int x, const int y) override;
};

#endif	// __BUTTON_ENABLE_H__
