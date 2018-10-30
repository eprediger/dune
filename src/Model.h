#ifndef __MODEL_H__
#define __MODEL_H__

#include "Unity.h"
#include "Map.h"
#include "VistaUnidad.h"
#include <vector>
#include <memory>

#define LIMIT_TO_SELECT 32*32

class Model {
private:
    Map map;
    std::vector<std::unique_ptr<Unity>> unitys;

public:
    Model(int width, int height);

//    Map& createMap();
    Map& getMap();

    Unity& createUnity(int x, int y);


    void step();

    Unity* selectUnity(int x, int y);


};

#endif //__MODEL_H__
