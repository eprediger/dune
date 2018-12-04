#include "HandlerThread.h"

HandlerThread::HandlerThread(Application &app) : app(app) {}

void HandlerThread::run() {
	while (app.running()) {
		app.handleEvent();
	}
}

void HandlerThread::stop() {
    SDL_Event quit;
    quit.type = SDL_QUIT;
    SDL_PushEvent(&quit);
}
