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
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, CHANNELS, 1024);
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
    Mix_PlayChannel(BUTTON_FX_CHANNEL,chunk,0);
    currentChunk = chunk;
}

void Sound::playExplosionFX(Mix_Chunk* chunk){
    Mix_PlayChannel(EXPLOSION_CHANNEL,chunk,0);
    currentChunk = chunk;
}

void Sound::playSelectionFX(Mix_Chunk* chunk){
    Mix_PlayChannel(SELECTOR_CHANNEL,chunk,0);
    currentChunk = chunk;
}

Mix_Chunk* Sound::getCurrentChunk(){
    return this->currentChunk;
}

Mix_Music* Sound::getCurrentMusic(){
    return this->currentMusic;
}


void Sound::playEmergencyFx(Mix_Chunk* chunk){
    Mix_PlayChannel(EMERGENGY_CHANNEL,chunk,0);
    currentChunk = chunk;
}

void Sound::stopMusic(){
    Mix_HaltMusic();
}

#include <iostream>

Sound::~Sound(){
    std::cout<<"chau\n";
    Mix_HaltMusic();
    //Mix_HaltChannel(-1);
    Mix_Quit();
    this->instance = nullptr;
    std::cout<<"chau2\n";
}

