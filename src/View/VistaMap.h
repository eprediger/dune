#ifndef __VISTA_MAP_H__
#define __VISTA_MAP_H__

#include "../Map.h"
#include "SdlTexture.h"
#include "SdlWindow.h"
#include <map>
#include "Area.h"

class VistaMap{
	public:
		VistaMap(Map& mapa, SdlWindow& window);
		void dibujar(Area camara);
	private:
		Map& mapa;
		SdlTexture terrenos;
		std::map<char,Area> areas;
};

#endif
