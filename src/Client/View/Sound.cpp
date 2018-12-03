#include "Sound.h"
#include <string>
#include "SdlException.h"

std::unique_ptr<Sound> Sound::instance(new Sound());

Sound::Sound()
{
    int result = 0;
    int flags = MIX_INIT_MP3;
    if (flags != (result = Mix_Init(flags))) {
        throw SdlException("Error en recurso en audio", Mix_GetError());
    }
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Volume(-1,128);
}

std::unique_ptr<Sound>& Sound::getSound(){
    if (!instance){
        instance = std::move(std::unique_ptr<Sound>(new Sound()));
    }
    return instance;
}

void Sound::playMusic(Mix_Music* music) {
    if (Mix_PlayingMusic()){
        Mix_HaltMusic();
    }
    this->currentMusic = music;
    Mix_PlayMusic(music, -1);
}

void Sound::playButtonFx(Mix_Chunk* chunk){
    if (!Mix_Playing(BUTTON_FX_CHANNEL)){
        Mix_PlayChannel(BUTTON_FX_CHANNEL,chunk,0);
    }
}

void Sound::playExplosionFX(Mix_Chunk* chunk){
    if (!Mix_Playing(EXPLOSION_CHANNEL)){
        Mix_PlayChannel(EXPLOSION_CHANNEL,chunk,0);
    }
}

void Sound::playSelectionFX(Mix_Chunk* chunk){
    Mix_PlayChannel(SELECTOR_CHANNEL,chunk,0);
}

Mix_Music* Sound::getCurrentMusic(){
    return this->currentMusic;
}


void Sound::playEmergencyFx(Mix_Chunk* chunk){
    if (!Mix_Playing(EMERGENGY_CHANNEL)){
        Mix_PlayChannel(EMERGENGY_CHANNEL,chunk,0);
    }
}

void Sound::playShootingFx(Mix_Chunk* chunk){
    if (!Mix_Playing(SHOOTING_CHANNEL)){
        Mix_PlayChannel(SHOOTING_CHANNEL,chunk,0);
    }
}

void Sound::stopMusic(){
    Mix_HaltMusic();
}

#include <iostream>

Sound::~Sound(){
    Mix_HaltMusic();
    Mix_HaltChannel(-1);
    Mix_Quit();
}

