/*
 * constantes.h
 *
 *  Created on: 16/05/2022
 *      Author: algo2
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#define IZQUIERDA 'a'
#define ARRIBA 'w'
#define DERECHA 'd'
#define ABAJO 's'
#define DIAGONAL_IZQUERDA_ARRIBA 'q'
#define DIAGONAL_DERECHA_ARRIBA 'e'
#define DIAGONAL_IZQUERDA_ABAJO 'z'
#define DIAGONAL_DERECHA_ABAJO 'c'

enum EstadoFicha{
	vivo,
	muerto,
};

enum TipoFicha{
	avion,
	barco,
	soldado
};

enum TipoDeCarta
    {
        MISIL,
        AVION,
        BARCO,
        MOLOTOV,
        ESCUDO,
        REVIVIR
    };



#endif /* CONSTANTES_H_ */