#include "PlayerSounds.h"


std::map<std::string,Mix_Chunk*> PlayerSounds::sounds;
PlayerSounds::PlayerSounds(Player& player)
    :player(player)
    ,yardLife(player.getConstructionYard().getLife())
{
    Mix_OpenAudio(22050, AUDIO_S16SYS, 4, 4096);
    if (sounds.empty()){
        sounds.insert(std::make_pair("siren",(Mix_LoadWAV("../assets/sound/fx/Siren_Noise-KevanGC-1337458893.wav"))));
        sounds.insert(std::make_pair("cash", (Mix_LoadWAV("../assets/sound/fx/Cash Register Sound Effect.wav"))));
        sounds.insert(std::make_pair("newRaider",(Mix_LoadWAV("../assets/sound/fx/new raider.wav"))));
        sounds.insert(std::make_pair("newInfantry",(Mix_LoadWAV("../assets/sound/fx/new infantry.wav"))));
        sounds.insert(std::make_pair("newHarvester",(Mix_LoadWAV("../assets/sound/fx/new harvester.wav"))));
        sounds.insert(std::make_pair("newTank",(Mix_LoadWAV("../assets/sound/fx/new tank.wav"))));
        sounds.insert(std::make_pair("newTrike",(Mix_LoadWAV("../assets/sound/fx/new trike.wav"))));
    }
}

#include <iostream>



void PlayerSounds::manageSounds(){
    if (player.getConstructionYard().getLife() < yardLife){
            yardLife = player.getConstructionYard().getLife();
            Mix_PlayChannel(0,sounds.at("siren"),1);
    }
}