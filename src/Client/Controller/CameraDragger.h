#ifndef __DRAGGER_H__
#define __DRAGGER_H__

#include <View/GameView.h>

#define SENSITIVITY 15

class CameraDragger {
public:
	explicit CameraDragger(GameView& view);
	void on(Position initial);
	bool isOn();
	void move(Position move_pos);
	void off();

private:
	GameView& view;
	Position reference;
	const int sensivity;
	bool drag_on;
};

#endif	// __DRAGGER_H__
