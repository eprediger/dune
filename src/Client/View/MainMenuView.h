#ifndef __MAIN_MENU_VIEW_H__
#define __MAIN_MENU_VIEW_H__

#include "View.h"
#include <vector>

#define TXT_FONT_SIZE 	28
#define BOX_FONT_SIZE 	24
#define BTN_FONT_SIZE	36

/* Mejoras:
 * Colores del texto
 * TextBox de tamaño fijo
 * Resaltar TextBox seleccionado
 * Remover unique_ptr
 */
// https://gamedev.stackexchange.com/questions/140294/what-is-the-most-efficient-way-to-render-a-textbox-in-c-sdl2
// https://wiki.libsdl.org/Tutorials/TextInput#Example
// https://wiki.libsdl.org/SDL_RenderSetClipRect

class MainMenuView : public View {
public:
	// Crea la ventana principal del juego
	MainMenuView(const int width, const int height);

	// Libera recursos de la instancia
	~MainMenuView();

	// Selecciona elemento en posicion (x, y)
	// Los seleccionables son inputBoxes o playButton
	bool setFocusOn(const unsigned x, const unsigned y);

	// Selecciona el siguiente textBox
	void selectNextTextBox();

	// Elimina caracteres del textBox seleccionado
	void deleteFromTextBox();

	// Inserta texto en el textBox seleccionado
	void insertTextToTextBox(const char* text);

	// Imprime la informacion de los textBox (servidor y puerto)
	// Luego, se va a modificar para conectarse contra el servidor
	std::string getHost() const;

	std::string getPort() const;

    std::string getWindowWidth() const;

    std::string getWindowHeight() const;

	void render() override;
	
private:
	SdlTexture backgroundImage;
	Sound backgroundMusic;
	// Text title;
	SdlTexture titleImage;
	std::vector<std::unique_ptr<Text> > tags;
	std::vector<std::unique_ptr<TextBox> > inputBoxes;
	std::unique_ptr<Text> playButton;
	TextBox* selectedTextBox;
	unsigned textBoxIndex;
};

#endif	// __MAIN_MENU_VIEW_H__
