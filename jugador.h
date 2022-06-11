#ifndef JUGADOR_H
#define JUGADOR_H
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
	///Lista<Lista <Lista<Casillero *>*>*> * filas  = new Lista<Lista <Lista<Casillero *>*>*>; 
	Lista<Ficha *>* listaFichas;
	Lista<Carta *>* listaCartas;
public:
	Jugador(string nombre, size_t id);
	void agregarFicha(Ficha* ficha);
	~Jugador();
	string obtenerNombreJugador();
	void setNombreJugador(string nombre);
	void setearIdJugador(size_t id);
	size_t obtenerIdJugador();
};

#endif
