#include "Application.h"
#include "View/BuildingViewFactory.h"

Application::Application(View& view, InputHandler& handler, Model& model) :
	isRunning(true),
	/*host(),
	port(),
	house(),*/
	view(view),
	handler(handler),
	model(model) {
}

Application::~Application() {}

bool Application::running() {
	return this->isRunning;
}

void Application::handleEvent() {
	this->isRunning = this->handler.handleInput();
}

void Application::render() {
	this->view.render();
}

void Application::update() {
	this->handler.update();
}
