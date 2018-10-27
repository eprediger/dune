#ifndef __VISTA_MAP_H__
#define __VISTA_MAP_H__

#include "Map.h"
#include "SdlTexture.h"
#include "SdlWindow.h"

class VistaMap{
	public:
		VistaMap(Map& mapa, SdlWindow& window);
		void dibujar();
	private:
		Map& mapa;
		SdlTexture terrenos;
};

#endif
