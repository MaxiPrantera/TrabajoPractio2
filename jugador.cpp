#include "jugador.h"
#include "ficha.h"

using namespace std;

/*
POST: Crea un jugador con atributos por default.
*/
Jugador::Jugador()
{
	this->listaFichas = new Lista<Ficha *>();
	this->cartas = new Lista<Carta>();
	this->nombreJugador = "";
}

/*
POST: Crea un jugador con un nombre
*/
Jugador::Jugador(string nombre)
{
	this->listaFichas = new Lista<Ficha *>();
	this->cartas = new Lista<Carta>();
	this->nombreJugador = nombre;
}

unsigned int Jugador::getFichas(){
	unsigned int contadorFichas = 0;
	this->listaFichas->reiniciarCursor();
	while(this->listaFichas->avanzarCursor()){
		if(this->listaFichas->getCursor()->getTipoFicha() == soldado && this->listaFichas->getCursor()->getEstado() == viva){
			contadorFichas++;
		}
	}
	return contadorFichas;
}

Ficha* Jugador::getFichaAux(unsigned int ficha)
{
	return this->listaFichas->get(ficha);
}

/**/
Jugador::~Jugador()
{

}
/*POST: Setea el nombre del jugador*/
void Jugador::setNombreJugador(string nombre)
{
	this->nombreJugador = nombre;
}

/*POST: Devuelve el nombre del jugador*/
string Jugador::getNombreJugador()
{
	return this->nombreJugador;
}

/*
PRE: el jugador existe
POST: devuelve la ID del jugador*/
unsigned int Jugador:: getIdJugador()
{
//	return this->idJugador;
}
void Jugador::setIdJugador(unsigned int id)
{
//	this->idJugador = id;
}

void Jugador::agregarFicha(Ficha* ficha){
	this->listaFichas->agregar(ficha);
}

/*
 * Pre: ---
 * Post: El jugador roba una carta para ser utilizada en alguno de sus turnos.
 */
void Jugador::robarCarta(Cola<Carta>* mazo)
{
	this->cartas->agregar(mazo->desacolar());
}

/*
 * Pre: ---
 * Post: El jugador roba una carta para ser utilizada en alguno de sus turnos.
 */
void Jugador::tirarCarta(unsigned int carta, Tablero* tablero)
{
	this->cartas->get(carta).tirarCarta(tablero);
}
