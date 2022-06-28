#include "casillero.h"
#include "ficha.h"
#include <iostream>


/*
Post: Inicializa un casillero con  una ficha nueva con el simbolo especificado
*/
Casillero::Casillero(){
    this->estado = vacio;
    this->turnosRestantesDesbloqueo = 0;
}

void Casillero::setEstado(EstadoCasillero estado){
    this->estado = estado;
}

EstadoCasillero Casillero::getEstado(){
    return this->estado;
}

void Casillero::setTerreno(Terreno terreno){
    this->terreno = terreno;
}

Terreno Casillero::getTerreno(){
    return this->terreno;
}

unsigned int Casillero::getX(){
    return this->x;
}

unsigned int Casillero::getY(){
    return this->y;
}

unsigned int Casillero::getZ(){
    return this->z;
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
PRE: el casillero existe
Post: copia el contenido de un casillero a otro casillero
*/
void Casillero::copiarCasillero(Casillero* dest){
//    dest->contenidoCasillero = this->contenidoCasillero;
//    this->contenidoCasillero = NULL;
}

/*
Pre: casillero fue creado anteriormete
Post :retorna la cantidad de turnos restantes por los cuales el casillero esta bloqueado
*/
unsigned int Casillero::getTurnosRestantesDesbloqueo(){
    return this->turnosRestantesDesbloqueo;
}

/*
Pre : casillero creado anteriormete
Post : setea la cantidad de turnos restantes por los cuales el casillero esta bajo efectos de una carta
*/

void Casillero::setTurnosRestantesDesbloqueo(unsigned int cantidadTurnos){
    this->turnosRestantesDesbloqueo = cantidadTurnos;

}
/*
Pre : casillero creado anteriormetePost : Decrementa en 1 la cantidad de turnos restantes para que pueda usarse el casillero*/

void Casillero::decrementarTurnosRestantesDesbloqueo(){
    (this->turnosRestantesDesbloqueo)--;
}
/*
PRE: el casillero fue creado anteriormente y posee una ficha en el
Post : Bloquea la ficha del casillero
void Casillero::bloquearFichaDelCasillero(){
    this->contenidoCasillero->bloquearFicha();
}
*/

void Casillero::setFicha(Ficha* ficha) {
    this->ficha = ficha;
    this->estado = ocupado;
}

/*
Pre : casillero creado anteriormete
Post: devuelve el contenido del casillero*/
//Ficha* Casillero::obtenerContenidoCasillero(){
//	return this->contenidoCasillero;
//}

void Casillero::eliminarFicha(){
    this->ficha->eliminarFicha();
    this->turnosRestantesDesbloqueo = 0;
    this->estado = inactivo;
}

