#include "ficha.h"

Ficha::Ficha(TipoFicha tipo, unsigned int x, unsigned int y, unsigned int z){
	this->tipo = tipo;
	this->estado = viva;
	this->x = x;
	this->y = y;
	this->z = z;

	//Repensar (Como eliminar la otra ficha del casillero???)
	//if (this->posicion->getEstado() == ocupado){
	//	casillero->eliminarFicha();
	//	eliminarFicha();
	//}
}

Ficha::Ficha(const Ficha& ficha){
	this->tipo = ficha.tipo;
	this->estado = ficha.estado;
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

void Ficha::setPosicion(unsigned int x, unsigned inty, unsigned int z){
	this->x = x;
	this->y = y;
	this->z = z;
}
/*
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
*/

void Ficha::eliminarFicha(){
	setEstado(muerta);
}

TipoFicha Ficha::getTipoFicha(){
	return this->tipo;
}








