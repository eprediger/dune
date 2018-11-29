#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "View/View.h"
#include "Controller/InputHandler.h"
#include "Model/Model.h"

#define WINDOW_WIDTH  1240
#define WINDOW_HEIGHT 768

class Application {
public:
	Application(View& view, InputHandler& handler, Model& model);

	// Liberación de recursos asoaciados
	~Application();

	// Retorna true mientras el cliente no salga de la aplicación
	bool running();

	// Manejar input de usuario
	void handleEvent();

	// Renderiza vista
	void render();

private:
	bool isRunning;
	// std::string host, port, house;
	View& view;
	InputHandler& handler;
	Model& model;
};

#endif	// __APPLICATION_H__
