#include "Orientation.h"
#include "Position.h"

Orientation::Orientation() {
	this->valor = indefinida();
}

void Orientation::calcular(const Position& p1, const Position& p2) {
	if (p1 == p2) return;
	if (p1.getX() < p2.getX()) {
		if (p1.getY() < p2.getY()) {
			this->valor = sudoeste();
		} else if (p1.getY() == p2.getY()) {
			this->valor = oeste();
		} else {
			this->valor = noroeste();
		}
	} else if (p1.getX() == p2.getX()) {
		if (p1.getY() < p2.getY()) {
			this->valor = sur();
		} else {
			this->valor = norte();
		}
	} else {
		if (p1.getY() < p2.getY()) {
			this->valor = sudeste();
		} else if (p1.getY() == p2.getY()) {
			this->valor = este();
		} else {
			this->valor = noreste();
		}
	}
}

void Orientation::calcularEnAtaque(const Position& p1, const Position& p2) {
	if (p1 == p2) return;
	if (p1.getX() < p2.getX() - 32) {
		if (p1.getY() < p2.getY() - 32) {
			this->valor = sudoeste();
		} else if (p1.getY() < p2.getY() + 32) {
			this->valor = oeste();
		} else {
			this->valor = noroeste();
		}
	} else if (p1.getX() < p2.getX() + 32) {
		if (p1.getY() < p2.getY()) {
			this->valor = sur();
		} else {
			this->valor = norte();
		}
	} else {
		if (p1.getY() < p2.getY() - 32) {
			this->valor = sudeste();
		} else if (p1.getY() < p2.getY() + 32) {
			this->valor = este();
		} else {
			this->valor = noreste();
		}
	}
}

bool Orientation::operator==(const Orientation& other) {
	return this->valor == other.valor;
}

int Orientation::getValor() {
	return this->valor;
}

int Orientation::indefinida() {
	return 0;
}

int Orientation::norte() {
	return 1;
}

int Orientation::noroeste() {
	return 2;
}

int Orientation::oeste() {
	return 3;
}

int Orientation::sudoeste() {
	return 4;
}

int Orientation::sur() {
	return 5;
}

int Orientation::sudeste() {
	return 6;
}

int Orientation::este() {
	return 7;
}

int Orientation::noreste() {
	return 8;
}
