#ifndef __ORIENTATION_H__
#define __ORIENTATION_H__

#include "Position.h"

class Orientation{
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
		void calcular(const Position& p1,const Position& p2);
		void calcularEnAtaque(const Position& p1, const Position& p2);
		bool operator==(const Orientation& other);
		int getValor();
		Orientation();		
	private:
		int valor;	
};

#endif
