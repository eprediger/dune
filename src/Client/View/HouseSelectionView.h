#ifndef __HOUSE_SELECTION_VIEW_H__
#define __HOUSE_SELECTION_VIEW_H__

#include "View.h"
#include <vector>

/*#define TITLE_FONT_SIZE 42*/
#define HOUSE_FONT_SIZE 28

class HouseSelectionView : public View {
public:
	// PRE:  width > 0 height > 0
	// POST: creación de ventana de selección de casa
	HouseSelectionView(const int width, const int height);

	// Libera recursos asociados a la instancia
	~HouseSelectionView();

	// Selecciona elemento en posicion (x, y)
	bool setFocusOn(const int x, const int y);

	std::string getHouse() const;

	void render() override;

private:
	SdlTexture backgroundImage;
	Sound backgroundMusic;
	Text title;
	std::vector<std::unique_ptr<SdlTexture>> houses;
	std::vector<std::unique_ptr<Text>> houseNames;
	Text* selectedHouse;
};

#endif	// __HOUSE_SELECTION_VIEW_H__
