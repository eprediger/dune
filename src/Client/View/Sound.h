#ifndef __SOUND_H__
#define __SOUND_H__

#include <string>
#include "Thread.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

class Sound : public Thread {
public:
    // filename debe ser la ruta a un archivo de sonido en formato mp3
    explicit Sound(const std::string& filename);
    
    // Libera recursos de la instancia
    ~Sound();
    
    // Inicia la reproducción del sonido
    void run();
    
    // Detiene la reproducción del sonido
    void stop();

private:
    Mix_Music* music;
};

#endif	// __SOUND_H__
