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

class Jugador
{
private:
	std::string  nombre;
	Lista<Ficha>* fichas;
	Lista<Carta>* cartas;
public:
	Jugador();
	Jugador(std::string nombre);
	~Jugador();
	std::string getNombre();
	void agregarFicha(const Ficha& ficha);
	unsigned int getCantidadFichas();
	Ficha* getFicha(unsigned int);
	void robarCarta(Cola<Carta>* mazo);
	unsigned int getCantidadCartas();
	std::string getNombreCarta(unsigned int);
	//F: Fijarse bien que necesita esta funcion.
	void tirarCarta(unsigned int, Tablero*);
    Jugador& operator = (const Jugador&);
};

#endif
