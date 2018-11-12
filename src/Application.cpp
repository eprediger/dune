#include "Application.h"

Application::Application(View& view, InputHandler& handler) :
	isRunning(true),
	/*host(),
	port(),
	house(),*/
	view(view),
	handler(handler) {
}

Application::~Application() {}

bool Application::running() {
	return this->isRunning;
}

void Application::handleEvent() {
	this->isRunning = this->handler.handleInput();
}

void Application::update() {
	// this->model.step();
}

void Application::render() {
	this->view.render();
}
