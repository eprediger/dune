#include "VistaMap.h"
#include <iostream>
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Map.h"

VistaMap::VistaMap(Map& mapa, SdlWindow& window)
	:mapa(mapa)
	,terrenos("../terrain/d2k_BLOXBASE.bmp",window){}



Area get_source_area(char key){
	switch (key){
		case 'A':
			return Area(0,8,32,32);
		case 'R':
			return Area(120,240,32,32);
		case 'P':
			return Area(0,64,32,32);
		case 'D':
			return Area(32,96,32,32);
		case 'S':
			return Area(112,64,32,32);
			break;
	}
	return Area(0,8,16,16);
}

void VistaMap::dibujar(){
	for(int i = 0; i<mapa.getHeightInBlocks() ; i++){
		for (int j = 0; j<mapa.getWidthInBlocks() ; j++){
			terrenos.render(get_source_area(mapa.blockAt(j,i).getKey()),Area(j*32,i*32,32,32));
		}
	}
}
