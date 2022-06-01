/*
 * soldado.h
 *
 *  Created on: 11/05/2022
 *      Author: algo2
 */

#ifndef SOLDADO_H_
#define SOLDADO_H_

#include "casillero.h"

enum EstadoSoldado{
	vivo,
	muerto,
};


class Soldado
{
private:
	EstadoSoldado estado;
	int numSoldado;
	int ubicacion[3];
	Casillero* posicion;
public:
	Soldado(EstadoSoldado,int,int[3]);
	virtual ~Soldado();
	EstadoSoldado getEstado();
	int getNumSoldado();
	int getUbicacionX();
	int getUbicacionY();
	void setEstado(EstadoSoldado);
	void setNumSoldado(int);
	void setUbicacion(int, int);
	void moverSoldado(char);
	void verificarAtaque(int, int);

};



#endif /* SOLDADO_H_ */
