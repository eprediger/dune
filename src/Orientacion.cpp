#include "Orientacion.h"
#include "Position.h"

Orientacion::Orientacion(){
	this->valor = indefinida();
}

void Orientacion::calcular(Position& p1, Position& p2){
	if (p1==p2) return;	
	if (p1.getX() < p2.getX()){
		if (p1.getY() < p2.getY()){ 
			this->valor = sudoeste(); 
		}else if (p1.getY() == p2.getY()){
			this->valor = oeste();
		} else this->valor = noroeste();
	} else if (p1.getX() == p2.getX()){
		if (p1.getY() < p2.getY()){
			this->valor = sur();
		}
		else this->valor = norte();
	} else {
		if (p1.getY() < p2.getY()){
			this->valor = sudeste();
		} else if (p1.getY() == p2.getY()){
			this->valor = este();
		} else this->valor = noreste();
	}
}

int Orientacion::getValor(){
	return this->valor;
}

int Orientacion::indefinida(){
	return 0;
}

int Orientacion::norte(){
	return 1;
}

int Orientacion::noroeste(){
	return 2;
}

int Orientacion::oeste(){
	return 3;
}

int Orientacion::sudoeste(){
	return 4;
}

int Orientacion::sur(){
	return 5;
}

int Orientacion::sudeste(){
	return 6;
}

int Orientacion::este(){
	return 7;
}

int Orientacion::noreste(){
	return 8;
}



