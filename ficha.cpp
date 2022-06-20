#include "ficha.h"

Ficha::Ficha(TipoFicha tipo, Casillero * casillero){
	this->tipo = tipo;
	this->estado = viva;
	this->posicion = casillero;

	//Repensar (Como eliminar la otra ficha del casillero???)
	if (this->posicion->getEstado() == ocupado){
		casillero->eliminarFicha();
		eliminarFicha();
	}
}

Ficha::Ficha(const Ficha& ficha){
	this->tipo = ficha.tipo;
	this->estado = ficha.estado;
	this->posicion = ficha.posicion;
}

Ficha::~Ficha(){

}

EstadoFicha Ficha::getEstado(){
	return this->estado;
}

int Ficha::getUbicacionX(){
	return this->posicion->getX();
}

int Ficha::getUbicacionY(){
	return this->posicion->getY();
}

int Ficha::getUbicacionZ(){
	return this->posicion->getZ();
}

void Ficha::setEstado(EstadoFicha estado){
	this->estado = estado;
}

void Ficha::setPosicion(Casillero * casillero){
	this->posicion = casillero;
}

void Ficha::moverFicha(char direccion, Tablero * tablero){
	
	int x = getUbicacionX();
	int y = getUbicacionY();
	int z = getUbicacionZ();
	Casillero* casillero;
	
	switch (direccion){
		case IZQUIERDA:
			x--;
		break;

		case ARRIBA:
			y--;
		break;

		case DERECHA:
			x++;
		break;

		case ABAJO:
			y++;
		break;

		case DIAGONAL_IZQUERDA_ARRIBA:
			x--;
			y--;
		break;

		case DIAGONAL_DERECHA_ARRIBA:
			x++;
			y--;
		break;

		case DIAGONAL_IZQUERDA_ABAJO:
			x--;
			y++;
		break;

		case DIAGONAL_DERECHA_ABAJO:
			x++;
			y++;
		break;
	}
	casillero = tablero->getCasillero(x,y,z);
	if (casillero->getEstado() == vacio){
		setPosicion(casillero);
		casillero->setEstado(ocupado);
	}
	else if (casillero->getEstado() == ocupado){
		casillero->eliminarFicha();
		casillero->setEstado(inactivo);
		eliminarFicha();
		
	}
	else{
		std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
	}
}


void Ficha::revivirSoldado(){
	setEstado(viva);
	this->posicion->setEstado(ocupado);
}

void Ficha::eliminarFicha(){
	setEstado(muerta);
}

TipoFicha Ficha::getTipoFicha(){
	return this->tipo;
}








