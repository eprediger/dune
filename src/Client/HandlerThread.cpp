#include "HandlerThread.h"

HandlerThread::HandlerThread(Application &app) : app(app) {}

void HandlerThread::run() {
	while (app.running()) {
		app.handleEvent();
	}
}
