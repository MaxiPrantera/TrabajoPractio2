#include "casillero.h"
#include <iostream>
#define SIMBOLO_FICHA_VACIA ' '

/*
Post: Inicializa un casillero con  una ficha nueva con el simbolo especificado
*/
Casillero::Casillero(){
    this->casilleroVacio = true;
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroAnulado = false;
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
Post: : devuelve true si el casillero esta vacio
*/
bool Casillero::estaCasilleroVacio()
{
    return this->casilleroVacio;
}

/* Post: devuelve true si el casillero esta anulado para colocar fichas*/
bool Casillero::estaCasilleroAnulado(){
    return this->casilleroAnulado;
}
/*
PRE: el casillero esta vacio al momento de anularse
Post:  anula un casillero , entonces no podran colocarse fichas en el
*/
void Casillero::anularCasillero(){
    this->casilleroAnulado = true;
}
/*
PRE: el casillero existe
Post: vacia un casillero para que pueda colocarse otra ficha
asignandole la ficha vacia
*/
void Casillero::vaciarCasillero(){
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroAnulado = false;

}

/*
PRE: el casillero existe
Post: copia el contenido de un casillero a otro casillero
*/
void Casillero::moverJugadorEnCasillero(Casillero* dest){
    dest->contenidoCasillero->insertarJugadorEnCasillero(this->obtenerContenidoCasillero());
    dest->casilleroVacio = false;
    ///falta  mover el puntero
    this->casilleroVacio = true;
}
void Casillero::insertarJugadorEnCasillero(Jugador* jugador){
    this->contenidoCasillero = jugador;
}
/*
Pre: casillero fue creado anteriormete
Post :retorna la cantidad de turnos restantes por los cuales el casillero esta bloqueado
*/
size_t Casillero::getTurnosRestantesDesbloqueo(){
    return this->turnosRestantesDesbloqueo;
}

/*
Pre : casillero creado anteriormete
Post : setea la cantidad de turnos restantes por los cuales el casillero esta bajo efectos de una carta
*/

void Casillero::setTurnosRestantesDesbloqueo(size_t cantidadTurnos){
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
*/
void Casillero::bloquearFichaDelCasillero(){
    this->contenidoCasillero->bloquearFicha();
}

/*Pre : casillero creado anteriormete
 * POST:asigna una ficha en el contenido del casillero
 */

void Casillero::setJugadorEnCasillero(Jugador jugadorId) {
    this->contenidoCasillero = new Jugador(jugadorId);
    
}

/*
Pre : casillero creado anteriormete
Post: devuelve el contenido del casillero*/
Jugador* Casillero::obtenerContenidoCasillero()
{
	return this->contenidoCasillero;
}

/*Pre : casillero creado anteriormete
 * POST:Desbloquea el casillero cambiando el estado de casilleroAnulado a false
 */
void Casillero::desbloquearCasillero()
{
	this->casilleroAnulado=false;
}


