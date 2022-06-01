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
public:
	Jugador(string nombre);
	~Jugador();
	string obtenerNombreJugador();
	void setNombreJugador(string nombre);
	void setearIdJugador(size_t id);
	size_t obtenerIdJugador();
};

#endif
