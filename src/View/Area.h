#ifndef __AREA_H__
#define __AREA_H__

class Area {
public:
	Area(int x, int y, int width, int height);
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
