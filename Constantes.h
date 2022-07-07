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
	#define ARRIBA 'r'
	#define ABAJO 'f'

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
        TELETRANSPORTAR
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

    const unsigned int CANTIDAD_CARTAS_MAZO = 30;
    const unsigned int CANTIDAD_CARTAS_INICIALES = 3;
    const unsigned int PROFUNDIDAD_TABLERO = 20;
    const unsigned int ANCHO_TABLERO = 20;
    const unsigned int ALTO_TABLERO = 5;
    const unsigned int PIXELES_POR_CASILLERO = 600;

#endif // CONSTANTES_INCLUDED
