#ifndef __GAMEVIEW_H__
#define __GAMEVIEW_H__


#include "MapView.h"
#include "UnitView.h"
#include "BuildingView.h"
#include <memory>
#include "SelectorView.h"
#include "../Model/Model.h"
#include "View.h"

#define TAG_FONT_SIZE 20

class OldView : public View {
private:
	std::vector<UnitView*> unit_views;
	std::vector<BuildingView*> building_views;
	SelectorView* selectorView;
    MapView map_view;
	Area camera;

	Sound backgroundMusic;
	Text moneyTag, buildingTag, unitsTag;
	unsigned moneyBalance;
	std::vector<SdlTexture*> buildings;
	std::vector<SdlTexture*> units;
	SdlTexture buttons;
	int map_width;
	int map_height;
	int camera_width;
	int camera_height;

public:
	OldView(const int width, const int height, Model &model);
	~OldView();

	SdlWindow& getWindow();
	void addUnitView(UnitView* unitView);

	void addBuildingView(BuildingView* buildingView);

	void addSelectorView(SelectorView* selectorView);

	void RenderVPBar(int x, int y, int w, int h, float percent, SDL_Color FGColor, SDL_Color BGColor);

	void cleanDeadUnitViews();

	void moveUp(int distance);
	void moveDown(int distance);
	void moveLeft(int distance);
	void moveRight(int distance);

	void render() override;

};
#endif //__VIEW_H__
