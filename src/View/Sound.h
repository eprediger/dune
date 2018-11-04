#include <string>
#include <iostream>
#include "../Common/Thread.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

// g++ -Wall -Werror -std=c++11 Sound.cpp SdlException.cpp -lSDL2 -lSDL2_mixer -o sound-test

class Sound : public Thread {
// class Sound {
public:
    explicit Sound(const std::string& filename);
    ~Sound();
    void run();
    void stop();
private:
    const std::string& filename;
    Mix_Music* music;
};

// int main(int argc, char const *argv[]) {
// 	Sound sonido(argv[1]);
// 	sonido.play();
// 	sonido.stop();
// 	return 0;
// }
