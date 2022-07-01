/*
 * constantes.h
 *
 *  Created on: 16/05/2022
 *      Author: algo2
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_

    #define IZQUIERDA 'a'
    #define ADELANTE 'w'
    #define DERECHA 'd'
    #define ATRAS 's'
    #define DIAGONAL_IZQUERDA_ADELANTE 'q'
    #define DIAGONAL_DERECHA_ADELANTE 'e'
    #define DIAGONAL_IZQUERDA_ATRAS 'z'
    #define DIAGONAL_DERECHA_ATRAS 'c'

    enum EstadoFicha{
        viva,
        muerta
    };

    enum TipoFicha{
        avion,
        barco,
        soldado
    };

    enum TipoCarta
    {
        MISIL,
        AVION,
        BARCO,
        MOLOTOV,
        ESCUDO,
        REVIVIR
    };

    enum Terreno
	{
		agua,
		aire,
		tierra
	};

	enum EstadoCasillero
	{
		vacio,
		ocupado,
		inactivo
	};



    //Esta cantidad debe ser multiplo de 6, asi siempre hay misma cantidad de cada tipo???
    const unsigned int CANTIDAD_CARTAS_MAZO = 30;
    const unsigned int CANTIDAD_CARTAS_INICIALES = 3;

#endif // CONSTANTES_INCLUDED
