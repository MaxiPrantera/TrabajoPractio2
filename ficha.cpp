#include "constantes.h"
#include "ficha.h"

Ficha::Ficha(TipoFicha tipo, EstadoFicha estado, Jugador * jugador, Casillero * casillero){
	this->tipo = tipo;
	this->estado = estado;
	this->duenio = jugador;
	this->posicion = casillero;
}

Ficha::Ficha(const Ficha& ficha){
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

void Ficha::setEstado(EstadoFicha estado){
	this->estado = estado;
}

void Ficha::setPosicion(Casillero * casillero){
	this->posicion = casillero;
}

void Ficha::moverFicha(char direccion, Tablero* tablero){
	
	int x = getUbicacionX();
	int y = getUbicacionY();
	Casillero* casillero;
	
	switch (direccion){
		case IZQUIERDA:
			x--;
			casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				setPosicion(casillero);
			}
			else if (casillero->getEstado() == ocupado){
				casillero->eliminarContenidoCasillero();
				eliminarFicha();
				casillero->setEstado(inactivo);
			}
			else{
				std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
			}
		break;

		case ARRIBA:
			y--;
			casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				setPosicion(casillero);
			}
			else if (casillero->getEstado() == ocupado){
				casillero->eliminarContenidoCasillero();
				eliminarFicha();
				casillero->setEstado(inactivo);
			}
			else{
				std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
			}
		break;

		case DERECHA:
			x++;
			casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				setPosicion(casillero);
			}
			else if (casillero->getEstado() == ocupado){
				casillero->eliminarContenidoCasillero();
				eliminarFicha();
				casillero->setEstado(inactivo);
			}
			else{
				std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
			}
		break;

		case ABAJO:
			y++;
			casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				setPosicion(casillero);
			}
			else if (casillero->getEstado() == ocupado){
				casillero->eliminarContenidoCasillero();
				eliminarFicha();
				casillero->setEstado(inactivo);
			}
			else{
				std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
			}
		break;

		case DIAGONAL_IZQUERDA_ARRIBA:
			x--;
			y--;
			casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				setPosicion(casillero);
			}
			else if (casillero->getEstado() == ocupado){
				casillero->eliminarContenidoCasillero();
				eliminarFicha();
				casillero->setEstado(inactivo);
			}
			else{
				std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
			}
		break;

		case DIAGONAL_DERECHA_ARRIBA:
			x++;
			y--;
			casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				setPosicion(casillero);
			}
			else if (casillero->getEstado() == ocupado){
				casillero->eliminarContenidoCasillero();
				eliminarFicha();
				casillero->setEstado(inactivo);
			}
			else{
				std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
			}
		break;

		case DIAGONAL_IZQUERDA_ABAJO:
			x--;
			y++;
			casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				setPosicion(casillero);
			}
			else if (casillero->getEstado() == ocupado){
				casillero->eliminarContenidoCasillero();
				eliminarFicha();
				casillero->setEstado(inactivo);
			}
			else{
				std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
			}
		break;

		case DIAGONAL_DERECHA_ABAJO:
			x++;
			y++;
			casillero = tablero->getCasillero(x,y,1);
			if (casillero->getEstado() == vacio){
				setPosicion(casillero);
			}
			else if (casillero->getEstado() == ocupado){
				casillero->eliminarContenidoCasillero();
				eliminarFicha();
				casillero->setEstado(inactivo);
			}
			else{
				std::cout << "Casillero inactivo no puedes moverte ahi" <<endl;
			}
		break;
	}
}

/*
void Ficha::revivirSoldado(){
	setEstado(vivo);
}

void Ficha::eliminarFicha(){
	setEstado(muerto);
}
*/






