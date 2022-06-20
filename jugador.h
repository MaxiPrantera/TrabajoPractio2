#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Lista.h"
#include "Cola.h"
#include "tablero.h"
#include "Carta.h"
#include "ficha.h"

/* [TDA JUGADOR] :
	.nombreJugador : Es el nombre del jugador
	.idJugador: Es un identificatorio del jugador
 */

using namespace std;
class Jugador
{
private:
	string  nombreJugador;
//	unsigned int idJugador;
//	unsigned int cantidadFichas;
	Lista<Ficha *>* listaFichas;
	Lista<Carta>* cartas;
public:
	Jugador();
	Jugador(string nombre);
	~Jugador();
	void agregarFicha(Ficha* ficha);
	string getNombreJugador();
	unsigned int getFichas();
	Ficha* getFichaAux(unsigned int);
	void setNombreJugador(string nombre);
	void setIdJugador(unsigned int id);
	unsigned int getIdJugador();
	void robarCarta(Cola<Carta>* mazo);
	unsigned int getCantidadCartas();
	string getNombreCarta(unsigned int);
	void tirarCarta(unsigned int, Tablero*);
};

#endif
