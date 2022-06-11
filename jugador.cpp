#include "jugador.h"

using namespace std;
/*
POST: Crea un jugador con un nombre
*/
Jugador::Jugador(string nombre, size_t id)
{
	Lista<Ficha *>* listaDeFichas= new Lista<Ficha *>*;
	this->listaFichas = listaDeFichas;
	Lista<Carta *>* listaDeCartas= new Lista<Carta *>*;
	this->listaFichas = listaDeCartas;
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
string Jugador::obtenerNombreJugador()
{
	return this->nombreJugador;
}

/*
PRE: el jugador existe
POST: devuelve la ID del jugador*/
size_t Jugador:: obtenerIdJugador()
{
	return this->idJugador;
}
void Jugador::setearIdJugador(size_t id)
{
	this->idJugador = id;
}

void Jugador::agregarFicha(Ficha* ficha){
	this->listaFichas->agregar(ficha);
}