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
	size_t idJugador;
	unsigned int cantidadFichas;
<<<<<<< Updated upstream
	///Lista<Lista <Lista<Casillero *>*>*> * filas  = new Lista<Lista <Lista<Casillero *>*>*>; 
	Lista<Ficha *>* listaFichas;
	Lista<Carta *>* listaCartas;
public:
	Jugador(string nombre, size_t id);
	void agregarFicha(Ficha* ficha);
=======
	Lista<Ficha *>* listaFichas;
	Lista<Carta *>* listaCartas;
public:
	Jugador(string nombre, int id);
>>>>>>> Stashed changes
	~Jugador();
	void agregarFicha(Ficha* ficha);
	string getNombreJugador();
	unsigned int getFichas();
	void setNombreJugador(string nombre);
	void setIdJugador(size_t id);
	size_t getIdJugador();
};

#endif
