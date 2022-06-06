#include "jugador.h"

using namespace std;
/*
POST: Crea un jugador con un nombre
*/
Jugador::Jugador(std::string nombre)
{

	this->nombreJugador = nombre;
	this->idJugador = 0;
}

/**/
Jugador::~Jugador()
{

}
/*POST: Setea el nombre del jugador*/
void Jugador::setNombreJugador(std::string nombre)
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
