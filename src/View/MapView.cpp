#include "MapView.h"
#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "../Model/Map.h"
#include "Area.h"

MapView::MapView(Map &mapa, SdlWindow &window) :
	map(mapa),
	terrenos("../terrain/d2k_BLOXBASE.bmp", window),
	areas() {
	areas.emplace(std::make_pair('A', Area(0, 8, 32, 32)));
	areas.emplace(std::make_pair('S', Area(64,296,32,24)));
	areas.emplace(std::make_pair('M', Area(80,296,32,24)));
	areas.emplace(std::make_pair('R', Area(106, 216, 32, 32)));
	areas.emplace(std::make_pair('P', Area(0, 64, 32, 32)));
	areas.emplace(std::make_pair('D', Area(32, 96, 32, 32)));
	areas.emplace(std::make_pair('C', Area(112, 64, 32, 32)));
}

void MapView::draw(Area& camara) {
	int i = camara.getY() / map.getBlockHeight();
	int lim_i = i + 1 + (camara.getHeight() / map.getBlockHeight());
	if (lim_i > map.getHeightInBlocks()) {
		lim_i = map.getHeightInBlocks();
	}

	int j = camara.getX() / map.getBlockWidth();
	int lim_j = j + 1 + (camara.getWidth() / map.getBlockWidth());
	if (lim_j > map.getWidthInBlocks()) {
		lim_j = map.getWidthInBlocks();
	}
	for (; i < lim_i ; i++) {
		for (j = camara.getX() / BLOCK_WIDTH; j < lim_j ; j++) {
			terrenos.render(areas.at(map.blockAt(j, i).getKey()), Area(j * BLOCK_WIDTH- camara.getX(), i * BLOCK_HEIGHT - camara.getY(), 32, 32));
		}
	}
}