#include "jugador.h"
#include "ficha.h"

using namespace std;
/*
POST: Crea un jugador con un nombre
*/
Jugador::Jugador(string nombre, int id)
{
	this->listaFichas = new Lista<Ficha *>();
	this->listaCartas = new Lista<Carta *>();
	this->nombreJugador = nombre;
	this->idJugador = id ;
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
	return this->idJugador;
}
void Jugador::setIdJugador(unsigned int id)
{
	this->idJugador = id;
}

void Jugador::agregarFicha(Ficha* ficha){
	this->listaFichas->agregar(ficha);
}