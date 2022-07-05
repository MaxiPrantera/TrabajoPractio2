#include "casillero.h"
#include "ficha.h"
#include <iostream>


/*
Post: Inicializa un casillero con  una ficha nueva con el simbolo especificado
*/
Casillero::Casillero(){
	this->terreno = aire;
    this->estado = vacio;
    this->ficha = 0;
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

/*
Post: Inicializa un casillero sin ficha en las coordenadas indicadas.
*/
Casillero::Casillero(unsigned int x, unsigned int y, unsigned int z){
	this->terreno = aire;
    this->estado = vacio;
    this->ficha = 0;
    this->x = x;
    this->y = y;
    this->z = z;
}

/*
Pre:Existe el casillero
Post: elimina la memoria dinamica del casillero
y de la ficha que contiene
*/
Casillero::~Casillero()
{

}

/*
Post: Setea el estado con el valor indicado.
*/
void Casillero::setEstado(EstadoCasillero estado){
    this->estado = estado;
}

/*
Post: Setea el terreno con el valor indicado.
*/
void Casillero::setTerreno(Terreno terreno){
    this->terreno = terreno;
}

/*
Post: Devuelve la coordenada en x del casillero.
*/
unsigned int Casillero::getX(){
    return this->x;
}

/*
Post: Devuelve la coordenada en y del casillero.
*/
unsigned int Casillero::getY(){
    return this->y;
}

/*
Post: Devuelve la coordenada en z del casillero.
*/
unsigned int Casillero::getZ(){
    return this->z;
}

/*
Post: Devuelve el estado del casillero.
*/
EstadoCasillero Casillero::getEstado(){
    return this->estado;
}

/*
Post: Devuelve el terreno del casillero.
*/
Terreno Casillero::getTerreno(){
    return this->terreno;
}

/*
Pre : casillero creado anteriormete
Post: devuelve la ficha contenida en el casillero*/
Ficha* Casillero::getFicha(){
	return this->ficha;
}

/*
Post: Asigna la ficha al casillero.
*/
void Casillero::setFicha(Ficha* ficha) {
	if(ficha == 0)
	{
	    this->ficha = ficha;
        this->estado = vacio;
	}
	else
	{
		if (this->estado == vacio)
		{
			ficha->setPosicion(this->x, this->y, this->z);
		    this->ficha = ficha;
	        this->estado = ocupado;
		}
		else if (this->estado == ocupado){
			if (ficha->getEscudo() && this->ficha->getEscudo()){
				this->ficha->quitarEscudo();
				ficha->quitarEscudo();
			}
			this->eliminarFicha();
			ficha->eliminarFicha();
			if (ficha->getEstado() == viva){
				ficha->setPosicion(this->x, this->y, this->z);
			    this->ficha = ficha;
		        this->estado = ocupado;
			}
		}
	}
}

/*
Post: Elimina la ficha del casillero.
*/
void Casillero::eliminarFicha(){
    this->estado = inactivo;
	if(this->ficha != 0)
	{
	    this->ficha->eliminarFicha();
	    if (this->ficha->getEstado() == viva)
	    {
	    	this->estado = ocupado;
	    }
	}
}

