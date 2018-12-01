#include "Sound.h"
#include <string>
#include "SdlException.h"

Sound::Sound(const std::string& filename) : 
	music(nullptr) {
    int result = 0;
    int flags = MIX_INIT_MP3;
    if (flags != (result = Mix_Init(flags))) {
        throw SdlException("Error en recurso en audio", Mix_GetError());
    }
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    this->music = Mix_LoadMUS(filename.c_str());
}

Sound::~Sound() {
    Mix_FreeMusic(this->music);
    Mix_Quit();
    this->music = nullptr;
}

void Sound::run() {
    Mix_PlayMusic(this->music, -1);
}

void Sound::stop() {
    Mix_HaltMusic();
}
