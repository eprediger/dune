#ifndef __ASTAR_H__
#define __ASTAR_H__

#include "AStarNode.h"
#include "Unity.h"

#include <set>
#include <map>
#include <stack>

class AStar {
private:
    std::vector<AStarNode> closeList;
    std::vector<AStarNode> openList;

public:
    AStar();

    std::stack<Position> reconstructPath(std::map<Position, Position> &bether_path, Position &start);
    std::stack<Position> makePath(Position start, Position end, Unity& unity);

};

#endif //__ASTAR_H__
