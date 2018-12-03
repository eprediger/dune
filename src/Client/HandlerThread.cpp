//
// Created by demian on 29/11/18.
//

#include "HandlerThread.h"

HandlerThread::HandlerThread(Application &app) : app(app) {}

void HandlerThread::run() {
    while (app.running()) {
        app.handleEvent();
    }
}
