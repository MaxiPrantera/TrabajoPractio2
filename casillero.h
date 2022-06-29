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
    unsigned int turnosRestantesDesbloqueo;
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
    void setTurnosRestantesDesbloqueo(unsigned int cantidadTurnos);
    unsigned int getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();
    void copiarCasillero(Casillero* dest);
    Ficha* obtenerContenidoCasillero();
    void setFicha(Ficha* ficha);
    void eliminarFicha();
};

#endif
