#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include "InputHandler.h"
#include "Cursor.h"

enum class WindowStatus { OPEN, CLOSE, NEXT_WINDOW };

class InputHandler {
public:
	// 
	InputHandler();
	
	// Liberación recursos de la instancia
	virtual ~InputHandler();

	// Handler de eventos de teclado/mouse
	// Retorna false si el evento es SDL_QUIT
	virtual WindowStatus handleInput() = 0;

	virtual void update();

protected:
	Cursor cursor;
};

#endif	// __INPUT_HANDLER_H__
