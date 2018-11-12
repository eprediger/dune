#include "MapView.h"
#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Model/Map.h"
#include "Area.h"

MapView::MapView(Map& mapa, SdlWindow& window) :
	mapa(mapa),
	terrenos("../terrain/d2k_BLOXBASE.bmp", window),
	areas() {
	areas.emplace(std::make_pair('A', Area(0, 8, 32, 32)));
	areas.emplace(std::make_pair('R', Area(120, 240, 32, 32)));
	areas.emplace(std::make_pair('P', Area(0, 64, 32, 32)));
	areas.emplace(std::make_pair('D', Area(32, 96, 32, 32)));
	areas.emplace(std::make_pair('C', Area(112, 64, 32, 32)));
}

void MapView::draw(Area& camara) {
	int i = camara.getY() / 32;
	int lim_i = i + 1 + (camara.getHeight() / 32);
	if (lim_i > mapa.getHeightInBlocks()) {
		lim_i -= 1;
	}

	int j = camara.getX() / 32;
	int lim_j = j + 1 + (camara.getWidth() / 32);
	if (lim_j > mapa.getWidthInBlocks()) {
		lim_j -= 1;
	}

	for (; i < lim_i ; i++) {
		for (j = camara.getX() / 32; j < lim_j ; j++) {
			terrenos.render(areas.at(mapa.blockAt(j, i).getKey()), Area(j * 32 - camara.getX(), i * 32 - camara.getY(), 32, 32));
		}
	}
}
