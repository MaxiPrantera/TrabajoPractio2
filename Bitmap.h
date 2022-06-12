#include "tablero.h"
#include "casillero.h"
#include "ficha.h"

class Bitmap{

private:
    Tablero* tablero;
    Ficha* getContenidoCasillero;
    Lista<BMP*> listaBitmap;

public:

    Bitmap();

    void dibujarTablero(Lista<BMP*> * capasTablero, unsigned int xMax, unsigned int yMax, unsigned int zMax);

    void dibujarAgua(const double x, const double y, const double c1, const double c2, const double c3, const double c4);

    void dibujarTierra(const double x, const double y, const double c1, const double c2, const double c3, const double c4);

    void dibujarFuego(double c1, double c2, double c3, double c4);

    void imprimirTablero(Tablero * tablero, unsigned int xMax, unsigned int yMax, unsigned int zMax);

    virtual ~Bitmap();

}