#include "constantes.h"
#include "ficha.h"

Ficha::Ficha(Ficha tipo, EstadoFicha estado, Jugador * jugador, Casillero * casillero){
	this->tipo = tipo;
	this->estado = estado;
	this->duenio = jugador;
	this->posicion = casillero;
}

Ficha::Ficha(const Ficha& ficha){
	this->tipo = ficha.tipo;
	this->estado = ficha.estado;
	this->duenio = ficha.duenio;
	this->posicion = ficha.posicion;
}

Ficha::~Ficha(){

}

EstadoFicha Ficha::getEstado(){
	return this->estado;
}

int Ficha::getUbicacionX(){
	return this->posicion->retornarX();
}

int Ficha::getUbicacionY(){
	return this->posicion->retornarY();
}

void Ficha::setEstado(EstadoFicha estado){
	this->estado = estado;
}

void Ficha::setPosicion(Casillero * casillero){
	this->posicion = casillero;
}

void Ficha::moverFicha(char direccion, Tablero tablero){
	
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
		eliminarFicha();
	}
	else{
		std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
	}
}


void Ficha::revivirSoldado(){
	setEstado(vivo);
}

void Ficha::eliminarFicha(){
	setEstado(muerto);
}








