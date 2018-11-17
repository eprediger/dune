#ifndef __BUTTON_DISABLE_H__
#define __BUTTON_DISABLE_H__

#include "ButtonState.h"

class DisableState : public ButtonState {
public:
	DisableState();
	~DisableState();
	virtual void handle(ButtonHandler *button, const int x, const int y) override;
};

#endif	// __BUTTON_DISABLE_H__
