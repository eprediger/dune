#ifndef __GAME_VIEW_H__
#define __GAME_VIEW_H__

#include "View.h"

#include <vector>

#define TAG_FONT_SIZE 20

class GameView : public View {
public:
	//
	GameView(const int width, const int height);

	// Libera recursos asociados a la instancia
	~GameView();

	void RenderHPBar(int x, int y, int w, int h, float Percent, SDL_Color FGColor, SDL_Color BGColor);

	void RenderVPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor);

	void render() override;

private:
	Sound backgroundMusic;
	Text moneyTag, buildingTag, unitsTag;
	unsigned moneyBalance;
	std::vector<SdlTexture*> buildings;
	std::vector<SdlTexture*> units;
	SdlTexture buttons;

};

#endif	// __GAME_VIEW_H__
