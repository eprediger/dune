#ifndef __BUTTON_STATE_H__
#define __BUTTON_STATE_H__

#include <string>

class ButtonHandler;

enum class State { DISABLED, ENABLED }; //, BUSY, READY };

class ButtonState {
public:
	ButtonState();
	virtual ~ButtonState();
	virtual void handle(ButtonHandler *button, const int x, const int y) = 0;
};

#endif	// __BUTTON_STATE_H__
