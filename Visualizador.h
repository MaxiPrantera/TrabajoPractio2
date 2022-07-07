#ifndef VISUALIZADOR_INCLUDED
#define VISUALIZADOR_INCLUDED

#include "EasyBMP.h"
#include "tablero.h"

class Visualizador
{
private:
    BMP imagen;

public:

    Visualizador();

    virtual ~Visualizador();

    void dibujarCapa(Tablero*, unsigned int);

    void dibujarTerreno(unsigned int, unsigned int, Terreno);

    void imprimirTablero(Tablero * tablero, unsigned int xMax, unsigned int yMax, unsigned int zMax);


    void casilleroAnulado();
    
    void agregarEscudo();
};

#endif // VISUALIZADOR_INCLUDED
