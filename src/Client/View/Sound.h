#ifndef __SOUND_H__
#define __SOUND_H__

#include <string>
#include "Thread.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <memory>

#define CHANNELS 4
#define SELECTOR_CHANNEL 0
#define BUTTON_FX_CHANNEL 1
#define EMERGENGY_CHANNEL 2
#define EXPLOSION_CHANNEL 3

class Sound {
public:
    ~Sound();

    static std::unique_ptr<Sound>& getSound();
    void playButtonFx(Mix_Chunk* chunk);
    void playEmergencyFx(Mix_Chunk* chunk);
    void playSelectionFX(Mix_Chunk* chunk);
    void playMusic(Mix_Music* music);
    void playExplosionFX(Mix_Chunk* chunk);

    void stopMusic();

    Mix_Music* getCurrentMusic();
    Mix_Chunk* getCurrentChunk();

private:
    Sound();
    static std::unique_ptr<Sound> instance;
    Mix_Chunk* currentChunk;
    Mix_Music* currentMusic;

};

#endif	// __SOUND_H__
