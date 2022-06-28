#include "jugador.h"
#include "ficha.h"

using namespace std;

/*
POST: Crea un jugador con atributos por default.
*/
Jugador::Jugador()
{
	this->nombre = "";
	this->fichas = new Lista<Ficha>();
	this->cartas = new Lista<Carta>();
}

/*
POST: Crea un jugador con un nombre
*/
Jugador::Jugador(string nombre)
{
	this->nombre = nombre;
	this->fichas = new Lista<Ficha>();
	this->cartas = new Lista<Carta>();
}

/**/
Jugador::~Jugador()
{
	delete this->fichas;
	delete this->cartas;
}

/*POST: Devuelve el nombre del jugador*/
string Jugador::getNombre()
{
	return this->nombre;
}

//F: Agregar post.
void Jugador::agregarFicha(const Ficha& ficha){
	this->fichas->agregar(ficha);
}

//F: Agregar post.
unsigned int Jugador::getCantidadFichas(){
	return this->fichas->getTamanio();
}

//F: Agregar post.
Ficha* Jugador::getFicha(unsigned int ficha)
{
	return &this->fichas->get(ficha);
}

/*
 * Pre: ---
 * Post: El jugador roba una carta para ser utilizada en alguno de sus turnos.
 */
void Jugador::robarCarta(Cola<Carta>* mazo)
{this->cartas->agregar(mazo->desacolar());}

/*
 * Pre: ---
 * Post: Devuelve la cantidad de cartas que tiene el jugador.
 */
unsigned int Jugador::getCantidadCartas()
{return this->cartas->getTamanio();}

/*
 * Pre: ---
 * Post: Devuelve el nombre de la carta en la posicion indicada.
 */
string Jugador::getNombreCarta(unsigned int carta)
{return this->cartas->get(carta).getNombre();}

/*
 * Pre: ---
 * Post: El jugador roba una carta para ser utilizada en alguno de sus turnos.
 */
void Jugador::tirarCarta(unsigned int carta, Tablero* tablero)
{this->cartas->get(carta).tirarCarta(tablero);}

/*
 * Pre: Igualar dos variables del tipo jugador.
 * Post: Iguala las caracteristicas de la primer carta a las de la segunda.
*/
Jugador& Jugador::operator=(const Jugador& jugador)
{
    this->nombre = jugador.nombre;
    delete this->fichas;
	this->fichas = new Lista<Ficha>();
    this->fichas->agregar(jugador.fichas);
    delete this->cartas;
	this->cartas = new Lista<Carta>();
    this->cartas->agregar(jugador.cartas);
    return *this;
}
