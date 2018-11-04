#include "Sound.h"
#include "SdlException.h"

Sound::Sound(const std::string& filename) : 
	filename(filename),
	music(nullptr) {
    int result = 0;
    int flags = MIX_INIT_MP3;
    if (flags != (result = Mix_Init(flags))) {
        throw SdlException("Error en recurso en audio", Mix_GetError());
    }
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    this->music = Mix_LoadMUS(filename.c_str());
}

Sound::~Sound() {
    Mix_FreeMusic(this->music);
    SDL_Quit();
    this->music = nullptr;
}

void Sound::run() {
    Mix_PlayMusic(this->music, 0);
    bool isPlaying = true;
    while (!SDL_QuitRequested() && isPlaying) {
        isPlaying = Mix_PlayingMusic();
        SDL_Delay(250);
    }
}

void Sound::stop() {
    Mix_HaltMusic();
}
