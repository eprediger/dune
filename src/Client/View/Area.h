#ifndef __AREA_H__
#define __AREA_H__

#include "Position.h"

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

#endif	// __AREA_H__
