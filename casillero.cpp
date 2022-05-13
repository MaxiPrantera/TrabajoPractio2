#include "casillero.h"
#include <iostream>
#define SIMBOLO_FICHA_VACIA ' '

/*
Post: Inicializa un casillero con  una ficha nueva con el simbolo especificado
*/
Casillero::Casillero(char simboloFicha){
    this->contenidoCasillero = new Soldado(simboloFicha);
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
    if(this->contenidoCasillero->getSimboloFicha() == SIMBOLO_FICHA_VACIA)
    {
        return true;
    }
    return false;
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
    this->contenidoCasillero->setSimboloFicha(SIMBOLO_FICHA_VACIA);
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroAnulado = false;

}

/*
PRE: el casillero existe
Post: copia el contenido de un casillero a otro casillero
*/
void Casillero::copiarCasillero(Casillero* dest){
    dest->contenidoCasillero->setSimboloFicha(this->contenidoCasillero->getSimboloFicha());
    this->contenidoCasillero->setSimboloFicha(SIMBOLO_FICHA_VACIA);
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

void Casillero::setSimboloFichaDelCasillero(char simboloFicha) {
    this->contenidoCasillero->setSimboloFicha(simboloFicha);
}
/*Pre : casillero creado anteriormete
 * POST:obtiene la ficha del casillero
 */

char Casillero::obtenerSimboloFichaDelCasillero() {
    return this->contenidoCasillero->getSimboloFicha();
}

/*
Pre : casillero creado anteriormete
Post: devuelve el contenido del casillero*/
Ficha* Casillero::obtenerContenidoCasillero()
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


