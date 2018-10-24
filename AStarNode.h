#ifndef __ASTARNODE_H__
#define __ASTARNODE_H__

#include "Position.h"

struct AStarNode {
    Position pos;
    int f,g,h;

    AStarNode();
    AStarNode(Position pos);
    std::vector<AStarNode> getAdjacents();

    void actualize(int f, int g, int h);

    bool operator==(const AStarNode& other) const;


};

#endif //__ASTARNODE_H__
