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

	void tirarMisil(Tablero*);
	void ponerAvion(Tablero*);
	void ponerBarco(Tablero*);
	void tirarMolotov(Tablero*);
	void ponerEscudo(Tablero*);
	void revivir(Tablero*);
public:
	Jugador();
	Jugador(std::string nombre);
	~Jugador();
	std::string getNombre();
	void agregarFicha(TipoFicha, Tablero*);
	unsigned int getCantidadFichas();
	unsigned int getCantidadSoldadosVivos();
	Ficha* getFicha(unsigned int);
	void robarCarta(Cola<Carta>* mazo);
	unsigned int getCantidadCartas();
	std::string getNombreCarta(unsigned int);
	void tirarCarta(unsigned int, Tablero*);
    Jugador& operator = (const Jugador&);
};

#endif
