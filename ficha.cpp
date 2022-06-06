#include "constantes.h"
#include "ficha.h"

Ficha::Ficha(Ficha tipo, EstadoFicha estado, Jugador * jugador, Casillero * casillero){
	this->tipo = tipo;
	this->estado = estado;
	this->dueño = jugador;
	this->posicion = casillero;
}

Ficha::Ficha(const Ficha& ficha){
	this->estado = ficha.estado;
	this->numFicha = ficha.numFicha;
	this->posicion = ficha.posicion;
}

Ficha::~Ficha(){

}

EstadoFicha Ficha::getEstado(){
	return this->estado;
}

int Ficha::getNumFicha(){
	return this->numFicha;
}

int Ficha::getUbicacionX(){
	return this->posicion->getX;
}

int Ficha::getUbicacionY(){
	return this->posicion->getY;
}

void Ficha::setEstado(EstadoFicha estado){
	this->estado = estado;
}

void Ficha::setNumFicha(int numFicha){
	this->numFicha = numFicha;
}

void Ficha::setPosicion(Casillero * casillero){
	this->posicion = casillero;
}

void Soldado::moverSoldado(char direccion){
	switch (direccion){
		case IZQUIERDA:
			setUbicacionX(x - 1);
		break;

		case ARRIBA:
			setUbicacionY(y - 1);
		break;

		case DERECHA:
			setUbicacionX(x + 1);
		break;

		case ABAJO:
			setUbicacionY(y + 1);
		break;

		case DIAGONAL_IZQUERDA_ARRIBA:
			setUbicacionX(x - 1);
			setUbicacionY(y - 1);
		break;

		case DIAGONAL_DERECHA_ARRIBA:
			setUbicacionX(x + 1);
			setUbicacionY(y - 1);
		break;

		case DIAGONAL_IZQUERDA_ABAJO:
			setUbicacionX(x - 1);
			setUbicacionY(y + 1);
		break;

		case DIAGONAL_DERECHA_ABAJO:
			setUbicacionX(x + 1);
			setUbicacionY(y + 1);
		break;
	}
}

void Ficha::verificarAtaque(int x, int y){
	if(this->posicion->getX == x
		&& this->posicion->getY == y){
		eliminarFicha();
	}

}

void Ficha::revivirFicha(){
	setEstado(vivo);
}

void Soldado::eliminarSoldado(){
	setEstado(muerto);
}









