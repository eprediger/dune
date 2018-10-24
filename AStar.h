#ifndef __ASTAR_H__
#define __ASTAR_H__

#include "AStarNode.h"
#include "Unity.h"
#include "Map.h"

#include <set>
#include <map>
#include <stack>

class AStar {
private:
    std::vector<AStarNode> closeList;
    std::vector<AStarNode> openList;
    Map& map;
public:
    AStar(Map &map);

    std::stack<Position> reconstructPath(std::map<Position, Position> &bether_path, Position &start);
    std::stack<Position> makePath(Unity &unity, Position end);

};

#endif //__ASTAR_H__
