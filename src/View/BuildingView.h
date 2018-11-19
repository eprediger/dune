#ifndef __BUILDINGVIEW_H__
#define __BUILDINGVIEW_H__

#include "../Model/Buildings/Building.h"
#include "SdlWindow.h"
#include "Area.h"
#include "SdlTexture.h"
#include "DeadBuildingView.h"
class BuildingView {
public:
	explicit BuildingView(Building& building,SdlWindow& window, Area src_area, Area dest_area);
	virtual ~BuildingView();
	Building& getBuilding();
	virtual void draw(Area& camara) = 0;
	void draw(Area& camara, SdlTexture*& sprite);
	void draw(Area& camara, SdlTexture*& sprite, SdlTexture*& base,int base_x, int base_y);
	void drawConstruction(Area& camara);

	DeadBuildingView* getDeadBuildingView();

	static bool isDead(BuildingView* view);

protected:
	static std::vector<SdlTexture*> construction_sprites; 
	std::vector<SdlTexture*>::iterator construction_it;
	Building& building;
	SdlWindow& window;
	Position pos;
	bool destroyed;
	Area src_area,dest_area;
	int player_r,player_g,player_b;
	SDL_Rect playerColorRect;
	bool construido;
	int update_sprite;
};

#endif //__BUILDINGVIEW_H__
