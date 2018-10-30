#include "VistaUnidad.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "Position.h"
#include "Orientacion.h"
#include <map>
#include "Area.h"

std::map<int,SdlTexture*> VistaUnidad::vistas;

VistaUnidad::VistaUnidad(Unity& unidad, SdlWindow& window)
	:unidad(unidad)
	,prev_pos(unidad.getPosition())
	,orientacion()
{
	if (vistas.empty()){
		vistas.emplace(std::make_pair(Orientacion::indefinida(),new SdlTexture("../imgs/imgs/000a612e.bmp",window)));		
		vistas.emplace(std::make_pair(Orientacion::norte(),new SdlTexture("../imgs/imgs/000a612e.bmp",window)));
		vistas.emplace(std::make_pair(Orientacion::noroeste(),new SdlTexture("../imgs/imgs/000a73a3.bmp",window)));	
		vistas.emplace(std::make_pair(Orientacion::oeste(),new SdlTexture("../imgs/imgs/000a910f.bmp",window)));
		vistas.emplace(std::make_pair(Orientacion::sudoeste(),new SdlTexture("../imgs/imgs/000aad94.bmp",window)));
		vistas.emplace(std::make_pair(Orientacion::sur(),new SdlTexture("../imgs/imgs/000ac0d3.bmp",window)));
		vistas.emplace(std::make_pair(Orientacion::sudeste(),new SdlTexture("../imgs/imgs/000ad4b2.bmp",window)));
		vistas.emplace(std::make_pair(Orientacion::este(),new SdlTexture("../imgs/imgs/000af1f9.bmp",window)));
		vistas.emplace(std::make_pair(Orientacion::noreste(),new SdlTexture("../imgs/imgs/000b0a18.bmp",window)));
	}
}

void VistaUnidad::dibujar(Area camara){
	Position pos = unidad.getPosition();
	Area dest(pos.getX()- 16 - camara.getX(),pos.getY()-16 - camara.getY() ,32,32);
	orientacion.calcular(prev_pos,pos);
	prev_pos = pos;
	vistas.at(orientacion.getValor())->render(Area(0, 0, 41, 38),dest);
}

Unity &VistaUnidad::getUnity() {
	return unidad;
}


