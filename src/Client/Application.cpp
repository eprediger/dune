#include "Application.h"
#include "View/BuildingViewFactory.h"

Application::Application(View& view, InputHandler& handler, Model& model) :
	status(WindowStatus::OPEN),
	view(view),
	handler(handler),
	model(model) {
}

Application::~Application() {}

bool Application::running() {
	return (this->status != WindowStatus::CLOSE);
}

void Application::handleEvent() {
	this->status = this->handler.handleInput();
}

void Application::render() {
	this->view.render();
}

void Application::update() {
	this->handler.update();
	this->model.step();
}
