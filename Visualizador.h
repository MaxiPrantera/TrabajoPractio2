#ifndef VISUALIZADOR_INCLUDED
#define VISUALIZADOR_INCLUDED

#include "EasyBMP.h"
#include "tablero.h"

class Visualizador
{
private:
    BMP capa;

public:

    Visualizador();
    virtual ~Visualizador();
    void dibujarCapa(Tablero*, unsigned int);
    void dibujarTerreno(unsigned int, unsigned int, Terreno);
    void dibujarInactivo(unsigned int, unsigned int);
    void dibujarFicha(unsigned int, unsigned int, std::string);
    void exportarImagen(unsigned int);
    
    //void agregarEscudo();
};

#endif // VISUALIZADOR_INCLUDED
