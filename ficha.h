
#ifndef FICHA_H_
#define FICHA_H_

#include <string>
#include <iostream>
#include "Constantes.h"


class Ficha
{
private:
	EstadoFicha estado;
	TipoFicha tipo;
	bool escudo;
	unsigned int x;
	unsigned int y;
	unsigned int z;
	std::string duenio;
public:
	/*
		PRE: -
		POST: Crea la instancia de ficha
	*/
	Ficha();

	/*
		PRE: - 
		POST: Crea la instancia de ficha
	*/
	Ficha(TipoFicha, unsigned int, unsigned int, unsigned int, std::string);
	
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
		POST: Devuelve la ubicacion en "x" de la ficha
	*/
	int getUbicacionX();
	
	/*
		PRE: Tiene que existir la instancia de ficha
		POST: Devuelve la ubicacion en "y" de la ficha
	*/
	int getUbicacionY();
	
	/*
		PRE: Tiene que existir la instancia de ficha
		POST: Devuelve la ubicacion en "z" de la ficha
	*/
	int getUbicacionZ();
	/*
		PRE: Tiene que existir la instancia de ficha
		POST: Cambia el estado de la ficha
	*/
	void setEstado(EstadoFicha);
	
	/*
		PRE: Tiene que existir la instancia de ficha y se le debe pasar un casillero valido
		POST: Cambia la posicion de la ficha al casillero indicado
	*/
	void setPosicion(unsigned int, unsigned int, unsigned int);
	
	/*
		PRE: La ficha debe existir y debe estar viva
		POST: Cambia el estado de la ficha al soldado
		
	*/
	void eliminarFicha();
	
	/*
		PRE: La ficha debe existir
		POST: Devuleve el tipo de ficha
	*/
	TipoFicha getTipoFicha();

	/*
		PRE: La ficha debe existir
		POST: Devuleve el tipo de ficha en formato string
	*/
	std::string getTipoFichaStr();

	/*
		PRE: -
		POST: devuelve true si tiene escudo, false si no
	*/
	bool getEscudo();

	/*
		PRE: La ficha debe existir y no debe tener escudo
		POST: le da un escudo a la ficha
	*/
	void darEscudo();

	/*
		PRE: La ficha debe existir y debe tener escudo
		POST: le quita el escudo a la ficha
	*/
	void quitarEscudo();

};



#endif /* FICHA_H_ */
