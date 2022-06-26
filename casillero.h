#ifndef CASILLLERO_H
#define CASILLLERO_H

#include <iostream>
#include "Constantes.h"
#include "ficha.h"
//#include "jugador.h"

using namespace std;

/*[TDA CASILLERO]
    .turnosRestantesDesbloqueo: es la cantidad de turnos antes de poder desbloquearse
    .casilleroAnulado: indica si  en ese casillero puede colocarse una ficha
*/


class Casillero{

private:

//    Jugador* jugador;
    Terreno terreno;
    EstadoCasillero estado;
    unsigned int turnosRestantesDesbloqueo;
    Ficha* ficha;
    int x;
    int y;
    int z;
  

public:
    Casillero();
    virtual ~Casillero();
    void setEstado(EstadoCasillero estado);
    void setTerreno(Terreno terreno);
    int getX();
    int getY();
    int getZ();
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
