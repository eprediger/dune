#ifndef __GAME_VIEW_H__
#define __GAME_VIEW_H__

#include "View.h"
#include "Model/Model.h"
#include "UnitView.h"

#include "BuildingView.h"
#include "SelectorView.h"
#include "BuildingConstructorView.h"
#include "MapView.h"
#include "ButtonView.h"
#include "PlayerView.h"
#include <memory>
#include <string>
#include <vector>

#define TAG_FONT_SIZE	16

#define BTN_INIT_HEIGHT 6
#define BTN_WIDTH 80
#define BTN_HEIGHT ((BTN_WIDTH) * 3 / 4)
#define BTN_VERT_SPACE ((BTN_HEIGHT) + 5)
#define BTN_SELL_BUILDING 34

#define ENERGY_BAR_WIDTH 5

class RocketView;

class GameView : public View {
private:
	Model& model;
	Player& player;
	std::vector<UnitView*> unitViews;
	std::vector<DeadUnitView*> deadUnitViews;
	std::vector<BuildingView*> buildingViews;
	std::vector<RocketView*> rocketViews;
	SelectorView* selectorView;
	PlayerView playerView;
	BuildingConstructorView* constructorView;
	MapView map_view;
	Area camera;
	Sound backgroundMusic;
	Text buildingTag, unitsTag;
	std::vector<ButtonView*> buildingButtons;
	std::vector<ButtonView*> unitButtons;
	ButtonView* buildingSellButton;
	int map_width;
	int map_height;
	int camera_width;
	int camera_height;

public:
	GameView(const int width, const int height, Model& model, Player& player);

	~GameView();

	SdlWindow& getWindow();

	void addUnitView(UnitView* unitView);

	void addBuildingView(BuildingView* buildingView);

	void addRocketView(RocketView* rocketView);

	void addSelectorView(Selector& selector);

	void addBuildingConstructorView(BuildingConstructor* constructor);

	void RenderVPBar(int x, int y, int h, float percent, SDL_Color FGColor, SDL_Color BGColor);

	void cleanDeadViews();

	std::vector<RocketView*>& getRocketViews();

	void moveUp(const int distance);
	void moveDown(const int distance);
	void moveLeft(const int distance);
	void moveRight(const int distance);

	int getCameraX() const;
	int getCameraY() const;
	int getCameraWidth() const;
	int getCameraHeight() const;

	void grabMouse();
	void releaseMouse();

	ButtonView& createUnitButton(const std::string& filename, int number_steps, const char* sound_fx);

	ButtonView& createBuildingButton(const std::string& filename, int number_steps, const char* sound_fx);

	ButtonView& createBarracksButton(const std::string& playerHouse, int number_steps, const char* sound_fx);

	ButtonView& createSellBuildingButton(const std::string& filename);

	void render() override;
};

#endif	// __GAME_VIEW_H__
