#include "Sound.h"
#include "SdlException.h"

Sound::Sound(const std::string &filename) : 
	filename(filename),
	music(nullptr) {
}

Sound::~Sound() {
	Mix_FreeMusic(music);
    SDL_Quit();
    this->music = nullptr;
}

void Sound::run() {
	int result = 0;
    int flags = MIX_INIT_MP3;
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        throw SdlException("Error inicializando audio", SDL_GetError());
    }
    if (flags != (result = Mix_Init(flags))) {
        throw SdlException("Error en recurso en audio", Mix_GetError());
        /*printf("Could not initialize mixer (result: %d).\n", result);
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);*/
    }
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    this->music = Mix_LoadMUS(filename.c_str());Mix_PlayMusic(music, 1);
    while (!SDL_QuitRequested()) {
        SDL_Delay(250);
    }
}
