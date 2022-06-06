
#ifndef FICHA_H_
#define FICHA_H_

#include "constantes.h"
#include "jugador.h"
#include "casillero.h"


class Ficha
{
private:
	EstadoFicha estado;
	Ficha tipo;
	Jugador* dueño;
	Casillero* posicion;
public:
	Ficha(Ficha, EstadoFicha, Jugador*, Casillero*);
	Ficha(const Ficha&);
	virtual ~Ficha();
	EstadoFicha getEstado();
	int getNumFicha();
	int getUbicacionX();
	int getUbicacionY();
	void setEstado(EstadoFicha);
	void setNumFicha(int);
	void setPosicion(Casillero*);
	void moverFicha(char);
	void verificarAtaque(int, int);
	void revivirSoldado();
	void eliminarFicha();

};



#endif /* FICHA_H_ */
