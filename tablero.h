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
    //No seria mejor ponerles nombres tipo, ancho alto y profundo???
    unsigned int xMax;
    unsigned int yMax;
    unsigned int zMax;

public:
    Tablero(unsigned int cantFilas, unsigned int cantColumnas, unsigned int cantEnProfundidad);
    Tablero();
    virtual ~Tablero();
    Casillero* getCasillero(unsigned int filaIntroducida, unsigned int columnaIntroducida, unsigned int profundidadIntroducida);
    //void setCasilla(unsigned int x, unsigned int y, unsigned int z, Ficha* simboloFicha);
    unsigned int getCantidadFilas();
    unsigned int getCantidadColumnas();
    unsigned int getCantidadProfundidad();
    bool existeLaCasilla(unsigned int m, unsigned int n, unsigned int l);
    Lista<Lista<Lista<Casillero> > >* obtenerMatrizTablero();
    Casillero* elegirCoordenadas(std::string, bool, bool);
    void moverFicha(Ficha*);
    void disparar(Casillero*);
    void tirarMisil(Casillero*);
	void tirarMolotov(Casillero*);
};

#endif //TP2_TABLERO_H
