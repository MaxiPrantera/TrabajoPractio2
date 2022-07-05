#ifndef CASILLLERO_H
#define CASILLLERO_H

#include <iostream>
#include "Constantes.h"
#include "ficha.h"

/*[TDA CASILLERO]
    .turnosRestantesDesbloqueo: es la cantidad de turnos antes de poder desbloquearse
    .casilleroAnulado: indica si  en ese casillero puede colocarse una ficha
*/


class Casillero{

private:
    Terreno terreno;
    EstadoCasillero estado;
    Ficha* ficha;
    unsigned int x;
    unsigned int y;
    unsigned int z;
  
public:
    Casillero();
    Casillero(unsigned int, unsigned int, unsigned int);
    virtual ~Casillero();
    void setEstado(EstadoCasillero estado);
    void setTerreno(Terreno terreno);
    unsigned int getX();
    unsigned int getY();
    unsigned int getZ();
    EstadoCasillero getEstado();
    Terreno getTerreno();
    Ficha* getFicha();
    void setFicha(Ficha* ficha);
    void eliminarFicha();
};

#endif
