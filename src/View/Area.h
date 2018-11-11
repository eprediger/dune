//
// Created by emiliano on 24/10/18.
//

#ifndef WINDOW_AREA_H
#define WINDOW_AREA_H

#include "../Position.h"

class Area {
public:
	Area(int x, int y, int width, int height);
	Area(const Position& pos1,const Position& pos2);
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
private:
	int x, y;
	int width, height;
};


#endif //WINDOW_AREA_H
