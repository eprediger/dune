#ifndef __ORIENTACION_H__
#define __ORIENTACION_H__

#include "../Position.h"

class Orientacion{
	public:
		static int indefinida();
		static int norte();
		static int noroeste();
		static int oeste();
		static int sudoeste();
		static int sur();
		static int sudeste();
		static int este();
		static int noreste();
		void calcular(Position& p1, Position& p2);
		int getValor();
		Orientacion();		
	private:
		int valor;	
};

#endif
