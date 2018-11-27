#ifndef __GAMEINTERFACE_H__
#define __GAMEINTERFACE_H__


#include <nlohmann/json.hpp>
#include "Model/Model.h"
#include "View/GameView.h"

class GameInterface {
public:
    GameInterface(Model &model, GameView &view);
    void execute(nlohmann::json json);
private:
    Model& model;
    GameView& view;
};


#endif //__GAMEINTERFACE_H__
