#include "tablero.h"
#include "casillero.h"
#include "ficha.h"

class Bitmap{

private:
    Tablero* tablero;
    Lista<BMP*> listaBitmap;

public:

    Bitmap();

    void dibujarTablero(Lista<BMP*> * capasTablero, unsigned int xMax, unsigned int yMax, unsigned int zMax);

    void dibujarAgua( BMP& InputImage );

    void dibujarTierra( BMP& InputImage );

    void dibujarLaguna();

    void quemarCasillero( BMP& InputImage );

    void casilleroAnulado();

    void imprimirTablero(Tablero * tablero, unsigned int xMax, unsigned int yMax, unsigned int zMax);

    virtual ~Bitmap();

}
