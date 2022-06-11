#ifndef JUGADOR_H
#define JUGADOR_H
#include "ficha.h"
#include "Carta(ACTUALIZAR).h"
#include <string>

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
	Lista<Carta *>* listaCartas;
public:
	Jugador(string nombre, int id);
	~Jugador();
	void agregarFicha(Ficha* ficha);
	string getNombreJugador();
	unsigned int getFichas();
	void setNombreJugador(string nombre);
	void setIdJugador(unsigned int id);
	unsigned int getIdJugador();
};

#endif
