#ifndef __VISTA_UNIDAD_H__
#define __VISTA_UNIDAD_H__


#include "Unity.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Position.h"
#include <map>
#include "Orientacion.h"

class VistaUnidad{
	public:
		VistaUnidad(Unity& unidad, SdlWindow& window);
		void dibujar();
	private:
		Unity& unidad;
		Position prev_pos;
		Orientacion orientacion;
		static std::map<int,SdlTexture*> vistas;
};

#endif
