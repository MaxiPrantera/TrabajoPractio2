#include "ficha.h"

Ficha::Ficha(){
	this->tipo = soldado;
	this->estado = viva;
	this->escudo = false;
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Ficha::Ficha(TipoFicha tipo, unsigned int x, unsigned int y, unsigned int z){
	this->tipo = tipo;
	this->estado = viva;
	this->escudo = false;
	this->x = x;
	this->y = y;
	this->z = z;
}

Ficha::Ficha(const Ficha& ficha){
	this->tipo = ficha.tipo;
	this->estado = ficha.estado;
	this->escudo = ficha.escudo;
	this->x = ficha.x;
	this->y = ficha.y;
	this->z = ficha.z;
}

Ficha::~Ficha(){

}

EstadoFicha Ficha::getEstado(){
	return this->estado;
}

int Ficha::getUbicacionX(){
	return this->x;
}

int Ficha::getUbicacionY(){
	return this->y;
}

int Ficha::getUbicacionZ(){
	return this->z;
}

void Ficha::setEstado(EstadoFicha estado){
	this->estado = estado;
}

void Ficha::setPosicion(unsigned int x, unsigned int y, unsigned int z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void Ficha::eliminarFicha(){
	if (this->escudo == true){
		quitarEscudo();
	}
	else{
		setEstado(muerta);
	}
}

TipoFicha Ficha::getTipoFicha(){
	return this->tipo;
}

bool Ficha::getEscudo(){
	return this->escudo;
}

void Ficha::darEscudo(){
	this->escudo = true;
}


void Ficha::quitarEscudo(){
	this->escudo = false;
}







