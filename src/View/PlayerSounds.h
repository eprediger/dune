#ifndef __PLAYER_SOUNDS_H__
#define __PLAYER_SOUNDS_H__

#include "SDL2/SDL_mixer.h"
#include <map>
#include "../Model/Player.h"
class PlayerSounds{
    public:
        PlayerSounds(Player& player);
        void manageSounds();
    private:
        static std::map<std::string, Mix_Chunk*> sounds;
        Player& player;
        int yardLife;
        int sirenChannel;

};



#endif