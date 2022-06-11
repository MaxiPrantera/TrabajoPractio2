#ifndef JUGADOR_H
#define JUGADOR_H
#include "ficha.h"
#include "Carta.h"
#include <string>
#include "Lista.h"
#include "Cola.h"
#include "Carta.h"

/* [TDA JUGADOR] :
	.nombreJugador : Es el nombre del jugador
	.idJugador: Es un identificatorio del jugador
 */

using namespace std;
class Jugador
{
private:
	string  nombreJugador;
	unsigned int idJugador;
	unsigned int cantidadFichas;
	Lista<Ficha *>* listaFichas;
	Lista<Carta>* listaCartas;
public:
	Jugador(string nombre, int id);
	~Jugador();
	void agregarFicha(Ficha* ficha);
	string getNombreJugador();
	unsigned int getFichas();
	void setNombreJugador(string nombre);
	void setIdJugador(unsigned int id);
	unsigned int getIdJugador();
	void robarCarta(Cola<Carta>* mazo);
	//DEBUG
	unsigned int getCantidadCartas();
	string getNombreCarta(unsigned int);
	void tirarCarta(unsigned int);
};

#endif
