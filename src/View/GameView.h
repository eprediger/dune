#ifndef __OLD_VIEW_H__
#define __OLD_VIEW_H__

#include "MapView.h"
#include "UnitView.h"
#include "BuildingView.h"
#include <memory>
#include "SelectorView.h"
#include "../Model/Model.h"
#include "View.h"

#define TAG_FONT_SIZE 20

class GameView : public View {
private:
	Model& model;
	std::vector<UnitView*> unitViews;
	std::vector<BuildingView*> buildingViews;
	SelectorView* selectorView;
	MapView map_view;
public:
	Area camera;
private:
	Sound backgroundMusic;
	Text moneyTag, moneyBalance, buildingTag, unitsTag;
	std::vector<SdlTexture*> buildingButtons;
	std::vector<SdlTexture*> unitButtons;
	SdlTexture buttons;
	int map_width;
	int map_height;
	int camera_width;
	int camera_height;

public:
	GameView(const int width, const int height, Model& model);
	~GameView();

	SdlWindow& getWindow();
	void addUnitView(UnitView* unitView);

	void addBuildingView(BuildingView* buildingView);

	void addSelectorView(Selector& selector);

	void RenderVPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor);

	void cleanDeadUnitViews();

	void moveUp(int distance);
	void moveDown(int distance);
	void moveLeft(int distance);
	void moveRight(const int distance);

	void render() override;
};

#endif	// __OLD_VIEW_H__
