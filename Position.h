#ifndef __POSITION_H__
#define __POSITION_H__

#include <vector>
class Position {
private:
    int x,y;
public:
    Position();
    Position(int x, int y);

    int getX() const;
    int getY() const;

    std::vector<Position> getAdjacents();

    bool operator==(const Position& other) const;
    bool operator<(const Position& other) const;

    int sqrtDistance(const Position &pos);
};

#endif //__POSITION_H__
