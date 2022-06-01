#include "soldado.h"
#include "constantes.h"

Soldado::Soldado(EstadoSoldado estado, int numSoldado, int ubicacion[3]){
	this->estado = estado;
	this->numSoldado = numSoldado;
	this->ubicacion[0] = ubicacion[0];
	this->ubicacion[1] = ubicacion[1];
	this->ubicacion[2] = 1;
}

Soldado::~Soldado(){

}

EstadoSoldado Soldado::getEstado(){
	return this->estado;
}

int Soldado::getNumSoldado(){
	return this->numSoldado;
}

int Soldado::getUbicacionX(){
	return this->ubicacion[0];
}

int Soldado::getUbicacionY(){
	return this->ubicacion[1];
}

void Soldado::setEstado(EstadoSoldado estado){
	this->estado = estado;
}

void Soldado::setNumSoldado(int numSoldado){
	this->numSoldado = numSoldado;
}

void Soldado::setUbicacion(int x, int y){
	this->ubicacion[0] = x;
	this->ubicacion[1] = y;

}

void Soldado::moverSoldado(char direccion){
	switch (direccion){
		case IZQUIERDA:
			setUbicacion(ubicacion[0] - 1, ubicacion[1]);
		break;

		case ARRIBA:
			setUbicacion(ubicacion[0], ubicacion[1] - 1);
		break;

		case DERECHA:
			setUbicacion(ubicacion[0] + 1, ubicacion[1]);
		break;

		case ABAJO:
			setUbicacion(ubicacion[0], ubicacion[1] + 1);
		break;

		case DIAGONAL_IZQUERDA_ARRIBA:
			setUbicacion(ubicacion[0] - 1, ubicacion[1] - 1);
		break;

		case DIAGONAL_DERECHA_ARRIBA:
			setUbicacion(ubicacion[0] + 1, ubicacion[1] - 1);
		break;

		case DIAGONAL_IZQUERDA_ABAJO:
			setUbicacion(ubicacion[0] - 1, ubicacion[1] + 1);
		break;

		case DIAGONAL_DERECHA_ABAJO:
			setUbicacion(ubicacion[0] + 1, ubicacion[1] + 1);
		break;
	}
}

void Soldado::verificarAtaque(int x, int y){
	if(x==ubicacion[0]
		&& y==ubicacion[1]){
		setEstado(muerto);
	}

}










