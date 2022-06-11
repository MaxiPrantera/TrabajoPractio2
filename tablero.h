#ifndef TABLERO_H
#define TABLERO_H
#include "Lista.h"
#include "casillero.h"
#include "ficha.h"

using namespace std;

/*
    .casilleros: es la lista de listas de lista de punteros a casillero
    .cantFilas : es la cantidad de filas que tiene el tablero
    .cantColumnas : es la cantidad de columnas que tiene el tablero
    .cantEnProfundidad : es la cantidad de profundo que tiene el tablero
*/

class Tablero {
private:
    Lista<Lista<Lista<Casillero*>*>*>* casilleros; 
    unsigned int xMax;
    unsigned int yMax;
    unsigned int zMax;

public:
    Tablero(unsigned int cantFilas, unsigned int cantColumnas, unsigned int cantEnProfundidad);
    Tablero();
    virtual ~Tablero();
    Casillero *getCasillero(unsigned int filaIntroducida, unsigned int columnaIntroducida, unsigned int profundidadIntroducida);
    void setCasilla(unsigned int x, unsigned int y, unsigned int z, Ficha* simboloFicha); 
    unsigned int getCantFilasTablero();
    unsigned int getCantColumnasTablero();
    unsigned int getCantProfundidadTablero();
    bool existeLaCasilla(unsigned int m, unsigned int n, unsigned int l);
    Lista<Lista<Lista<Casillero*>*>*>* obtenerMatrizTablero();


};


#endif //TP2_TABLERO_H
