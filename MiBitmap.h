#ifndef MIBITMAP_INCLUDED
#define MIBITMAP_INCLUDED

#include "tablero.h"
#include "EasyBMP.h"

class MiBitmap
{
private:
    Lista<BMP>* filasAImprimir;

public:

    MiBitmap();

    virtual ~MiBitmap();

    void dibujarTablero();

    void dibujarAgua( BMP& InputImage );

    void dibujarTierra( BMP& InputImage );

    void dibujarLaguna();

    void quemarCasillero( BMP& InputImage );

    void casilleroAnulado();
    
    void agregarEscudo();

    void imprimirTablero(Tablero * tablero, unsigned int xMax, unsigned int yMax, unsigned int zMax);
};

#endif // MIBITMAP_INCLUDED
