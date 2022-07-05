#ifndef TABLERO_H
#define TABLERO_H

#include "Lista.h"
#include "casillero.h"

/*
    .casilleros: es la lista de listas de lista de punteros a casillero
    .cantFilas : es la cantidad de filas que tiene el tablero
    .cantColumnas : es la cantidad de columnas que tiene el tablero
    .cantEnProfundidad : es la cantidad de profundo que tiene el tablero
*/

class Tablero {
private:
    Lista<Lista<Lista<Casillero> > >* casilleros;
    unsigned int profundidad; /*Máximo valor en x*/
    unsigned int ancho; /*Máximo valor en y*/
    unsigned int alto; /*Máximo valor en z*/

public:
    Tablero(unsigned int cantProfundidad, unsigned int cantColumnas, unsigned int cantFilas);
    virtual ~Tablero();
    Casillero* getCasillero(unsigned int profundidadIntroducida, unsigned int columnaIntroducida, unsigned int filaIntroducida);
    unsigned int getCantidadProfundidad();
    unsigned int getCantidadColumnas();
    unsigned int getCantidadFilas();
    bool existeLaCasilla(unsigned int profundidadIntroducida, unsigned int columnaIntroducida, unsigned int filaIntroducida);
    Casillero* elegirCoordenadas(std::string, bool, bool);
    void moverFicha(Ficha*);
    void disparar(Casillero*);
    void tirarMisil(Casillero*);
	void tirarMolotov(Casillero*);
};

#endif //TP2_TABLERO_H
