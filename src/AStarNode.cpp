#include "AStarNode.h"

#include "Map.h"

std::vector<AStarNode> AStarNode::getAdjacents(Map &map) {
    std::vector<AStarNode> vec;
    for (int i = -1 ; i <= 1 ; ++i){
        for (int j = -1 ; j <= 1 ; ++j) {
            Position p(pos.getX()+i,pos.getY()+j);
            if ((i != 0 || j != 0) && map.isValid(p)){
                vec.push_back(AStarNode(p));
            }
        }
    }

    return std::move(vec);
}

AStarNode::AStarNode(Position pos) : f(0), g(0), h(0) {
    pos = Position(pos.getX()/BLOCK_HEIGHT , pos.getY()/BLOCK_WIDTH);
}

bool AStarNode::operator==(const AStarNode &other) const{
    return other.pos == this->pos;
}

void AStarNode::actualize(int f, int g, int h) {
    this->f = f;
    this->g = g;
    this->h = h;
}

AStarNode::AStarNode() : pos(0,0), f(0), g(0), h(0){

}
