#include <iostream>

#include "Map.h"
#include "Unity.h"
#include "Infantry.h"
#include "AStar.h"
#include <set>
int main( int argc, char* args[] ) {
//   Map mapa(10,10);
    Map::create(10, 10);
    Unity unidad(9, 0);
    Infantry infanteria(9, 1);
    Map::getInstance()->print();
    Map::getInstance()->put(unidad);
    Map::getInstance()->put(infanteria);

    unidad.setDestiny(0, 9);
    infanteria.setDestiny(9,9);

    std::cout << "****************************************" << std::endl;
    Map::getInstance()->print();

//    while (unidad.move() && infanteria.move()) {
    while (Map::getInstance()->moveUnitys()) {
        if (unidad.getPosition() == Position(3,9)){
            unidad.setDestiny(5, 0);
        }
        std::cout << "****************************************" << std::endl;
        Map::getInstance()->print();
    }

//
//    AStarNode a(Position(9,0));
//    AStarNode b(Position(8,0));
//
//    std::set<AStarNode> set;
//
//    set.insert(a);
//    b.f = 10;
//
//    if (set.count(b)){
//        std::cout << "B esta en set" << std::endl;
//    }

    return 0;
}