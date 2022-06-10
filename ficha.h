
#ifndef FICHA_H_
#define FICHA_H_

#include "constantes.h"
#include "jugador.h"
#include "casillero.h"
#include "tablero.h"


class Ficha
{
private:
	EstadoFicha estado;
	Ficha tipo;
	Jugador* duenio;
	Casillero* posicion;
public:
	
	/*
		PRE: - 
		POST: Crea la instancia de ficha
	*/
	Ficha(Ficha, EstadoFicha, Jugador*, Casillero*);
	
	/*
		PRE: Tiene que existir una ficha
		POST: Copia la instancia de ficha
	*/
	Ficha(const Ficha&);
	
	/*
		PRE: Tiene que existir una ficha
		POST: Elimina la instancia de ficha
	*/
	virtual ~Ficha();
	
	/*
		PRE: Tiene que existir la instancia de ficha
		POST: Devuelve el estado de la ficha
	*/
	EstadoFicha getEstado();
	
	/*
		PRE: Tiene que existir la instancia de ficha
		POST: Devuelve la ubicacion en x de la ficha
	*/
	int getUbicacionX();
	
	/*
		PRE: Tiene que existir la instancia de ficha
		POST: Devuelve la ubicacion en y de la ficha
	*/
	int getUbicacionY();
	
	/*
		PRE: Tiene que existir la instancia de ficha
		POST: Cambia el estado de la ficha
	*/
	void setEstado(EstadoFicha);
	
	/*
		PRE: Tiene que existir la instancia de ficha y se le debe pasar un casillero valido
		POST: Cambia la posicion de la ficha al casillero indicado
	*/
	void setPosicion(Casillero*);
	
	/*
		PRE: Se le pasa la direccion en la que quiere mover la ficha
		POST: Se mueve la ficha una unidad en la direccion indicacda
		
	*/
	void moverFicha(char, Tablero);
	
	/*
		PRE: La ficha tiene que ser un soldado, debe existir y debe estar muerto
		POST: Cambia el estado del soldado a vivo
	*/
	void revivirSoldado();
	
	/*
		PRE: La ficha debe existir y debe estar viva
		POST: Cambia el estado de la ficha al soldado
		
	*/
	void eliminarFicha();

};



#endif /* FICHA_H_ */
