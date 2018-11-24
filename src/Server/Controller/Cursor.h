#ifndef __CURSOR_H__
#define __CURSOR_H__

#include <SDL2/SDL.h>

class Cursor {
public:
	// Wrapper para cursor. Atributos:
	// initial_@ para salvar posicion inicial
	// current_@ para salvar position actual
	Cursor();

	// Libera recursos asociados a la instancia
	~Cursor();

	// Setea posicion inicial del mouse relativo a la ventana
	void initialPosition();

	// Setea posicion actual del mouse relativo a la ventana
	void currentPosition();

	// Devuelve true si initial_@ == current_@
	bool notMoving();

	int initial_x, initial_y, current_x, current_y;
};

#endif	// __CURSOR_H__
